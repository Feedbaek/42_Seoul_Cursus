/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:30:25 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/12 20:20:55 by minskim2         ###   ########.fr       */
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
		std::string s(argv[i]);
		for (size_t j=0; j<strlen(argv[i]); j++) {
			argv[i][j] = toupper(argv[i][j]);
		}
		std::cout << s;
	}
	std::cout << std::endl;;
	return (0);
}
