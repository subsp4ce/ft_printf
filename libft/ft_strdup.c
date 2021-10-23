/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smiller <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 15:49:40 by smiller       #+#    #+#                 */
/*   Updated: 2021/04/01 16:10:20 by smiller       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		y;
	int		len;
	char	*newp;

	y = 0;
	len = ft_strlen(s1) + 1;
	newp = ft_calloc(len, sizeof(char));
	if (newp == NULL)
		return (NULL);
	else
	{
		while (s1[y])
		{
			newp[y] = s1[y];
			y++;
		}
	}
	newp[y] = '\0';
	return (newp);
}
