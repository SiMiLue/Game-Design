#pragma once
#ifndef HEADER_PET
#define HEADER_PET
#include "stdafx.h"
#include <string>
#include <vector>

#include "Object.h"


class Shop;
class Team;

class Pet {
	friend class UserInterface;
	friend class Environment;

public:
	
	std::string m_name;

	Pet(std::string name, Team* team, Shop* shop);
	

	

protected:
	std::string m_repr;

	Team* m_team;
	Team* m_adv_team;
	Shop* m_shop;

	int m_id;
	int m_pack;
	int m_tier;
	int m_attack;
	int m_life;
	int m_xp;
	//Object* m_object;

	int m_attack_buff;
	int m_life_buff;

private:
	static std::string get_random_name(int max_tier, bool strict_tier = false);
};


#endif // HEADER_PET