#include <stdafx.h>
#include "Pig.h"

Pig::Pig(Team* team, Shop* shop) : Pet("Pig", team, shop) {
	m_id = 5;
	m_tier = 1;
	m_attack = 4;
	m_life = 1;

}

