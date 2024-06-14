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
	if (phases == ATKPHASE) {
		atksystem.mainLoop();
		if (atksystem.checklife()) {
			game_done = true;
			atksystem.resetGame();
		}
	}
	if (current_win == 15) {
		lastresult.SetFrameIndexOfBitmap(0);
		phases = ENDPHASE;
	}
	if (current_heart == 0) {
		lastresult.SetFrameIndexOfBitmap(1);
		phases = ENDPHASE;
	}

}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{

	srand((unsigned int)time(NULL));
	ant.Load_img();
	ant.get_img().SetTopLeft(100, 500);

	background.LoadBitmapByString({ "resources/initialize_background.bmp","resources/atk_background.bmp" });
	background.SetTopLeft(0, 0);

	resume.LoadBitmapByString({ "resources/resume.bmp" });
	resume.SetTopLeft(880, 570);
	money.LoadBitmapByString({ "resources/money.bmp" }, RGB(255, 255, 255));
	money.SetTopLeft(0, 0);
	heart.LoadBitmapByString({ "resources/heart.bmp" }, RGB(255, 255, 255));
	heart.SetTopLeft(150, 5);
	round.LoadBitmapByString({ "resources/time.bmp" }, RGB(255, 255, 255));
	round.SetTopLeft(300, 0);
	win.LoadBitmapByString({ "resources/game_win.bmp" }, RGB(255, 255, 255));
	win.SetTopLeft(450, 0);
	tst.push_back(make_shared<Ant>());
	roundEnd.LoadBitmapByString({ "resources/round_end.bmp" });
	roundEnd.SetTopLeft(1000, 450);
	drawDice.LoadBitmapByString({ "resources/draw.bmp" });
	drawDice.SetTopLeft(0, 600);
	Cfreeze.LoadBitmapByString({ "resources/freeze.bmp" ,"resources/unfreeze.bmp" });
	Cfreeze.SetTopLeft(0, 500);
	Csell.LoadBitmapByString({ "resources/sell.bmp" });
	Csell.SetTopLeft(1000, 328);
	lastresult.LoadBitmapByString({ "resources/win.bmp","resources/fail.bmp" });
	shop.init();
	atkcell.init();
	shop.get_random_pet(current_round);
	shop.get_random_foods(current_round);
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
	if (nChar == VK_ESCAPE) {
		if (phases == ATKPHASE) { phases = BUYPHASE; }
		if (phases == BUYPHASE) { GotoGameState(GAME_STATE_INIT); }
	}
	if ((GetKeyState(VK_CONTROL) & 0x8000) && nChar == 'H') {
		current_money = 100;
	}
	if (nChar == 'D') {
		current_money -= 1;
		shop.get_random_pet(current_round);
		shop.get_random_foods(current_round);
	}
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	showinfo = false;
	vector<shared_ptr<Object>> foods = shop.get_foods();
	vector<bool> food_select = shop.get_foodSelect();
	vector<shared_ptr<Pet>> atkPets= atkcell.get_pets();
	if (phases == ENDPHASE) { 
		phases = BUYPHASE;
		GotoGameState(GAME_STATE_OVER);
	}
	if (shop.get_selectfood() != nullptr) {
		for (size_t i = 0; i < atkPets.size(); i++) {
			if (atkPets[i] != nullptr) {
				CMovingBitmap atkPet = atkPets[i]->get_img();
				if (point.x >= atkPet.GetLeft() && point.x <= atkPet.GetLeft() + atkPet.GetWidth() && point.y >= atkPet.GetTop() && point.y <= atkPet.GetTop() + atkPet.GetHeight()) {
					shop.get_selectfood()->Boost(atkcell.get_pets(), i, 0);
					shop.set_food_is_buy(shop.get_selectfood());
					current_money -= 3;
				}

			}
		}
		if (point.x >= Cfreeze.GetLeft() && point.x <= Cfreeze.GetLeft() + Cfreeze.GetWidth() && point.y >= Cfreeze.GetTop() && point.y <= Cfreeze.GetTop() + Cfreeze.GetHeight()) {
			shop.set_food_is_freeze(shop.get_selectfood());
		}
	}
	
	for (size_t i = 0; i < foods.size(); i++) {
		CMovingBitmap food = foods[i]->get_img();
		if (point.x >= food.GetLeft() && point.x <= food.GetLeft() + food.GetWidth() && point.y >= food.GetTop() && point.y <= food.GetTop() + food.GetHeight()&&!shop.get_food_bought(i)) {
			shop.check_food_select(i);
		}
		else {
			shop.check_select_item_exit(point.x,point.y);
		}
	}
	
	
	if (point.x >= resume.GetLeft() && point.x <= resume.GetLeft() + resume.GetWidth() && point.y >= resume.GetTop() && point.y <= resume.GetTop() + resume.GetHeight() && game_done == true && phases == ATKPHASE) {
		if (atksystem.friendly_life() && atksystem.m_enemy_life()) { lastwin = false; }
		else if (atksystem.friendly_life()) {
			current_heart -= 1; 
			lastwin = false;
		}
		else if (atksystem.m_enemy_life()) {
			current_win += 1; 
			lastwin = true;
		}
		phases = BUYPHASE;
	}

	if (current_money > 0) {
		if (point.x >= drawDice.GetLeft() && point.x <= drawDice.GetLeft() + drawDice.GetWidth() && point.y >= drawDice.GetTop() && point.y <= drawDice.GetTop() + drawDice.GetHeight()) {
			current_money -= 1;
			shop.get_random_pet(current_round);
			shop.get_random_foods(current_round);
			draw_clicked = true;
		}
	}

	if (point.x >= roundEnd.GetLeft() && point.x <= roundEnd.GetLeft() + roundEnd.GetWidth() && point.y >= roundEnd.GetTop() && point.y <= roundEnd.GetTop() + roundEnd.GetHeight()) {
		phases = ATKPHASE;
		game_done = false;
		vector<Level> levels;
		levels.push_back(Level(1, { make_shared<Otter>(), make_shared<Otter>(), make_shared<Otter>() }));
		levels.push_back(Level(2, { make_shared<Ant>(), make_shared<Ant>(), make_shared<Ant>(),make_shared<Ant>(),make_shared<Ant>() }));

		levels.push_back(Level(3, { make_shared<Horse>(), make_shared<Snail>(), make_shared<Rat>(),make_shared<Fish>(),make_shared<Swan>() }));
		levels.push_back(Level(4, { make_shared<Spider>(), make_shared<Swan>(), make_shared<Duck>(),make_shared<Worm>(),make_shared<Crab>() }));

		levels.push_back(Level(5, { make_shared<Sheep>(), make_shared<Peacock>(), make_shared<Dodo>(),make_shared<Hedgehog>(),make_shared<Ox>() }));
		levels.push_back(Level(6, { make_shared<Dolphin>(), make_shared<Pig>(), make_shared<Rabbit>(),make_shared<Elephant>(),make_shared<Dog>() }));

		levels.push_back(Level(7, { make_shared<Hippo>(), make_shared<Whale>(), make_shared<Skunk>(),make_shared<Turtle>(),make_shared<Dog>() }));
		levels.push_back(Level(8, { make_shared<Bison>(), make_shared<Penguin>(), make_shared<Deer>(),make_shared<Squirrel>(),make_shared<Blowfish>() }));

		levels.push_back(Level(9, { make_shared<Crocodile>(), make_shared<Rooster>(), make_shared<Cow>(),make_shared<Armadillo>(),make_shared<Monkey>() }));
		levels.push_back(Level(10, { make_shared<Turkey>(), make_shared<Shark>(), make_shared<Crocodile>(),make_shared<Rhino>(),make_shared<Seal>() }));

		levels.push_back(Level(11, { make_shared<Snake>(), make_shared<Shark>(), make_shared<Parrot>(),make_shared<Scorpion>(),make_shared<Monkey>() }));
		levels.push_back(Level(12, { make_shared<Tiger>(), make_shared<Leopard>(), make_shared<Gorilla>(),make_shared<Dragon>(),make_shared<Mammoth>() }));

		levels.push_back(Level(13, { make_shared<Cat>(), make_shared<Cat>(), make_shared<Cat>(),make_shared<Cat>(),make_shared<Cat>() }));
		levels.push_back(Level(14, { make_shared<Mammoth>(), make_shared<Gorilla>(), make_shared<Cat>(),make_shared<Leopard>(),make_shared<Dragon>() }));
		levels.push_back(Level(15, { make_shared<Boar>(), make_shared<Boar>(), make_shared<Boar>(),make_shared<Boar>(),make_shared<Boar>() }));

		levels[current_win].startLevel(atksystem, atkcell, shop, current_round, current_money, current_win, current_heart,game_done);
		/*
		current_round += 1;
		current_money = 10;
		shop.get_random_pet(current_round);
		*/

		//if (result == 0) { current_heart -= 1; }
		//if (result == 1) { current_win += 1; }

	}

}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	select_item = {};
	for (unsigned int i = 0; i < shop.get_shop_item().size(); i++) {
		shop.set_touched(i, false);
	}
	for (unsigned int i = 0; i < atkcell.get_pets().size(); i++) {
		atkcell.set_touched(i, false);
	}
	vector<shared_ptr<Pet>> item = shop.get_shop_item();
	for (unsigned int i = 0; i < item.size(); i++) {
		tuple<bool, int> buything = atkcell.isbuying(item[i]->get_img().GetLeft(), item[i]->get_img().GetTop());
		int atk_idx = get<1>(buything);
		shared_ptr<Pet> current_atk_pet;
		if (get<0>(buything)) { current_atk_pet = atkcell.get_pets_by_idx(atk_idx); }
		else { current_atk_pet = nullptr; }

		if (CMovingBitmap::IsOverlap(item[i]->get_img(), Cfreeze)) {
			if (shop.get_freeze_by_idx(i)) {
				shop.set_freeze_by_idx(i, false);
			}
			else {
				shop.set_freeze_by_idx(i, true);
			}
		}
		shared_ptr<Pet> temp;
		if (get<0>(buything) && current_money >= 3) {
			shop.set_freeze_by_idx(i, false);
			if (current_atk_pet == nullptr) {
				current_money -= 3;
				item[i]->onBuy(atkcell.get_pets(), 1, atk_idx);
				atkcell.buy_by_index(get<1>(buything), item[i]->clone());
				item[i]->set_locate(0, 0);
				shop.set_buy_by_index(i);
			}
			else if (CMovingBitmap::IsOverlap(item[i]->get_img(), current_atk_pet->get_img()) && current_atk_pet->get_id() == item[i]->get_id()) {
				current_money -= 3;

				current_atk_pet->set_atk(current_atk_pet->get_attack() + 1);
				current_atk_pet->set_life(current_atk_pet->get_life() + 1);
				item[i]->set_locate(0, 0);
				atkcell.set_level_by_idx(atk_idx);
				item[i]->onBuy(atkcell.get_pets(), atkcell.get_level_by_idx(atk_idx), atk_idx);
				if (atkcell.get_vectorlevel(atk_idx) == 2 || atkcell.get_vectorlevel(atk_idx) == 5) {
					item[i]->onLevelup(atkcell.get_pets(), atkcell.get_vectorlevel(atk_idx), atk_idx);
				}
				shop.set_buy_by_index(i);
			}
			else {
				item[i]->set_locate(shop.get_cordinate(i, "x"), shop.get_cordinate(i, "y"));
			}
		}
		else {
			item[i]->set_locate(shop.get_cordinate(i, "x"), shop.get_cordinate(i, "y"));
		}
	}
	if (selected == 1) {
		vector<shared_ptr<Pet>> atk = atkcell.get_pets();
		for (unsigned int i = 0; i < atk.size(); i++) {
			if (atk[i] != nullptr) {
				tuple<bool, int> atkPosition = atkcell.isbuying(atk[i]->get_img().GetLeft(), atk[i]->get_img().GetTop());
				if (get<0>(atkPosition)) { test = 1; atkcell.changePosition(i, get<1>(atkPosition)); }
				else if (CMovingBitmap::IsOverlap(atk[i]->get_img(), Csell)) {
					int current_level = atkcell.get_level_by_idx(i);
					atkcell.sell_by_index(i, 2, &current_money);
					atk[i]->onSell(&current_money, shop.get_shop_item(), atkcell.get_pets(), current_level);
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
	shop_item_drag = false;
	bool foundFood = false;


	vector<shared_ptr<Pet>> item = shop.get_shop_item();
	for (unsigned int i = 0; i < item.size(); i++) {
		CMovingBitmap img = item[i]->get_img();
		if (point.x > img.GetLeft() && point.x < img.GetLeft() + img.GetWidth() && point.y > img.GetTop() && point.y < img.GetTop() + img.GetHeight() && !shop.get_isbought_by_index(i)) {
			if (nFlags == MK_LBUTTON) {
				shop_item_drag = true;
				choose_item(item[i]);
				shop.set_touched(i, true);
				showinfo = false;
				if (shop.get_freeze_by_idx(i)) {
					Cfreeze.SetFrameIndexOfBitmap(1);
				}
				else {
					Cfreeze.SetFrameIndexOfBitmap(0);
				}
			}
			else {
				info = i;
				showinfo = true;
				foundFood = true;
				item[i]->showii(shop.get_cordinate(i, "x"), shop.get_cordinate(i, "y"));
			}

		}
		if (nFlags == MK_LBUTTON) {
			if (shop.get_touched_by_index(i)) {
				//item[i]->set_locate(point.x - 20, point.y - 20);
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
					choose_item(atk[i]);
					atkcell.set_touched(i, true);
					atkinfo = false;
				}
				else {
					info = i;
					atkinfo = true;
					foundFood = true;
					atk[i]->showii(atkcell.get_cordinate(i, "x"), atkcell.get_cordinate(i, "y"));
				}
			}
			if (nFlags == MK_LBUTTON) {
				if (atkcell.get_touched_by_index(i)) {
					//atk[i]->set_locate(point.x - 20, point.y - 20);
				}
			}
		}
	}
	vector<shared_ptr<Object>> foods = shop.get_foods();
	for (size_t i = 0; i < foods.size(); i++) {
		CMovingBitmap food = foods[i]->get_img();
		if (point.x >= food.GetLeft() && point.x <= food.GetLeft() + food.GetWidth() && point.y >= food.GetTop() && point.y <= food.GetTop() + food.GetHeight() && !shop.get_food_bought(i)) {
			showfoodinfo = true;
			showfood_index = i;
			foundFood = true;
		}
		
		
	}
	if (!foundFood) {
		showinfo = false;
		atkinfo = false;
		showfoodinfo = false;
	}
	
	if (nFlags == MK_LBUTTON) {
		if (select_item.size() == 1) {
			select_item[0]->set_locate(point.x - 20, point.y - 20);
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

		Csell.ShowBitmap();

		if (shop_item_drag || shop.get_selectfood()!=nullptr) {
			Cfreeze.ShowBitmap();
		}
		shop.show_img();
		atkcell.show_pets();
		show_money_text();
		show_heart_text(test);
		show_round_text(test1);
		show_wins_text();
		show_info();
		if (shop.get_selectfood() != nullptr) {
			for (size_t i = 0; i < atkcell.get_pets().size(); i++) {
				if (atkcell.get_pets()[i] != nullptr) {
					atkcell.get_pets()[i]->show_select(atkcell.get_cordinate(i,"x"), atkcell.get_cordinate(i, "y"));
				}
			}
		}
		if (showfoodinfo) {
			shop.get_foods()[showfood_index]->showAB(shop.get_food_cordinate(showfood_index,"x"), shop.get_food_cordinate(showfood_index, "y"));
		}
		
	}
	else if (phases == ATKPHASE) {
		background.SetFrameIndexOfBitmap(1);
		background.ShowBitmap();
		if(game_done==true){ resume.ShowBitmap(); }
		
		atksystem.show();
		show_heart_text(test);
		show_round_text(test1);
	}
	else if (phases == ENDPHASE) {
		lastresult.ShowBitmap();
	}


}

void CGameStateRun::choose_item(shared_ptr<Pet> &current_pet) {
	if (select_item.size() == 0) {
		select_item.push_back(current_pet);
	}
}

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

}
void CGameStateRun::show_text_by_phase() {
	CDC *pDC = CDDraw::GetBackCDC();

	CTextDraw::ChangeFontLog(pDC, 21, "微軟正黑體", RGB(0, 0, 0), 800);

	CDDraw::ReleaseBackCDC();

}
void CGameStateRun::show_money_text() {
	CDC *pDC = CDDraw::GetBackCDC();
	CTextDraw::ChangeFontLog(pDC, 32, "Lapsus Pro Bold", RGB(0, 0, 0));
	CTextDraw::Print(pDC, 65, 5, to_string(current_money));
	CTextDraw::Print(pDC, 215, 5, to_string(current_heart));
	CTextDraw::Print(pDC, 365, 5, to_string(current_round));
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
	
}


