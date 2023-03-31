/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:18:53 by mmuesser          #+#    #+#             */
/*   Updated: 2023/03/31 17:44:49 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	verif_op(char **list_op)
{
	int	i;

	i = 0;
	while (list_op[i])
	{
		if (ft_strcmp(list_op[i], "sa") == 0)
			i++;
		else if (ft_strcmp(list_op[i], "sb") == 0)
			i++;
		else if (ft_strcmp(list_op[i], "pa") == 0)
			i++;
		else if (ft_strcmp(list_op[i], "pb") == 0)
			i++;
		else if (ft_strcmp(list_op[i], "ra") == 0)
			i++;
		else if (ft_strcmp(list_op[i], "rb") == 0)
			i++;
		else if (ft_strcmp(list_op[i], "rr") == 0)
			i++;
		else if (ft_strcmp(list_op[i], "rra") == 0)
			i++;
		else if (ft_strcmp(list_op[i], "rrb") == 0)
			i++;
		else if (ft_strcmp(list_op[i], "rrr") == 0)
			i++;
		else
			return (1);
	}
	return (0);
}

char	*ft_read(void)
{
	int		i;
	char	buffer[2];
	char	*str;

	str = NULL;
	i = 1;
	while (i != 0)
	{
		i = read(0, buffer, 1);
		if (i == -1)
		{
			if (str)
				free(str);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	**create_list_op(void)
{
	char	*str;
	char	**list_op;

	str = ft_read();
	if (!str)
	{
		write(1, "Error 3\n", 8);
		return (NULL);
	}
	list_op = ft_split(str, '\n');
	if (verif_op(list_op) == 1)
	{
		free(str);
		free_list_op(list_op);
		write(1, "Error 4\n", 8);
		return (NULL);
	}
	free(str);
	return (list_op);
}
