/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:49:50 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/18 14:41:34 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

void test_normal(void) {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void list_normal(void) {
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

void test_reverse_iterator(void) {
	MutantStack<double> mstack;
	mstack.push(1.0);
	mstack.push(2.0);
	mstack.push(3.0);
	mstack.push(4.0);
	mstack.push(5.0);
	MutantStack<double>::reverse_iterator rit = mstack.rbegin();
	MutantStack<double>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}
}
void list_reverse_iterator(void) {
	std::list<double> mstack;
	mstack.push_back(1.0);
	mstack.push_back(2.0);
	mstack.push_back(3.0);
	mstack.push_back(4.0);
	mstack.push_back(5.0);
	std::list<double>::reverse_iterator rit = mstack.rbegin();
	std::list<double>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}
}

int main(void) {
	std::cout << "<MutantStack>\n";
	test_normal();
	std::cout << "<list>\n";
	list_normal();
	std::cout << std::endl;
	std::cout << "<MutantStack>\n";
	test_reverse_iterator();
	std::cout << "<list>\n";
	list_reverse_iterator();
	return 0;
}
