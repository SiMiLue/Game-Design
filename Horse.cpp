#include <stdafx.h>
#include "Horse.h"
Horse::Horse(Team* team, Shop* shop) :Pet("Horse", team, shop) {
	m_id = 10;
	m_tier = 1;
	m_attack = 2;
	m_life = 1;

}

