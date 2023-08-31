#include "RailCamera.h"
#include "ImGuiManager.h"
#include "cassert"

void RailCamera::Initalize() {

	worldTransform_.scale_ = {1.0f, 1.0f, 1.0f};

	worldTransform_.rotation_ = {0.0f, 0.0f, 0.0f};

	worldTransform_.translation_ = {0.0f, 0.0f, 0.0f};

	viewProjection_.Initialize();
}

void RailCamera::Update() {

	//worldTransform_.translation_.z -= 0.01f;
	//worldTransform_.rotation_.y += 0.01f;

	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	viewProjection_.matView = Inverse(worldTransform_.matWorld_);

	// viewProjection_.UpdateMatrix();
	// viewProjection_.TransferMatrix();
#ifdef _DEBUG
	ImGui::Begin("Camera");

	ImGui::DragFloat3("Translation", &worldTransform_.translation_.x, 0.01f);
	ImGui::DragFloat3("Rotation", &worldTransform_.rotation_.x, 0.01f);

	ImGui::End();

#endif 
}

RailCamera::~RailCamera() {}

Vector3 RailCamera::GetWorldPosition() {
	Vector3 worldPos = {};

	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos;
}
