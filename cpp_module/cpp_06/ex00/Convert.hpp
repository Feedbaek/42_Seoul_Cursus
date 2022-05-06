/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:07:09 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/06 21:12:48 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>

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
};

#endif
