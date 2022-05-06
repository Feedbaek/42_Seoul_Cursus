/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:06:42 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/06 18:49:42 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

int RobotomyRequestForm::seed = 0;

RobotomyRequestForm::RobotomyRequestForm() :Form(){
	this->setType("RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(std::string str) :Form(str, 72, 45) {
	this->setType("RobotomyRequestForm");
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a) :Form(a){
	this->setType("RobotomyRequestForm");
}
RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &a) {
	return *(dynamic_cast<RobotomyRequestForm*>(&(Form::operator=(a))));
}

void	RobotomyRequestForm::execute(const Bureaucrat &a) const {
	this->executable(a);
	if (this->seed == 0) {
		srand((unsigned int)time(NULL));
		this->seed = 1;
	}
	int num = rand() % 2;
	if (num == 0) {
		std::cout << "drrrrrrrrrrrrrrr..." << std::endl;
		std::cout << getName() << " has been robotomized successfully" << std::endl;
	}
	else {
		std::cout << "br br br..." << std::endl;
		std::cout << getName() << " failed to be robotomized" << std::endl;
	}
}
