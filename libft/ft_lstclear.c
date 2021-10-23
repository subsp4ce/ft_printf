/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: smiller <smiller@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/30 20:35:40 by smiller       #+#    #+#                 */
/*   Updated: 2020/05/21 12:42:49 by smiller       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*delstruc;

	temp = *lst;
	delstruc = *lst;
	if (*lst && del)
	{
		while (temp != NULL)
		{
			del(temp->content);
			delstruc = temp;
			temp = temp->next;
			free(delstruc);
		}
		*lst = NULL;
	}
}
