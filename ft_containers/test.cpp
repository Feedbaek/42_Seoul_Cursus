#include "vector.hpp"
#include <vector>
#include <iostream>

struct test_s
{
	int a;
	std::string s;
};
int main() {

	ft::vector<int> v;
	ft::vector<int>::iterator iter;
	int a = int();
	a = 10;
	//std::cout << a;
	std::vector<int> v_i;
	//v_i.reserve(4);
	//for (int i=0; i<4; i++)
	//	v_i.push_back(i);
	std::cout << "resize \n";
	//v_i.insert(v_i.begin(), 5, -1);
	//v_i.resize(11);
	//for (int i=0; i<v_i.capacity(); i++)
	v_i.push_back(-1);
		std::cout << *(v_i.end()+1) << " ";
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
