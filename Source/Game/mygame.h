/*
 * mygame.h: 本檔案儲遊戲本身的class的interface
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/
#include "attackCell.h"
#include "Shop.h"
#include "atkSystem.h"
#include "object.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////
	/*
	enum AUDIO_ID {// 定義各種音效的編號
		AUDIO_Main,
		AUDIO_DING,				// 0
		AUDIO_LAKE,				// 1
		AUDIO_NTUT				// 2
	};
	*/
	enum PHASE {
		INTROPHASE,
		BUYPHASE,
		ATKPHASE,
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnMouseMove(UINT nFlags, CPoint point);
		void OnKeyDown(UINT, UINT, UINT);
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		GenPets pets;
		GenObject objects;
		vector<shared_ptr<Pet>> pet = pets.get_pets();
		vector<shared_ptr<Object>> object = objects.get_Object();
		CMovingBitmap background;		// csie的logo
		CMovingBitmap StartGame;
		CMovingBitmap brand;
		CMovingBitmap Pets_Button;
		bool showinfo = false;
		bool showpetinfo = false;
		bool food_Button = false;
		bool food_load = false;
		bool petchange = false;
		bool startchange = false;
		int food_info;
		unsigned int pet_info;

		CMovingBitmap check_food;


		void load_background();
		void load_food();
		void load_food_info();
		void load_pet();
		void draw_text();
		void show_food();
		void show_pet();
		void show_image_by_phase();
		void show_food_info();
		void show_pet_info();
		vector<CMovingBitmap> food_array;

		vector<CMovingBitmap> food_info_array;
		//vector<CMovingBitmap> pets_array;


	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作 
		void OnRButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnRButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作

	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();			                        // 顯示這個狀態的遊戲畫面
	private:
		int phase = 1;
		int sub_phase = 1;
		int current_money = 10;
		int current_heart = 5;
		int current_round = 1;
		int current_win = 0;
		int current_pets = 0;
		int selected = 0;
		
		CMovingBitmap resume;
		CMovingBitmap background;
		CMovingBitmap money;
		CMovingBitmap heart;
		CMovingBitmap win;
		CMovingBitmap round;
		CMovingBitmap Cfreeze;
		CMovingBitmap Csell;
		CMovingBitmap roundEnd;
		CMovingBitmap drawDice;
		PHASE phases{BUYPHASE};
		AttackCell atkcell;
		Atksystem atksystem;
		bool shop_item_drag = false;
		bool draw_clicked=false;
		void show_image_by_phase();
		void show_text_by_phase();

		void show_money_text();
		void show_heart_text(int test);
		void show_wins_text();
		void show_round_text(int test);
		void show_info();
		void choose_item(shared_ptr<Pet> &current_pet);
		int test=0;
		int test1 = 0;
		int info = 1;
		Ant ant;
		bool showinfo=false;
		bool atkinfo = false;
		vector<shared_ptr<Pet>> select_item;

		Shop shop;
		vector<shared_ptr<Pet>> tst;
		
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		int counter;	// 倒數之計數器
	};

}
