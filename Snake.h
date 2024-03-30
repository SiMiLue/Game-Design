#pragma once
#ifndef HEADER_PETS_SNAKE
#define HEADER_PETS_SNAKE

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Snake : public Pet {
public:
	Snake(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_SNAKE