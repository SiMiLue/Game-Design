#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0, "Start Initialize...");	// 一開始的loading進度為0%
	
	//
	// 開始載入資料
	//
	CAudio::Instance()->Load(0, "Sounds/mains.mp3");
	CAudio::Instance()->Play(0, true);
	load_background();
	load_food_info();
	load_food();
	Sleep(1000);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
}

void CGameStateInit::OnBeginState()
{
}
void CGameStateInit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{	
	if (nChar == VK_ESCAPE) {
		food_Button = false;
	}
}
void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}
void CGameStateInit::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (food_load == true) {
		
		//for (auto &v : food_array) 
			if (point.x > apple.GetLeft() && point.x < apple.GetLeft() + apple.GetWidth() && point.y > apple.GetTop() && point.y < apple.GetTop() + apple.GetHeight()) {
				showinfo = true;
				food_info = "apple";
				}
			else if (point.x > honey.GetLeft() && point.x < honey.GetLeft() + honey.GetWidth() && point.y > honey.GetTop() && point.y < honey.GetTop() + honey.GetHeight()) {
				showinfo = true;
				food_info = "honey";
			}
			else {
				showinfo = false;
			}


			
			

		


	}
	
}
void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (point.x > 400 && point.y > 420 && point.x < 702 && point.y < 556) {
		//CAudio::Instance()->Play(AUDIO_MENUTOGAME, false);
		GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
	}
	else if (point.x > 400 && point.y > 560 && point.x < 830 && point.y < 635) {
		food_Button = true;
	}
	
	
}

void CGameStateInit::OnShow()
{
	show_image_by_phase();
	show_food();
	show_food_info();
	//draw_text();
}
void CGameStateInit::load_background() {
	background.LoadBitmapByString({"resources/back3.bmp","resources/character_info.bmp"});
	background.SetTopLeft(0, 0);

	brand.LoadBitmapByString({ "resources/Brand.bmp" }, RGB(0, 0, 0));
	brand.SetTopLeft(0, 0);
	StartGame.LoadBitmapByString({ "resources/StartGame.bmp" });
	StartGame.SetTopLeft(400, 420);
	Pets_Button.LoadBitmapByString({ "resources/Pets_Button.bmp" });
	Pets_Button.SetTopLeft(400, 560);
	
}
void CGameStateInit::load_food() {
	
	apple.LoadBitmapByString({ "resources/food/Apple.bmp " }, RGB(255, 255, 255));
	apple.SetTopLeft(1000, 35);
	honey.LoadBitmapByString({ "resources/food/Honey.bmp " }, RGB(255, 255, 255));
	honey.SetTopLeft(1070, 35);
	pill.LoadBitmapByString({ "resources/food/Sleeping_Pill.bmp" }, RGB(255, 255, 255));
	pill.SetTopLeft(930, 155);
	meatbone.LoadBitmapByString({ "resources/food/Meat_Bone.bmp" }, RGB(255, 255, 255));
	meatbone.SetTopLeft(1000, 155);
	cupcake.LoadBitmapByString({ "resources/food/Cupcake.bmp" }, RGB(255, 255, 255));
	cupcake.SetTopLeft(1070, 155);
	salad.LoadBitmapByString({"resources/food/Salad_Bowl.bmp"}, RGB(255, 255, 255));
	salad.SetTopLeft(1000, 265);
	garlic.LoadBitmapByString({ "resources/food/Garlic.bmp" }, RGB(255, 255, 255));
	garlic.SetTopLeft(1070, 250);
	Canned.LoadBitmapByString({ "resources/food/Canned_Food.bmp" }, RGB(0, 0, 0));
	Canned.SetTopLeft(1000, 365);
	Pear.LoadBitmapByString({ "resources/food/Pear.bmp" }, RGB(0, 0, 0));
	Pear.SetTopLeft(1070, 365);
	Chili.LoadBitmapByString({ "resources/food/Chili.bmp" }, RGB(0, 0, 0));
	Chili.SetTopLeft(930, 485);
	Chocolate.LoadBitmapByString({ "resources/food/Chocolate.bmp" }, RGB(0, 0, 0));
	Chocolate.SetTopLeft(990, 485);
	Sushi.LoadBitmapByString({ "resources/food/Sushi.bmp" }, RGB(0, 0, 0));
	Sushi.SetTopLeft(1070, 490);
	Steak.LoadBitmapByString({ "resources/food/Steak.bmp" }, RGB(0, 0, 0));
	Steak.SetTopLeft(860, 613);
	Melon.LoadBitmapByString({ "resources/food/Melon.bmp" }, RGB(0, 0, 0));
	Melon.SetTopLeft(930, 600);
	Mushroom.LoadBitmapByString({ "resources/food/Mushroom.bmp" }, RGB(0, 0, 0));
	Mushroom.SetTopLeft(1000, 600);
	Pizza.LoadBitmapByString({ "resources/food/Pizza.bmp" }, RGB(0, 0, 0));
	Pizza.SetTopLeft(1070, 600);

	food_array.push_back(apple);
	food_array.push_back(honey);
	food_array.push_back(pill);
	food_array.push_back(meatbone);
	food_array.push_back(cupcake);
	food_array.push_back(salad);
	food_array.push_back(garlic);
	food_array.push_back(Canned);
	food_array.push_back(Pear);
	food_array.push_back(Chili);
	food_array.push_back(Chocolate);
	food_array.push_back(Sushi);
	food_array.push_back(Steak);
	food_array.push_back(Melon);
	food_array.push_back(Mushroom);
	food_array.push_back(Pizza);
	food_load = true;
}
void CGameStateInit::load_food_info() {
	apple_info.LoadBitmapByString({ "resources/food_info/Apple_info.bmp " });
	apple_info.SetTopLeft(20, 510);
	honey_info.LoadBitmapByString({ "resources/food_info/Honey_info.bmp " });
	honey_info.SetTopLeft(20, 510);
	pill_info.LoadBitmapByString({ "resources/food_info/Pill_info.bmp" });
	pill_info.SetTopLeft(20, 510);
	meatbone_info.LoadBitmapByString({ "resources/food_info/Meat_info.bmp" });
	meatbone_info.SetTopLeft(20, 510);
	cupcake_info.LoadBitmapByString({ "resources/food_info/Cupcake_info.bmp" });
	cupcake_info.SetTopLeft(20, 510);
	salad_info.LoadBitmapByString({ "resources/food_info/Salad_info.bmp" });
	salad_info.SetTopLeft(20, 510);
	garlic_info.LoadBitmapByString({ "resources/food_info/Garlic_info.bmp" });
	garlic_info.SetTopLeft(20, 510);
	Canned_info.LoadBitmapByString({ "resources/food_info/Canned_info.bmp" });
	Canned_info.SetTopLeft(600, 35);
	Pear_info.LoadBitmapByString({ "resources/food_info/Pear_info.bmp" });
	Pear_info.SetTopLeft(600, 35);
	Chili_info.LoadBitmapByString({ "resources/food_info/Chili_info.bmp" });
	Chili_info.SetTopLeft(600, 35);
	Chocolate_info.LoadBitmapByString({ "resources/food_info/Chocolat_info.bmp" });
	Chocolate_info.SetTopLeft(600, 35);
	Sushi_info.LoadBitmapByString({ "resources/food_info/Sushi_info.bmp" });
	Sushi_info.SetTopLeft(600, 35);
	Steak_info.LoadBitmapByString({ "resources/food_info/Steak_info.bmp" });
	Steak_info.SetTopLeft(600, 35);
	Melon_info.LoadBitmapByString({ "resources/food_info/Melon_info.bmp" });
	Melon_info.SetTopLeft(600, 35);
	Mushroom_info.LoadBitmapByString({ "resources/food_info/Mushroom_info.bmp" });
	Mushroom_info.SetTopLeft(600, 35);
	Pizza_info.LoadBitmapByString({ "resources/food_info/Pizza_info.bmp" });
	Pizza_info.SetTopLeft(600, 35);

	food_info_array.push_back(apple_info);
	food_info_array.push_back(honey_info);
	food_info_array.push_back(pill_info);
	food_info_array.push_back(meatbone_info);
	food_info_array.push_back(cupcake_info);
	food_info_array.push_back(salad_info);
	food_info_array.push_back(garlic_info);
	food_info_array.push_back(Canned_info);
	food_info_array.push_back(Pear_info);
	food_info_array.push_back(Chili_info);
	food_info_array.push_back(Chocolate_info);
	food_info_array.push_back(Sushi_info);
	food_info_array.push_back(Steak_info);
	food_info_array.push_back(Melon_info);
	food_info_array.push_back(Mushroom_info);
	food_info_array.push_back(Pizza_info);
}

void CGameStateInit::show_food() {
	if (food_Button == true ) {
		apple.ShowBitmap();
		honey.ShowBitmap();
		pill.ShowBitmap();
		meatbone.ShowBitmap();
		garlic.ShowBitmap();
		pill.ShowBitmap();
		cupcake.ShowBitmap();
		salad.ShowBitmap();
		meatbone.ShowBitmap();
		Canned.ShowBitmap();
		Pear.ShowBitmap();
		Chili.ShowBitmap();
		Chocolate.ShowBitmap();
		Sushi.ShowBitmap();
		Steak.ShowBitmap();
		Melon.ShowBitmap();
		Mushroom.ShowBitmap();
		Pizza.ShowBitmap();
	}
	
	
	
}

void CGameStateInit::show_image_by_phase() {
	if (food_Button == true) {
		background.SetFrameIndexOfBitmap(1);
		background.ShowBitmap();
	}
	else if (food_Button == false) {
		background.SetFrameIndexOfBitmap(0);
		background.ShowBitmap();
		StartGame.ShowBitmap();
		brand.ShowBitmap();
		Pets_Button.ShowBitmap();
	}

}
void CGameStateInit::show_food_info() {
	if (food_Button == true && showinfo == true) {
		if ( food_info == "apple" ) {
		apple_info.ShowBitmap();
		}
		else if (food_info == "honey") {
			honey_info.ShowBitmap();
		}

	}
	
	
}
void CGameStateInit::draw_text() {
	CDC *pDC = CDDraw::GetBackCDC();

	/* Print title */
	CTextDraw::ChangeFontLog(pDC, 36, "微軟正黑體", RGB(255, 255, 255));
	//CTextDraw::Print(pDC, 79, 228, "Game Framework Practice");

	/* Print info */
	CTextDraw::ChangeFontLog(pDC, 24, "微軟正黑體", RGB(255, 255, 255));
	//CTextDraw::Print(pDC, 182, 431, "Press any key to start");

	CDDraw::ReleaseBackCDC();
}
