/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:45:20 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/22 17:27:55 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat :public Animal {
private:
	Brain	*brain;

public:
	Cat();
	Cat(const Brain &brain);
	Cat(const Cat &a);
	virtual ~Cat();

	Cat &operator=(const Cat &a);

	void	makeSound() const;
	void	setter(std::string str, int n);
	std::string	getter();
};

#endif
