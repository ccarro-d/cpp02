/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:35:18 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/02/08 12:21:47 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

std::ostream&	operator<<(std::ostream& os, const Fixed& toStream)
{
	os << toStream.toFloat();
	return (os);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(rawBits_);
}

int	Fixed::toInt(void) const
{
	int	result;
	result = rawBits_ >> fractionalBits_; //es lo mismo que dividir entre 256
	return (result);
}

float	Fixed::toFloat(void) const
{
	float	result;
	float	scale;
	scale = (1 << fractionalBits_);
	result = static_cast<float>(rawBits_) / scale;
	return (result);
}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	rawBits_ = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // Lo hacemos así para forzar el operator= y clavar los prints, pero usar el getter sería equivalente (salvo por los prints)
}

Fixed::Fixed(int const interger)
{
	std::cout << "Int constructor called" << std::endl;
	rawBits_ = interger << fractionalBits_; // Desplazamos 8 bits a la izquierda (lo mismo que multiplicar por 256)
}

int	Fixed::roundToInt(float const& floatingNumber)
{
	if (floatingNumber >= 0.0f)
		return (static_cast<int>(std::floor(floatingNumber + 0.5f)));
	return (static_cast<int>(std::ceil(floatingNumber - 0.5f)));
}

Fixed::Fixed(float const floatingPoint)
{
	std::cout << "Float constructor called" << std::endl;
	int	scale = (1 << fractionalBits_); // Desplazamos 00000001	8 posiciones a 100000000 (noveno bit) que equivale a 256
	rawBits_ = roundToInt(floatingPoint * scale); // Es lo mismo que desplazar 8 bits a la izquierda
}

Fixed& Fixed::operator=(const	Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits_ = other.rawBits_; // Podemos acceder directamente al atributo privado de otro objeto de la misma clase. En ex00 usábamos el getter para clavar el print pero ambas soluciones son equivalentes
	return(*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}