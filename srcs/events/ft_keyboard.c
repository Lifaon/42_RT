/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:53:34 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/13 17:59:38 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <stdlib.h>

static int		do_event(int key, t_data *param)
{
	static t_funar_keyb		*tab_fct = NULL;
	static int				size_tab;
	int						i;

	if (tab_fct == NULL)
		if (!(tab_fct = fill_funar_key_event(&size_tab)))
			return (0);
	i = -1;
	if (key == 2)
		return (1);
	if (key == GDK_KEY_Escape)
	{
		if (tab_fct)
			free(tab_fct);
		return (-1);
	}
	while (++i < size_tab)
	{
		if (tab_fct[i].key == key)
		{
			tab_fct[i].f(param);
			return (1);
		}
	}
	return (0);
}

gboolean		ft_keyboard(GtkWidget *widget, GdkEventKey *event, gpointer param)
{
	int					ret;
	t_data				*par;

	if (!widget && !event && !param)
		param = NULL;
	par = (t_data*)param;
	ret = 0;
	if ((ret = do_event(event->keyval, par)) == 1)
		draw_image(par);
	if (ret == -1)
		exit_all(par);
	/*if (event->keyval == 0)//SDLK_h)
		draw_image(par);*/
		//put_pixelbuf_to_widget(par->img, NULL);
	return (0);
}
