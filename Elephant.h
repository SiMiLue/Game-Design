#pragma once
#ifndef HEADER_PETS_ELEPHANT
#define HEADER_PETS_ELEPHANT

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Elephant : public Pet {
public:
	Elephant(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_ELEPHANT