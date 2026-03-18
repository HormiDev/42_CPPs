/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 03:30:38 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/18 03:18:58 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_2_0_H
#define HARL_2_0_H

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class Harl {
public:
    Harl();
    void complain(std::string level);
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif