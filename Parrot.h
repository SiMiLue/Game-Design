#pragma once
#ifndef HEADER_PETS_PARROT
#define HEADER_PETS_PARROT

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Parrot : public Pet {
public:
	Parrot(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_PARROT