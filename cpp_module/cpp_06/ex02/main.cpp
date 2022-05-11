/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:35:18 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/11 15:15:00 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
	srand(time(0));

	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);

	delete ptr;
	return 0;
}
