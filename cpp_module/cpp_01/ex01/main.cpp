/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:54:18 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 01:54:53 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	int	N = 10;
	std::string	name = "hoooorrrrde";
	Zombie	*horde = zombieHorde(N, name);
	for (int i=0; i<N; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
