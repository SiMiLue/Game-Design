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
					atkcells[i]->set_Stats(get<0>(cordinate[i]), get<1>(cordinate[i])+50);
					atkcells[i]->show_levels(levels[i], get<0>(cordinate[i]), get<1>(cordinate[i]));
				}
			}
			
		}
		void buy_by_index(int index,shared_ptr<Pet> pet) {
			if (atkcells[index] == nullptr) {
				atkcells[index] = pet;
				atkcells[index]->Load_img();
				atkcells[index]->set_locate(get<0>(cordinate[index]), get<1>(cordinate[index]));
			}
			
		}
		int sell_by_index(int index) {
			shared_ptr<Pet> test;
			atkcells[index] = test;
			return 1;
		}
		void set_level_by_idx(int index) {
			levels[index] = levels[index] + 1;
		}
		tuple<bool,int> isbuying(int cx,int cy) {
			
			for (int j = 0; j < 5; j++) {
				int x = get<0>(cordinate[j]);
				int y = get<1>(cordinate[j]);
				if (cx > x - 30 && cx < x + 30 && cy > y -30 && cy < y + 30) {
					return { true, j};
				}
			}
			
			return { false, 9};
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
	private:
		vector<shared_ptr<Pet>> atkcells;
		vector<bool> item_exist{ false,false,false,false,false };
		vector<int> levels{ 0,0,0,0,0 };
		vector<tuple<int, int>> cordinate{ {725,330},{600,330},{480,330},{377,330},{270,330} };
	};
}

#endif // !ATKCELL_H

