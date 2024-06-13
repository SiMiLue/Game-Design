#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework ;
/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(0, "Start Initialize...");	// �@�}�l��loading�i�׬�0%

	//
	// �}�l���J���
	//
	CAudio::Instance()->Load(0, "Sounds/mains.mp3");
	CAudio::Instance()->Play(0, true);
	load_background();
	load_food_info();
	load_pet();
	load_food();
	Sleep(1000);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
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
	if (point.x > 350 && point.y > 560 && point.x < 800 && point.y < 650) {
		petchange = true;
	}
	else
	{
		petchange = false;
	}
	if (point.x > 400 && point.y > 420 && point.x < 750 && point.y < 551) {
		startchange = true;
	}
	else
	{
		startchange = false;
	}
	if (food_load == true) {
		bool foundFood = false;
		for (size_t i = 0; i < object.size(); i++) {
			CMovingBitmap info = object[i]->get_img();
			if (point.x > info.GetLeft() && point.x < info.GetLeft() + info.GetWidth() && point.y >info.GetTop() && point.y < info.GetTop() + info.GetHeight()) {
				showinfo = true;
				food_info = i;
				foundFood = true;
			}
		}

		for (unsigned int j = 0; j < pet.size(); j++) {
			CMovingBitmap info = pet[j]->get_img();
			if (point.x > info.GetLeft() && point.x < info.GetLeft() + info.GetWidth() && point.y >info.GetTop() && point.y < info.GetTop() + info.GetHeight()) {
				showpetinfo = true;
				pet_info = j;
				foundFood = true;
			}
		}
		if (!foundFood) {
			showinfo = false;
			showpetinfo = false;
		}

	}

}
void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (point.x > 400 && point.y > 420 && point.x < 702 && point.y < 556 && food_Button == false) {
		//CAudio::Instance()->Play(AUDIO_MENUTOGAME, false);
		GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
	}
	else if (point.x > 350 && point.y > 560 && point.x < 800 && point.y < 650) {
		food_Button = true;
	}
}

void CGameStateInit::OnShow()
{
	show_image_by_phase();
	show_food();
	show_pet();
	show_food_info();
	show_pet_info();
}
void CGameStateInit::load_background() {
	background.LoadBitmapByString({ "resources/back3.bmp","resources/character_info.bmp" });
	background.SetTopLeft(0, 0);
	brand.LoadBitmapByString({ "resources/Brand.bmp" }, RGB(0, 0, 0));
	brand.SetTopLeft(0, 0);
	StartGame.LoadBitmapByString({ "resources/StartGame1.bmp", "resources/StartGame.bmp" }, RGB(255, 255, 255));
	StartGame.SetTopLeft(400, 420);
	Pets_Button.LoadBitmapByString({ "resources/PetButton.bmp" ,"resources/PetButton2.bmp" }, RGB(255, 255, 255));
	Pets_Button.SetTopLeft(350, 560);

}
void CGameStateInit::load_food() {
	for (auto item : object) {
		item->Load_img();
	}
	int idx = 0;
	int first = 0;
	for (int y = 35; y <= 635; y = y + 120) {
		if (idx == 2 || idx == 9) first = 930;
		else if (idx == 12) first = 860;
		else first = 1000;
		for (int x = first; x <= 1070; x = x + 70) {
			if (idx > 6) object[idx++]->set_locate(x, y - 20);
			else object[idx++]->set_locate(x, y);

		}
	}

	food_load = true;
}

void CGameStateInit::load_pet() {

	for (auto item : pet) {
		item->Load_img();
	}
	int idx = 0;
	for (int y = 35; y <= 635; y = y + 120) {
		for (int x = 140; x <= 680; x = x + 60) {
			if (y >= 635) {
				pet[idx++]->set_locate(x, 610);
			}
			else {
				pet[idx++]->set_locate(x, y);
			}

		}
	}
	int infoidx = 0;
	for (auto item : pet) {
		if (infoidx < 30) {
			item->setinfo_locate(20, 510);
		}
		else
		{
			item->setinfo_locate(20, 0);
		}
		infoidx++;
	}

}
void CGameStateInit::load_food_info() {
	for (auto item : object) {
		item->Load_img();
	}
	int infoidx = 0;
	for (auto item : object) {
		if (infoidx < 30) {
			item->setinfo_locate(20, 510);
		}
		else
		{
			item->setinfo_locate(20, 0);
		}
		infoidx++;
	}
}


void CGameStateInit::show_food() {
	if (food_Button == true) {
		for (auto &v : object) {
			v->get_img().ShowBitmap();
		}
	}
}

void CGameStateInit::show_pet() {
	if (food_Button == true) {
		for (auto &v : pet) {
			v->get_img().ShowBitmap();
		}
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
		brand.ShowBitmap();
		if (!petchange) {
			Pets_Button.SetFrameIndexOfBitmap(0);
			Pets_Button.ShowBitmap();
		}
		else if (petchange)
		{
			Pets_Button.SetFrameIndexOfBitmap(1);
			Pets_Button.ShowBitmap();
		}
		if (!startchange) {
			StartGame.SetFrameIndexOfBitmap(0);
			StartGame.ShowBitmap();
		}
		else if (startchange) {
			StartGame.SetFrameIndexOfBitmap(1);
			StartGame.ShowBitmap();
		}

	}

}
void CGameStateInit::show_food_info() {
	if (food_Button == true && showinfo == true) {
		object[food_info]->get_info().ShowBitmap();
	}
}
void CGameStateInit::show_pet_info() {
	if (food_Button == true && showpetinfo == true) {
		pet[pet_info]->get_info().ShowBitmap();
	}
}
void CGameStateInit::draw_text() {
	CDC *pDC = CDDraw::GetBackCDC();

	/* Print title */
	CTextDraw::ChangeFontLog(pDC, 36, "�L�n������", RGB(255, 255, 255));
	//CTextDraw::Print(pDC, 79, 228, "Game Framework Practice");

	/* Print info */
	CTextDraw::ChangeFontLog(pDC, 24, "�L�n������", RGB(255, 255, 255));
	//CTextDraw::Print(pDC, 182, 431, "Press any key to start");

	CDDraw::ReleaseBackCDC();
}
