#pragma once
#ifndef HEADER_PETS_WHALE
#define HEADER_PETS_WHALE

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Whale : public Pet {
public:
	Whale(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_WHALE