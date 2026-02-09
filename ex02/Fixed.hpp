/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:41:35 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/02/08 20:15:10 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					rawBits_;
		static const int	fractionalBits_ = 8; // es la potencia de 2 a la que elevamos, es decir, 2^8 (equivale a 256 en decimal)
		
		static int			roundToInt(const float& floatingPoint);

	public:
		//CONSTRUCTORS & DESTRUCTOR
		Fixed();
		Fixed(const Fixed& other); // recibe otro objeto Fixed que promete no modificar. La referencia es necesaria para eivar bucle infinito
		Fixed(const int integer);
		Fixed(const float floatingPoint);
		~Fixed();

		//MEMBER FUNCTIONS
		int					getRawBits(void) const;
		void				setRawBits(const int raw);

		int					toInt(void) const;
		float				toFloat(void) const;

		static Fixed&		min(Fixed& n1, Fixed& n2);
		static const Fixed&	min(const Fixed& n1, const Fixed& n2);
		static Fixed&		max(Fixed& n1, Fixed& n2);
		static const Fixed&	max(const Fixed& n1, const Fixed& n2);

		// ASSIGNMENT OPERATOR
		Fixed& 	operator=(const	Fixed& other); // Devuelve una referencia al objeto de la izquierda (al que está asignando). Se llama cuando el objeto ya existe y le asignas otro

		//COMPARISON OPERATORS
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;

		// ARITHMETIC OPERATORS
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other)const;
		Fixed	operator*(const Fixed& other)const;
		Fixed	operator/(const Fixed& other)const;

		// (IN/DE)CREMENT OPERATORS
		Fixed&	operator++(void); // PreIncremento
		Fixed	operator++(int); // PostIncremento | Devuelve Fixed por valor porque queremos incrementar *this pero devolver una copia previa al incremento para operar
		Fixed&	operator--(void); // PreDecremento
		Fixed	operator--(int); // PostDecremento | Devuelve Fixed por valor porque queremos decrementar *this pero devolver una copia previa al decremento para operar
};

std::ostream&	operator<<(std::ostream& os, const Fixed& toStream); // toma dos parámetros por no ser función miembro

#endif