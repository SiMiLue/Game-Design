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
	load_pet();
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
		for (size_t i = 0; i < food_array.size(); i++ ) {
			if (point.x > food_array[i].GetLeft() && point.x < food_array[i].GetLeft() + food_array[i].GetWidth() && point.y > food_array[i].GetTop() && point.y < food_array[i].GetTop() + food_array[i].GetHeight()) {
				showinfo = true;
				food_info = i; 
				foundFood = true;
			}
		}
		for (size_t j = 0; j < pets_array.size(); j++) {
			if (point.x > pets_array[j].GetLeft() && point.x < pets_array[j].GetLeft() + pets_array[j].GetWidth() && point.y > pets_array[j].GetTop() && point.y < pets_array[j].GetTop() + pets_array[j].GetHeight()) {
				showpetinfo = true;
				pet_info = j;
				foundFood = true;
			}
		}
		if (!foundFood ) {
			showinfo = false;
			showpetinfo = false;
		}

	}
	
}
void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (point.x > 400 && point.y > 420 && point.x < 702 && point.y < 556 && food_Button == false) {
		//CAudio::Instance()->Play(AUDIO_MENUTOGAME, false);
		GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
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
	background.LoadBitmapByString({"resources/back3.bmp","resources/character_info.bmp"});
	background.SetTopLeft(0, 0);

	brand.LoadBitmapByString({ "resources/Brand.bmp" }, RGB(0, 0, 0));
	brand.SetTopLeft(0, 0);
	StartGame.LoadBitmapByString({ "resources/StartGame1.bmp", "resources/StartGame.bmp" }, RGB(255, 255, 255));
	StartGame.SetTopLeft(400, 420);
	Pets_Button.LoadBitmapByString({ "resources/PetButton.bmp" ,"resources/PetButton2.bmp"}, RGB(255, 255, 255));
	Pets_Button.SetTopLeft(350, 560);
	
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

void CGameStateInit::load_pet() {
	Duck.LoadBitmapByString({ "resources/pets/Duck.bmp" }, RGB(255, 255, 255));
	Duck.SetTopLeft(140, 40);
	pets_array.push_back(Duck);
	Beaver.LoadBitmapByString({ "resources/pets/Beaver.bmp" }, RGB(255, 255, 255));
	Beaver.SetTopLeft(200, 43);
	pets_array.push_back(Beaver);
	Pigeon.LoadBitmapByString({ "resources/pets/Pigeon.bmp" }, RGB(255, 255, 255));
	Pigeon.SetTopLeft(260, 40);
	pets_array.push_back(Pigeon);
	Otter.LoadBitmapByString({ "resources/pets/Otter.bmp" }, RGB(255, 255, 255));
	Otter.SetTopLeft(320, 44);
	pets_array.push_back(Otter);
	Pig.LoadBitmapByString({ "resources/pets/Pig.bmp" }, RGB(255, 255, 255));
	Pig.SetTopLeft(380, 44);
	pets_array.push_back(Pig);
	Ant.LoadBitmapByString({ "resources/pets/Ant.bmp" }, RGB(255, 255, 255));
	Ant.SetTopLeft(440, 46);
	pets_array.push_back(Ant);
	Mosquito.LoadBitmapByString({ "resources/pets/Mosquito.bmp" }, RGB(255, 255, 255));
	Mosquito.SetTopLeft(500, 48);
	pets_array.push_back(Mosquito);
	Fish.LoadBitmapByString({ "resources/pets/Fish.bmp" }, RGB(255, 255, 255));
	Fish.SetTopLeft(560, 50);
	pets_array.push_back(Fish);
	Cricket.LoadBitmapByString({ "resources/pets/Cricket.bmp" }, RGB(255, 255, 255));
	Cricket.SetTopLeft(620, 50);
	pets_array.push_back(Cricket);
	Horse.LoadBitmapByString({ "resources/pets/Horse.bmp" }, RGB(255, 255, 255));
	Horse.SetTopLeft(680, 47);
	pets_array.push_back(Horse);
	Snail.LoadBitmapByString({ "resources/pets/Snail.bmp" }, RGB(255, 255, 255));
	Snail.SetTopLeft(140, 160);
	pets_array.push_back(Snail);
	Crab.LoadBitmapByString({ "resources/pets/Crab.bmp" }, RGB(255, 255, 255));
	Crab.SetTopLeft(200, 165);
	pets_array.push_back(Crab);
	Swan.LoadBitmapByString({ "resources/pets/Swan.bmp" }, RGB(255, 255, 255));
	Swan.SetTopLeft(260, 155);
	pets_array.push_back(Swan);
	Rat.LoadBitmapByString({ "resources/pets/Rat.bmp" }, RGB(255, 255, 255));
	Rat.SetTopLeft(320, 155);
	pets_array.push_back(Rat);
	Hedgehog.LoadBitmapByString({ "resources/pets/Hedgehog.bmp" }, RGB(255, 255, 255));
	Hedgehog.SetTopLeft(380, 165);
	pets_array.push_back(Hedgehog);
	Peacock.LoadBitmapByString({ "resources/pets/Peacock.bmp" }, RGB(255, 255, 255));
	Peacock.SetTopLeft(440, 155);
	pets_array.push_back(Peacock);
	Flamingo.LoadBitmapByString({ "resources/pets/Flamingo.bmp" }, RGB(255, 255, 255));
	Flamingo.SetTopLeft(500, 150);
	pets_array.push_back(Flamingo);
	Worm.LoadBitmapByString({ "resources/pets/Worm.bmp" }, RGB(255, 255, 255));
	Worm.SetTopLeft(560, 155);
	pets_array.push_back(Worm);
	Kangaroo.LoadBitmapByString({ "resources/pets/Kangaroo.bmp" }, RGB(255, 255, 255));
	Kangaroo.SetTopLeft(620, 165);
	pets_array.push_back(Kangaroo);
	Spider.LoadBitmapByString({ "resources/pets/Spider.bmp" }, RGB(255, 255, 255));
	Spider.SetTopLeft(680, 165);
	pets_array.push_back(Spider);
	Fir.LoadBitmapByString({ "resources/pets_info/Duck_info.bmp" , "resources/pets_info/Beaver_info.bmp" , "resources/pets_info/Pigeon_info.bmp" ,"resources/pets_info/Otter_info.bmp"
		,"resources/pets_info/Pig_info.bmp","resources/pets_info/Ant_info.bmp" ,"resources/pets_info/Mosquito_info.bmp","resources/pets_info/Fish_info.bmp" ,"resources/pets_info/Cricket_info.bmp" 
		,"resources/pets_info/Horse_info.bmp"});
	Fir.SetTopLeft(20, 510);


	Dodo.LoadBitmapByString({ "resources/pets/Dodo.bmp" }, RGB(255, 255, 255));
	Dodo.SetTopLeft(140, 275);
	pets_array.push_back(Dodo);
	Badger.LoadBitmapByString({ "resources/pets/Badger.bmp" }, RGB(255, 255, 255));
	Badger.SetTopLeft(200, 285);
	pets_array.push_back(Badger);
	Dolphin.LoadBitmapByString({ "resources/pets/Dolphin.bmp" }, RGB(255, 255, 255));
	Dolphin.SetTopLeft(260, 280);
	pets_array.push_back(Dolphin);
	Giraffe.LoadBitmapByString({ "resources/pets/Giraffe.bmp" }, RGB(255, 255, 255));
	Giraffe.SetTopLeft(320, 275);
	pets_array.push_back(Giraffe);
	Elephant.LoadBitmapByString({ "resources/pets/Elephant.bmp" }, RGB(255, 255, 255));
	Elephant.SetTopLeft(380, 275);
	pets_array.push_back(Elephant);
	Camel.LoadBitmapByString({ "resources/pets/Camel.bmp" }, RGB(255, 255, 255));
	Camel.SetTopLeft(440, 275);
	pets_array.push_back(Camel);
	Rabbit.LoadBitmapByString({ "resources/pets/Rabbit.bmp" }, RGB(255, 255, 255));
	Rabbit.SetTopLeft(500, 265);
	pets_array.push_back(Rabbit);
	Ox.LoadBitmapByString({ "resources/pets/Ox.bmp" }, RGB(255, 255, 255));
	Ox.SetTopLeft(560, 275);
	pets_array.push_back(Ox);
	Dog.LoadBitmapByString({ "resources/pets/Dog.bmp" }, RGB(255, 255, 255));
	Dog.SetTopLeft(620, 275);
	pets_array.push_back(Dog);
	Sheep.LoadBitmapByString({ "resources/pets/Sheep.bmp" }, RGB(255, 255, 255));
	Sheep.SetTopLeft(680, 275);
	pets_array.push_back(Sheep);
	Sec.LoadBitmapByString({ "resources/pets_info/Snail_info.bmp" , "resources/pets_info/Crab_info.bmp" , "resources/pets_info/Swan_info.bmp" ,"resources/pets_info/Rat_info.bmp"
		,"resources/pets_info/Hedgehog_info.bmp","resources/pets_info/Peacock_info.bmp" ,"resources/pets_info/Flamigo_info.bmp","resources/pets_info/Worm_info.bmp" ,"resources/pets_info/Kangaroo_info.bmp"
		,"resources/pets_info/Spider_info.bmp" });
	Sec.SetTopLeft(20, 510);

	Thr.LoadBitmapByString({ "resources/pets_info/Dodo_info.bmp" , "resources/pets_info/Badger_info.bmp" , "resources/pets_info/Dolphin_info.bmp" ,"resources/pets_info/Giraffe_info.bmp"
		,"resources/pets_info/Elephant_info.bmp","resources/pets_info/Camel_info.bmp" ,"resources/pets_info/Rabbit_info.bmp","resources/pets_info/Ox_info.bmp" ,"resources/pets_info/Dog_info.bmp"
		,"resources/pets_info/Sheep_info.bmp" });
	Thr.SetTopLeft(20, 510);
	Skunk.LoadBitmapByString({ "resources/pets/Skunk.bmp" }, RGB(255, 255, 255));
	Skunk.SetTopLeft(140, 390);
	pets_array.push_back(Skunk);
	Hippo.LoadBitmapByString({ "resources/pets/Hippo.bmp" }, RGB(255, 255, 255));
	Hippo.SetTopLeft(200, 400);
	pets_array.push_back(Hippo);
	Bison.LoadBitmapByString({ "resources/pets/Bison.bmp" }, RGB(255, 255, 255));
	Bison.SetTopLeft(260, 395);
	pets_array.push_back(Bison);
	Blowfish.LoadBitmapByString({ "resources/pets/Blowfish.bmp" }, RGB(255, 255, 255));
	Blowfish.SetTopLeft(320, 395);
	pets_array.push_back(Blowfish);
	Turtle.LoadBitmapByString({ "resources/pets/Turtle.bmp" }, RGB(255, 255, 255));
	Turtle.SetTopLeft(380, 400);
	pets_array.push_back(Turtle);
	Squirrel.LoadBitmapByString({ "resources/pets/Squirrel.bmp" }, RGB(255, 255, 255));
	Squirrel.SetTopLeft(440, 395);
	pets_array.push_back(Squirrel);
	Penguin.LoadBitmapByString({ "resources/pets/Penguin.bmp" }, RGB(255, 255, 255));
	Penguin.SetTopLeft(500, 385);
	pets_array.push_back(Penguin);
	Deer.LoadBitmapByString({ "resources/pets/Deer.bmp" }, RGB(255, 255, 255));
	Deer.SetTopLeft(560, 385);
	pets_array.push_back(Deer);
	Whale.LoadBitmapByString({ "resources/pets/Whale.bmp" }, RGB(255, 255, 255));
	Whale.SetTopLeft(620, 410);
	pets_array.push_back(Whale);
	Parrot.LoadBitmapByString({ "resources/pets/Parrot.bmp" }, RGB(255, 255, 255));
	Parrot.SetTopLeft(680, 395);
	pets_array.push_back(Parrot);
	For.LoadBitmapByString({ "resources/pets_info/Skunk_info.bmp" , "resources/pets_info/Hippo_info.bmp" , "resources/pets_info/Bison_info.bmp" ,"resources/pets_info/Blowfish_info.bmp"
		,"resources/pets_info/Turtle_info.bmp","resources/pets_info/Squirrel_info.bmp" ,"resources/pets_info/Penguin_info.bmp","resources/pets_info/Deer_info.bmp" ,"resources/pets_info/Whale_info.bmp"
		,"resources/pets_info/Parrot_info.bmp" });
	For.SetTopLeft(20, 0);
	Scorpion.LoadBitmapByString({ "resources/pets/Scorpion.bmp" }, RGB(255, 255, 255));
	Scorpion.SetTopLeft(140, 490);
	pets_array.push_back(Scorpion);
	Crocodile.LoadBitmapByString({ "resources/pets/Crocodile.bmp" }, RGB(255, 255, 255));
	Crocodile.SetTopLeft(200, 500);
	pets_array.push_back(Crocodile);
	Rhino.LoadBitmapByString({ "resources/pets/Rhino.bmp" }, RGB(255, 255, 255));
	Rhino.SetTopLeft(260, 500);
	pets_array.push_back(Rhino);
	Monkey.LoadBitmapByString({ "resources/pets/Monkey.bmp" }, RGB(255, 255, 255));
	Monkey.SetTopLeft(320, 500);
	pets_array.push_back(Monkey);
	Armadillo.LoadBitmapByString({ "resources/pets/Armadillo.bmp" }, RGB(255, 255, 255));
	Armadillo.SetTopLeft(380, 500);
	pets_array.push_back(Armadillo);
	Cow.LoadBitmapByString({ "resources/pets/Cow.bmp" }, RGB(255, 255, 255));
	Cow.SetTopLeft(440, 500);
	pets_array.push_back(Cow);
	Seal.LoadBitmapByString({ "resources/pets/Seal.bmp" }, RGB(255, 255, 255));
	Seal.SetTopLeft(500, 500);
	pets_array.push_back(Seal);
	Rooster.LoadBitmapByString({ "resources/pets/Rooster.bmp" }, RGB(255, 255, 255));
	Rooster.SetTopLeft(560, 500);
	pets_array.push_back(Rooster);
	Shark.LoadBitmapByString({ "resources/pets/Shark.bmp" }, RGB(255, 255, 255));
	Shark.SetTopLeft(620, 500);
	pets_array.push_back(Shark);
	Turkey.LoadBitmapByString({ "resources/pets/Turkey.bmp" }, RGB(255, 255, 255));
	Turkey.SetTopLeft(680, 500);
	pets_array.push_back(Turkey);
	Fiv.LoadBitmapByString({ "resources/pets_info/Scorpion_info.bmp" , "resources/pets_info/Crocodile_info.bmp" , "resources/pets_info/Rhino_info.bmp" ,"resources/pets_info/Monkey_info.bmp"
		,"resources/pets_info/Armadillo_info.bmp","resources/pets_info/Cow_info.bmp" ,"resources/pets_info/Seal_info.bmp","resources/pets_info/Rooster_info.bmp" ,"resources/pets_info/Shark_info.bmp"
		,"resources/pets_info/Turkey_info.bmp" });
	Fiv.SetTopLeft(20, 0);
	Leopard.LoadBitmapByString({ "resources/pets/Leopard.bmp" }, RGB(255, 255, 255));
	Leopard.SetTopLeft(140, 610);
	pets_array.push_back(Leopard);
	Boar.LoadBitmapByString({ "resources/pets/Boar.bmp" }, RGB(255, 255, 255));
	Boar.SetTopLeft(200, 610);
	pets_array.push_back(Boar);
	Tiger.LoadBitmapByString({ "resources/pets/Tiger.bmp" }, RGB(255, 255, 255));
	Tiger.SetTopLeft(260, 610);
	pets_array.push_back(Tiger);
	Wolverine.LoadBitmapByString({ "resources/pets/Wolverine.bmp" }, RGB(255, 255, 255));
	Wolverine.SetTopLeft(320, 630);
	pets_array.push_back(Wolverine);
	Gorilla.LoadBitmapByString({ "resources/pets/Gorilla.bmp" }, RGB(255, 255, 255));
	Gorilla.SetTopLeft(380, 610);
	pets_array.push_back(Gorilla);
	Dragon.LoadBitmapByString({ "resources/pets/Dragon.bmp" }, RGB(255, 255, 255));
	Dragon.SetTopLeft(440, 610);
	pets_array.push_back(Dragon);
	Mammoth.LoadBitmapByString({ "resources/pets/Mammoth.bmp" }, RGB(255, 255, 255));
	Mammoth.SetTopLeft(500, 610);
	pets_array.push_back(Mammoth);
	Cat.LoadBitmapByString({ "resources/pets/Cat.bmp" }, RGB(255, 255, 255));
	Cat.SetTopLeft(560, 610);
	pets_array.push_back(Cat);
	Snake.LoadBitmapByString({ "resources/pets/Snake.bmp" }, RGB(255, 255, 255));
	Snake.SetTopLeft(620, 610);
	pets_array.push_back(Snake);
	Fly.LoadBitmapByString({ "resources/pets/Fly.bmp" }, RGB(255, 255, 255));
	Fly.SetTopLeft(680, 610);
	pets_array.push_back(Fly);
	Six.LoadBitmapByString({ "resources/pets_info/Leopard_info.bmp" , "resources/pets_info/Boar_info.bmp" , "resources/pets_info/Tiger_info.bmp" ,"resources/pets_info/Wolverine_info.bmp"
		,"resources/pets_info/Gorilla_info.bmp","resources/pets_info/Dragon_info.bmp" ,"resources/pets_info/Mammoth_info.bmp","resources/pets_info/Cat_info.bmp" ,"resources/pets_info/Snake_info.bmp"
		,"resources/pets_info/Fly_info.bmp" });
	Six.SetTopLeft(20, 0);
}
void CGameStateInit::load_food_info() {
	apple_info.LoadBitmapByString({ "resources/food_info/Apple_info.bmp " });
	apple_info.SetTopLeft(20, 510);
	food_info_array.push_back(apple_info);
	honey_info.LoadBitmapByString({ "resources/food_info/Honey_info.bmp " });
	honey_info.SetTopLeft(20, 510);
	food_info_array.push_back(honey_info);
	pill_info.LoadBitmapByString({ "resources/food_info/Pill_info.bmp" });
	pill_info.SetTopLeft(20, 510);
	food_info_array.push_back(pill_info);
	meatbone_info.LoadBitmapByString({ "resources/food_info/Meat_info.bmp" });
	meatbone_info.SetTopLeft(20, 510);
	food_info_array.push_back(meatbone_info);
	cupcake_info.LoadBitmapByString({ "resources/food_info/Cupcake_info.bmp" });
	cupcake_info.SetTopLeft(20, 510);
	food_info_array.push_back(cupcake_info);
	salad_info.LoadBitmapByString({ "resources/food_info/Salad_info.bmp" });
	salad_info.SetTopLeft(20, 510);
	food_info_array.push_back(salad_info);
	garlic_info.LoadBitmapByString({ "resources/food_info/Garlic_info.bmp" });
	garlic_info.SetTopLeft(20, 510);
	food_info_array.push_back(garlic_info);
	Canned_info.LoadBitmapByString({ "resources/food_info/Canned_info.bmp" });
	Canned_info.SetTopLeft(20, 0);
	food_info_array.push_back(Canned_info);
	Pear_info.LoadBitmapByString({ "resources/food_info/Pear_info.bmp" });
	Pear_info.SetTopLeft(20, 0);
	food_info_array.push_back(Pear_info);
	Chili_info.LoadBitmapByString({ "resources/food_info/Chili_info.bmp" });
	Chili_info.SetTopLeft(20, 0);
	food_info_array.push_back(Chili_info);
	Chocolate_info.LoadBitmapByString({ "resources/food_info/Chocolat_info.bmp" });
	Chocolate_info.SetTopLeft(20, 0);
	food_info_array.push_back(Chocolate_info);
	Sushi_info.LoadBitmapByString({ "resources/food_info/Sushi_info.bmp" });
	Sushi_info.SetTopLeft(20, 0);
	food_info_array.push_back(Sushi_info);
	Steak_info.LoadBitmapByString({ "resources/food_info/Steak_info.bmp" });
	Steak_info.SetTopLeft(20, 0);
	food_info_array.push_back(Steak_info);
	Melon_info.LoadBitmapByString({ "resources/food_info/Melon_info.bmp" });
	Melon_info.SetTopLeft(20, 0);
	food_info_array.push_back(Melon_info);
	Mushroom_info.LoadBitmapByString({ "resources/food_info/Mushroom_info.bmp" });
	Mushroom_info.SetTopLeft(20, 0);
	food_info_array.push_back(Mushroom_info);
	Pizza_info.LoadBitmapByString({ "resources/food_info/Pizza_info.bmp" });
	Pizza_info.SetTopLeft(20, 0);
	food_info_array.push_back(Pizza_info);
}


void CGameStateInit::show_food() {
	if (food_Button == true ) {
		for (auto &v : food_array) {
			v.ShowBitmap();
		}
	}
}

void CGameStateInit::show_pet() {
	if (food_Button == true) {
		for (auto &v : pets_array) {
			v.ShowBitmap();
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
		else if(petchange)
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
<<<<<<< Updated upstream
		food_info_array[food_info].ShowBitmap();
=======
		object[food_info]->get_info().ShowBitmap();
>>>>>>> Stashed changes
	}
}
void CGameStateInit::show_pet_info() {
	if (food_Button == true && showpetinfo == true) {
<<<<<<< Updated upstream
		if (pet_info < 10) {
			Fir.SetFrameIndexOfBitmap(pet_info);
			Fir.ShowBitmap();
		}
		else if (pet_info < 20) {
			Sec.SetFrameIndexOfBitmap(pet_info-10);
			Sec.ShowBitmap();
		}
		else if (pet_info < 30) {
			Thr.SetFrameIndexOfBitmap(pet_info - 20);
			Thr.ShowBitmap();
		}
		else if (pet_info < 40) {
			For.SetFrameIndexOfBitmap(pet_info - 30);
			For.ShowBitmap();
		}
		else if (pet_info < 50) {
			Fiv.SetFrameIndexOfBitmap(pet_info - 40);
			Fiv.ShowBitmap();
		}
		else if (pet_info < 60) {
			Six.SetFrameIndexOfBitmap(pet_info - 50);
			Six.ShowBitmap();
		}
		
=======
		
		pet[pet_info]->get_info().ShowBitmap();
>>>>>>> Stashed changes
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
