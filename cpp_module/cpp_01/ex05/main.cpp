/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:29:45 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 22:20:58 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl ha;
	ha.complain("DEBUG");
	ha.complain("INFO");
	ha.complain("WARNING");
	ha.complain("ERROR");
	return (0);
}
