#include <iostream>
#include <vector>
#include <map>

#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	//#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif

int main() {
	std::map<char,int> mymap;

	mymap['d'] = 400;
	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;
	// show content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}
