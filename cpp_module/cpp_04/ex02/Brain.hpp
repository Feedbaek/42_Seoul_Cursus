/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:50:37 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/18 16:52:04 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
private:
	std::string	ideas[100];
public:
	Brain();
	Brain(const Brain &a);
	~Brain();

	Brain	&operator=(const Brain &a);

	void	setter(std::string str, int n);
	std::string	getter();
};

#endif
