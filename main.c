/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:38:10 by qdufour           #+#    #+#             */
/*   Updated: 2022/02/22 18:38:11 by qdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, int sortie)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(sortie, &str[i], 1);
		i++;
	}
}

void	ft_display_file(char *nom)
{
	char	c;
	int		fd;
	
	fd = open(nom, O_RDONLY, 0);
	if (fd == -1)
		ft_putstr("Cannot read file.\n", 2);
	else
	{
		while (read(fd, &c, 1) != '\0')
		{
			ft_putchar(c);
		}
	}
	close(fd);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_putstr("File name missing.\n", 2);
	else if (ac > 2)
		ft_putstr("Too many arguments.\n", 2);
	else
		ft_display_file(av[1]);
	return (0);
}
