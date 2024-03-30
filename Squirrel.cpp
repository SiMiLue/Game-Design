#include <stdafx.h>
#include "Squirrel.h"
Squirrel::Squirrel(Team* team, Shop* shop) :Pet("Squirrel", team, shop) {
	m_id = 36;
	m_tier = 4;
	m_attack = 2;
	m_life = 5;
}