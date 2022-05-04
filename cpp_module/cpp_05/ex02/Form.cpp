/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:58:34 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/04 16:49:31 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char	*Form::GradeTooHighException::what(void) const throw() {
	return ("Form Grade Too High");
}
const char	*Form::GradeTooLowException::what(void) const throw() {
	return ("Form Grade Too Low");
}
const char	*Form::DoesNotSignedException::what(void) const throw() {
	return ("Not Signed");
}
const char	*Form::FileNotWorkingException::what(void) const throw() {
	return ("File Not Working");
}
Form::Form() :sign_grade(0), exec_grade(0) {
}
Form::Form(std::string str, const int sign_num, const int exec_num) :type("Form"), name(str), sign_grade(sign_num), exec_grade(exec_num), is_signed(false) {
	if (this->sign_grade < 1 || this->exec_grade < 1)
		throw Form::GradeTooHighException();
	if (this->sign_grade > 150 || this->exec_grade > 150)
		throw Form::GradeTooLowException();
}
Form::Form(const Form &a) :type("Form"), name(a.name), sign_grade(a.sign_grade), exec_grade(a.exec_grade), is_signed(a.is_signed) {
	if (this->sign_grade < 1 || this->exec_grade < 1)
		throw Form::GradeTooHighException();
	if (this->sign_grade > 150 || this->exec_grade > 150)
		throw Form::GradeTooLowException();
}
Form::~Form() {
}

Form &Form::operator=(const Form &a) {
	this->type = a.type;
	*(const_cast<std::string *>(&this->name)) = a.name;
	*(const_cast<int *>(&this->sign_grade)) = a.sign_grade;
	*(const_cast<int *>(&this->exec_grade)) = a.exec_grade;
	this->is_signed = a.is_signed;
	return *this;
}

void	Form::setType(std::string str) {
	this->type = str;
}

std::string	Form::getType() const {
	return this->type;
}

std::string	Form::getName() const {
	return this->name;
}
int	Form::getExec() const {
	return this->exec_grade;
}
int	Form::getSign() const {
	return this->sign_grade;
}
bool	Form::getIsSigned() const {
	return this->is_signed;
}

void	Form::beSigned(Bureaucrat &a) {
	if (a.getGrade() <= this->sign_grade) {
		this->is_signed = true;
	}
	else {
		throw Form::GradeTooHighException();
	}
}

void Form::executable(Bureaucrat& b){
	if (!this->getIsSigned())
		throw DoesNotSignedException();
	if (b.getGrade() > this->exec_grade)
		throw GradeTooHighException();
}

std::ostream& operator<<(std::ostream &out, Form &b) {
	out << b.getName() + ", form sign grade: " << b.getSign() << " exec grade: " << b.getExec() << " signed: " << std::boolalpha << b.getIsSigned();
	return out;
}
