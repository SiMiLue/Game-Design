#include <stdafx.h>
#include "Turkey.h"
Turkey::Turkey(Team* team, Shop* shop) :Pet("Turkey", team, shop) {
	m_id = 50;
	m_tier = 5;
	m_attack = 3;
	m_life = 4;
}