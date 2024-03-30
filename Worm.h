#pragma once
#ifndef HEADER_PETS_WORM
#define HEADER_PETS_WORM

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Worm : public Pet {
public:
	Worm(Team* team, Shop* shop);


	//void on_sell() override;
};


#endif // HEADER_PETS_WORM