/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:55:09 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/06 20:35:59 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char	*Intern::NoMatchingTypeException::what(void) const throw() {
	return ("No Matching Type");
}

Intern::Intern() {
}
Intern::Intern(const Intern &a) {
	(void)a;
}
Intern::~Intern() {
}

Intern	&Intern::operator=(const Intern &a) {
	(void)a;
	return *this;
}

Form	*Intern::makeForm(std::string type, std::string name) {
	std::string arr[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	try {
		for (int i=0; i<3; i++) {
			if (arr[i] == type) {
				std::cout << "Intern creates " + type + " : " + name << std::endl;
				switch (i) {
				case 0:
					return new PresidentialPardonForm(name);
				case 1:
					return new RobotomyRequestForm(name);
				case 2:
					return new ShrubberyCreationForm(name);
				}
			}
		}
		throw Intern::NoMatchingTypeException();
	} catch (std::exception &e) {
		std::cerr << "Intern can't create " + type + " : " + name + " because " << e.what() << std::endl;
		return NULL;
	}
}
