#ifndef SHOP_H
#define SHOP_H
#include "Pets.h"
#include "object.h"
namespace game_framework {
	class Shop {
	public:
		Shop() {
			srand((unsigned int)time(NULL));
		}
		~Shop() {
		}
		void show_img() {
			for (size_t i = 0; i < shop_item.size();i++) {
				int x = get_cordinate(i, "x");
				int y = get_cordinate(i, "y");
				if (!isbought[i]) {
					if (isfreezed[i]) {
						shop_item[i]->show_ice(x - 20, y - 30);
					}
					shop_item[i]->get_img().ShowBitmap();
					shop_item[i]->set_Stats(x, y + 50);
					shop_item[i]->show_tiers(x, y + 50);
					
				}	
			}
			for (unsigned int i = 0; i < food_item.size(); i++) {
				food_item[i]->get_img().ShowBitmap();
				food_item[i]->show_tiers(get<0>(food_coordinate[i]), get<1>(food_coordinate[i])+50);
			}
		}
		void set_img() {
			for (size_t i = 0; i < shop_item.size(); i++) {
				shop_item[i]->set_locate(250 + i * 120, 570);
			}
		}
		void set_food_img() {
			for (unsigned int i = 0; i < food_item.size(); i++) {
				food_item[i]->set_locate(990 - i * 115, 580);
			}
		}
		int get_max(int Cround) {
			if (Cround >= 11) {
				return 60;
			}
			return (unsigned int)(round(Cround / 2.0* 10));
		}
		int food_get_max(int Cround) {
			if (Cround <= 2) { return 2; }
			else if (Cround <= 4) { return 5; }
			else if (Cround <= 6) { return 7; }
			else if (Cround <= 8) { return 9; }
			else if (Cround <= 10) { return 12; }
			else { return 16; }
		}
		void freeze_check() {
			freeze_item = {};
			for (unsigned int i = 0; i < shop_item.size(); i++) {
				if (isfreezed[i]) {
					isfreezed[i] = false;
					freeze_item.push_back(shop_item[i]);
				}
			}
		}
		void freeze_check_food() {
			food_freeze_item = {};
			for (unsigned int i = 0; i < food_item.size(); i++) {
				if (food_isfreezed[i]) {
					food_isfreezed[i] = false;
					food_freeze_item.push_back(food_item[i]);
					
				}
			}
		}
		void get_random_pet(int round){
			srand((unsigned int)time(NULL));
			isbought = { false,false,false,false,false };
			freeze_check();
			//isfreezed = { false,false,false,false,false };
			int max = get_max(round);
			unsigned int block = ((round < 5) ? 3 : (round >= 9) ? 5 : 4);
			bool sign = true;
			shop_item = {};
			vector<int> pet_rands = {};
			for (unsigned int i = 0; i < freeze_item.size(); i++) {
				shop_item.push_back(freeze_item[i]);
				isfreezed[i] = true;
			}
			
			
			while (pet_rands.size() < block-shop_item.size()) {
				int current_rand = rand() % max ;
				sign = true;
				for (unsigned int i = 0; i < pet_rands.size(); i++) {
					if (pet_rands[i] == current_rand) {
						sign = false;
					}
				}
				if (sign) {
					pet_rands.push_back(current_rand);
				}
			}
			for (int n : pet_rands) {
				shop_item.push_back(pets_arr.get_pets()[n]->clone());
			}
			for (auto item : shop_item) {
				item->Load_img();
			}
			set_img();
		}
		void get_random_foods(int C_round) {
			srand((unsigned int)time(NULL));
			food_isbought = { false,false };
			freeze_check_food();
			int max = food_get_max(C_round);
			int block = C_round < 5 ? 1 : 2;
			bool sign = true;
			food_item = {};
			vector<int> current_rands = {};
			for (unsigned int i = 0; i < food_freeze_item.size(); i++) {
				food_item.push_back(food_freeze_item[i]);
				food_isfreezed[i] = true;
			}
			while (current_rands.size()< block-food_item.size()) {
				int current_rand = rand() % max;
				sign = true;
				for (unsigned int i = 0; i < current_rands.size(); i++) {
					if (current_rand == current_rands[i]) { sign = false; }
				}
				if (sign) {
					current_rands.push_back(current_rand);
				}
			}
			for (int n : current_rands) {
				food_item.push_back(food_arr.get_Object()[n]->clone());
			}
			for (auto obj : food_item) {
				obj->Load_img();
			}
			set_food_img();
		}
		void init() {
			pets_arr.init();
			food_arr.init();
		}
		GenPets get_pets() { return pets_arr; }
		vector<shared_ptr<Pet>> get_shop_item() {
			return shop_item;
		}
		
		void set_touched(int index, bool status) {
			touched[index] = status;
		}
		bool get_touched_by_index(int index) {
			return touched[index];
		}
		bool get_isbought_by_index(int index) {
			return isbought[index];
		}
		int get_cordinate(int index,string xy) {
			if(xy == "x"){ return get<0>(cordinate[index]); }
			else if (xy == "y") { return get<1>(cordinate[index]); }
			return 0;
		}
		void set_buy_by_index(int i) {
			isbought[i] = true;
		}
		void set_freeze_by_idx(int index,bool stats) {
			isfreezed[index] = stats;
		}
		bool get_freeze_by_idx(int index) {
			return isfreezed[index];
		}
	private:
		GenPets pets_arr;
		GenObject food_arr;
		vector<bool> isfreezed{ false,false,false,false ,false};
		vector<bool> touched{ false,false,false,false,false };
		vector<bool> isbought{ false,false,false,false,false };
		vector<tuple<int, int>> cordinate{ {250,570},{370,570},{490,570},{610,570},{730,570} };
		vector<shared_ptr<Pet>> shop_item;
		vector<shared_ptr<Pet>> freeze_item;
		vector<bool> food_isfreezed{ false,false };
		vector<bool> food_isbought{ false,false };
		vector<tuple<int, int>> food_coordinate{ {990,580},{875,580} };
		vector<shared_ptr<Object>> food_item;
		vector<shared_ptr<Object>> food_freeze_item;
	};
}

#endif
