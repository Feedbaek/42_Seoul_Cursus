/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:06:42 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/04 23:06:39 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(std::string str) {

}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a) {

}
RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &a) {

}

void	RobotomyRequestForm::execute(const Bureaucrat &a) const {
	this->executable(a);
}
