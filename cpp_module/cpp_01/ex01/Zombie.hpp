/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:54:42 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 01:34:25 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
private:
	std::string	name;
public:
	void	announce(void);
	void	initialize(std::string name);
	Zombie(void);
	~Zombie(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
