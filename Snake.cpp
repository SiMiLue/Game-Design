#include <stdafx.h>
#include "Snake.h"
Snake::Snake(Team* team, Shop* shop) :Pet("Snake", team, shop) {
	m_id = 59;
	m_tier = 6;
	m_attack = 6;
	m_life = 6;
}