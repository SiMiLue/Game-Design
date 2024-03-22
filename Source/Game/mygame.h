/*
 * mygame.h: ���ɮ��x�C��������class��interface
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


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////
	
	enum AUDIO_ID {// �w�q�U�ح��Ī��s��
		AUDIO_Main,
		AUDIO_DING,				// 0
		AUDIO_LAKE,				// 1
		AUDIO_NTUT				// 2
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyUp(UINT, UINT, UINT); 				// �B�z��LUp���ʧ@
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);
		void OnKeyDown(UINT, UINT, UINT);
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap background;		// csie��logo
		CMovingBitmap StartGame;
		CMovingBitmap brand;
		CMovingBitmap Pets_Button;
		bool showinfo = false;
		bool food_Button = false;
		bool food_load = false;
		string food_info;
		CMovingBitmap check_food;
		CMovingBitmap apple;
		CMovingBitmap apple_info;
		CMovingBitmap honey;
		CMovingBitmap honey_info;
		CMovingBitmap pill;
		CMovingBitmap pill_info;
		CMovingBitmap meatbone;
		CMovingBitmap meatbone_info;
		CMovingBitmap cupcake;
		CMovingBitmap cupcake_info;
		CMovingBitmap salad;
		CMovingBitmap salad_info;
		CMovingBitmap garlic;
		CMovingBitmap garlic_info;
		CMovingBitmap Canned;
		CMovingBitmap Canned_info;
		CMovingBitmap Pear;
		CMovingBitmap Pear_info;
		CMovingBitmap Chili;
		CMovingBitmap Chili_info;
		CMovingBitmap Chocolate;
		CMovingBitmap Chocolate_info;
		CMovingBitmap Sushi;
		CMovingBitmap Sushi_info;
		CMovingBitmap Steak;
		CMovingBitmap Steak_info;
		CMovingBitmap Melon;
		CMovingBitmap Melon_info;
		CMovingBitmap Mushroom;
		CMovingBitmap Mushroom_info;
		CMovingBitmap Pizza;
		CMovingBitmap Pizza_info;

		CMovingBitmap Duck;
		CMovingBitmap Beaver;
		CMovingBitmap Pigeon;
		CMovingBitmap Otter;
		CMovingBitmap Pig;
		CMovingBitmap Ant;
		CMovingBitmap Mosquito;
		CMovingBitmap Fish;
		CMovingBitmap Cricket;
		CMovingBitmap Horse;

		CMovingBitmap Snail;
		CMovingBitmap Crab;
		CMovingBitmap Swan;
		CMovingBitmap Rat;
		CMovingBitmap Hedgehog;
		CMovingBitmap Peacock;
		CMovingBitmap Flamingo;
		CMovingBitmap Worm;
		CMovingBitmap Kangaroo;
		CMovingBitmap Spider;

		CMovingBitmap Dodo;
		CMovingBitmap Badger;
		CMovingBitmap Dolphin;
		CMovingBitmap Giraffe;
		CMovingBitmap Elephant;
		CMovingBitmap Camel;
		CMovingBitmap Rabbit;
		CMovingBitmap Ox;
		CMovingBitmap Dog;
		CMovingBitmap Sheep;
		void load_background();
		void load_food();
		void load_food_info();
		void load_pet();
		void draw_text();
		void show_food();
		void show_pet();
		void show_image_by_phase();
		void show_food_info();
		vector<CMovingBitmap> food_array;
		vector<CMovingBitmap> pets_array;
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@ 
		void OnRButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnRButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();			                        // ��ܳo�Ӫ��A���C���e��
	private:
		int phase = 1;
		int sub_phase = 1;
		CMovingBitmap background;
		//void show_image_by_phase();
		void show_text_by_phase();
		
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		int counter;	// �˼Ƥ��p�ƾ�
	};

}
