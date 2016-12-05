#include "TraversableSet.h"

int main()
{
	TraversableSet a;
	a.add(1);
	a.add(2);
	a.add(6);
	a.add(5);
	a.add(3);
	a.add(1);
	a.add(4);
	std::cout << a;
	a.remove(3);
	std::cout << a;
	int k = a[3];
	std::cout << "3. clan: " << k<<std::endl;
	getchar();
	getchar();
}