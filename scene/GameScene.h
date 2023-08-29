#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Player.h"
#include "DebugCamera.h"
#include "Enemy.h"
#include "Skydome.h"
#include "RailCamera.h"
#include "EnemyBullet.h"
#include <sstream>
#include "Scene.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 衝突判定と応答
	/// </summary>
	void CheckAllCollisions();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="viewProjection">ビュープロジェクション</param>
	void AddEnemyBullet(EnemyBullet* enemyBullet);

	void EnemyPop(Vector3 position);

	const std::list<Enemy*>& GetEnemys() const { return enemys_; }
	const std::list<EnemyBullet*>& GetBullets() const { return enemyBullets_; }

	 void LoadEnemyPopData();

	/// <summary>
	 /// 敵発生コマンドの更新
	 /// </summary>
	 void UpdataEnemyPopCommands();

	 bool isSceneEnd = false;
	 bool IsSceneEnd() { return isSceneEnd; }

	 bool isGameOver = false;
	 bool IsGameOver() { return isGameOver; }

	 SceneType NextScene() { 

	if (isSceneEnd == true) 
	{
	 return SceneType::kClearGame;
	}else
	if (isGameOver == true) {
	 return SceneType::kGameOver;
	}
	return SceneType::kGamePlay;
	 }

	 SceneType GameOver() { return SceneType::kGameOver; }

 private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	uint32_t textureHandle_ = 0;
	uint32_t textureHandle2_ = 0;

	Model* model_ = nullptr;
	Model* playerModel_ = nullptr;
	
	ViewProjection viewProjection_;
	Player* player_ = nullptr;
	
	bool isDebugCameraActive_ = false;
	DebugCamera* debugCamera_ = nullptr;

	
	std::list<EnemyBullet*> enemyBullets_;

	std::list<Enemy*> enemys_;

	Enemy* enemy_ = nullptr;
	EnemyBullet* enemyBullet_ = nullptr;


	Skydome* skydome_ = nullptr;

	Model* modelSkydome_ = nullptr;

	RailCamera* railCamera_ = nullptr;

	 std::stringstream enemyPopCommands;


	 // 待機中タイマー
	 int32_t waitTimer_ = 10;
	 // 待機フラグ
	 bool waitFlag_ = true;


	 
	


	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
