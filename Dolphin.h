#pragma once
#ifndef HEADER_PETS_DOLPHIN
#define HEADER_PETS_DOLPHIN

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Dolphin : public Pet {
public:
	Dolphin(Team* team, Shop* shop);
	

	//void on_sell() override;
};

#endif // HEADER_PETS_DOLPHIN