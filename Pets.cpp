#include "stdafx.h"
#include "Pets.h"


Pet::Pet(std::string name, Team* team, Shop* shop) :
	m_name(name), m_team(team), m_adv_team(nullptr), m_shop(shop), m_xp(0) {
	//reset_stats();
}
