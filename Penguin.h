#pragma once
#ifndef HEADER_PETS_PENGUIN
#define HEADER_PETS_PENGUIN

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Penguin : public Pet {
public:
	Penguin(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_PENGUIN