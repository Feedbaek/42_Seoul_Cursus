/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:26:00 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/08 18:58:58 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::contact_add(std::string first_name, std::string last_name,
std::string nickname, std::string phone_number, std::string darkest_secret) {
	this->index = this->size;
	this->size = this->size + 1;
	//this->index++;
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}
void	Contact::get_index(void) {
	std::string s = std::to_string(this->index);
	int i;
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
	int i;
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
	int i;
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
	int i;
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
	int i;
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
	int i;
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
Contact::Contact(void) {
	this->index = this->size;
	this->size = this->size + 1;
}
