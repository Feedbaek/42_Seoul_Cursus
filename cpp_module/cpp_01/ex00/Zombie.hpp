/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:18:31 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 01:22:25 by minskim2         ###   ########.fr       */
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
	Zombie(std::string name);
	~Zombie(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
