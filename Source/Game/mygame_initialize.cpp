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
	Sleep(1000);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
	//
}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (point.x > 400 && point.y > 420 && point.x < 702 && point.y < 556) {
		//CAudio::Instance()->Play(AUDIO_MENUTOGAME, false);
		GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
	}
}

void CGameStateInit::OnShow()
{
	background.ShowBitmap();
	brand.ShowBitmap();
	StartGame.ShowBitmap();
	draw_text();
}
void CGameStateInit::load_background() {
	brand.LoadBitmapByString({ "resources/Brand.bmp" }, RGB(0, 0, 0));
	brand.SetTopLeft(0, 0);

	background.LoadBitmapByString({ "resources/back3.bmp" });
	background.SetTopLeft(0, 0);

	StartGame.LoadBitmapByString({ "resources/StartGame.bmp" });
	StartGame.SetTopLeft(400, 420);
	
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
