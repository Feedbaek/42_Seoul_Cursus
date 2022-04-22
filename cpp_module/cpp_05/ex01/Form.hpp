/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:30:08 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/22 21:40:29 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Form {
private:
	const std::string	name;
	const int	sign_grade;
	const int	exec_grade;
	bool	is_signed;
public:
	Form (/* args */);
	~Form ();
};

#endif
