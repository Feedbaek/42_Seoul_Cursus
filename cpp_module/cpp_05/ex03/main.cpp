/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:17:34 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/06 20:33:03 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void) {
	Intern i;
	Bureaucrat b1("Admin", 1);
	Bureaucrat b2("Jseo", 15);
	Bureaucrat b3("Dohykim", 70);
	Bureaucrat b4("Hyson", 140);

	Form* f1 = i.makeForm("PresidentialPardonForm", "Chang Chen");
	Form* f2 = i.makeForm("RobotomyRequestForm", "Terminator");
	Form* f3 = i.makeForm("ShrubberyCreationForm", "Fangorn");
	i.makeForm("Something Wrong", "NOT GONNAE GENERATED");

	if (!f1 || !f2 || !f3)
		return (1);
	std::cout << std::endl;
	std::cout << b1 << std::endl
		<< b2 << std::endl
		<< b3 << std::endl
		<< b4 << std::endl;
	std::cout << std::endl;
	std::cout << *f1 << std::endl
		<< *f2 << std::endl
		<< *f3 << std::endl;
	std::cout << std::endl;
	b2.signForm(*f1);
	b3.signForm(*f2);
	b4.signForm(*f3);
	std::cout << std::endl;
	b2.executeForm(*f1);
	b3.executeForm(*f2);
	b4.executeForm(*f3);
	std::cout << std::endl;
	b1.executeForm(*f1);
	b1.executeForm(*f2);
	b1.executeForm(*f3);

	delete f3;
	delete f2;
	delete f1;
	return 0;
}
