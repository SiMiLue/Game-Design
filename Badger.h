#pragma once
#ifndef HEADER_PETS_BADGER
#define HEADER_PETS_BADGER

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Badger : public Pet {
public:
	Badger(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_BADGER