/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_limited_object_ui.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:49:06 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/28 20:39:49 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

int		create_limited_object_ui(t_wid_data *wid_d, t_obj *obj)
{
	gboolean		is_limited;
	GtkSizeGroup	*group;
	t_point			crd;
	GtkWidget		*wid;
	GtkWidget		*sw;

	is_limited = obj->limited == -1 ? FALSE : TRUE;
	if (!(l_new(wid_d, "limited object")))
		return (0);
	crd = pt_set(wid_d->pos.x, 1);
	wid_d->pos.y = 2;
	new_cb_limited(wid_d, group, obj);
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	wid_d->f = &change_obj_min;
	if (!(group = add_vector_choose_no_scale(wid_d, "min", obj->min, NULL)))
		return (0);
	wid_d->pos = pt_set(crd.x + 1, 2);
	wid_d->f = &change_obj_max;
	if (!(group = add_vector_choose(wid_d, "max", obj->min, group)))
		return (0);
	wid_d->f = NULL;
	/*is_limited = g_data->objs[index].limited == 1 ? TRUE : FALSE
	if (!(switch_new(wid_d, wid_d, TRUE, &switch_obj)))
		return (0);
	wid_d->pos = pt_set(3, 2);
	wid_d->f = change_obj_alpha;
	if (!(make_label_and_scale(wid_d, "Alpha", g_data->objs[index].r * 100)))
		return (0);
	wid_d->pos = pt_set(5, 0);
	wid_d->f = &change_obj_angle;
	vec = g_data->objs[index].angle;
	if (!(group = add_vector_choose(wid_d, "angle rotation", vec)))
		return (0);
	wid_d->pos = pt_set(5, 2);
	vec = g_data->objs[index].pos;
	wid_d->f = &change_obj_pos;
	set_wid_data_scale(wid_d, 10, ptdb_set(-30000, 30000));
	if (!(add_vector_choose(wid_d, "position", vec)))
		return (0);
	wid_d->f = change_obj_r;
	if (!(make_label_and_entry(wid_d, "Radius", g_data->objs[index].r)))
		return (create_limited_object_ui(wid_d, index))*/
	wid_d->pos = crd;
	g_data->ui->is_active = 1;
	if (!(sw = switch_new(wid_d, group, is_limited, &switch_obj_limited)))
		return (0);
	if (is_limited == FALSE)
		switch_obj_limited(sw, FALSE, group);
	g_data->ui->is_active = 0;
	return (1);
}
