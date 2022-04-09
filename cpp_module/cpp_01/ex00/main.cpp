/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:17:20 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 01:00:23 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	zombie("first");
	zombie.announce();
	Zombie	*new_zombie = newZombie("second");
	new_zombie->announce();
	randomChump("third");
	delete new_zombie;
	return (0);
}
