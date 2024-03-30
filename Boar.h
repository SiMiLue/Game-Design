#pragma once
#ifndef HEADER_PETS_BOAR
#define HEADER_PETS_BOAR

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Boar : public Pet {
public:
	Boar(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_BOAR