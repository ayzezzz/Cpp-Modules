/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:57:17 by zayaz             #+#    #+#             */
/*   Updated: 2026/03/03 15:57:26 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cerr << "Invalid argument count" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}