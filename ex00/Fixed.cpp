/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:35:18 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/02/07 21:25:18 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(rawBits_);
}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	rawBits_ = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->rawBits_ = other.getRawBits();
}

Fixed& Fixed::operator=(const	Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits_ = other.getRawBits();
	return(*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}