#pragma once
#ifndef HEADER_PETS_BIOWFISH
#define HEADER_PETS_BIOWFISH

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Blowfish : public Pet {
public:
	Blowfish(Team* team, Shop* shop);


	//void on_sell() override;
};


#endif // HEADER_PETS_BLOWFISH