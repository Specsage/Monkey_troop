/****** MAIN ********/
#include "GreenMonkey.hpp"//include header file
#include "Habitat.hpp"// Include Habitat header
#include <iostream>
using namespace std;
int main()
{
	Habitat H;
	H.initialization(50);
	//H.getEmptyCells();
	H.showGrid();
	/*H.invasion(300);
	for (int x = 0; x < 5; x++)
	{
		H.ageAll();
		for (int x = 0; x < 52; x++)
		{
			H.feedAll();
		}
	}
	//H.getStatistics();
	H.showGrid();
	cin.get();*/
	return 0;
}