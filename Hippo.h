#pragma once
#ifndef HEADER_PETS_HIPPO
#define HEADER_PETS_HIPPO

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Hippo : public Pet {
public:
	Hippo(Team* team, Shop* shop);


	//void on_sell() override;
};


#endif // HEADER_PETS_HIPPO
