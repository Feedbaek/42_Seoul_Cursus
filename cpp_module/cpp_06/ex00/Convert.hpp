/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:07:09 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/13 15:27:35 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Convert {
private:
	std::string _input;

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

	std::string	getInput() const;
	class ImpossibleException : public std::exception {
		public:
			const char	*what() const throw();
	};
	class NonDisplayableException : public std::exception {
		public:
			const char	*what() const throw();
	};
};

#endif
