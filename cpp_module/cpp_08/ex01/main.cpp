/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:21:55 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/17 21:41:11 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void test_normal(void) {
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test_max(void) {
	Span sp = Span(10000);

	for (int i = -5000; i < 5000; i++)
		sp.addNumber(i);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test_container_range(void) {
	std::vector<int>  v;
	Span sp(9);

	for (int i = 1 ; i < 10 ; i++)
		v.push_back(i * 3);
	sp.addRange(v.begin(), v.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test_array_range(void) {
	int a[9] = {3, 6, 9, 12, 15, 18, 23, 24, 27};
	Span sp(9);

	sp.addRange(a, a+9);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test_no_span(void) {
	try {
		Span sp(0);
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Span sp(0);
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void test_no_store(void) {
	try {
		Span sp(0);
		sp.addNumber(0);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Span sp(1);
		int a[2] = {3, 6};
		sp.addRange(a, a+2);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

int	main() {
	test_normal();
	std::cout << std::endl;
	test_max();
	std::cout << std::endl;
	test_container_range();
	std::cout << std::endl;
	test_array_range();
	std::cout << std::endl;
	test_no_span();
	std::cout << std::endl;
	test_no_store();
	return 0;
}
