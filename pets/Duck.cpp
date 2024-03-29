#include "Duck.h"
#include "utils.hpp"
Duck::Duck(Team* team, Shop* shop) : Pet("Duck", team, shop) {
	
	m_id = 6;
	m_pack = PACK_STANDARD;
	m_tier = 1;
	m_attack = 1;
	m_life = 3;
	reset_stats();
}

Duck::~Duck() { }

