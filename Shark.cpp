#include <stdafx.h>
#include "Shark.h"
Shark::Shark(Team* team, Shop* shop) :Pet("Shark", team, shop) {
	m_id = 49;
	m_tier = 5;
	m_attack = 2;
	m_life = 2;
}