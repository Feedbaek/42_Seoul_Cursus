/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:45:20 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/17 16:37:05 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat :public Animal {
private:

public:
	Cat();
	Cat(const Cat &a);
	~Cat();

	Cat &operator=(const Cat &a);

	void	makeSound() const;
};

#endif
