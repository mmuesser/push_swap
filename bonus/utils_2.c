/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:23:53 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/31 18:42:51 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

static char	*ft_rep(const char *str, char c, int i)
{
	int		lenght;
	int		j;
	char	*tmp;

	lenght = 0;
	j = 0;
	while (str[i + lenght] != c && str[i + lenght])
		lenght++;
	tmp = (char *) malloc(sizeof(char) * (lenght + 1));
	if (!tmp)
		return (NULL);
	while (str[i] != c && str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

static char	**ft_create_str(const char *str, char c, char **dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
		{
			dest[j] = ft_rep(str, c, i);
			if (!dest[j])
			{
				free_all(dest);
				return (NULL);
			}
		}
		j++;
		while (str[i] != c && str[i])
			i++;
	}
	return (dest);
}

static size_t	nb_chaines(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

char	**ft_split(char *str, char c)
{
	size_t	i;
	char	**dest;

	if (!str)
		return (NULL);
	i = nb_chaines(str, c);
	dest = NULL;
	dest = (char **) malloc(sizeof(char *) * (i + 1));
	if (!dest)
		return (NULL);
	dest = ft_create_str(str, c, dest);
	if (!dest)
		return (NULL);
	dest[i] = NULL;
	return (dest);
}
