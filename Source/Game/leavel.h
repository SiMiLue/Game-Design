#ifndef LEAVEL_H
#define LEAVEL_H
#include "Pets.h"
#include "object.h"
#include "attackCell.h"
namespace game_framework {
	class Level {
	private:
		vector<shared_ptr<Pet>> enemies;  // 敵人列表
		unsigned int difficulty;  // 關卡難度
	public:
		Level(unsigned int difficulty, vector<shared_ptr<Pet>> enemies)
			: difficulty(difficulty), enemies(enemies) {}

		vector<shared_ptr<Pet>> getEnemies() { return enemies; }

		unsigned int getDifficulty() { return difficulty; }

		void startLevel(Atksystem& atkSystem, AttackCell& atkCell, Shop& shop, int& currentRound, int& currentMoney, int& currentWin, int& currentHeart) {
			atkSystem.set_fight_combination(atkCell.get_pets(), enemies);
			currentRound += 1;
			currentMoney = 10;
			shop.get_random_pet(currentRound);
		}

	};
}

#endif