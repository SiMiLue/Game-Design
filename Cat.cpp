#include <stdafx.h>
#include "Cat.h"
Cat::Cat(Team* team, Shop* shop) :Pet("Cat", team, shop) {
	m_id = 58;
	m_tier = 6;
	m_attack = 4;
	m_life = 5;
}