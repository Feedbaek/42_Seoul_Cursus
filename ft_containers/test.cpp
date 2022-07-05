#include <iostream>
#include <vector>
#include <map>

#if 0 //CREATE A REAL STL EXAMPLE
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
	ft::vector<int> v;
	v.push_back(1);
	ft::vector<int>::iterator it1 = v.begin();
	ft::vector<int>::const_iterator it2 = v.begin();
	if (it1 == it2)
		std::cout << "equal\n";
	*it2 = 3;
	std::cout << *it1;
	//std::map<char,int> mymap;

	//mymap['b'] = 100;
	//mymap['a'] = 200;
	//mymap['c'] = 300;
	//std::map<char,int>::iterator itb=mymap.end();
	//std::cout << itb->first << " => " << itb->second << '\n';
	//// show content:
	//for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	//	std::cout << it->first << " => " << it->second << '\n';

	return 0;
}
