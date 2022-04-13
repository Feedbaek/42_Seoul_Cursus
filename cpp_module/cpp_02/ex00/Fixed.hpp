/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:31:17 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/13 11:01:10 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int	fixed_point;
	static const int fractional_bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &a);
	Fixed	&operator= (const Fixed &a);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
