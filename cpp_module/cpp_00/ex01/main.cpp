/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:35:34 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 21:49:27 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	ADD(PhoneBook &book) {
	std::string f_name, l_name, n_name, p_num, d_secret;
	std::cout << "Input first name, last name, nickname, phone number, darkest secret" << std::endl;
	std::cin >> f_name >> l_name >> n_name >> p_num >> d_secret;
	std::cin.ignore(5, '\n');
	book.add(f_name, l_name, n_name, p_num, d_secret);
}

void	SEARCH(PhoneBook &book) {
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	book.search();
}

int		EXIT(int exit) {
	return (exit);
}

int		main(void) {
	PhoneBook book;
	std::string input;
	book.set_contact();
	std::cout << "ADD or SEARCH or EXIT" << std::endl;
	while (1) {
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			return (EXIT(0));
		else if (input == "ADD")
			ADD(book);
		else if (input == "SEARCH")
			SEARCH(book);
	}
	return (0);
}
