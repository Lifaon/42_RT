/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:43:21 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/29 17:12:34 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static uint32_t		*change_sdl_to_gtk(uint32_t *gtk, uint32_t *sdl,
		t_point size)
{
	t_point				crd;
	int					i;
	t_color				color;

	i = 0;
	crd = pt_set(0, 0);
	while (crd.x < size.x)
	{
		color.c = sdl[i];
		gtk[i] = get_color_gtk(255, color.argb.r, color.argb.g,
				color.argb.b);
		crd = pt_ypluseg(crd, 0, size.y);
		i++;
	}
	return (gtk);
}

static void			export_png(char *name)
{
	static GdkPixbuf	*pixbuf = NULL;
	static uint32_t		*pxl = NULL;
	t_point				size;
	GError				*error;
	char				*path;

	error = NULL;
	size = *g_data->win->size;
	if (!pixbuf)
	{
		pixbuf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8, size.x, size.y);
		pxl = (uint32_t*)gdk_pixbuf_get_pixels(pixbuf);
	}
	pxl = change_sdl_to_gtk(pxl, g_data->tex->tab_pxl, size);
	gdk_pixbuf_save(pixbuf, name, "png", &error, NULL);
	if (error && error->message)
		ft_putstr(error->message);
}

void				click_export(GtkWidget *widget, gpointer data)
{
	char		*path;
	char		*name;
	GtkWidget	*select;
	gint		response;

	if (!widget && !data)
		return ;
	select = gtk_file_chooser_dialog_new("name the export image",
			GTK_WINDOW(g_data->win_gtk), GTK_FILE_CHOOSER_ACTION_SAVE,
			"export to png", GTK_RESPONSE_ACCEPT, NULL);
	gtk_window_set_modal(GTK_WINDOW(select), TRUE);
	response = gtk_dialog_run(GTK_DIALOG(select));
	if (response == GTK_RESPONSE_ACCEPT)
	{
		path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(select));
		name = ft_strjoin(path, ".png");
		export_png(name);
		ft_strdel(&path);
		ft_strdel(&name);
	}
	gtk_widget_destroy(select);
}
