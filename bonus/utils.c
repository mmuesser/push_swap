/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:25:15 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/30 20:58:15 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		dest[i] = s2[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*fill_line(char *dest, char *str, char c, int len)
{
	int	i;

	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**create_line(char **dest, char *str, char c)
{
	int	i;
	int	nb;
	int	len;

	nb = 0;
	i = 0;
	while (str[i])
	{
		len = 0;
		while (str[i] == c)
			i++;
		while (str[i + len] != c)
			len++;
		dest[nb] = fill_line(dest[nb], &str[i], c, len);
		if (!dest[nb])
		{
			// free_dest(dest);
			return (NULL);
		}
		nb++;
		i++;
	}
	return (dest);
}

int	count_line(char *str, char c)
{
	int	i;
	int	nb_line;

	nb_line = 1;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;	
		nb_line++;
		while (str[i] != c)
			i++;
	}
	return (nb_line);
}

char	**ft_split(char *str, char c)
{
	char	**dest;
	int		nb_line;

	nb_line = count_line(str, c);
	dest = (char **) malloc(sizeof(char *) * (nb_line + 1));
	if (!dest)
		return (NULL);
	dest = create_line(dest, str, c);
	if (!dest)
		return (NULL);
	dest[nb_line] = NULL;
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

void	free_list_op(char **list_op)
{
	int	i;

	i = 0;
	while (list_op[i])
	{
		free(list_op[i]);
		i++;
	}
}