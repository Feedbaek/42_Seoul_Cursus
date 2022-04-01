/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:30:25 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/01 16:16:50 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * \n";
		return (0);
	}
	for (int i=1; i<argc; i++) {
		for (int j=0; j<strlen(argv[i]); j++) {
			std::cout << (char)toupper(argv[i][j]);
		}
	}
	std::cout << std::endl;;
	return (0);
}
