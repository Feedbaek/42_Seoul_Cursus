#include <iostream>
#include <list>

#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif

int main(void) {
	//ft::stack<int> i1;
	////i1.push(0);
	//i1.push(1);
	//i1.push(2);
	//i1.push(3);
	//ft::stack<int> i2 = i1;
	//std::cout << i2.top() << "\n";
	//i2.pop();
	//std::cout << i2.top() << "\n";
	//i2.pop();
	//std::cout << i2.top() << "\n";
	//i2.pop();
	//std::cout << i2.top() << "\n";
	//std::cout << i1.top() << "\n";
	//i1.pop();
	//std::cout << i1.top() << "\n";
	//i1.pop();
	//std::cout << i1.top() << "\n";
	//i1.pop();
	//std::cout << i1.top() << "\n";
	system("leaks a.out");
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
