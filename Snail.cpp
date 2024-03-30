#include <stdafx.h>
#include "Snail.h"
Snail::Snail(Team* team, Shop* shop) :Pet("Snail", team, shop) {
	m_id = 11;
	m_tier = 2;
	m_attack = 2;
	m_life = 2;

}
