#include <stdafx.h>
#include "Cow.h"
Cow::Cow(Team* team, Shop* shop) :Pet("Cow", team, shop) {
	m_id = 46;
	m_tier = 5;
	m_attack = 4;
	m_life = 6;
}