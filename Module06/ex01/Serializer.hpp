/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 00:52:21 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/11/18 14:18:15 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_HPP
#define Serializer_HPP

#include <cstdint>
#include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();
};

#endif