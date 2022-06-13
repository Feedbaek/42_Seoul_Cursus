//#include "vector.hpp"
#include <vector>
#include <iostream>

int main() {
	//ft::vector<int> v;
	//ft::vector<int>::iterator iter;
	//int a = int();
	//a = 10;
	//std::cout << a;
	std::vector<int> v_i;
	v_i.reserve(4);
	for (int i=0; i<4; i++)
		v_i.push_back(i);
	v_i.reserve(1);
	for (int i=0; i<4; i++)
		std::cout << v_i[i];
	std::cout << std::endl;
	std::cout << v_i.capacity() << "\n";
	std::cout << v_i.size() << "\n";
	v_i.reserve(6);
	for (int i=0; i<6; i++)
		std::cout << v_i[i];
	std::cout << std::endl;
	std::cout << v_i.capacity() << "\n";
	std::cout << v_i.size();
	return 0;
}
