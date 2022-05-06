/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:31:47 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/06 18:43:47 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {
private:
	PresidentialPardonForm();

public:
	PresidentialPardonForm(std::string str);
	PresidentialPardonForm(const PresidentialPardonForm &a);
	~PresidentialPardonForm();

	PresidentialPardonForm	&operator=(const PresidentialPardonForm &a);

	void	execute(const Bureaucrat &a) const;
};


#endif
