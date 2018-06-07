/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_funar_key_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:42:41 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/05 17:53:44 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

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

	i = 0;
	nb_fct = 4;
	*size = nb_fct;
	tab = (t_funar_keyb*)malloc(sizeof(t_funar_keyb) * nb_fct);
	*size = nb_fct;
	tab[i++] = add_one(SDLK_i, &rotate_i);
	tab[i++] = add_one(SDLK_j, &rotate_j);
	tab[i++] = add_one(SDLK_k, &rotate_k);
	tab[i++] = add_one(SDLK_l, &rotate_l);
	//tab[i++] = add_one(SDLK_k, &rotate_z);
	return (tab);
}
