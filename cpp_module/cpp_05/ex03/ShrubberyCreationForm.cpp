/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:59:20 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/06 18:54:20 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :Form() {
	this->setType("ShrubberyCreationForm");
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :Form(target, 145, 137) {
	this->setType("ShrubberyCreationForm");
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a) :Form(a) {
	this->setType("ShrubberyCreationForm");
}
ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a) {
	return *(dynamic_cast<ShrubberyCreationForm*>(&(Form::operator=(a))));
}

void	ShrubberyCreationForm::execute(const Bureaucrat &a) const {
	this->executable(a);
	std::ofstream out((getName() + "_shrubbery").c_str(),
		std::ofstream::out | std::ofstream::trunc);
	if (!out.good())
		throw FileNotWorkingException();
	std::string shrubbery = "               ,@@@@@@@,\n"
							"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
							"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
							"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
							"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
							"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
							"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
							"       |o|        | |         | |\n"
							"       |.|        | |         | |\n"
							"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
	out << shrubbery;
	out.close();
}
