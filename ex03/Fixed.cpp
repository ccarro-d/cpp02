/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:35:18 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/02/08 20:59:34 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

//CONSTRUCTORS

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	rawBits_ = 0;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other; // Lo hacemos así para forzar el operator= y clavar los prints, pero usar el getter sería equivalente (salvo por los prints)
}

Fixed::Fixed(const int integer)
{
	//std::cout << "Int constructor called" << std::endl;
	rawBits_ = integer << fractionalBits_; // Desplazamos 8 bits a la izquierda (lo mismo que multiplicar por 256)
}

int	Fixed::roundToInt(const float& floatingNumber)
{
	if (floatingNumber >= 0.0f)
		return (static_cast<int>(std::floor(floatingNumber + 0.5f)));
	return (static_cast<int>(std::ceil(floatingNumber - 0.5f)));
}

Fixed::Fixed(const float floatingPoint)
{
	//std::cout << "Float constructor called" << std::endl;
	int	scale = (1 << fractionalBits_); // Desplazamos 00000001	8 posiciones a 100000000 (noveno bit) que equivale a 256
	rawBits_ = roundToInt(floatingPoint * scale); // Es lo mismo que desplazar 8 bits a la izquierda
}

// DESTRUCTOR

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

// MEMBER FUNCTIONS

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return(rawBits_);
}

void	Fixed::setRawBits(const int raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	rawBits_ = raw;
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

Fixed& Fixed::min(Fixed& n1, Fixed& n2)
{
	if (n1.rawBits_ < n2.rawBits_)
		return (n1);
	return (n2);
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2)
{
	if (n1.rawBits_ < n2.rawBits_)
		return (n1);
	return (n2);
}

Fixed& Fixed::max(Fixed& n1, Fixed& n2)
{
	if (n1.rawBits_ > n2.rawBits_)
		return (n1);
	return (n2);
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2)
{
	if (n1.rawBits_ > n2.rawBits_)
		return (n1);
	return (n2);
}

// ASSIGNMENT OPERATOR

Fixed& Fixed::operator=(const	Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits_ = other.rawBits_; // Podemos acceder directamente al atributo privado de otro objeto de la misma clase. En ex00 usábamos el getter para clavar el print pero ambas soluciones son equivalentes
	return(*this);
}

//COMPARISON OPERATORS

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->rawBits_ == other.rawBits_);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->rawBits_ != other.rawBits_);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->rawBits_ > other.rawBits_);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->rawBits_ >= other.rawBits_);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->rawBits_ < other.rawBits_);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->rawBits_ <= other.rawBits_);
}

// ARITHMETIC OPERATORS

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	result.rawBits_ = this->rawBits_ + other.rawBits_;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	result.rawBits_ = this->rawBits_ - other.rawBits_;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed		result;
	long long	intermediate; // definimos un tipo lo suficientemente grande para evitar desbordamiento
	intermediate = static_cast<long long>(this->rawBits_) * other.rawBits_;
	intermediate >>= fractionalBits_; // como ambos factores anteriores estaban escalados 8bits (256^2), tenemos que desescalar una vez
	result.rawBits_ = static_cast<int>(intermediate); // ahora guardamos el dato
	return (result); // y lo devolvemos
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed		result;
	long long	intermediate;
	intermediate = static_cast<long long>(this->rawBits_) << fractionalBits_; // escalamos porque, si no, al hacer la división directamente, cancelamos la escala de ambos números
	intermediate /= other.rawBits_;
	result.rawBits_ = static_cast<int>(intermediate);
	return (result);
}

// (IN/DE)CREMENT OPERATORS

Fixed& Fixed::operator++(void)
{
	this->rawBits_++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	result(*this); // guardamos el valor presente en una copia para operar. Será lo que retornemos
	this->rawBits_++; // incrementamos el valor para después de la operación
	return (result); //devolvemos el valor previo al incremento para hacer la operación que toque
}

Fixed& Fixed::operator--(void)
{
	this->rawBits_--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	result(*this); // guardamos el valor presente en una copia para operar. Será lo que retornemos
	this->rawBits_--; // decrementamos el valor para después de la operación
	return (result); //devolvemos el valor previo al decremento para hacer la operación que toque
}

// INSERTION OPERATOR (NON-MEMBER FUNCTION)

std::ostream&	operator<<(std::ostream& os, const Fixed& toStream)
{
	os << toStream.toFloat();
	return (os);
}
