#include <iostream>
#include"Darray.h"

using namespace std;




int main()
{
	Darray<int> dar(10);
	dar.Print();
	dar.RandomInit(10,120);
	dar.Print();
	dar.Insert(5, 100);
	dar.Print();
	dar.At(2) = 500;
	dar[3] = 600;
	dar.Print();



	return 0;
}