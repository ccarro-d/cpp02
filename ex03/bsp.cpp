/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:32:41 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/02/09 02:19:08 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	cross(const Point& segmentStart, const Point& segmentEnd, const Point& toCheck)
{
	Fixed	result;
	result = (segmentEnd.getX() - segmentStart.getX())*(toCheck.getY() - segmentStart.getY()) - (segmentEnd.getY() - segmentStart.getY())*(toCheck.getX() - segmentStart.getX());
	return (result);
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	s1 = cross(a, b, point);
	Fixed	s2 = cross(b, c, point);
	Fixed	s3 = cross(c, a, point);
	Fixed	zero; // El default constructor lo inicializa a 0
	
	if (s1 == zero || s2 == zero || s3 == zero)
		return (false);
	if (s1 < zero && s2 < zero && s3 < zero)
		return (true);
	if (s1 > zero && s2 > zero && s3 > zero)
		return (true);
	return (false);
}