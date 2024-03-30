#pragma once
#ifndef HEADER_PETS_RHINO
#define HEADER_PETS_RHINO

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Rhino : public Pet {
public:
	Rhino(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_RHINO