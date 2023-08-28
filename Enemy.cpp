#include "Enemy.h"
#include "cassert"
#include "ImGuiManager.h"
#include "Player.h"
#include"GameScene.h"

void Enemy::Initialize(Model* model, uint32_t textureHandle, Vector3 enemyPosition) {
	assert(model);

	model_ = model;

	
	textureHandle_ = textureHandle;
	

	worldTransform_.Initialize();


	worldTransform_.scale_ = {3.0f, 3.0f, 3.0f};

	worldTransform_.rotation_ = {0.0f, 0.0f, 0.0f};

	worldTransform_.translation_ = enemyPosition;

	
	
}

void (Enemy::*Enemy::Phase_[])() = {
    &Enemy::Approach_, // 接近する
    &Enemy::Leave_,    // 離脱する

};

void Enemy::Update() {
	
	
	
	worldTransform_.UpdateMatrix();

	
	phaseReset();
	

	(this->*Phase_[static_cast<size_t>(phase_)])();

	#ifdef _DEBUG
	ImGui::Begin("en");
	ImGui::Text(
	    " x: %f,y: %f z: %f", worldTransform_.translation_.x, worldTransform_.translation_.y,
	    worldTransform_.translation_.z);
	ImGui::DragFloat3("EnemyPos", &worldTransform_.translation_.x, 0.01f);
	ImGui::End();
	#endif

}

void Enemy::Draw(const ViewProjection& viewProjection) {
	
	model_->Draw(worldTransform_, viewProjection, textureHandle_);

	

}

void Enemy::Approach_() {
	

	worldTransform_.translation_.z -= move.z;
	if (worldTransform_.translation_.z < 0.0f) {
		phase_ = Phase::Leave;
	}

}

void Enemy::Leave_() {
	
	 move = {0.0f, 0.0f, 0.2f};


	worldTransform_.translation_.x -= move.x;
	worldTransform_.translation_.y += move.y;
	worldTransform_.translation_.z -= move.z;


}

Enemy::~Enemy() {

	for (EnemyBullet* bullet : bullets_) {

		delete bullet;
	}

}

void Enemy::Fire() {

	assert(player_);	

	const float kBulletSpeed = 0.5f;

	Vector3 playerWorld = player_->GetWorldPosition();
	Vector3 enemyWorld = GetWorldPosition();

	Vector3 difVector = {
	    playerWorld.x - enemyWorld.x, playerWorld.y - enemyWorld.y, playerWorld.z - enemyWorld.z};

	Vector3 difVectorN = Normalize(difVector);

	Vector3 velocity(
	    difVectorN.x * kBulletSpeed, difVectorN.y * kBulletSpeed, difVectorN.z * kBulletSpeed);

	velocity = TransformNormal(velocity, worldTransform_.matWorld_);






	EnemyBullet* newBullet = new EnemyBullet();

	newBullet->Initialize(model_, worldTransform_.translation_, velocity);

	
	
	gameScene_->AddEnemyBullet(newBullet);
 

}

void Enemy::phaseReset() {

	fireTimer--;

	if (fireTimer <= 0 && (worldTransform_.translation_.z>20)) {
		
		Fire();

		fireTimer = kFireInterval;
	}
}

Vector3 Enemy::GetWorldPosition() {
	Vector3 worldPos = {};

	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos;
}

void Enemy::OnColision() { 
	isDead_ = true;

}

void Enemy::Particle() {






}
