/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:45:51 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/14 20:02:30 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	std::deque<int> d;
	std::list<int> l;
	std::vector<int> v;

	for (int i=0; i<10; i++) {
		d.push_back(i);
		l.push_back(i);
		v.push_back(i);
	}
	try {
		std::deque<int>::iterator iter = easyfind(&d, 3);
		std::cout << "Index " << std::distance(d.begin(), iter) << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::list<int>::iterator iter = easyfind(&l, 6);
		std::cout << "Index " << std::distance(l.begin(), iter) << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::vector<int>::iterator iter = easyfind(&v, 10);
		std::cout << "Index " << std::distance(v.begin(), iter) << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
