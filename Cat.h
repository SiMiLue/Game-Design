#pragma once
#ifndef HEADER_PETS_CAT
#define HEADER_PETS_CAT

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Cat : public Pet {
public:
	Cat(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_CAT