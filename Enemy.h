#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "Input.h"
#include "Affine.h"
#include <list>
#include"EnemyBullet.h"
class Player;
class GameScene;

enum class Phase {
	Approach,//接近する
	Leave,//離脱する
};

class Enemy {

public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model">モデル</param>
	void Initialize(Model* model, uint32_t textureHandle, Vector3 enemyPosition);
	/// <summary>
	/// 更新
	/// </summary>
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="viewProjection">ビュープロジェクション</param>
	void Draw(const ViewProjection& viewProjection);

	void Approach_(); // 接近する
	void Leave_();


	~Enemy();

	/// <summary>
	/// 弾発射
	/// </summary>
	void Fire();

	static const int kFireInterval = 60;

	void phaseReset();

	void SetPlayer(Player* player) { player_ = player; }

	Vector3 GetWorldPosition();

	void OnColision();

	

	const std::list<EnemyBullet*>& GetBullets() const { return bullets_; }

	void SetGameScene(GameScene* gameScene) { gameScene_ = gameScene; }

	bool IsDead() const { return isDead_; }

	void Particle();


private:
	WorldTransform worldTransform_;

	Model* model_ = nullptr;

	uint32_t textureHandle_ = 0u;

	Input* input_ = nullptr;

	Phase phase_ = Phase::Approach;

	static void (Enemy::*Phase_[])();

	std::list<EnemyBullet*> bullets_;

	int32_t fireTimer = 0;

	Vector3 move = {0.0f, 0.0f, 0.2f};

	Player* player_ = nullptr;

	GameScene* gameScene_ = nullptr;

	// デスフラグ
	bool isDead_ = false;

};
