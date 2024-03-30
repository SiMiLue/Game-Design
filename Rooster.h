#pragma once
#ifndef HEADER_PETS_ROOSTER
#define HEADER_PETS_ROOSTER

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Rooster : public Pet {
public:
	Rooster(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_ROOSTER