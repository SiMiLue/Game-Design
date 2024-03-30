#include <stdafx.h>
#include "Spider.h"
Spider::Spider(Team* team, Shop* shop) :Pet("Spider", team, shop) {
	m_id = 20;
	m_tier = 2;
	m_attack = 2;
	m_life = 2;
}

