static int		construct_phase_3(t_wid_data *wid_d, t_obj *obj)
{
	return (create_object_texture_ui(wid_d, obj));
}

int				construct_phase_2(t_wid_data *wid_d, t_obj *obj)
{
	GtkSizeGroup	*group;
	t_vec			vec;
	GtkWidget		*check_b;

	if (!(make_label_and_scale(wid_d, "Alpha", obj->alpha , obj)))
		return (0);
	wid_d->pos.y = 0;
	wid_d->f = &change_obj_focus;
	if (!(check_b = new_check_button(wid_d, "DOF Focus", g_ui->gp_dof_focus)))
		return (0);
	gtk_size_group_add_widget(g_ui->gp_dof_focus, check_b);
	wid_d->pos.y = 2;
	wid_d->entry_f = change_obj_r;
	if (!(make_label_and_entry(wid_d, "Radius", obj->r, obj)))
		return (0);
	wid_d->pos.x += 1;
	wid_d->pos = pt_set(5, 0);
	wid_d->f = &change_obj_pos;
	set_wid_data_scale(wid_d, 10, ptdb_set(-30000, 30000));
	if (!(add_vector_choose(wid_d, "position", obj->pos)))
		return (0);
	wid_d->f = &change_obj_angle;
	wid_d->pos = pt_set(5, 2);
	set_wid_data_scale(wid_d, 10, ptdb_set(-180, 180));
	if (!(group = add_vector_choose(wid_d, "angle rotation", obj->angle)))
		return (0);
	return (construct_phase_3(wid_d, obj));
}