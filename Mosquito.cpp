#include <stdafx.h>
#include "Mosquito.h"
Mosquito::Mosquito(Team* team, Shop* shop) :Pet("Mosquito", team, shop) {
	m_id = 7;
	m_tier = 1;
	m_attack = 2;
	m_life = 2;

}

