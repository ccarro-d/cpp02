/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:23:45 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/02/09 02:12:32 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

	private:
		const Fixed	x_;
		const Fixed y_;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		~Point();

		Point&			operator=(const Point& other); // Se incluye por el Canonical pero no debe hacer nada porque x_ e y_ son const

		const Fixed&	getX(void) const;
		const Fixed&	getY(void) const;
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif