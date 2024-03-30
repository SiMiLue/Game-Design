#pragma once
#ifndef HEADER_PETS_HEDGEHOG
#define HEADER_PETS_HEDGEHOG

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Hedgehog : public Pet {
public:
	Hedgehog(Team* team, Shop* shop);


	//void on_sell() override;
};


#endif // HEADER_PETS_HEDGEHOG