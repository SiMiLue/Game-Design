#include <stdafx.h>
#include "Turtle.h"
Turtle::Turtle(Team* team, Shop* shop) :Pet("Turtle", team, shop) {
	m_id = 35;
	m_tier = 4;
	m_attack = 2;
	m_life = 5;
}