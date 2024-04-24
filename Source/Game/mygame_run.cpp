#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>


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

void CGameStateRun::OnMove()							// 移動遊戲元素
{

}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{

	
	ant.Load_img();
	ant.get_img().SetTopLeft(100,500);
	
	background.LoadBitmapByString({ "resources/initialize_background.bmp","resources/atk_background.bmp" });
	background.SetTopLeft(0, 0);

	resume.LoadBitmapByString({ "resources/resume.bmp" });
	resume.SetTopLeft(880, 570);
	money.LoadBitmapByString({ "resources/money.bmp" });
	money.SetTopLeft(0, 0);
	heart.LoadBitmapByString({ "resources/heart.bmp" });
	heart.SetTopLeft(150, 0);
	round.LoadBitmapByString({ "resources/round.bmp" });
	round.SetTopLeft(300, 0);
	win.LoadBitmapByString({ "resources/game_win.bmp" });
	win.SetTopLeft(450, 0);
	tst.push_back(make_shared<Ant>());
	roundEnd.LoadBitmapByString({ "resources/round_end.bmp" });
	roundEnd.SetTopLeft(1000, 450);
	drawDice.LoadBitmapByString({ "resources/draw.bmp" });
	drawDice.SetTopLeft(0, 600);
	Cfreeze.LoadBitmapByString({ "resources/freeze.bmp" });
	Cfreeze.SetTopLeft(0, 400);
	Csell.LoadBitmapByString({ "resources/sell.bmp" });
	Csell.SetTopLeft(1000,328);
	shop.init();
	atkcell.init();
	shop.get_random_pet(current_round);
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
	if (nChar == VK_ESCAPE) {
		if (phases == ATKPHASE) { phases = BUYPHASE; }
	}
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	if (point.x >= resume.GetLeft() && point.x <= resume.GetLeft() + resume.GetWidth() && point.y >= resume.GetTop() && point.y <= resume.GetTop() + resume.GetHeight()) {
		phases = BUYPHASE;
	}

	
	isdrag = true;
	if (current_money > 0) {
		if (point.x >= drawDice.GetLeft() && point.x <= drawDice.GetLeft() + drawDice.GetWidth() && point.y >= drawDice.GetTop() && point.y <= drawDice.GetTop() + drawDice.GetHeight()) {
			current_money -= 1;
			shop.get_random_pet(current_round);
			draw_clicked = true;
		}
	}
	
	if (point.x >= roundEnd.GetLeft() && point.x <= roundEnd.GetLeft() + roundEnd.GetWidth() && point.y >= roundEnd.GetTop() && point.y <= roundEnd.GetTop() + roundEnd.GetHeight()) {
		phases = ATKPHASE;
		shared_ptr<Pet> ant = make_shared<Ant>();
		shared_ptr<Pet> ant2 = make_shared<Ant>();
		shared_ptr<Pet> ant3 = make_shared<Ant>();
		ant->set_life(20);
		ant2->set_life(20);
		ant3->set_life(20);
		atksystem.set_fight_combination(atkcell.get_pets(), { ant,ant2,ant3 });
		int result = atksystem.atk();
		current_round += 1;
		current_money = 10;
		shop.get_random_pet(current_round);
		
		
		if (result == 0) { current_heart -= 1; }
		if (result == 1) { current_win += 1; }
		
	}
	
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	
	vector<shared_ptr<Pet>> item = shop.get_shop_item();
	for (unsigned int i = 0; i < item.size(); i++) {
		tuple<bool, int> buything= atkcell.isbuying(item[i]->get_img().GetLeft(), item[i]->get_img().GetTop());
		int atk_idx = get<1>(buything);
		shared_ptr<Pet> current_atk_pet;
		if(get<0>(buything)){ current_atk_pet = atkcell.get_pets_by_idx(atk_idx); }
		else { current_atk_pet = nullptr; }
		if (get<0>(buything) && current_atk_pet == nullptr && current_money>=3) {
			current_money -= 3;
			atkcell.buy_by_index(get<1>(buything),item[i]->clone());
			item[i]->set_locate(0, 0);
			shop.set_buy_by_index(i);
		}
		else if(get<0>(buything) && CMovingBitmap::IsOverlap(item[i]->get_img(),current_atk_pet->get_img())&& current_money >= 3){
			current_money -= 3;
			current_atk_pet->set_atk(current_atk_pet->get_attack() + 1);
			current_atk_pet->set_life(current_atk_pet->get_life() + 1);
			item[i]->set_locate(0, 0);
			atkcell.set_level_by_idx(atk_idx);
			shop.set_buy_by_index(i);
		}
		else {
			item[i]->set_locate(shop.get_cordinate(i,"x"), shop.get_cordinate(i, "y"));
			
		}
	}
	if (selected == 1) {
		vector<shared_ptr<Pet>> atk = atkcell.get_pets();
		for (unsigned int i = 0; i < atk.size(); i++) {
			if (atk[i] != nullptr) {
				
				if (CMovingBitmap::IsOverlap(atk[i]->get_img(), Csell)) {
					int money=atkcell.sell_by_index(i,2);
				}
				else {
					atk[i]->set_locate(atkcell.get_cordinate(i, "x"), atkcell.get_cordinate(i, "y"));
				}
				
				
			}

		}
	}
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	test = point.x;
	test1 = point.y;
	if (nFlags == MK_LBUTTON) {
		vector<shared_ptr<Pet>> item = shop.get_shop_item();
		for (unsigned int i = 0; i < item.size(); i++) {
			CMovingBitmap img = item[i]->get_img();
			if (point.x > img.GetLeft() && point.x < img.GetLeft() + img.GetWidth() && point.y > img.GetTop() && point.y < img.GetTop() + img.GetHeight()) {
				item[i]->set_locate(point.x - 20, point.y - 20);
			}
			
		}
		vector<shared_ptr<Pet>> atk = atkcell.get_pets();
		for (unsigned int i = 0; i < atk.size(); i++) {
			if (atk[i] != nullptr) {
				CMovingBitmap img = atk[i]->get_img();
				if (point.x > img.GetLeft() && point.x < img.GetLeft() + img.GetWidth() && point.y > img.GetTop() && point.y < img.GetTop() + img.GetHeight()) {
					selected = 1;
					atk[i]->set_locate(point.x - 20, point.y - 20);
				}
			
			}
		}
	}
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	
	if (phases == BUYPHASE) {
		background.SetFrameIndexOfBitmap(0);
		background.ShowBitmap();
		money.ShowBitmap();
		heart.ShowBitmap();
		round.ShowBitmap();
		win.ShowBitmap();
		roundEnd.ShowBitmap();
		drawDice.ShowBitmap();
		if (selected == 1) {
			Csell.ShowBitmap();
		}
		shop.show_img();
		atkcell.show_pets();
		show_money_text();
		show_heart_text(test);
		show_round_text(test1);
		show_wins_text();
	}
	else if (phases == ATKPHASE) {
		background.SetFrameIndexOfBitmap(1);
		background.ShowBitmap();
		resume.ShowBitmap();
		atksystem.show();
		show_heart_text(test);
		show_round_text(test1);
	}
	
	
	
}

void CGameStateRun::show_image_by_phase() {

}
void CGameStateRun::show_text_by_phase() {
	CDC *pDC = CDDraw::GetBackCDC();

	CTextDraw::ChangeFontLog(pDC, 21, "微軟正黑體", RGB(0, 0, 0), 800);

	CDDraw::ReleaseBackCDC();

}
void CGameStateRun::show_money_text() {
	CDC *pDC = CDDraw::GetBackCDC();
	CTextDraw::ChangeFontLog(pDC, 32, "Lapsus Pro Bold", RGB(0, 0, 0));
	CTextDraw::Print(pDC, 65, 0, to_string(current_money));
	CTextDraw::Print(pDC, 215, 0, to_string(current_heart));
	CTextDraw::Print(pDC, 365, 0, to_string(current_round));
	CDDraw::ReleaseBackCDC();
}
void CGameStateRun::show_heart_text(int test) {
	CDC *pDC = CDDraw::GetBackCDC();
	CTextDraw::ChangeFontLog(pDC, 36, "微軟正黑體", RGB(0, 0, 0));
	CTextDraw::Print(pDC, 888, 0, to_string(test));
	CDDraw::ReleaseBackCDC();
}
void CGameStateRun::show_round_text(int test) {
	CDC *pDC = CDDraw::GetBackCDC();
	CTextDraw::ChangeFontLog(pDC, 36, "微軟正黑體", RGB(0, 0, 0));
	CTextDraw::Print(pDC, 1000, 0, to_string(test));
	CDDraw::ReleaseBackCDC();
}
void CGameStateRun::show_wins_text() {
	string str = to_string(current_win);
	str.append("/15");
	CDC *pDC = CDDraw::GetBackCDC();
	CTextDraw::ChangeFontLog(pDC, 36, "微軟正黑體", RGB(0, 0, 0));
	CTextDraw::Print(pDC, 515, 0, str);
	CDDraw::ReleaseBackCDC();
	if (current_win == 15) {
		GotoGameState(GAME_STATE_OVER);
	}
}


