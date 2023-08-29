#include "TitleScene.h"
#include "AxisIndicator.h"
#include "ImGuiManager.h"
#include "TextureManager.h"
#include <cassert>
#include <math.h>
#include<fstream>

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
	delete title_; 



}

void TitleScene::Initialize()
{
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	

}

void TitleScene::Update()
{
	
	
		if (input_->IsPressMouse(0)) {
			
			isSceneEnd = true;
		} else {
			isSceneEnd = false;
		}
	


}

void TitleScene::Draw()
{

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



	

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる

	

	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion

}
