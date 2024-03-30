#include <stdafx.h>
#include "Fly.h"
Fly::Fly(Team* team, Shop* shop) :Pet("Fly", team, shop) {
	m_id = 60;
	m_tier = 5;
	m_attack = 5;
	m_life = 5;
}