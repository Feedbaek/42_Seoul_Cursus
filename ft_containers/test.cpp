#include <iostream>
#include <list>

#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	#include "set.hpp"
#endif

#define T1 char

template <class SET>
void	cst(const SET &lhs, const SET &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	ft::set<T1> st1;
	ft::set<T1> st2;

	st1.insert('a');
	st1.insert('b');
	st1.insert('c');
	st1.insert('d');
	st2.insert('a');
	st2.insert('b');
	st2.insert('c');
	st2.insert('d');

	cst(st1, st1); // 0
	cst(st1, st2); // 1

	st2.insert('e');
	st2.insert('f');
	st2.insert('h');
	st2.insert('h');

	cst(st1, st2); // 2
	cst(st2, st1); // 3

	swap(st1, st2);

	cst(st1, st2); // 4
	cst(st2, st1); // 5

	return (0);
}


//typedef ft::set<T1>::iterator ft_iterator;
//typedef ft::set<T1>::const_iterator ft_const_iterator;

//static int iter = 0;

//template <typename T>
//std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
//{
//	o << "value: " << *iterator;
//	if (nl)
//		o << std::endl;
//	return ("");
//}

//template <typename T_SET>
//void	printSize(T_SET const &st, bool print_content = 1)
//{
//	std::cout << "size: " << st.size() << std::endl;
//	std::cout << "max_size: " << st.max_size() << std::endl;
//	if (print_content)
//	{
//		typename T_SET::const_iterator it = st.begin(), ite = st.end();
//		std::cout << std::endl << "Content is:" << std::endl;
//		for (; it != ite; ++it)
//			std::cout << "- " << printPair(it, false) << std::endl;
//	}
//	std::cout << "###############################################" << std::endl;
//}

//template <typename SET>
//void	ft_bound(SET &st, const T1 &param)
//{
//	ft_iterator ite = st.end(), it[2];
//	ft::pair<ft_iterator, ft_iterator> ft_range;

//	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
//	std::cout << "with key [" << param << "]:" << std::endl;
//	it[0] = st.lower_bound(param); it[1] = st.upper_bound(param);
//	ft_range = st.equal_range(param);
//	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
//	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
//	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
//}

//template <typename SET>
//void	ft_const_bound(const SET &st, const T1 &param)
//{
//	ft_const_iterator ite = st.end(), it[2];
//	ft::pair<ft_const_iterator, ft_const_iterator> ft_range;

//	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
//	std::cout << "with key [" << param << "]:" << std::endl;
//	it[0] = st.lower_bound(param); it[1] = st.upper_bound(param);
//	ft_range = st.equal_range(param);
//	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
//	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
//	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
//}

//int		main(void)
//{
//	std::list<T1> lst;
//	unsigned int lst_size = 10;
//	for (unsigned int i = 0; i < lst_size; ++i)
//		lst.push_back((i + 1) * 3);
//	ft::set<T1> st(lst.begin(), lst.end());
//	printSize(st);

//	ft_const_bound(st, -10);
//	ft_const_bound(st, 1);
//	ft_const_bound(st, 5);
//	ft_const_bound(st, 10);
//	ft_const_bound(st, 50);

//	printSize(st);

//	ft_bound(st, 5);
//	ft_bound(st, 7);

//	printSize(st);
//	return (0);
//}
