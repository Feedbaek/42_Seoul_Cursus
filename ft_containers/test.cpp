#include <iostream>
#include <vector>

#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif

int main() {
	//ft::vector<int> v;
	//ft::vector<int>::iterator iter;
	//int a = int();
	//a = 10;
	//std::cout << a;
	std::vector<int> v_i;
	std::vector<int> v_i_2(v_i);
	std::cout << std::distance(v_i.begin(), v_i.end());
	v_i.reserve(10);
	std::vector<int>::iterator iter = v_i.begin();
	//v_i.erase(v_i.begin());
	//v_i.assign(7, -2);
	for (int i=0; i<4; i++)
		v_i.push_back(i);
	for (int i=0; i<4; i++)
		v_i_2.push_back(i);
	//v_i.pop_back();
	//v_i.insert(v_i.begin(), 2, -1);
	if (v_i == v_i_2)
		std::cout << "same\n";
	std::cout << std::distance(v_i.begin(), v_i.end());
	std::cout << "resize \n";
	//v_i.insert(v_i.begin(), 5, -1);
	//v_i.resize(11);
	for (int i=0; i<v_i.capacity(); i++)
		std::cout << *(iter + i) << " ";
	//v_i.push_back(-1);
	std::cout << std::endl;
	std::cout << v_i.capacity() << "\n";
	std::cout << v_i.size() << "\n";
	//std::cout << "\nreserve \n";
	//v_i.reserve(10);
	//for (int i=0; i<10; i++)
	//	std::cout << v_i[i] << " ";
	//std::cout << std::endl;
	//std::cout << v_i.capacity() << "\n";
	//std::cout << v_i.size();
	return 0;
}
