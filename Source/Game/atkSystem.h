#ifndef ATKSYSTEM_H
#define ATKSYSTEM_H

#include "Pets.h"
#include "attackCell.h"

namespace game_framework {
	class Atksystem {
	public:
		Atksystem() {
		}
		~Atksystem() {
		}
		void OnMove() {


		}
		void show() {
			
			CDC *pDC = CDDraw::GetBackCDC();
			pDC->MoveTo(600,0);
			pDC->LineTo(600, 1200);
			CDDraw::ReleaseBackCDC();
			
			for (unsigned int i = 0; i < m_enemy.size(); i++) {
				if (m_enemy[i] != nullptr) {
					m_enemy[i]->Load_img();
					m_enemy[i]->set_locate(get<0>(enemy_coordinate[i]), get<1>(enemy_coordinate[i]));
					m_enemy[i]->get_img().ShowBitmap();
					m_enemy[i]->set_Stats(m_enemy[i]->get_img().GetLeft(), m_enemy[i]->get_img().GetTop()+50);
					
				}
			}
			for(unsigned int i=0;i<m_friendly.size();i++){
				if (m_friendly[i] != nullptr) {
					m_friendly[i]->Load_img();
					m_friendly[i]->set_locate(get<0>(friend_coordinate[i]), get<1>(friend_coordinate[i]));
					m_friendly[i]->get_img().ShowBitmap();
					m_friendly[i]->set_Stats(m_friendly[i]->get_img().GetLeft(), m_friendly[i]->get_img().GetTop() + 50);
					
				}
			}
			
		}
		int atk() {
			size_t friend_idx = 0;
			size_t enemy_idx = 0;
			while (m_friendly.size() != 0 && m_enemy.size() != 0) {
				int current_friend_atk = m_friendly[friend_idx]->get_attack();
				int current_friend_life = m_friendly[friend_idx]->get_life();
				int current_enemy_atk = m_enemy[enemy_idx]->get_attack();
				int current_enemy_life = m_enemy[enemy_idx]->get_life();
				m_friendly[friend_idx]->set_life(current_friend_life - current_enemy_atk);
				m_enemy[enemy_idx]->set_life(current_enemy_life - current_friend_atk);
				if (m_friendly[friend_idx]->get_life() <= 0) { friend_idx+=1; }
				if (m_enemy[enemy_idx]->get_life() <= 0) { enemy_idx+=1; }
				if (m_friendly.size() <= friend_idx && m_enemy.size() <= enemy_idx) { return 2; }
				else if (m_friendly.size() == friend_idx && m_enemy.size() >= enemy_idx) { return 0; }
				else if (m_friendly.size() >= friend_idx && m_enemy.size() == enemy_idx) { return 1; }
			}
			return 0;
		}
		void clean_idx(){
			for (vector<shared_ptr<Pet>>::iterator it = m_friendly.begin(); it != m_friendly.end();) {
				if (*it == nullptr) {
					it = m_friendly.erase(it);
				}
				else {
					++it;
				}
			}
			for (vector<shared_ptr<Pet>>::iterator it = m_enemy.begin(); it != m_enemy.end();) {
				if (*it == nullptr) {
					it = m_enemy.erase(it);
				}
				else {
					++it;
				}
			}
		}
		void set_fight_combination(vector<shared_ptr<Pet>> friendly, vector<shared_ptr<Pet>> enemy) {
			m_enemy = enemy;
			m_friendly = {};
			for (unsigned int i = 0; i < friendly.size();  i++) {
				if (friendly[i] != nullptr) {
					shared_ptr<Pet> temp = friendly[i]->clone();
					temp->set_atk(friendly[i]->get_attack());
					temp->set_life(friendly[i]->get_life());
					m_friendly.push_back(temp);
				}
			}
			clean_idx();
			for (unsigned int i = 0; i < m_friendly.size(); i++) {
				
			}
			for (unsigned int i = 0; i < m_enemy.size(); i++) {
				
			}
		}
		  	
	private:
		vector<shared_ptr<Pet>> m_friendly;
		vector<shared_ptr<Pet>> m_enemy;
		vector<tuple<int, int>> friend_coordinate{ {520,460},{420,460},{320,460},{220,460},{110,460} };
		vector<tuple<int, int>> enemy_coordinate{ {650,460},{750,460},{850,460},{950,460},{1050,460} };
		AttackCell cells;
	};
}

#endif
