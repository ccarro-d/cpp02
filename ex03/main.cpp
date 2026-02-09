/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:49:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/02/09 02:14:33 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int	main(void)
{
	Point a(0, 0);
	Point b(5, 10);
	Point c(10, 0);
	Point point(5, 9);

	if (bsp(a, b, c, point))
		std::cout << "Point inside triangle" << std::endl;
	else
		std::cout << "Point outside triangle" << std::endl;

	return (0);
}
