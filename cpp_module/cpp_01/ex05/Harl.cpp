/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:30:31 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 22:20:02 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for \
my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for \
years whereas you started working here since last month." << std::endl;

}
void	Harl::error(void) {
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	void	(Harl::*fp[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	keyword[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i=0; i<4; i++)
		if (level == keyword[i])
			(this->*fp[i])();
}

Harl::Harl() {
}
Harl::~Harl() {
}
