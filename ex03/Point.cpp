/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:23:48 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/02/09 00:51:20 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// CONSTRUCTORS
Point::Point() : x_(0), y_(0) {}

Point::Point(const float x, const float y) : x_(x), y_(y) {}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {}

// DESTRUCTOR
Point::~Point(void)
{
	return ;
}

// GETTERS

const Fixed&	Point::getX(void) const
{
	return (x_);
}

const Fixed&	Point::getY(void) const
{
	return (y_);
}

// OPERATORS
Point&	Point::operator=(const Point& other)
{
	static_cast<void>(other); //silenciamos parámetro
	return (*this); // devolvemos el valor de la izquierda (al que asignamos) porque no podemos asignarle (x_ e y_ son const)
}