#pragma once
#ifndef HEADER_PETS_SHARK
#define HEADER_PETS_SHARK

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Shark : public Pet {
public:
	Shark(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_SHARK