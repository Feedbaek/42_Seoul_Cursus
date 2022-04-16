/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:12:28 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/16 17:08:32 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "iostream"
# include "ClapTrap.hpp"

class FragTrap :public ClapTrap {
private:

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &a);
	~FragTrap();

	FragTrap	&operator=(const FragTrap &a);

	void	highFivesGuys(void);
};

#endif
