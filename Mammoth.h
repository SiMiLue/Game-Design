#pragma once
#ifndef HEADER_PETS_MAMMOTH
#define HEADER_PETS_MAMMOTH

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Mammoth : public Pet {
public:
	Mammoth(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_MAMMOTH