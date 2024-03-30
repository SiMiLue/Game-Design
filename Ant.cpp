#include "stdafx.h"
#include "Ant.h"

Ant::Ant(Team* team, Shop* shop) :Pet("Ant", team, shop) {
	m_id = 6;
	m_tier = 1;
	m_attack = 2;
	m_life = 2;

}
