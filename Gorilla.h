#pragma once
#ifndef HEADER_PETS_GORILLA
#define HEADER_PETS_GORILLA

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Gorilla : public Pet {
public:
	Gorilla(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_GORILLA