/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:49:26 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/06 20:19:40 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
private:

public:
	class NoMatchingTypeException : public std::exception {
		public:
			const char	*what(void) const throw();
	};
	Intern();
	Intern(const Intern &a);
	~Intern();

	Intern	&operator=(const Intern &a);

	Form	*makeForm(std::string type, std::string name);
};

#endif
