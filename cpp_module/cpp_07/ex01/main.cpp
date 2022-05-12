/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:41:10 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/12 17:00:06 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	int	i_arr[5] = {1, 2, 3, 4, 5};
	double d_arr[5] = {1.2, 2.3, 3.4, 4.5, 5.6};
	std::string str_arr[5] = {"as", "df", "qw", "er", "ty"};

	iter(i_arr, 5, std_cout);
	std::cout << std::endl;

	iter(d_arr, 5, std_cout);
	std::cout << std::endl;

	iter(str_arr, 5, std_cout);
	std::cout << std::endl;
	return 0;
}
