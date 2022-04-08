/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:26:00 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/08 22:36:08 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int		Contact::size = 0;

void	Contact::contact_add(std::string first_name, std::string last_name,
std::string nickname, std::string phone_number, std::string darkest_secret) {
	this->index = this->size;
	this->size = this->size + 1;
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}
void	Contact::get_index(void) {
	std::string s = std::to_string(this->index);
	size_t i;
	for (i=0; i<9 && i<s.size(); i++) {
		std::cout << s[i];
	}
	if (i == 9) {
		if (s.size() > 10)
			std::cout << ".";
		else
			std::cout << s[9];
	}
}
void	Contact::get_first_name(void) {
	std::string s = this->first_name;
	size_t i;
	for (i=0; i<9 && i<s.size(); i++) {
		std::cout << s[i];
	}
	if (i == 9) {
		if (s.size() > 10)
			std::cout << ".";
		else
			std::cout << s[9];
	}
}
void	Contact::get_last_name(void) {
	std::string s = this->last_name;
	size_t i;
	for (i=0; i<9 && i<s.size(); i++) {
		std::cout << s[i];
	}
	if (i == 9) {
		if (s.size() > 10)
			std::cout << ".";
		else
			std::cout << s[9];
	}
}
void	Contact::get_nickname(void) {
	std::string s = this->nickname;
	size_t i;
	for (i=0; i<9 && i<s.size(); i++) {
		std::cout << s[i];
	}
	if (i == 9) {
		if (s.size() > 10)
			std::cout << ".";
		else
			std::cout << s[9];
	}
}
void	Contact::get_phone_number(void) {
	std::string s = this->phone_number;
	size_t i;
	for (i=0; i<9 && i<s.size(); i++) {
		std::cout << s[i];
	}
	if (i == 9) {
		if (s.size() > 10)
			std::cout << ".";
		else
			std::cout << s[9];
	}
}
void	Contact::get_darkest_secret(void) {
	std::string s = this->darkest_secret;
	size_t i;
	for (i=0; i<9 && i<s.size(); i++) {
		std::cout << s[i];
	}
	if (i == 9) {
		if (s.size() > 10)
			std::cout << ".";
		else
			std::cout << s[9];
	}
}
void	Contact::set_size(void) {
	this->size = 0;
}
