#include "GameScene.h"
#include "AxisIndicator.h"
#include "ImGuiManager.h"
#include "TextureManager.h"
#include <cassert>
#include <math.h>
#include<fstream>


GameScene::GameScene() {}

GameScene::~GameScene() {

	delete model_;
	delete player_;
	delete debugCamera_;

	delete playerModel_;

	delete modelSkydome_;
	delete railCamera_;

	for (EnemyBullet* bullet : enemyBullets_) {

		delete bullet;
	}
	for (Enemy* enemy : enemys_) {

		delete enemy;
	}

	for (int i = 0; i < 4; i++) {
	
	delete lifeUI[i];
	}

}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	textureHandle_ = TextureManager::Load("blue.png");
	textureHandle2_ = TextureManager::Load("enemy.png");

	model_ = Model::Create();
	playerModel_ = Model::CreateFromOBJ("player", true);

	viewProjection_.Initialize();

	railCamera_ = new RailCamera();
	railCamera_->Initalize();

	

	player_ = new Player();

	Vector3 playerPosition(0, 0, 20.0f);
	player_->SetParent(&railCamera_->GetWorldTransform());
	player_->Initalize(playerModel_, textureHandle_, playerPosition);

	debugCamera_ = new DebugCamera(1280, 720);

	AxisIndicator::GetInstance()->SetVisible(true);
	AxisIndicator::GetInstance()->SetTargetViewProjection(&viewProjection_);

	

	// 02_13 P13まで

	skydome_ = new Skydome();

	modelSkydome_ = Model::CreateFromOBJ("skydome", true);

	skydome_->Initialize(modelSkydome_);

	LoadEnemyPopData();

	// レティクル用テクスチャ取得
	uint32_t lifeTitle = TextureManager::Load("Life.png");

	lifeUI[1] = Sprite::Create(lifeTitle, {33.0f, 28.0f}, {1.0f, 1.0f, 1.0f, 1}, {0.5f, 0.5f});
	lifeUI[2] = Sprite::Create(lifeTitle, {72.0f, 28.0f}, {1.0f, 1.0f, 1.0f, 1}, {0.5f, 0.5f});
	lifeUI[3] = Sprite::Create(lifeTitle, {111.0f,28.0f}, {1.0f, 1.0f, 1.0f, 1}, {0.5f, 0.5f});
}

void GameScene::Update() {

	// デスフラグの立った弾を削除
	enemys_.remove_if([](Enemy* enemy) {
		if (enemy->IsDead()) {
			delete enemy;

			return true;
		}

		return false;
	});

	// デスフラグの立った弾を削除
	enemyBullets_.remove_if([](EnemyBullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;

			return true;
		}
		return false;
	});

	



	if (isDebugCameraActive_ == true) {
		debugCamera_->Update();
		viewProjection_.matView = debugCamera_->GetViewProjection().matView;
		viewProjection_.matProjection = debugCamera_->GetViewProjection().matProjection;

		viewProjection_.TransferMatrix();
	} else {
		railCamera_->Update();
		viewProjection_.matView = railCamera_->GetViewProjection().matView;
		viewProjection_.matProjection = railCamera_->GetViewProjection().matProjection;
		viewProjection_.TransferMatrix();
		// viewProjection_.UpdateMatrix();
	}

	player_->Update(viewProjection_);

	if (isGameOver == true || isSceneEnd == true) {

		
	}
	LoadEnemyPopData();
	
	UpdataEnemyPopCommands();
	

	for (Enemy* enemy : enemys_) {
		enemy->Update();
	}

	for (EnemyBullet* bullet : enemyBullets_) {
		
	
		bullet->Update();
	}

	skydome_->Update();

	CheckAllCollisions();

	callScene();

#ifdef _DEBUG

	if (input_->IsPressMouse(1)) {

		isSceneEnd = true;
	}

#endif // DEBUG





	/*ImGui::Begin("camera");
	ImGui::DragFloat3("Translation", &viewProjection_.translation_.x, 0.01f);
	ImGui::DragFloat3("Rotation", &viewProjection_.rotation_.x, 0.01f);

	ImGui::End();*/
}

void GameScene::CheckAllCollisions() {
	Vector3 posA, posB;

	const std::list<PlayerBullet*>& playerBullets = player_->GetBullets();

	

#pragma region // 自キャラと敵弾の当たり判定
	posA = player_->GetWorldPosition();

	for (EnemyBullet* bullet : enemyBullets_) {
		posB = bullet->GetWorldPosition();

		float X = (posB.x - posA.x);
		float Y = (posB.y - posA.y);
		float Z = (posB.z - posA.z);

		float center = X * X + Y * Y + Z * Z;
		float R1 = 3.0f; // 自分で決める
		float R2 = 1.0f; // 自分で決める
		float RR = (R1 + R2);

		if (center <= (RR * RR)) {
			// 自キャラの衝突時コールバックを呼び出す
			player_->OnColision();
			// 敵弾の衝突時コールバックを呼び出す
			bullet->OnColision();
			playerLife -= 1;
		}
	}
#pragma endregion

#pragma region // 自弾と敵キャラの当たり判定

	for (Enemy* enemy : enemys_) {
		for (PlayerBullet* bullet : playerBullets) {
			posA = enemy->GetWorldPosition();
			posB = bullet->GetWorldPosition();

			float X = (posB.x - posA.x);
			float Y = (posB.y - posA.y);
			float Z = (posB.z - posA.z);

			float center = sqrtf(X * X + Y * Y + Z * Z);
			float R1 = 1.5f; // 自分で決める
			float R2 = 0.5f; // 自分で決める
			float RR = (R1 + R2);

			if (center <= (RR * RR)) {
				// 敵キャラの衝突時コールバックを呼び出す
           				enemy->OnColision();
				// 自弾の衝突時コールバックを呼び出す
				bullet->OnColision();

				score += 1;
			}
		}
	}

#pragma endregion

#pragma region // 自弾と敵弾の当たり判定
	for (EnemyBullet* bullet1 : enemyBullets_) {

		for (PlayerBullet* bullet2 : playerBullets) {
			posA = bullet1->GetWorldPosition();
			posB = bullet2->GetWorldPosition();

			float X = (posB.x - posA.x);
			float Y = (posB.y - posA.y);
			float Z = (posB.z - posA.z);

			float center = sqrtf(X * X + Y * Y + Z * Z);
			float R1 = 1.0f; // 自分で決める
			float R2 = 1.0f; // 自分で決める
			float RR = (R1 + R2);

			if (center <= (RR * RR)) {
				// 自キャラの衝突時コールバックを呼び出す
				bullet1->OnColision();
				// 敵弾の衝突時コールバックを呼び出す
				bullet2->OnColision();
			}
		}
	}
#pragma endregion
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	player_->Draw(viewProjection_);
	
	for (Enemy* enemy : enemys_) {

		enemy->Draw(viewProjection_);
	}
	for (EnemyBullet* bullet : enemyBullets_) {

		bullet->Draw(viewProjection_);
	}
	

	skydome_->Draw(viewProjection_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	 
	player_->DrawUI();
	
	if (3 <= playerLife) {

		lifeUI[3]->Draw();
	} 
	if (2 <= playerLife) {

		lifeUI[2]->Draw();
	} 
	if (1 <= playerLife) {

		lifeUI[1]->Draw();
	}



	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

void GameScene::AddEnemyBullet(EnemyBullet* enemyBullet) { enemyBullets_.push_back(enemyBullet); }

void GameScene::EnemyPop(Vector3 position) {

	Enemy* enemy = new Enemy();

	enemy->Initialize(model_, textureHandle2_, position);

	enemy->SetGameScene(this);

	enemy->SetPlayer(player_);

	enemys_.push_back(enemy);

	
}

void GameScene::LoadEnemyPopData() 
{
	//ファイルを開く
	std::ifstream file;

	file.open("Resources//enemyPop.csv");

	assert(file.is_open());

	//ファイルの内容を文字列ストリームにコピー
	enemyPopCommands << file.rdbuf();

	//ファイルを閉じる
	file.close();

}

void GameScene::UpdataEnemyPopCommands() 
{
	//待機処理
	if (waitFlag_) {
		waitTimer_--;
		if (waitTimer_ <= 0) {
		//待機完了
			waitFlag_ = false;
		
		}
		return;

	}


	//1行分の文字列を入れる変数
	std::string line;

	//コマンド実行ループ
	while (getline(enemyPopCommands,line)) {
		//1行分の文字列をストリームに変換して解析しやすくする
		std::istringstream line_stream(line);

		std::string word;

		//,区切りで行の先頭行列を取得
		getline(line_stream, word, ',');

		if (word.find("//") == 0) {
		//コメント行を飛ばす
		continue;
		}

		if (word.find("POP") == 0) {
		// x座標
		getline(line_stream, word, ',');
		float x = (float)std::atof(word.c_str());
		
		// y座標
		getline(line_stream, word, ',');
		float y = (float)std::atof(word.c_str());
		
		
		// z座標
		getline(line_stream, word, ',');
		float z = (float)std::atof(word.c_str());
		
		EnemyPop(Vector3(x, y, z));
		
		} 
		 else if (word.find("WAIT") == 0) {

		getline(line_stream, word, ',');

		//待ち時間
		int32_t waitTime = atoi(word.c_str());

		//待機開始
		waitFlag_ = true;
		waitTimer_ = waitTime;

		//コマンドループを抜ける
		break;
		}


		//つづく
	}




}

void GameScene::callScene() 
{
	
	if (playerLife<=0) {

	isGameOver = true;
	
	} else
	{
	isGameOver = false;
	}

	if (20 <= score) {

	
	isSceneEnd = true;
	
	}
	else
	{
	isSceneEnd = false;
	}


}

void GameScene::Reset() {

	for (Enemy* enemy : enemys_) {
		enemy->OnColision();
	}
	for (EnemyBullet* bullet : enemyBullets_) {
		bullet->OnColision();
	}
	playerLife = 3;
	score = 0;

}
