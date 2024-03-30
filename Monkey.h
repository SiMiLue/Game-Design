#pragma once
#ifndef HEADER_PETS_MONKEY
#define HEADER_PETS_MONKEY

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Monkey : public Pet {
public:
	Monkey(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_MONKEY