/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:17:20 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/09 22:48:46 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	zombie("first");
	zombie.announce();
	Zombie	*new_zombie = zombie.newZombie("second");
	new_zombie->announce();
	new_zombie->randomChump("third");
	delete new_zombie;
	return (0);
}
