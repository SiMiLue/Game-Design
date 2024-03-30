#pragma once
#ifndef HEADER_PETS_SQUIRREL
#define HEADER_PETS_SQUIRREL

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Squirrel : public Pet {
public:
	Squirrel(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_SQUIRREL