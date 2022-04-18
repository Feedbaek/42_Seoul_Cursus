/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:45:20 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/18 15:54:49 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
	std::string	type;

public:
	Animal();
	Animal(const Animal &a);
	virtual ~Animal();

	Animal &operator= (const Animal &a);

	virtual void	makeSound() const;

	std::string	getType() const;
};

#endif
