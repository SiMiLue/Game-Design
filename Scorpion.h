#pragma once
#ifndef HEADER_PETS_SCORPION
#define HEADER_PETS_SCORPION

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Scorpion : public Pet {
public:
	Scorpion(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_SCORPION