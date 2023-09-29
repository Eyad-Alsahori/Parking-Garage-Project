#include"stack.h"
using namespace std;

struct car
{
	int counter = 0;
	char code;
	string Name;
	int number;
	bool operator==(const car& obj2)
	{
		if (Name == obj2.Name)
			return true;
		else
			return false;
	}
};
