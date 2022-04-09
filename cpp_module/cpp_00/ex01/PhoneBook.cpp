/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:44:10 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/08 22:36:03 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add(std::string f_name, std::string l_name, std::string n_name, std::string p_num, std::string d_secret) {
	arr[input_cnt % 8].contact_add(f_name, l_name, n_name, p_num, d_secret);
	input_cnt++;
}

void	PhoneBook::search(void) {
	for (int i=0; i<8 && i<this->input_cnt; i++) {
		this->arr[i].get_index();
		std::cout << "|";
		this->arr[i].get_first_name();
		std::cout << "|";
		this->arr[i].get_last_name();
		std::cout << "|";
		this->arr[i].get_nickname();
		std::cout << std::endl;
	}
}

void	PhoneBook::set_contact(void) {
	this->input_cnt = 0;
}
