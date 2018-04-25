/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 22:38:45 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/13 22:58:02 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst_char(t_list *chain)
{
	t_list		*cp;

	cp = chain;
	while (cp)
	{
		ft_putendl(cp->content);
		cp = cp->next;
	}
}
