#ifndef HEADER_PETS_FISH
#define HEADER_PETS_FISH
#include "./Pets.h"
#include "shop.h"
#include "team.h"
class FISH : public Pet {
public:
	FISH(Team* team, Shop* shop);


	//void on_sell() override;
};


#endif // HEADER_PETS_FISH