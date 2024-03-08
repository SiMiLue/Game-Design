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
	background.LoadBitmapByString({"Resources/character_info.bmp" });
	background.SetTopLeft(0, 0);

	infobox.LoadBitmapByString({"Resources/info_block.bmp"});
	infobox.SetTopLeft(0, 400);

	apple.LoadBitmapByString({ "resources/Apple.bmp " });
	apple.SetTopLeft(900, 35);
	honey.LoadBitmapByString({ "resources/Honey.bmp " });
	honey.SetTopLeft(1000, 35);

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
	
	if (point.x > apple.GetLeft() && point.x < apple.GetLeft() + apple.GetWidth() && point.y > apple.GetTop() && point.y < apple.GetTop() + apple.GetHeight()) {
		showinfo = true;
	}
	else {
		showinfo = false;
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
	show_image_by_phase();
	//show_text_by_phase();
	show_food();
}

void CGameStateRun::show_image_by_phase() {
	background.ShowBitmap();
	if (showinfo == true) {
		infobox.ShowBitmap();
	}
}
void CGameStateRun::show_food() {
	apple.ShowBitmap();
	honey.ShowBitmap();
	/*
	garlic.ShowBitmap();
	pill.ShowBitmap();
	cupcake.ShowBitmap();
	salad.ShowBitmap();
	meatbone.ShowBitmap();
	*/
}
void CGameStateRun::show_text_by_phase() {
	CDC *pDC = CDDraw::GetBackCDC();
	CTextDraw::ChangeFontLog(pDC, 36, "微軟正黑體", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 79, 228, "Game Framework Practice");
}
