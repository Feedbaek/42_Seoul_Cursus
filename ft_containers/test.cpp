#include <iostream>
#include <vector>
#include <map>
#include <list>

#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	//#include "stack.hpp"
	#include "vector.hpp"
#endif

int main() {
	ft::map<int, int> const mp;
	ft::map<int, int>::iterator it = mp.begin(); // <-- error expected

	(void)it;
	return (0);
}

	//ft::map<char,int> mymap;

	//mymap['d'] = 400;
	//mymap['b'] = 100;
	//mymap['a'] = 200;
	//mymap['e'] = 300;
	//mymap['f'] = 300;
	//mymap['c'] = 300;
	//// show content:
	//std::cout << "=== before === \n";
	//for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	//	std::cout << it->first << " => " << it->second << '\n';
	//mymap.erase(mymap.begin(), mymap.end());
	//std::cout << "=== after === \n";
	//for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	//	std::cout << it->first << " => " << it->second << '\n';
	//return 0;
