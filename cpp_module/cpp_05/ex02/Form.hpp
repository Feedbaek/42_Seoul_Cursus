/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:30:08 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/03 20:41:36 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include "Bureaucrat.hpp"

class Form {
private:
	const std::string	name;
	const int	sign_grade;
	const int	exec_grade;
	bool	is_signed;
	Form ();

public:
	class GradeTooHighException : public std::exception {
		public:
			const char	*what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char	*what(void) const throw();
	};
	Form(std::string str, const int sign_num, const int exec_num);
	Form(const Form &a);
	virtual ~Form();

	Form &operator=(const Form &a);

	std::string	getName() const;
	int	getExec();
	int	getSign();
	bool	getIsSigned();

	void	beSigned(Bureaucrat &a);

	virtual void execute(const Bureaucrat& b) const = 0;
};

std::ostream& operator<<(std::ostream &out, Form &b);

#endif
