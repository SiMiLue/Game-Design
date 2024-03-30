#pragma once
#ifndef HEADER_PETS_PIGEON
#define HEADER_PETS_PIGEON

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class PIGEON : public Pet {
public:
	PIGEON(Team* team, Shop* shop);


	//void on_sell() override;
};


#endif // HEADER_PETS_PIGEON