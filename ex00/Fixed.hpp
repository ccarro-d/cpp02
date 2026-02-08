/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:41:35 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/02/07 21:08:13 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int					rawBits_;
		static const int	fractionalBits_ = 8;
	public:
		Fixed();
		Fixed(const Fixed& other); // recibe otro objeto Fixed que promete no modificar. La referencia es necesaria para eivar bucle infinito
		Fixed& operator=(const	Fixed& other); // Devuelve una referencia al objeto de la izquierda (al que está asignando). Se llama cuando el objeto ya existe y le asignas otro
		~Fixed();
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif