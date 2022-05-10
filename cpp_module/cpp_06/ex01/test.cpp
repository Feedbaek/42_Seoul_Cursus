#include <iostream>

int	main() {
	int x = 0;
	long ptr;
	intptr_t a;
	a = reinterpret_cast<intptr_t>(&x);
	ptr = reinterpret_cast<long>(a);
	std::cout << a << std::endl;
	std::cout << ptr << std::endl;
	return 0;
}
