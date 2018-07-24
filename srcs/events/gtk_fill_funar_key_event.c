/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_fill_funar_key_event.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:42:41 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 16:53:58 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static t_funar_keyb		add_one(int key, void (*f)(t_param*))
{
	t_funar_keyb		item;

	item.key = key;
	item.f = f;
	return (item);
}

t_funar_keyb			*fill_funar_key_event(int *size)
{
	t_funar_keyb		*tab;
	int					nb_fct;
	int					i;

	i = 0;
	nb_fct = 12;
	if (!(tab = (t_funar_keyb*)malloc(sizeof(t_funar_keyb) * nb_fct)))
		return (NULL);
	*size = nb_fct;
	tab[i++] = add_one(GDK_KEY_Up, &move_up);
	tab[i++] = add_one(GDK_KEY_Down, &move_down);
	tab[i++] = add_one(GDK_KEY_Left, &move_left);
	tab[i++] = add_one(GDK_KEY_Right, &move_right);
	tab[i++] = add_one(GDK_KEY_KP_Multiply, &iteration_max_up);
	tab[i++] = add_one(GDK_KEY_KP_Divide, &iteration_max_down);
	tab[i++] = add_one(GDK_KEY_KP_Add, &zoom_up);
	tab[i++] = add_one(GDK_KEY_KP_Subtract, &zoom_down);
	tab[i++] = add_one(GDK_KEY_f, &change_fractal);
	tab[i++] = add_one(GDK_KEY_c, &change_color);
	tab[i++] = add_one(GDK_KEY_l, &lock);
	tab[i++] = add_one(GDK_KEY_s, &ft_export);
	return (tab);
}
