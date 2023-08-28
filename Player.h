#pragma once
#include "Affine.h"
#include "Input.h"
#include "Model.h"
#include "PlayerBullet.h"
#include "WorldTransform.h"
#include <list>
#include"Sprite.h"

class Player {
public:
	void Initalize(Model* model, uint32_t textureHandle,Vector3 playerPosition);

	void Update(ViewProjection& viewProjection);

	void Rotate();

	void Draw(ViewProjection& viewProjection);

	~Player();

	void Attack();

	Vector3 GetWorldPosition();

	void OnColision();
	const std::list<PlayerBullet*>& GetBullets() const { return bullets_; }

	

	/// <summary>
	/// 親となるワールドトランスフォームをセット
	/// </summary>
	/// <param name="parent">親となるワールドトランスフォーム</param>
	void SetParent(const WorldTransform* parent);

	/// <summary>
	/// UI描画
	/// </summary>
	void DrawUI();


	void GetmMouse(ViewProjection& viewProjection);

	void GetGamePad(ViewProjection& viewProjection);


private:
	WorldTransform worldTransform_;

	Model* model_ = nullptr;

	uint32_t textureHandle_ = 0u;

	Input* input_ = nullptr;

	std::list <PlayerBullet*> bullets_;

	//3Dレティクル用ワールドトランスフォーム
	WorldTransform worldTransform3DReticle_; 

	// 2Dレティクル用スプライト
	Sprite* sprite2DReticle_ = nullptr;



};
