#ifndef SHOP_H
#define SHOP_H
#include "Pets.h"
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
				if (!isbought[i]) {
					shop_item[i]->get_img().ShowBitmap();
					shop_item[i]->set_Stats(get_cordinate(i, "x"), get_cordinate(i, "y") + 50);
					shop_item[i]->show_tiers(get_cordinate(i, "x"), get_cordinate(i, "y") + 50);
				}
			}
		}
		void set_img() {
			for (size_t i = 0; i < shop_item.size(); i++) {
				shop_item[i]->set_locate(250 + i * 120, 570);
			}
		}
		int get_max(int Cround) {
			if (Cround >= 11) {
				return 60;
			}
			return (unsigned int)(round(Cround / 2.0* 10));
		}
		void get_random_pet(int round){
			srand((unsigned int)time(NULL));
			isbought = { false,false,false,false,false };
			int max = get_max(round);
			unsigned int block = ((round < 5) ? 3 : (round >= 9) ? 5 : 4);
			bool sign = true;
			shop_item = {};
			vector<int> pet_rands = {};
			while (pet_rands.size() < block) {
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
		void init() {
			pets_arr.init();
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
		
		int get_cordinate(int index,string xy) {
			if(xy == "x"){ return get<0>(cordinate[index]); }
			else if (xy == "y") { return get<1>(cordinate[index]); }
			return 0;
		}
		void set_buy_by_index(int i) {
			isbought[i] = true;
		}
	private:
		GenPets pets_arr;
		vector<bool> isfreezed{ false,false,false,false ,false};
		vector<bool> touched{ false,false,false,false,false };
		vector<bool> isbought{ false,false,false,false,false };
		vector<tuple<int, int>> cordinate{ {250,570},{370,570},{490,570},{610,570},{730,570} };
		vector<shared_ptr<Pet>> shop_item;
	};
}

#endif
