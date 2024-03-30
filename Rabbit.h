#pragma once
#ifndef HEADER_PETS_RABBIT
#define HEADER_PETS_RABBIT

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Rabbit : public Pet {
public:
	Rabbit(Team* team, Shop* shop);
	

	//void on_sell() override;
};
#endif // HEADER_PETS_RABBIT