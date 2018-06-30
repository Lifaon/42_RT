/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_funar_key_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:42:41 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/19 18:10:06 by mlantonn         ###   ########.fr       */
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
	int				i;

	i = 0;
	*size = 12;
	tab = (t_funar_keyb*)malloc(sizeof(t_funar_keyb) * *size);
	tab[i++] = add_one(GDK_KEY_i, &rotate_up);
	tab[i++] = add_one(GDK_KEY_j, &rotate_left);
	tab[i++] = add_one(GDK_KEY_k, &rotate_down);
	tab[i++] = add_one(GDK_KEY_l, &rotate_right);
	tab[i++] = add_one(GDK_KEY_w, &translate_w);
	tab[i++] = add_one(GDK_KEY_a, &translate_a);
	tab[i++] = add_one(GDK_KEY_s, &translate_s);
	tab[i++] = add_one(GDK_KEY_d, &translate_d);
	tab[i++] = add_one(GDK_KEY_q, &translate_q);
	tab[i++] = add_one(GDK_KEY_e, &translate_e);
	tab[i++] = add_one(GDK_KEY_p, &pixelate);
	tab[i++] = add_one(GDK_KEY_o, &anti_alias);
	return (tab);
}
