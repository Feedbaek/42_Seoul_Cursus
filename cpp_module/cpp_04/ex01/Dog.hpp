/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:45:20 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/22 17:28:05 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog :public Animal {
private:
	Brain	*brain;

public:
	Dog();
	Dog(const Brain &a);
	Dog(const Dog &a);
	virtual ~Dog();

	Dog &operator=(const Dog &a);

	void	makeSound() const;
	void	setter(std::string str, int n);
	std::string	getter();
};

#endif
