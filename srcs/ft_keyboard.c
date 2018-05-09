/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:43:45 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/03 19:39:56 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdlib.h>

static int		do_event(int key, t_data *data)
{
	static t_funar_keyb		*tab_fct = NULL;
	static int				size_tab;
	int						i;

	if (key == 400)
		return (1);
	if (tab_fct == NULL)
		tab_fct = fill_funar_key_event(&size_tab);
	i = 0;
	if (key == SDLK_ESCAPE)
	{
		if (tab_fct)
			free(tab_fct);
		return (-1);
	}
	while (i < size_tab)
	{
		if (tab_fct[i].key == key)
		{
			tab_fct[i].f(data);
			return (1);
		}
		i++;
	}
	return (0);
}

int				ft_keyboard(int key, t_data *data)
{
	t_win		*win;
	int			ret;

	win = data->win;
	if (!data || !win)
		exit_all(data);
	ret = 0;
	ft_putstr("key = ");
	ft_putnbr(key);
	ft_putchar('\n');
	if ((ret = do_event(key, data)) == 1) // if do_event retourn 1 il faut retracer l'iamge
		ft_putstr("do_event = 1");
		//draw_image(data, data->objs, data->light);
	if (ret == -1)
		exit_all(data);
	return (0);
}