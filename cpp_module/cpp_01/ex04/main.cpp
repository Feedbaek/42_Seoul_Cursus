/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:11:26 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 18:16:20 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char const *argv[]) {
	Sed s;
	if (argc != 4) {
		std::cout << "Parameters Error\n";
		return (0);
	}
	s.replace(argv[1], argv[2], argv[3]);
	return 0;
}
