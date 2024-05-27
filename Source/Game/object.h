#ifndef HEADER_OBJECT
#define HEADER_OBJECT
#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "attackCell.h"
namespace game_framework {
	class Object{
	public:
		Object(vector<string> info, vector<string> img, string name, int cost, int tier) :s_info(info), s_img(img), m_name(name), m_cost(cost), m_tier(tier) {};
		virtual ~Object() {};
		string get_name() {
			return m_name;
		}
		CMovingBitmap get_img() {
			return m_img;
		}
		CMovingBitmap get_info() {
			return pet_info;
		}
		void show_tiers(int cx, int cy) {
			tiers.SetFrameIndexOfBitmap(get_tier() - 1);
			tiers.SetTopLeft(cx - 20, cy - 70);
			tiers.ShowBitmap();
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
		int get_cost() {
			return m_cost;
		}
		void Load_img() {
			pet_info.LoadBitmapByString(s_info);
			m_img.LoadBitmapByString(s_img, RGB(255, 255, 255));
			tiers.LoadBitmapByString({ "resources/Tier1.bmp","resources/Tier2.bmp","resources/Tier3.bmp","resources/Tier4.bmp","resources/Tier5.bmp", "resources/Tier6.bmp" });
		}
		void set_locate(int x, int y) {
			m_img.SetTopLeft(x, y);
		}
		void setinfo_locate(int x, int y) {
			pet_info.SetTopLeft(x, y);
		}
		virtual shared_ptr<Object> clone() = 0;

		virtual void Boost(vector<shared_ptr<Pet>>& friendPet, unsigned int idx, int power) {}
		//virtual void attackenemy(vector<shared_ptr<Pet>>& friendPet, vector<shared_ptr<Pet>>& enemyPet);
		//virtual void LevelUp(vector<shared_ptr<Pet>>& atkcells, int idx);
		virtual void LevelUp(vector<shared_ptr<Pet>>& atkcells, int idx) {};
	private:
		
		string m_name;
		vector<string> s_info;
		vector<string> s_img;
		CMovingBitmap pet_info;
		CMovingBitmap m_img;
		CMovingBitmap tiers;
		int m_id;
		int m_tier;
		int m_attack;
		int m_life;
		int m_cost;
	};
	class Apple :public Object {
	public:
		Apple() : Object({"resources/food_info/Apple_info.bmp " }, { "resources/food/Apple.bmp " }, "Apple", 3, 1) {
		}
		~Apple() override {
		}
		shared_ptr<Object> clone() { return make_shared<Apple>(); }
		void Boost(vector<shared_ptr<Pet>>& friendPet, unsigned int idx, int power) override{
			if (idx < 0 || idx >= friendPet.size() || !friendPet[idx]) {
				return;
			}
			friendPet[idx]->set_atk(friendPet[idx]->get_attack() + 1);
			friendPet[idx]->set_life(friendPet[idx]->get_life() + 1);
		}

	};
	class Honey :public Object {
	public:
		Honey() : Object({ "resources/food_info/Honey_info.bmp " }, { "resources/food/Honey.bmp " }, "Honey", 3, 1) {
		}
		~Honey() override {
		}
		shared_ptr<Object> clone() { return make_shared<Honey>(); }
		void onFaintSummonBee(vector<shared_ptr<Pet>>& friendPet) {
			if (friendPet.size() >= 5) {
				return;
			}

			shared_ptr<Pet> bee = make_shared<Dog>();  
			bee->set_atk(1);
			bee->set_life(1);
			friendPet.push_back(bee);


		}
	};
	class Pill :public Object {
	public:
		Pill() : Object({ "resources/food_info/Pill_info.bmp " }, { "resources/food/Sleeping_Pill.bmp " }, "Pill", 1, 2) {
		}
		~Pill() override {
		}
		shared_ptr<Object> clone() { return make_shared<Pill>(); }
		void FaintPet(vector<shared_ptr<Pet>>& friendPet, unsigned int idx) {
			if (idx < 0 || idx >= friendPet.size() || !friendPet[idx]) {
				return;
			}
			friendPet[idx]->setFainted(true);
		}
	};
	class Meatbone :public Object {
	public:
		Meatbone() : Object({ "resources/food_info/Meat_info.bmp " }, { "resources/food/Meat_Bone.bmp " }, "Meatbone", 3, 2) {
		}
		~Meatbone() override {
		}
		shared_ptr<Object> clone() { return make_shared<Meatbone>(); }
		void Buff(vector<shared_ptr<Pet>>& friendPet, int idx, int power) {
			friendPet[idx]->set_atk(friendPet[idx]->get_attack() + power);
		}
	};
	class Cupcake :public Object {
	public:
		Cupcake() : Object({ "resources/food_info/Cupcake_info.bmp " }, { "resources/food/Cupcake.bmp " }, "Cupcake", 3, 2) {
		}
		~Cupcake() override {
		}
		shared_ptr<Object> clone() { return make_shared<Cupcake>(); }

		void Boost(vector<shared_ptr<Pet>>& friendPet,unsigned int idx, int power) override {
			if (idx < 0 || idx >= friendPet.size() || !friendPet[idx]) {
				return;
			}
			friendPet[idx]->set_atk(friendPet[idx]->get_attack() + 3);
			friendPet[idx]->set_life(friendPet[idx]->get_life() + 3);
		}
	};
	class Salad :public Object {
	public:
		Salad() : Object({ "resources/food_info/Salad_info.bmp " }, { "resources/food/Salad_Bowl.bmp " }, "Salad", 3, 3) {
		}
		~Salad() override {
		}
		shared_ptr<Object> clone() { return make_shared<Salad>(); }
		void Boost(vector<shared_ptr<Pet>>& friendPet, unsigned int idx, int power) override {
			srand((unsigned int)time(NULL));
			if (friendPet.size() == 0) {
				return;
			}
			vector<int> selectedPets;
			for (int i = 0; i < 2; ++i) {
				bool selected = false;
				while (!selected) {
					int randN = rand() % 5;
					if (randN != idx && (!friendPet[randN]) && find(selectedPets.begin(), selectedPets.end(), randN) == selectedPets.end()) {
						friendPet[randN]->set_atk(friendPet[randN]->get_attack() + 1);
						friendPet[randN]->set_life(friendPet[randN]->get_life() + 1);
						selectedPets.push_back(randN);
						selected = true;
					}
				}
			}
		}
	};
	class Garlic :public Object {
	public:
		Garlic() : Object({ "resources/food_info/Garlic_info.bmp " }, { "resources/food/Garlic.bmp " }, "Garlic", 3, 3) {
		}
		~Garlic() override {
		}
		shared_ptr<Object> clone() { return make_shared<Garlic>(); }
	};
	class Canned :public Object {
	public:
		Canned() : Object({ "resources/food_info/Canned_info.bmp " }, { "resources/food/Canned_Food.bmp " }, "Canned", 3, 4) {
		}
		~Canned() override {
		}
		shared_ptr<Object> clone() { return make_shared<Canned>(); }
	};
	class Pear :public Object {
	public:
		Pear() : Object({ "resources/food_info/Pear_info.bmp " }, { "resources/food/Pear.bmp " }, "Pear", 3, 4) {
		}
		~Pear() override {
		}
		shared_ptr<Object> clone() { return make_shared<Pear>(); }

		void Boost(vector<shared_ptr<Pet>>& friendPet, unsigned int idx, int power) override {
			if (idx < 0 || idx >= friendPet.size() || !friendPet[idx]) {
				return;
			}
			friendPet[idx]->set_atk(friendPet[idx]->get_attack() + 2);
			friendPet[idx]->set_life(friendPet[idx]->get_life() + 2);
		}
	};
	class Chili :public Object {
	public:
		Chili() : Object({ "resources/food_info/Chili_info.bmp " }, { "resources/food/Chili.bmp " }, "Chili", 3, 5) {
		}
		~Chili() override {
		}
		shared_ptr<Object> clone() { return make_shared<Chili>(); }
	};
	class Chocolate :public Object {
	public:
		Chocolate() : Object({ "resources/food_info/Chocolat_info.bmp " }, { "resources/food/Chocolate.bmp " }, "Chocolate", 3, 5) {
		}
		~Chocolate() override {
		}
		shared_ptr<Object> clone() { return make_shared<Chocolate>(); }

		void LevelUp(vector<shared_ptr<Pet>>& atkcells, int idx)  {
		
		}	
		
	};
	class Sushi :public Object {
	public:
		Sushi() : Object({ "resources/food_info/Sushi_info.bmp " }, { "resources/food/Sushi.bmp " }, "Sushi", 3, 5) {
		}
		~Sushi() override {
		}
		shared_ptr<Object> clone() { return make_shared<Sushi>(); }
		void Boost(vector<shared_ptr<Pet>>& friendPet, unsigned int idx, int power) override {
			srand((unsigned int)time(NULL));
			if (friendPet.size() == 0) {
				return;
			}
			vector<int> selectedPets;
			for (int i = 0; i < 3; ++i) {
				bool selected = false;
				while (!selected) {
					int randN = rand() % 5;
					if (randN != idx && (!friendPet[randN]) && find(selectedPets.begin(), selectedPets.end(), randN) == selectedPets.end()) {
						friendPet[randN]->set_atk(friendPet[randN]->get_attack() + 1);
						friendPet[randN]->set_life(friendPet[randN]->get_life() + 1);
						selectedPets.push_back(randN);
						selected = true;
					}
				}
			}
		}
	};
	class Steak :public Object {
	public:
		Steak() : Object({ "resources/food_info/Steak_info.bmp " }, { "resources/food/Steak.bmp " }, "Steak", 3, 6) {
		}
		~Steak() override {
		}
		shared_ptr<Object> clone() { return make_shared<Steak>(); }
	};
	class Melon :public Object {
	public:
		Melon() : Object({ "resources/food_info/Melon_info.bmp " }, { "resources/food/Melon.bmp " }, "Melon", 3, 6) {
		}
		~Melon() override {
		}
		shared_ptr<Object> clone() { return make_shared<Melon>(); }
	};
	class Mushroom :public Object {
	public:
		Mushroom() : Object({ "resources/food_info/Mushroom_info.bmp " }, { "resources/food/Mushroom.bmp " }, "Mushroom", 3, 6) {
		}
		~Mushroom() override {
		}
		shared_ptr<Object> clone() { return make_shared<Mushroom>(); }
	};
	class Pizza :public Object {
	public:
		Pizza() : Object({ "resources/food_info/Pizza_info.bmp " }, { "resources/food/Pizza.bmp " }, "Pizza", 3, 6 ){
		}
		~Pizza() override {
		}
		shared_ptr<Object> clone() { return make_shared<Pizza>(); }
		void Boost(vector<shared_ptr<Pet>>& friendPet, unsigned int idx, int power) override {
			srand((unsigned int)time(NULL));
			if (friendPet.size() == 0) {
				return;
			}
			vector<int> selectedPets;
			for (int i = 0; i < 2; ++i) {
				bool selected = false;
				while (!selected) {
					int randN = rand() % 5;
					if (randN != idx && (!friendPet[randN]) && find(selectedPets.begin(), selectedPets.end(), randN) == selectedPets.end()) {
						friendPet[randN]->set_atk(friendPet[randN]->get_attack() + 2);
						friendPet[randN]->set_life(friendPet[randN]->get_life() + 2);
						selectedPets.push_back(randN);
						selected = true;
					}
				}
			}
		}
	};
	class GenObject{
	public:
		GenObject() {
			food_array.push_back(make_shared<Apple>());
			food_array.push_back(make_shared<Honey>());
			food_array.push_back(make_shared<Pill>());
			food_array.push_back(make_shared<Meatbone>());
			food_array.push_back(make_shared<Cupcake>());
			food_array.push_back(make_shared<Salad>());
			food_array.push_back(make_shared<Garlic>());
			food_array.push_back(make_shared<Canned>());
			food_array.push_back(make_shared<Pear>());
			food_array.push_back(make_shared<Chili>());
			food_array.push_back(make_shared<Chocolate>());
			food_array.push_back(make_shared<Sushi>());
			food_array.push_back(make_shared<Steak>());
			food_array.push_back(make_shared<Melon>());
			food_array.push_back(make_shared<Mushroom>());
			food_array.push_back(make_shared<Pizza>());
		
		
		};
		void init() {
			for (auto item : food_array) {
				item->Load_img();
			}
		}
		~GenObject() {};
		vector<shared_ptr<Object>> get_Object() { return food_array; }
	private:
		vector<shared_ptr<Object>> food_array;
	};

	
}
#endif  //HEADER_OBJECT