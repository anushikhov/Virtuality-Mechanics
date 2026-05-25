#include <iostream>

int thisOne()
{
	static int x = 5;
	x += 1;
	return x;
}

int main()
{
	std::cout << "First call to static: " << thisOne() << '\n';
	std::cout << "Second call to static: " << thisOne() << '\n';

	return 0;
}
