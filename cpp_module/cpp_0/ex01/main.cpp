/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:35:34 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/08 18:45:28 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	ADD(PhoneBook &book) {
	std::string f_name, l_name, n_name, p_num, d_secret;
	//Contact *c = new Contact();
	std::cin >> f_name >> l_name >> n_name >> p_num >> d_secret;
	//c->contact_add(f_name, l_name, n_name, p_num, d_secret);
	book.add(f_name, l_name, n_name, p_num, d_secret);
}

//std::string	convert(std::string str) {
//	std::string *s = new std::string();
//	for (int i=0; i<str.size(); i++) {
//		if (i == 9) {
//			if (str.size() > 10) {
//				*s += '.';
//				break;
//			}
//		}
//		*s += str[i];
//	}
//}

void	SEARCH(PhoneBook &book) {
	Contact **arr;

	arr = book.get_Contact();
	for (int i=0; i<8; i++) {

	}
}

int		EXIT(PhoneBook &book, int exit) {
	Contact **arr = book.get_Contact();
	for (int i=0; i<8; i++) {
		delete(arr[i]);
	}
	return (exit);
}

int		main(void) {
	PhoneBook book;
	return (0);
}
