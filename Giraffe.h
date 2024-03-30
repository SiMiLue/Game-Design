#pragma once
#ifndef HEADER_PETS_GIRAFFE
#define HEADER_PETS_GIRAFFE

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Giraffe : public Pet {
public:
	Giraffe(Team* team, Shop* shop);
	

	//void on_sell() override;
};

#endif // HEADER_PETS_GIRAFFE