/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:07:09 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/07 23:27:18 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>

class Convert {
private:
	bool _e;
	const std::string _input;
	const double _value;

	Convert();

public:
	explicit Convert(const std::string input);
	Convert(const Convert &a);
	~Convert();

	Convert	&operator=(const Convert &a);

	char	toChar() const;
	int		toInt() const;
	float	toFloat() const;
	double	toDouble() const;

	bool	getError() const;
	double	getValue() const;
	std::string	getInput() const;
};

std::ostream	&operator<<(std::ostream &o, const Convert &c);

#endif
