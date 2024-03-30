#include <stdafx.h>
#include "Dog.h"
Dog::Dog(Team* team, Shop* shop) :Pet("Dog", team, shop) {
	m_id = 29;
	m_tier = 3;
	m_attack = 3;
	m_life = 2;
}

