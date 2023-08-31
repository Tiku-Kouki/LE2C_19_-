#include "PlayerBullet.h"
#include "cassert"



void PlayerBullet::Initialize(Model* model, const Vector3& position,const Vector3& velocity) { 
	
	assert(model);

	model_ = Model::Create();
	model = 0;

	textureHandle_ = TextureManager::Load("Blue.png");

	worldTransform_.scale_ = {0.5f, 0.5f, 0.5f};
	worldTransform_.translation_ = position;

	worldTransform_.Initialize(); 
	
	velocity_ = velocity;

}

void PlayerBullet::Update() {

worldTransform_.UpdateMatrix();

worldTransform_.translation_.x += velocity_.x;
worldTransform_.translation_.y += velocity_.y;

worldTransform_.translation_.z += velocity_.z;

if (--deathTimer_ <= 0) {
	isDead_ = true;
}



}

void PlayerBullet::Draw(const ViewProjection& viewProjection) {

model_->Draw(worldTransform_, viewProjection, textureHandle_);

}

void PlayerBullet::OnColision() 
{ isDead_ = true; }


Vector3 PlayerBullet::GetWorldPosition() {

Vector3 worldPos = {};

worldPos.x = worldTransform_.matWorld_.m[3][0];
worldPos.y = worldTransform_.matWorld_.m[3][1];
worldPos.z = worldTransform_.matWorld_.m[3][2];

return worldPos;
}