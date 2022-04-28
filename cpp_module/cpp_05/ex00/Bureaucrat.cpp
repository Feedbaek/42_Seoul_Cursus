/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:33:06 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/28 21:21:37 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Bureaucrat Grade Too High");
}
const char	*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Bureaucrat Grade Too Low");
}

Bureaucrat::Bureaucrat() {
}
Bureaucrat::Bureaucrat(std::string str, int num) :name(str), grade(num){
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &a) :name(a.name), grade(a.grade) {
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &a) {
	if (this != &a) {
		*(const_cast<std::string *>(&this->name)) = a.name;
		this->grade = a.grade;
	}
	return *this;
}

std::string	Bureaucrat::getName() {
	return this->name;
}
int	Bureaucrat::getGrade() {
	return this->grade;
}
void	Bureaucrat::upGrade() {
	if (this->grade - 1 == 0)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}
void	Bureaucrat::downGrade() {
	if (this->grade + 1 == 151)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &b) {
	out << b.getName() + ", bureaucrat grade " << b.getGrade();
	return out;
}
