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
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	
	

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

void CGameStateRun::OnMove()
{
	
	int x = 2;
	int y = 2;
	
	
	Wolverine.SetTopLeft(Wolverine.GetLeft() + x, Wolverine.GetTop() - y);

	
		
		


		
	
	
	

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

