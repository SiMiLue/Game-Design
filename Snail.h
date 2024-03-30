#pragma once
#ifndef HEADER_PETS_SNAIL
#define HEADER_PETS_SNAIL

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Snail : public Pet {
public:
	Snail(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_SNAIL