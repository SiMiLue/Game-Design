#pragma once
#ifndef HEADER_PETS_SHEEP
#define HEADER_PETS_SHEEP

#include "./Pets.h"
#include "shop.h"
#include "team.h"

////
class Sheep : public Pet {
public:
	Sheep(Team* team, Shop* shop);
	~Sheep() override;

	//void on_sell() override;
};
#endif // HEADER_PETS_SHEEP