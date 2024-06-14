#ifndef ATKCELL_H
#define ATKCELL_H
#include "Pets.h"
#include "Shop.h"
namespace game_framework {
	class AttackCell {
	public:
		AttackCell() {
			for (int i = 0; i < 5; i++) {
				atkcells.push_back(nullptr);
			}
		}
		~AttackCell() {
		}
		void show_pets() {
			for (int i = 0; i < 5; i++) {
				if (!(atkcells[i] == nullptr)) {
					atkcells[i]->get_img().ShowBitmap();
					atkcells[i]->set_Stats(get<0>(cordinate[i]), get<1>(cordinate[i]) + 50);
					atkcells[i]->show_levels(levels[i], get<0>(cordinate[i]), get<1>(cordinate[i]));
				}
				
			}

		}
		void buy_by_index(int index, shared_ptr<Pet> pet) {
			if (atkcells[index] == nullptr) {
				atkcells[index] = pet;
				atkcells[index]->Load_img();
				atkcells[index]->set_locate(get<0>(cordinate[index]), get<1>(cordinate[index]));
			}

		}
		void sell_by_index(int index, int  sell_item_level, int* current_money) {
			shared_ptr<Pet> test;
			int current_level = get_level_by_idx(index);
			atkcells[index] = test;
			if (current_level == 1) {
				*current_money += 1;
			}
			else if (current_level == 2) {
				*current_money += 2;
			}
			else if (current_level == 3) { *current_money += 3; }
			levels[index] = 0;

		}
		void set_level_by_idx(int index) {
			if (levels[index] < 5) {
				levels[index] = levels[index] + 1;
			}

		}
		int get_level_by_idx(int index) {
			if (levels[index] < 2) {
				return 1;
			}
			else if (levels[index] < 4) {
				return 2;
			}
			else { return 3; }
		}
		int get_vectorlevel(int index) {
			return levels[index];
		}
		tuple<bool, int> isbuying(int cx, int cy) {

			for (int j = 0; j < 5; j++) {
				int x = get<0>(cordinate[j]);
				int y = get<1>(cordinate[j]);
				if (cx > x - 30 && cx < x + 30 && cy > y - 30 && cy < y + 30) {
					return { true, j };
				}
			}

			return { false, 9 };
		}
		shared_ptr<Pet> get_pets_by_idx(int index) {
			return atkcells[index];
		}
		void init() {
			//atkcell1->set_img({"resources/"})
		}
		vector<shared_ptr<Pet>> get_pets() {
			return atkcells;
		}
		int get_cordinate(int index, string xy) {
			if (xy == "x") { return get<0>(cordinate[index]); }
			else if (xy == "y") { return get<1>(cordinate[index]); }
			return 0;
		}
		int get_current_pet_num() {
			int current_pet_num = 0;
			for (unsigned int i = 0; i < atkcells.size(); i++) {
				if (atkcells[i] != nullptr) { current_pet_num += 1; }
			}
			return current_pet_num;
		}
		void set_touched(int index, bool stats) {
			touched[index] = stats;
		}
		bool get_touched_by_index(int index) {
			return touched[index];
		}
		void changePosition(int current_pet, int position) {
			if (current_pet == position) {
				atkcells[current_pet]->set_locate(get<0>(cordinate[current_pet]), get<1>(cordinate[current_pet]));
			}
			else if (atkcells[position] == nullptr) {
				atkcells[position] = atkcells[current_pet];
				atkcells[current_pet] = nullptr;
				atkcells[position]->set_locate(get<0>(cordinate[position]), get<1>(cordinate[position]));
				levels[position] = levels[current_pet];
				levels[current_pet] = 0;
			}
			else {
				
				shared_ptr<Pet> tempPet = atkcells[position];
				int tmplevel = levels[position];
				atkcells[position] = atkcells[current_pet];
				atkcells[current_pet] = tempPet;
				atkcells[position]->set_locate(get<0>(cordinate[position]), get<1>(cordinate[position]));
				atkcells[current_pet]->set_locate(get<0>(cordinate[current_pet]), get<1>(cordinate[current_pet]));
				levels[position] = levels[current_pet];
				levels[current_pet] = tmplevel;

			}
			/*
			else {
				atkcells[current_pet]->set_locate(get<0>(cordinate[current_pet]), get<1>(cordinate[current_pet]));
			}
			*/
		}
	private:
		vector<shared_ptr<Pet>> atkcells;
		vector<bool> item_exist{ false,false,false,false,false };
		vector<bool> touched{ false,false,false,false,false };
		vector<int> levels{ 0,0,0,0,0 };
		vector<tuple<int, int>> cordinate{ {725,330},{600,330},{480,330},{377,330},{270,330} };
	};
}

#endif // !ATKCELL_H

