#ifndef ATKSYSTEM_H
#define ATKSYSTEM_H

#include "Pets.h"
#include "attackCell.h"
#include <chrono>
#include <iostream>

namespace game_framework {
	class Atksystem {
	public:
		Atksystem() {
		}
		~Atksystem() {
		}
		void init() {
			smoke.LoadBitmapByString({ "resources/boom/1.bmp","resources/boom/2.bmp" ,"resources/boom/3.bmp" ,"resources/boom/4.bmp" ,"resources/boom/5.bmp" }, RGB(0, 0, 0));
			smoke.SetTopLeft(death_x - 10, death_y - 8);
			smoke.SetAnimation(120, false);
			smoke.ShowBitmap();
		}
		void show() {
			CDC *pDC = CDDraw::GetBackCDC();
			pDC->MoveTo(600, 0);
			pDC->LineTo(600, 1200);
			CDDraw::ReleaseBackCDC();
			drawPets(m_enemy, enemy_coordinate);
			drawPets(m_friendly, friend_coordinate);
			if (!m_friendly.empty()) {
				printattak();
			}
			if (smokei) {
				auto now = std::chrono::high_resolution_clock::now();
				if (std::chrono::duration_cast<std::chrono::seconds>(now - smoke_start) < smoke_duration) {
					init();
				}
				else {
					smokei = false;
					m_friendly.erase(m_friendly.begin());
				}
			}

		}

		void drawPets(vector<shared_ptr<Pet>>& pets, const vector<tuple<int, int>>& coordinates) {
			for (unsigned int i = 0; i < pets.size(); i++) {
				if (pets[i] != nullptr) {
					pets[i]->Load_img();
					pets[i]->set_locate(get<0>(coordinates[i]), get<1>(coordinates[i]));
					pets[i]->get_img().ShowBitmap();
					pets[i]->set_Stats(pets[i]->get_img().GetLeft(), pets[i]->get_img().GetTop() + 50);
				}
			}
		}
		int get_cordinate(int index, string xy) {
			if (xy == "x") { return get<0>(friend_coordinate[index]); }
			else if (xy == "y") { return get<1>(friend_coordinate[index]); }
			return 0;
		}
		void startBattle() {
			isBattling = true;
		}

		void doBattleRound() {
			auto friendlyPet = m_friendly[0];
			auto enemyPet = m_enemy[0];
			friendlyPet->set_life(friendlyPet->get_life() - enemyPet->get_attack());
			enemyPet->set_life(enemyPet->get_life() - friendlyPet->get_attack());
			if (friendlyPet->get_life() <= 0) {
				death_x = friendlyPet->get_img().GetLeft();
				death_y = friendlyPet->get_img().GetTop();
				smokei = true;

				smoke_start = std::chrono::high_resolution_clock::now();
			}
			if (enemyPet->get_life() <= 0) {
				m_enemy.erase(m_enemy.begin());
			}



		}
		void set_fight_combination(vector<shared_ptr<Pet>>& friendly, vector<shared_ptr<Pet>>& enemy) {
			m_enemy = enemy;
			m_friendly = {};
			for (unsigned int i = 0; i < friendly.size(); i++) {
				if (friendly[i] != nullptr) {
					shared_ptr<Pet> temp = friendly[i]->clone();
					temp->set_atk(friendly[i]->get_attack());
					temp->set_life(friendly[i]->get_life());
					m_friendly.push_back(temp);
				}
			}
		}

		bool checklife() {
			return m_friendly.empty() || m_enemy.empty();
		}
		bool friendly_life() {
			return m_friendly.empty();
		}
		bool  m_enemy_life() {
			return m_enemy.empty();
		}
		void resetGame() {
			isBattling = false;
			startBattleDelay = 3.0f;
		}
		void mainLoop() {
			std::chrono::high_resolution_clock::time_point thisTime = std::chrono::high_resolution_clock::now();
			float deltaTime = std::chrono::duration_cast<std::chrono::duration<float>>(thisTime - lastTime).count();
			lastTime = thisTime;
			if (!isBattling) {
				startBattleDelay -= 0.5;
				if (startBattleDelay <= 0) {
					startBattle();

				}
			}
			if (isBattling) {
				updateGame(deltaTime);

			}
		}
		void updateGame(float deltaTime) {
			timer += deltaTime;
			if (timer >= battleInterval) {
				doBattleRound();
				timer = 0.0f;
			}

		}
		void printattak() {
			CDC *pDC = CDDraw::GetBackCDC();
			CTextDraw::ChangeFontLog(pDC, 100, "FranxurterTotallyMedium", RGB(255, 0, 0));
			CTextDraw::Print(pDC, 520, 300, to_string(-m_friendly[0]->get_attack()));
			CDDraw::ReleaseBackCDC();
		}
	private:
		std::chrono::high_resolution_clock::time_point lastTime = std::chrono::high_resolution_clock::now();
		vector<shared_ptr<Pet>> m_friendly;
		vector<shared_ptr<Pet>> m_enemy;
		CMovingBitmap smoke;
		bool smokei = false;
		float timer = 0.0f;
		float battleInterval = 1.2f;
		float startBattleDelay = 3.0f;
		std::chrono::high_resolution_clock::time_point smoke_start;
		std::chrono::duration<double> smoke_duration{ 0.6 };
		vector<tuple<int, int>> friend_coordinate{ {520,460},{420,460},{320,460},{220,460},{110,460} };
		vector<tuple<int, int>> enemy_coordinate{ {650,460},{750,460},{850,460},{950,460},{1050,460} };
		AttackCell cells;
		bool isBattling = false;
		int death_x;
		int death_y;


	};
}

#endif
