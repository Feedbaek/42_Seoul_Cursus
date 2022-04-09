/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:36:15 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/08 22:36:18 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook {
private:
	Contact	arr[8];
	int		input_cnt;
public:
	void	add(std::string f_name, std::string l_name, std::string n_name, std::string p_num, std::string d_secret);
	void	search(void);
	void	set_contact(void);
};

#endif
