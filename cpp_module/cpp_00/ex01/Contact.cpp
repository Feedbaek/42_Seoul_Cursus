/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:26:00 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 21:47:10 by minskim2         ###   ########.fr       */
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
	std::stringstream ss;
	ss << this->index;
	std::string s = ss.str();
	std::cout << std::setw(10);
	if (s.length() > 10)
		s = s.substr(0, 9) + ".";
	std::cout << s;
}
void	Contact::get_first_name(void) {
	std::string s = this->first_name;
	std::cout << std::setw(10);
	if (s.length() > 10)
		s = s.substr(0, 9) + ".";
	std::cout << s;
}
void	Contact::get_last_name(void) {
	std::string s = this->last_name;
	std::cout << std::setw(10);
	if (s.length() > 10)
		s = s.substr(0, 9) + ".";
	std::cout << s;
}
void	Contact::get_nickname(void) {
	std::string s = this->nickname;
	std::cout << std::setw(10);
	if (s.length() > 10)
		s = s.substr(0, 9) + ".";
	std::cout << s;
}
void	Contact::get_phone_number(void) {
	std::string s = this->phone_number;
	std::cout << std::setw(10);
	if (s.length() > 10)
		s = s.substr(0, 9) + ".";
	std::cout << s;
}
void	Contact::get_darkest_secret(void) {
	std::string s = this->darkest_secret;
	std::cout << std::setw(10);
	if (s.length() > 10)
		s = s.substr(0, 9) + ".";
	std::cout << s;
}
void	Contact::set_size(void) {
	this->size = 0;
}
