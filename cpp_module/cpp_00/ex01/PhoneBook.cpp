/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:44:10 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/12 21:22:11 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add(std::string f_name, std::string l_name, std::string n_name, std::string p_num, std::string d_secret) {
	arr[input_cnt % 8].contact_add(f_name, l_name, n_name, p_num, d_secret);
	input_cnt++;
}

void	PhoneBook::search(void) {
	int	x;
	std::string	clean;

	for (int i=0; i<8 && i<this->input_cnt; i++) {
		std::cout << this->arr[i].get_index();
		std::cout << "|";
		std::cout << this->arr[i].get_first_name();
		std::cout << "|";
		std::cout << this->arr[i].get_last_name();
		std::cout << "|";
		std::cout << this->arr[i].get_nickname();
		std::cout << std::endl;
	}
	if (this->input_cnt == 0)
		return;
	while (1) {
		std::cout << "What index?\n> ";
		std::cin >> x;
		std::cin.ignore(1000, '\n');
		if (std::cin.fail()) {
			std::cout << "Error: index input\n";
			std::cin.clear();
			std::getline(std::cin, clean);
			return;
		}
		if (x >= this->input_cnt || x < 0) {
			std::cout << "Error: index bound\n";
			return;
		}
		for (int i=0; i<8 && i<this->input_cnt; i++) {
			if (this->arr[i].get_int_index() == x) {
				this->arr[i].print_inform();
				return ;
			}
		}
		std::cout << "Error: not found index\n";
	}
}

void	PhoneBook::set_contact(void) {
	this->input_cnt = 0;
}
