#pragma once
#ifndef HEADER_PETS_TURTLE
#define HEADER_PETS_TURTLE

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Turtle : public Pet {
public:
	Turtle(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_TURTLE