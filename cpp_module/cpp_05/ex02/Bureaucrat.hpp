/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:45:20 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/28 21:51:13 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Form;

class Bureaucrat {
private:
	const std::string	name;
	int	grade;
	Bureaucrat();

public:
	class GradeTooHighException : public std::exception {
		public:
			const char	*what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char	*what(void) const throw();
	};
	Bureaucrat(std::string str, int num);
	Bureaucrat(const Bureaucrat &a);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &a);

	std::string	getName();
	int	getGrade();
	void	upGrade();
	void	downGrade();

	void	signForm(Form &a);
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &b);

#endif
