#pragma once
#ifndef HEADER_PETS_DOG
#define HEADER_PETS_DOG

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Dog : public Pet {
public:
	Dog(Team* team, Shop* shop);
	

	//void on_sell() override;
};
#endif // HEADER_PETS_DOG
