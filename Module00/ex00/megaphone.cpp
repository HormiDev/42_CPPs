/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:51:35 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/06/20 22:10:10 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>

void ft_str_to_upper_extended(char *str)
{
	int				i;
	unsigned char	*ustr;

	i = 0;
	ustr = (unsigned char *)str;
	while (ustr[i])
	{
		if (ustr[i] <= 127)
		{
			if (ustr[i] >= 'a' && ustr[i] <= 'z')
				ustr[i] -= 32;
		}	
		else if (ustr[i] == 195)
		{
			i++;
			if ((ustr[i] >= 160 && ustr[i] <= 182)
				|| (ustr[i] >= 184 && ustr[i] <= 190))
				ustr[i] -= 32;
			else if (ustr[i] == 191)
			{
				ustr[i - 1] = 197;
				ustr[i] = 184;
			}
		}
		else if (ustr[i] == 197)
		{
			i++;
			if (ustr[i] == 161 || ustr[i] == 147 || ustr[i] == 190)
				ustr[i]--;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int					i;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		ft_str_to_upper_extended(argv[i]);
		std::cout << argv[i];
		if (i < argc - 1)
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}
