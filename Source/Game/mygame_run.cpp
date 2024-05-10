#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <chrono>
#include <thread>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}



void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	background.LoadBitmapByString({"Resources/initialize_background.bmp" });
	background.SetTopLeft(0, 0);
	Wolverine.LoadBitmapByString({ "resources/pets/Wolverine.bmp" }, RGB(255, 255, 255));
	Wolverine.SetTopLeft(320, 630);
	Gorilla.LoadBitmapByString({ "resources/pets/Gorilla.bmp" }, RGB(255, 255, 255));
	Gorilla.SetTopLeft(380, 610);
	
	
	/*
	pill.LoadBitmapByString({ "resources/Sleeping_Pill.bmp " });
	pill.SetTopLeft(1000, 150);
	cupcake.LoadBitmapByString({ "resources/Cupcake.bmp " });
	cupcake.SetTopLeft(1050, 150);

	meatbone.LoadBitmapByString({ "resources/Meat_Bone.bmp " });
	meatbone.SetTopLeft(1100, 150);
	salad.LoadBitmapByString({ "resources/Salad_Bowl.bmp " });
	salad.SetTopLeft(1000, 200);
	garlic.LoadBitmapByString({ "resources/Garlic.bmp " });
	garlic.SetTopLeft(1050, 200);
	*/
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
<<<<<<< Updated upstream
=======

	vector<shared_ptr<Pet>> item = shop.get_shop_item();
	for (unsigned int i = 0; i < item.size(); i++) {
		tuple<bool, int> buything = atkcell.isbuying(item[i]->get_img().GetLeft(), item[i]->get_img().GetTop());
		int atk_idx = get<1>(buything);
		shared_ptr<Pet> current_atk_pet;
		if (get<0>(buything)) { current_atk_pet = atkcell.get_pets_by_idx(atk_idx); }
		else { current_atk_pet = nullptr; }
		if (get<0>(buything) && current_atk_pet == nullptr && current_money >= 3) {
			current_money -= 3;
			atkcell.buy_by_index(get<1>(buything), item[i]->clone());
			item[i]->set_locate(0, 0);
			shop.set_buy_by_index(i);
		}
		else if (get<0>(buything) && CMovingBitmap::IsOverlap(item[i]->get_img(), current_atk_pet->get_img()) && current_money >= 3) {
			current_money -= 3;
			current_atk_pet->set_atk(current_atk_pet->get_attack() + 1);
			current_atk_pet->set_life(current_atk_pet->get_life() + 1);
			item[i]->set_locate(0, 0);
			atkcell.set_level_by_idx(atk_idx);
			shop.set_buy_by_index(i);
		}
		else {
			item[i]->set_locate(shop.get_cordinate(i, "x"), shop.get_cordinate(i, "y"));

		}
	}
	if (selected == 1) {
		vector<shared_ptr<Pet>> atk = atkcell.get_pets();
		for (unsigned int i = 0; i < atk.size(); i++) {
			if (atk[i] != nullptr) {

				if (CMovingBitmap::IsOverlap(atk[i]->get_img(), Csell)) { //動物移到賣出鍵那
					int money = atkcell.sell_by_index(i);
				}
				else {
					atk[i]->set_locate(atkcell.get_cordinate(i, "x"), atkcell.get_cordinate(i, "y"));
				}
			}
		}
	}
>>>>>>> Stashed changes
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
<<<<<<< Updated upstream
	
	

=======
	test = point.x;
	test1 = point.y;
	bool foundFood = false;
		vector<shared_ptr<Pet>> item = shop.get_shop_item();
		for (unsigned int i = 0; i < item.size(); i++) {
			CMovingBitmap img = item[i]->get_img();
			if (point.x > img.GetLeft() && point.x < img.GetLeft() + img.GetWidth() && point.y > img.GetTop() && point.y < img.GetTop() + img.GetHeight()) {
				if (nFlags == MK_LBUTTON) { 
					item[i]->set_locate(point.x - 20, point.y - 20); 
					showinfo = false;
					}
				else {
					info =i;
					showinfo = true;
					foundFood = true;
					item[i]->showii(shop.get_cordinate(i, "x"), shop.get_cordinate(i, "y") );
				}
				
			}
		}
		vector<shared_ptr<Pet>> atk = atkcell.get_pets();
		for (unsigned int i = 0; i < atk.size(); i++) {
			if (atk[i] != nullptr) {
				CMovingBitmap img = atk[i]->get_img();
				if (point.x > img.GetLeft() && point.x < img.GetLeft() + img.GetWidth() && point.y > img.GetTop() && point.y < img.GetTop() + img.GetHeight()) {
					selected = 1;
					if (nFlags == MK_LBUTTON) { 
						atk[i]->set_locate(point.x - 20, point.y - 20); 
						atkinfo = false;
					}
					else {
						info = i;
						atkinfo = true;
						foundFood = true;
						atk[i]->showii(atkcell.get_cordinate(i, "x"), atkcell.get_cordinate(i, "y"));
					}
				}

			}
		}
		if (!foundFood) {
			showinfo = false;
			atkinfo = false;
		}
>>>>>>> Stashed changes
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	background.ShowBitmap();
	show_text_by_phase();
	Wolverine.ShowBitmap();
	Gorilla.ShowBitmap();
	
}
<<<<<<< Updated upstream

void CGameStateRun::OnMove()
{
	
	int x = 2;
	int y = 2;
	
	
	Wolverine.SetTopLeft(Wolverine.GetLeft() + x, Wolverine.GetTop() - y);

	
		
		


		
	
	
	
=======
void CGameStateRun::show_info() {

	vector<shared_ptr<Pet>> item = shop.get_shop_item();
	vector<shared_ptr<Pet>> atk = atkcell.get_pets();
	if (showinfo == true) {
		item[info]->get_info().ShowBitmap();
	}
	else if (atkinfo == true) {

		atk[info]->get_info().ShowBitmap();
	}
}
void CGameStateRun::show_image_by_phase() {
>>>>>>> Stashed changes

}

void CGameStateRun::show_text_by_phase() {
	/*if (win) {
		CDC *pDC = CDDraw::GetBackCDC();
		CTextDraw::ChangeFontLog(pDC, 120, "微軟正黑體", RGB(238, 104, 37),1500);
		CTextDraw::Print(pDC, 340, 270, "恭喜獲勝");
		CDDraw::ReleaseBackCDC();
	}
	else
	{
		CDC *pDC = CDDraw::GetBackCDC();
		CTextDraw::ChangeFontLog(pDC, 120, "微軟正黑體", RGB(238, 104, 37), 1500);
		CTextDraw::Print(pDC, 340, 270, "遊戲失敗");
		CDDraw::ReleaseBackCDC();*/
	}
	
void CGameStateRun::attack() 
{
	//while (game->fight_step()) {
	
	
	if ()
	
	
	
	
	
	//}
	//return game->end_fight();







}

