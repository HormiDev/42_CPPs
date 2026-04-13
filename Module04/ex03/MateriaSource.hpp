/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 03:39:54 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/13 16:19:47 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
public:
    					MateriaSource();
						MateriaSource(const MateriaSource &other);
	MateriaSource		&operator=(const MateriaSource &other);
    					~MateriaSource();

    void				learnMateria(AMateria*);
    AMateria			*createMateria(std::string const & type);
	friend std::ostream	&operator<<(std::ostream &out, const MateriaSource &materia);

private:
    AMateria	*materia[4];
};

#endif