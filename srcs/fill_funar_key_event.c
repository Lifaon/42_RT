/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tabf_key_event.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:42:41 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/03 19:40:29 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdlib.h>

static t_funar_keyb		add_one(int key, void (*f)(t_data*))
{
	t_funar_keyb	item;

	item.key = key;
	item.f = f;
	return (item);
}

t_funar_keyb			*fill_funar_key_event(int *size)
{
	t_funar_keyb	*tab;
	int				nb_fct;
	int				i;

	*size = 0;
	return (NULL);
	/*i = 0;
	nb_fct = 11;
	tab = (t_funar_keyb*)malloc(sizeof(t_funar_keyb) * nb_fct);
	*size = nb_fct;
	tab[i++] = add_one(SDLK_UP, &move_up);
	tab[i++] = add_one(SDLK_DOWN, &move_down);
	tab[i++] = add_one(SDLK_LEFT, &move_left);
	tab[i++] = add_one(SDLK_RIGHT, &move_right);
	tab[i++] = add_one(SDLK_KP_MULTIPLY, &iteration_max_up);
	tab[i++] = add_one(SDLK_KP_DIVIDE, &iteration_max_down);
	tab[i++] = add_one(SDLK_KP_PLUS, &zoom_up);
	tab[i++] = add_one(SDLK_KP_MINUS, &zoom_down);
	tab[i++] = add_one(SDLK_f, &change_fractal);
	tab[i++] = add_one(SDLK_c, &change_color);
	tab[i++] = add_one(SDLK_l, &lock);*/
	return (tab);
}
