#include "EnemyBullet.h"
#include "cassert"

void EnemyBullet::Initialize(Model* model, const Vector3& position, const Vector3& velocity) {

	assert(model);

	model_ = model;

	textureHandle_ = TextureManager::Load("Red.png");

	worldTransform_.translation_ = position;

	worldTransform_.Initialize();

	velocity_ = velocity;
}

void EnemyBullet::Update() {

	

	worldTransform_.UpdateMatrix();

	worldTransform_.translation_.x += velocity_.x;
	worldTransform_.translation_.y += velocity_.y;

	worldTransform_.translation_.z += velocity_.z;

	

	
}

void EnemyBullet::Draw(const ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}

void EnemyBullet::OnColision() 
{ isDead_ = true; }

Vector3 EnemyBullet::GetWorldPosition() {

	Vector3 worldPos = {};

	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos;
}