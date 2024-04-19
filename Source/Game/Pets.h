#ifndef HEADER_PET
#define HEADER_PET
#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include <string>
#include <vector>
namespace game_framework {
	class Pet{
	public:
		Pet(vector<string> img, string name, int id, int tier, int attack, int life) :s_img(img), m_name(name), m_id(id), m_tier(tier), m_attack(attack), m_life(life) {
		}
		virtual~Pet() {
		}
		
		CMovingBitmap get_img() {
			return m_img;
		}
		void set_img(vector<string> s_img) {
			m_img.LoadBitmapByString(s_img);
		}
		void show_tiers(int cx,int cy){
			tiers.SetFrameIndexOfBitmap(get_tier() - 1);
			tiers.SetTopLeft(cx-20, cy-70);
			tiers.ShowBitmap();
		}
		void set_Stats(int cx,int cy) {
			status.SetTopLeft(cx-20, cy);
			status.ShowBitmap();
			CDC *pDC = CDDraw::GetBackCDC();
			CTextDraw::ChangeFontLog(pDC, 20, "Lapsus Pro Bold", RGB(255, 255, 255));
			CTextDraw::Print(pDC, cx, cy+8, to_string(m_attack));
			CTextDraw::Print(pDC, cx+45, cy+8, to_string(m_life));
			CDDraw::ReleaseBackCDC();
		}
		void show_levels(int index,int cx,int cy) {
			levels.SetFrameIndexOfBitmap(index);
			levels.SetTopLeft(cx-50,cy-70);
			levels.ShowBitmap();
		}
		string get_name() {
			return m_name;
		}
		void Load_img() {
			m_img.LoadBitmapByString(s_img, RGB(255, 255, 255));
			status.LoadBitmapByString({ "resources/Stats.bmp" }, RGB(255, 255, 255));
			tiers.LoadBitmapByString({ "resources/Tier1.bmp","resources/Tier2.bmp","resources/Tier3.bmp","resources/Tier4.bmp","resources/Tier5.bmp", "resources/Tier6.bmp" });
			levels.LoadBitmapByString({ "resources/Level0.bmp","resources/Level1.bmp" ,"resources/Level2.bmp" ,"resources/Level3.bmp" ,"resources/Level4.bmp" ,"resources/final.bmp" }, RGB(255, 255, 255));
		}
		void set_locate(int x, int y) {
			m_img.SetTopLeft(x, y);
		}
		void set_atk(int atk) {
			m_attack = atk;
		}
		void set_life(int life) {
			m_life = life;
		}
		int get_id() {
			return m_id;
		}
		int get_tier() {
			return m_tier;
		}
		int get_attack() {
			return m_attack;
		}
		int get_life() {
			return m_life;
		}
		int get_test() {
			return test;
		}
		virtual shared_ptr<Pet> clone() = 0;
	private:
		string m_name;
		vector<string> s_img;
		CMovingBitmap m_img;
		CMovingBitmap status;
		CMovingBitmap tiers;
		CMovingBitmap levels;
		int m_id;
		int m_tier;
		int m_attack;
		int m_life;
		int test;
	};
	class Ant :public Pet {
	public:
		Ant() :Pet({"resources/pets/Ant.bmp"}, "Ant", 6, 1, 2, 2) {
			
		}
		~Ant() override {
		}
		shared_ptr<Pet> clone() { return make_shared<Ant>(); }
	private:
		int m_id = 6;
		int m_tier = 1;
		int m_attack = 2;
		int m_life = 2;
	};
	
	class Armadillo:public Pet{
	public:
		Armadillo() :Pet({ "resources/pets/Armadillo.bmp" },"Armadillo",45, 5, 2, 6) {
		}
		~Armadillo() override {
		}
		shared_ptr<Pet> clone() { return make_shared<Armadillo>(); }
	private:
		int m_id = 45;
		int m_tier = 5;
		int m_attack = 2;
		int m_life = 6;
	};
	class Badger:public Pet{
	public:
		Badger() :Pet({ "resources/pets/Badger.bmp" },"Badger",22, 3, 6, 3) {
		}
		~Badger()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Badger>(); }
	private:
		int m_id = 22;
		int m_tier = 3;
		int m_attack = 6;
		int m_life = 3;
	};
	class Beaver :public Pet {
	public:
		Beaver() :Pet({ "resources/pets/Beaver.bmp" },"Beaver",2, 1, 3, 2) {
		}
		~Beaver()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Beaver>(); }
	private:
		int m_id = 2;
		int m_tier = 1;
		int m_attack = 3;
		int m_life = 2;
	};
	class Bison :public Pet {
	public:
		Bison() :Pet({ "resources/pets/Bison.bmp" },"Bison", 33, 4, 4, 4) {
		}
		~Bison()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Bison>(); }
	private:
		int m_id = 33;
		int m_tier = 4;
		int m_attack = 4;
		int m_life = 4;
	};
	class Blowfish :public Pet {
	public:
		Blowfish():Pet({ "resources/pets/Blowfish.bmp" },"Blowfish", 34, 4, 3, 6) {
		}
		~Blowfish()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Blowfish>(); }
	private:
		int m_id = 34;
		int m_tier = 4;
		int m_attack = 3;
		int m_life = 6;
	};
	class Boar :public Pet {
	public:
		Boar() :Pet({ "resources/pets/Boar.bmp" },"Boar", 52, 6, 10, 6) {
		}
		~Boar()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Boar>(); }
	private:
		int m_id = 52;
		int m_tier = 6;
		int m_attack = 10;
		int m_life = 6;
	};
	class Camel :public Pet {
	public:
		Camel() :Pet({ "resources/pets/Camel.bmp" },"Camel", 26, 3, 3, 4) {
		}
		~Camel()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Camel>(); }
	private:
		int m_id = 26;
		int m_tier = 3;
		int m_attack = 3;
		int m_life = 4;
	};
	class Cat :public Pet {
	public:
		Cat() :Pet({ "resources/pets/Cat.bmp" },"Cat", 58, 6, 4, 5) {
		}
		~Cat()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Cat>(); }
	private:
		int m_id = 58;
		int m_tier = 6;
		int m_attack = 4;
		int m_life = 5;
	};
	class Cow :public Pet {
	public:
		Cow() :Pet({ "resources/pets/Cow.bmp" },"Cow", 46, 5, 4, 6) {
		}
		~Cow()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Cow>(); }
	private:
		int m_id = 46;
		int m_tier = 5;
		int m_attack = 4;
		int m_life = 6;
	};
	class Crab :public Pet {
	public:
		Crab() :Pet({ "resources/pets/Crab.bmp" },"Crab", 12, 2, 4, 1) {
		}
		~Crab()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Crab>(); }
	private:
		int m_id = 12;
		int m_tier = 2;
		int m_attack = 4;
		int m_life = 1;
	};
	class Cricket :public Pet {
	public:
		Cricket() :Pet({ "resources/pets/Cricket.bmp" },"Cricket", 9, 1, 1, 3) {
		}
		~Cricket()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Cricket>(); }
	private:
		int m_id = 9;
		int m_tier = 1;
		int m_attack = 1;
		int m_life = 3;
	};
	class Crocodile :public Pet {
	public:
		Crocodile() :Pet({ "resources/pets/Crocodile.bmp" },"Crocodile", 42, 5, 8, 4) {
		}
		~Crocodile()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Crocodile>(); }
	private:
		int m_id = 42;
		int m_tier = 5;
		int m_attack = 8;
		int m_life = 4;
	};
	class Deer :public Pet {
	public:
		Deer() :Pet({ "resources/pets/Deer.bmp" },"Deer", 38, 4, 1, 1) {
		}
		~Deer()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Deer>(); }
	private:
		int m_id = 38;
		int m_tier = 4;
		int m_attack = 1;
		int m_life = 1;
	};
	class Dodo :public Pet {
	public:
		Dodo() :Pet({ "resources/pets/Dodo.bmp" },"Dodo", 21, 3, 4, 2) {
		}
		~Dodo()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Dodo>(); }
	private:
		int m_id = 21;
		int m_tier = 3;
		int m_attack = 4;
		int m_life = 2;
	};
	class Dog :public Pet {
	public:
		Dog() :Pet({ "resources/pets/Dog.bmp" },"Dog", 29, 3, 3, 2) {
		}
		~Dog()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Dog>(); }
	private:
		int m_id = 29;
		int m_tier = 3;
		int m_attack = 3;
		int m_life = 2;
	};
	class Dolphin :public Pet {
	public:
		Dolphin() :Pet({ "resources/pets/Dolphin.bmp" },"Dolphin", 23, 3, 4, 3) {
		}
		~Dolphin()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Dolphin>(); }
	private:
		int m_id = 23;
		int m_tier = 3;
		int m_attack = 4;
		int m_life = 3;
	};
	class Dragon :public Pet {
	public:
		Dragon() :Pet({ "resources/pets/Dragon.bmp" },"Dragon", 56, 6, 6, 8) {
		}
		~Dragon()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Dragon>(); }
	private:
		int m_id = 56;
		int m_tier = 6;
		int m_attack = 6;
		int m_life = 8;
	};
	class Duck :public Pet {
	public:
		Duck() :Pet({ "resources/pets/Duck.bmp" },"Duck", 1, 1, 2, 3) {
		}
		~Duck()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Duck>(); }
	private:
		int m_id = 1;
		int m_tier = 1;
		int m_attack = 2;
		int m_life = 3;
	};
	class Elephant :public Pet {
	public:
		Elephant() :Pet({ "resources/pets/Elephant.bmp" },"Elephant", 25, 3, 3, 7) {
		}
		~Elephant()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Elephant>(); }
	private:
		int m_id = 25;
		int m_tier = 3;
		int m_attack = 3;
		int m_life = 7;
	};
	class Fish :public Pet {
	public:
		Fish() :Pet({ "resources/pets/Fish.bmp" },"Fish", 8, 1, 2, 3) {
		}
		~Fish()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Fish>(); }
	private:
		int m_id = 8;
		int m_tier = 1;
		int m_attack = 2;
		int m_life = 3;
	};
	class Flamingo :public Pet {
	public:
		Flamingo() :Pet({ "resources/pets/Flamingo.bmp" },"Flamingo", 17, 2, 3, 2) {
		}
		~Flamingo()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Flamingo>(); }
	private:
		int m_id = 17;
		int m_tier = 2;
		int m_attack = 3;
		int m_life = 2;
	};
	class Fly :public Pet {
	public:
		Fly() :Pet({ "resources/pets/Fly.bmp" },"Fly", 60, 5, 5, 5) {
		}
		~Fly()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Fly>(); }
	private:
		int m_id = 60;
		int m_tier = 5;
		int m_attack = 5;
		int m_life = 5;
	};
	class Giraffe :public Pet {
	public:
		Giraffe() :Pet({ "resources/pets/Giraffe.bmp" },"Giraffe", 24, 3, 1, 2) {
		}
		~Giraffe()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Giraffe>(); }
	private:
		int m_id = 24;
		int m_tier = 3;
		int m_attack = 1;
		int m_life = 2;
	};
	class Gorilla :public Pet {
	public:
		Gorilla() :Pet({ "resources/pets/Gorilla.bmp" },"Gorilla", 54, 6, 7, 10) {
		}
		~Gorilla()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Gorilla>(); }
	private:
		int m_id = 54;
		int m_tier = 6;
		int m_attack = 7;
		int m_life = 10;
	};
	class Hedgehog :public Pet {
	public:
		Hedgehog() :Pet({ "resources/pets/Hedgehog.bmp" },"Hedgehog", 15, 2, 4, 2) {
		}
		~Hedgehog()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Hedgehog>(); }
	private:
		int m_id = 15;
		int m_tier = 2;
		int m_attack = 4;
		int m_life = 2;
	};
	class Hippo :public Pet {
	public:
		Hippo() :Pet({ "resources/pets/Hippo.bmp" },"Hippo", 32, 4, 4, 7) {
		}
		~Hippo()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Hippo>(); }
	private:
		int m_id = 32;
		int m_tier = 4;
		int m_attack = 4;
		int m_life = 7;
	};
	class Horse :public Pet {
	public:
		Horse() :Pet({ "resources/pets/Horse.bmp" },"Horse", 10, 1, 2, 1) {
		}
		~Horse()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Horse>(); }
	private:
		int m_id = 10;
		int m_tier = 1;
		int m_attack = 2;
		int m_life = 1;
	};
	class Kangaroo :public Pet {
	public:
		Kangaroo() :Pet({ "resources/pets/Kangaroo.bmp" },"Kangaroo", 19, 2, 2, 3) {
		}
		~Kangaroo()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Kangaroo>(); }
	private:
		int m_id = 19;
		int m_tier = 2;
		int m_attack = 2;
		int m_life = 3;
	};
	class Leopard :public Pet {
	public:
		Leopard() :Pet({ "resources/pets/Leopard.bmp" },"Leopard", 51, 6, 10, 4) {
		}
		~Leopard()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Leopard>(); }
	private:
		int m_id = 51;
		int m_tier = 6;
		int m_attack = 10;
		int m_life = 4;
	};
	class Mammoth :public Pet {
	public:
		Mammoth() :Pet({ "resources/pets/Mammoth.bmp" },"Mammoth", 57, 6, 4 ,12) {
		}
		~Mammoth()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Mammoth>(); }
	private:
		int m_id = 57;
		int m_tier = 6;
		int m_attack = 4;
		int m_life = 12;
	};
	class Monkey :public Pet {
	public:
		Monkey() :Pet({ "resources/pets/Monkey.bmp" },"Monkey", 44, 5, 1, 2) {
		}
		~Monkey()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Monkey>(); }
	private:
		int m_id = 44;
		int m_tier = 5;
		int m_attack = 1;
		int m_life = 2;
	};
	class Mosquito :public Pet {
	public:
		Mosquito() :Pet({ "resources/pets/Mosquito.bmp" },"Mosquito", 7, 1, 2, 2) {
		}
		~Mosquito()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Mosquito>(); }
	private:
		int m_id = 7;
		int m_tier = 1;
		int m_attack = 2;
		int m_life = 2;
	};
	class Otter :public Pet {
	public:
		Otter() :Pet({ "resources/pets/Otter.bmp" },"Otter", 4, 1, 1, 3) {
		}
		~Otter()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Otter>(); }
	private:
		int m_id = 4;
		int m_tier = 1;
		int m_attack = 1;
		int m_life = 3;
	};
	class Ox :public Pet {
	public:
		Ox() :Pet({ "resources/pets/Ox.bmp" },"Ox", 28, 3, 1, 3) {
		}
		~Ox()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Ox>(); }
	private:
		int m_id = 28;
		int m_tier = 3;
		int m_attack = 1;
		int m_life = 3;
	};
	class Parrot :public Pet {
	public:
		Parrot() :Pet({ "resources/pets/Parrot.bmp" },"Parrot", 40, 4, 4, 2) {
		}
		~Parrot()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Parrot>(); }
	private:
		int m_id = 40;
		int m_tier = 4;
		int m_attack = 4;
		int m_life = 2;
	};
	class Peacock :public Pet {
	public:
		Peacock() :Pet({ "resources/pets/Peacock.bmp" },"Peacock", 16, 2, 2, 5) {
		}
		~Peacock()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Peacock>(); }
	private:
		int m_id = 16;
		int m_tier = 2;
		int m_attack = 2;
		int m_life = 5;
	};
	class Penguin :public Pet {
	public:
		Penguin() :Pet({ "resources/pets/Penguin.bmp" },"Penguin", 37, 4, 1, 3) {
		}
		~Penguin()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Penguin>(); }
	private:
		int m_id = 37;
		int m_tier = 4;
		int m_attack = 1;
		int m_life = 3;
	};
	class Pig :public Pet {
	public:
		Pig() :Pet({ "resources/pets/Pig.bmp" },"Pig", 5, 1, 4, 1) {
		}
		~Pig()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Pig>(); }
	private:
		int m_id = 5;
		int m_tier = 1;
		int m_attack = 4;
		int m_life = 1;
	};
	class Pigeon :public Pet {
	public:
		Pigeon() :Pet({ "resources/pets/Pigeon.bmp" },"Pigeon", 3, 1, 3, 1) {
		}
		~Pigeon()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Pigeon>(); }
	private:
		int m_id = 3;
		int m_tier = 1;
		int m_attack = 3;
		int m_life = 1;
	};
	class Rabbit :public Pet {
	public:
		Rabbit() :Pet({ "resources/pets/Rabbit.bmp" },"Rabbit", 27, 3, 1, 2) {
		}
		~Rabbit()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Rabbit>(); }
	private:
		int m_id = 27;
		int m_tier = 3;
		int m_attack = 1;
		int m_life = 2;
	};
	class Rat :public Pet {
	public:
		Rat() :Pet({ "resources/pets/Rat.bmp" },"Rat", 14, 2, 3, 6) {
		}
		~Rat()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Rat>(); }
	private:
		int m_id = 14;
		int m_tier = 2;
		int m_attack = 3;
		int m_life = 6;
	};
	class Rhino :public Pet {
	public:
		Rhino() :Pet({ "resources/pets/Rhino.bmp" },"Rhino", 43, 5, 6, 9) {
		}
		~Rhino()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Rhino>(); }
	private:
		int m_id = 43;
		int m_tier = 5;
		int m_attack = 6;
		int m_life = 9;
	};
	class Rooster :public Pet {
	public:
		Rooster() :Pet({ "resources/pets/Rooster.bmp" },"Rooster", 48, 5, 6, 4) {
		}
		~Rooster()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Rooster>(); }
	private:
		int m_id = 48;
		int m_tier = 5;
		int m_attack = 6;
		int m_life = 4;
	};
	class Scorpion :public Pet {
	public:
		Scorpion() :Pet({ "resources/pets/Scorpion.bmp" },"Scorpion", 41, 5, 1, 1) {
		}
		~Scorpion()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Scorpion>(); }
	private:
		int m_id = 41;
		int m_tier = 5;
		int m_attack = 1;
		int m_life = 1;
	};
	class Seal :public Pet {
	public:
		Seal() :Pet({ "resources/pets/Seal.bmp" },"Seal", 47, 5, 3, 8) {
		}
		~Seal()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Seal>(); }
	private:
		int m_id = 47;
		int m_tier = 5;
		int m_attack = 3;
		int m_life = 8;
	};
	class Shark :public Pet {
	public:
		Shark() :Pet({ "resources/pets/Shark.bmp" },"Shark", 49, 5, 2, 2) {
		}
		~Shark()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Shark>(); }
	private:
		int m_id = 49;
		int m_tier = 5;
		int m_attack = 2;
		int m_life = 2;
	};
	class Sheep :public Pet {
	public:
		Sheep() :Pet({ "resources/pets/Sheep.bmp" },"Sheep", 30, 3, 2, 2) {
		}
		~Sheep()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Sheep>(); }
	private:
		int m_id = 30;
		int m_tier = 3;
		int m_attack = 2;
		int m_life = 2;
	};
	class Skunk :public Pet {
	public:
		Skunk() :Pet({ "resources/pets/Skunk.bmp" },"Skunk", 31, 4, 3, 5) {
		}
		~Skunk()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Skunk>(); }
	private:
		int m_id = 31;
		int m_tier = 4;
		int m_attack = 3;
		int m_life = 5;
	};
	class Snail :public Pet {
	public:
		Snail() :Pet({ "resources/pets/Snail.bmp" },"Snail", 11, 2, 2, 2) {
		}
		~Snail()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Snail>(); }
	private:
		int m_id = 11;
		int m_tier = 2;
		int m_attack = 2;
		int m_life = 2;
	};
	class Snake :public Pet {
	public:
		Snake() :Pet({ "resources/pets/Snake.bmp" },"Snake", 59, 6, 6, 6) {
		}
		~Snake()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Snake>(); }
	private:
		int m_id = 59;
		int m_tier = 6;
		int m_attack = 6;
		int m_life = 6;
	};
	class Spider :public Pet {
	public:
		Spider() :Pet({ "resources/pets/Spider.bmp" },"Spider", 20, 2, 2, 2) {
		}
		~Spider()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Spider>(); }
	private:
		int m_id = 20;
		int m_tier = 2;
		int m_attack = 2;
		int m_life = 2;
	};
	class Squirrel :public Pet {
	public:
		Squirrel() :Pet({ "resources/pets/Squirrel.bmp" },"Squirrel", 36, 4, 2, 5) {
		}
		~Squirrel()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Squirrel>(); }
	private:
		int m_id = 36;
		int m_tier = 4;
		int m_attack = 2;
		int m_life = 5;
	};
	class Swan :public Pet {
	public:
		Swan() :Pet({ "resources/pets/Swan.bmp" },"Swan", 13, 2, 1, 2) {
		}
		~Swan()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Swan>(); }
	private:
		int m_id = 13;
		int m_tier = 2;
		int m_attack = 1;
		int m_life = 2;
	};
	class Tiger :public Pet {
	public:
		Tiger() :Pet({ "resources/pets/Tiger.bmp" },"Tiger", 53, 6, 6, 4) {
		}
		~Tiger()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Tiger>(); }
	private:
		int m_id = 53;
		int m_tier = 6;
		int m_attack = 6;
		int m_life = 4;
	};
	class Turkey :public Pet {
	public:
		Turkey() :Pet({ "resources/pets/Turkey.bmp" },"Turkey", 50, 5, 3, 4) {
		}
		~Turkey()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Turkey>(); }
	private:
		int m_id = 50;
		int m_tier = 5;
		int m_attack = 3;
		int m_life = 4;
	};
	class Turtle :public Pet {
	public:
		Turtle() :Pet({ "resources/pets/Turtle.bmp" },"Turtle", 35, 4, 2, 5) {
		}
		~Turtle()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Turtle>(); }
	private:
		int m_id = 35;
		int m_tier = 4;
		int m_attack = 2;
		int m_life = 5;
	};
	class Whale :public Pet {
	public:
		Whale() :Pet({ "resources/pets/Whale.bmp" },"Whale", 39, 4, 4, 10) {
		}
		~Whale()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Whale>(); }
	private:
		int m_id = 39;
		int m_tier = 4;
		int m_attack = 4;
		int m_life = 10;
	};
	class Wolverine :public Pet {
	public:
		Wolverine() :Pet({ "resources/pets/Wolverine.bmp" },"Wolverine", 55, 6, 5, 4) {
		}
		~Wolverine()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Wolverine>(); }
	private:
		int m_id = 55;
		int m_tier = 6;
		int m_attack = 5;
		int m_life = 4;
	};
	class Worm :public Pet {
	public:
		Worm() :Pet({ "resources/pets/Worm.bmp" },"Worm", 18, 2, 1, 3) {
		}
		~Worm()override {
		}
		shared_ptr<Pet> clone() { return make_shared<Worm>(); }
	private:
		int m_id = 18;
		int m_tier = 2;
		int m_attack = 1;
		int m_life = 3;
	};
	
	class GenPets {
	public:
		GenPets() {
			
			pets_array.push_back(make_shared<Duck>());
			pets_array.push_back(make_shared<Beaver>());
			pets_array.push_back(make_shared<Pigeon>());
			pets_array.push_back(make_shared<Otter>());
			pets_array.push_back(make_shared<Pig>());
			pets_array.push_back(make_shared<Ant>());
			pets_array.push_back(make_shared<Mosquito>());
			pets_array.push_back(make_shared<Fish>());
			pets_array.push_back(make_shared<Cricket>());
			pets_array.push_back(make_shared<Horse>());
			pets_array.push_back(make_shared<Snail>());
			pets_array.push_back(make_shared<Crab>());
			pets_array.push_back(make_shared<Swan>());
			pets_array.push_back(make_shared<Rat>());
			pets_array.push_back(make_shared<Hedgehog>());
			pets_array.push_back(make_shared<Peacock>());
			pets_array.push_back(make_shared<Flamingo>());
			pets_array.push_back(make_shared<Worm>());
			pets_array.push_back(make_shared<Kangaroo>());
			pets_array.push_back(make_shared<Spider>());
			pets_array.push_back(make_shared<Dodo>());
			pets_array.push_back(make_shared<Badger>());
			pets_array.push_back(make_shared<Dolphin>());
			pets_array.push_back(make_shared<Giraffe>());
			pets_array.push_back(make_shared<Elephant>());
			pets_array.push_back(make_shared<Camel>());
			pets_array.push_back(make_shared<Rabbit>());
			pets_array.push_back(make_shared<Ox>());
			pets_array.push_back(make_shared<Dog>());
			pets_array.push_back(make_shared<Sheep>());
			pets_array.push_back(make_shared<Skunk>());
			pets_array.push_back(make_shared<Hippo>());
			pets_array.push_back(make_shared<Bison>());
			pets_array.push_back(make_shared<Blowfish>());
			pets_array.push_back(make_shared<Turtle>());
			pets_array.push_back(make_shared<Squirrel>());
			pets_array.push_back(make_shared<Penguin>());
			pets_array.push_back(make_shared<Deer>());
			pets_array.push_back(make_shared<Whale>());
			pets_array.push_back(make_shared<Parrot>());
			pets_array.push_back(make_shared<Scorpion>());
			pets_array.push_back(make_shared<Crocodile>());
			pets_array.push_back(make_shared<Rhino>());
			pets_array.push_back(make_shared<Monkey>());
			pets_array.push_back(make_shared<Armadillo>());
			pets_array.push_back(make_shared<Cow>());
			pets_array.push_back(make_shared<Seal>());
			pets_array.push_back(make_shared<Rooster>());
			pets_array.push_back(make_shared<Shark>());
			pets_array.push_back(make_shared<Turkey>());
			pets_array.push_back(make_shared<Leopard>());
			pets_array.push_back(make_shared<Boar>());
			pets_array.push_back(make_shared<Tiger>());
			pets_array.push_back(make_shared<Gorilla>());
			pets_array.push_back(make_shared<Wolverine>());
			pets_array.push_back(make_shared<Dragon>());
			pets_array.push_back(make_shared<Mammoth>());
			pets_array.push_back(make_shared<Cat>());
			pets_array.push_back(make_shared<Snake>());
			pets_array.push_back(make_shared<Fly>());
			
		}
		~GenPets() {
		}
		void init() {
			for (auto item : pets_array) {
				item->Load_img();
			}
		}
		vector<shared_ptr<Pet>> get_pets() { return pets_array; }
	private:
		vector<shared_ptr<Pet>> pets_array;
	};
}


#endif // HEADER_PET