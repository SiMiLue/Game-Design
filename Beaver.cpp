#include "Beaver.h"
#include <stdafx.h>
Beaver::Beaver(Team* team, Shop* shop) : Pet("Beaver", team, shop) {
	m_id = 2;
	m_tier = 1;
	m_attack = 3;
	m_life = 2;

}

Beaver::~Beaver() {


}