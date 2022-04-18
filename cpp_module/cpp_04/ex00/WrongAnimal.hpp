/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:45:20 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/18 14:52:15 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
	std::string	type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &a);
	~WrongAnimal();

	WrongAnimal &operator= (const WrongAnimal &a);

	void	makeSound() const;

	std::string	getType() const;
};

#endif
