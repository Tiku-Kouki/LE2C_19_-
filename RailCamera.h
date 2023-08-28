#pragma once
#include "Affine.h"
#include "Model.h"
#include "WorldTransform.h"

class RailCamera {
public:
	void Initalize();

	void Update();

	~RailCamera();

	Vector3 GetWorldPosition();

	const ViewProjection& GetViewProjection() { return viewProjection_; }

	const WorldTransform& GetWorldTransform() { return worldTransform_; }

private:
	bool isDebugCameraActive_ = false;

	WorldTransform worldTransform_;

	ViewProjection viewProjection_;
};
