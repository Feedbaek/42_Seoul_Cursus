/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:40:06 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/06 18:50:42 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :Form() {
	this->setType("PresidentialPardonForm");
}
PresidentialPardonForm::PresidentialPardonForm(std::string str) :Form(str, 25, 5) {
	this->setType("PresidentialPardonForm");
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a) :Form(a) {
	this->setType("PresidentialPardonForm");
}
PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &a) {
	return *(dynamic_cast<PresidentialPardonForm*>(&(Form::operator=(a))));
}

void	PresidentialPardonForm::execute(const Bureaucrat &a) const {
	this->executable(a);
	std::cout << this->getName() << "has been pardoned by Zafod Beeblebrox" << std::endl;
}
