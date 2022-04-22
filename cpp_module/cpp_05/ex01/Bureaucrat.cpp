/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:33:06 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/22 20:29:50 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Bureaucrat::Bureaucrat() :name(""), grade(150) {
//	std::cout << "Bureaucrat Default constructor\n";
//}
const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Bureaucrat Grade Too High");
}
const char	*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Bureaucrat Grade Too Low");
}

Bureaucrat::Bureaucrat() {
}
Bureaucrat::Bureaucrat(std::string str, int num) :name(str), grade(num){
	if (num < 1)
		throw Bureaucrat::GradeTooHighException();
	if (num > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &a) :name(a.name) {
	*this = a;
}
Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &a) {
	this->grade = a.grade;
	return *this;
}

std::string	Bureaucrat::getName() {
	return this->name;
}
int	Bureaucrat::getGrade() {
	return this->grade;
}
void	Bureaucrat::upGrade() {
	this->grade--;
	if (grade == 0)
		throw Bureaucrat::GradeTooHighException();
}
void	Bureaucrat::downGrade() {
	this->grade++;
	if (grade == 151)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &b) {
	out << b.getName() + ", bureaucrat grade " << b.getGrade();
	return out;
}
