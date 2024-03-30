#pragma once
#ifndef HEADER_PETS_ARMADILLO
#define HEADER_PETS_ARMADILLO

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Armadillo : public Pet {
public:
	Armadillo(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_ARMADILLO