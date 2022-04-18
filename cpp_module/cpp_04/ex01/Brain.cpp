/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:50:29 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/18 17:01:33 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor\n";
}
Brain::Brain(const Brain &a) {
	std::cout << "Brain copy constructor\n";
	*this = a;
}
Brain::~Brain() {
	std::cout << "Brain destructor\n";
}

Brain	&Brain::operator=(const Brain &a) {
	for (int i=0; i<100; i++) {
		this->ideas[i] = a.ideas[i];
	}
	return (*this);
}

void	Brain::setter(std::string str, int n) {
	for (int i=0; i<n; i++)
		this->ideas[i] = str;
}

std::string	Brain::getter() {
	return (*this->ideas);
}
