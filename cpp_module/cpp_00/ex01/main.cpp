/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:35:34 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/12 21:22:34 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	test(std::string input) {
	for (size_t j=0; j<input.size(); j++) {
		if (!isprint(input[j]))
			return (0);
	}
	return (1);
}

void	ADD(PhoneBook &book) {
	std::string f_name, l_name, n_name, p_num, d_secret;
	std::string input[5];
	std::string clean;
	std::string nav[5] = {"Input first name\n", "Input last name\n", "Input nickname\n", "Input phone number\n", "Input darkest secret\n"};
	for (int i=0; i<5; ) {
		std::cout << nav[i] << "> ";
		std::getline(std::cin, input[i]);
		if (!test(input[i]))
			continue;
		if (std::cin.fail()) {
			std::getline(std::cin, clean);
			return ;
		}
		if (input[i]== "")
			continue;
		i++;
	}
	book.add(input[0], input[1], input[2], input[3], input[4]);
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
		if (std::cin.fail()) {
			std::cout << "EOF\n";
			return (0);
		}
		if (input == "EXIT")
			return (EXIT(0));
		else if (input == "ADD")
			ADD(book);
		else if (input == "SEARCH")
			SEARCH(book);
	}
	return (0);
}
