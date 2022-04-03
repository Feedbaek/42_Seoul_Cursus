/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:35:34 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/03 22:46:20 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void	ADD(PhoneBook &book) {
	std::string f_name, l_name, n_name, p_num, d_secret;
	Contact *c = new Contact();
	std::cin >> f_name >> l_name >> n_name >> p_num >> d_secret;
	c->contact_add(f_name, l_name, n_name, p_num, d_secret);
	book.add(c);
}

std::string	convert(std::string str) {
	std::string *s = new std::string();
	for (int i=0; i<str.size(); i++) {
		if (i == 9) {
			if (str.size() > 10) {
				*s += '.';
				break;
			}
		}
		*s += str[i];
	}
}

void	SEARCH(PhoneBook &book) {
	char	index[10];
	std::string	s_index = convert(book)
	char	f_name[10];
	std::string	s_f_name(f_name);
	char	l_name[10];
	std::string	s_l_name(l_name);
	char	n_name[10];
	std::string	s_n_name(n_name);
	std::cout << s_index+"|" << s_f_name+"|" << s_l_name+"|" << s_n_name;
}

int		main(void) {
	PhoneBook book;
	return (0);
}
