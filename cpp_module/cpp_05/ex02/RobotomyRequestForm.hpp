/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:06:55 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/04 22:22:09 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Form.hpp"

class RobotomyRequestForm : public Form {
private:
	RobotomyRequestForm();

public:
	RobotomyRequestForm(std::string str);
	RobotomyRequestForm(const RobotomyRequestForm &a);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &a);

	void	execute(const Bureaucrat &a) const;
};

#endif
