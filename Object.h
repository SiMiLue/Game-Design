#ifndef HEADER_OBJECT
#define HEADER_OBJECT

#define PACK_STANDARD 1
#define PACK_DLC1 2

#include <string>
#include <vector>

enum class ObjType { FOOD, ITEM };

class Pet;
class Shop;
class Team;

namespace game_framework {
	class Object{
	public:
		Object();
		~Object();
		int get_cost;
		void set_pet(Pet* pet);

	private:

	private:

	};

	








}
#endif  HEADER_OBJECT