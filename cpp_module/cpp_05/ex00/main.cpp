/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:17:34 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/28 18:30:00 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
int main(void) {
	Bureaucrat a("Minskim2", 1);
	Bureaucrat b("loser", 150);
	Bureaucrat c(a);

	std::cout << a << "\n" << b << "\n" << c << std::endl;
	std::cout << std::endl;
	c = b;
	std::cout << c << std::endl;
	std::cout << std::endl;
	try {
		a.upGrade();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		b.downGrade();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try {
		Bureaucrat c("asdf", 151);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Bureaucrat c("asdf", -1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
