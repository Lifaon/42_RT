/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:49:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/28 23:42:24 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	print_parsed_data(t_data data)
{
	for (int i = 0; i < 1; i++)
	{
		printf("CAM nb : %d;\n", i + 1);
		printf("pos = %f, %f, %f\n", \
			data.cams[i].pos.x, data.cams[i].pos.y, data.cams[i].pos.z);
		printf("dir = %f, %f, %f\n", \
			data.cams[i].dir.x, data.cams[i].dir.y, data.cams[i].dir.z);
		printf("fov = %f\n\n", data.cams[i].fov);
	}
	for (int i = 0; i < data.nb_lights; i++)
	{
		printf("LIGHT nb : %d;\n", i + 1);
		printf("is_para = %d\n", data.lights[i].is_para);
		printf("color = %u, %u, %u, %u\n", data.lights[i].color.argb.r, \
			data.lights[i].color.argb.g, data.lights[i].color.argb.b, data.lights[i].color.argb.a);
		printf("r = %f\n", data.lights[i].r);
		printf("pos = %f, %f, %f\n", \
			data.lights[i].pos.x, data.lights[i].pos.y, data.lights[i].pos.z);
		printf("dir = %f, %f, %f\n\n", \
			data.lights[i].dir.x, data.lights[i].dir.y, data.lights[i].dir.z);
	}
	for (int i = 0; i < data.nb_objects; i++)
	{
		printf("OBJECT nb : %d;\n", i + 1);
		printf("r = %f\n", data.objs[i].r);
		printf("spec = %f\n", data.objs[i].spec);
		printf("color = %u, %u, %u, %u\n", data.objs[i].color.argb.r, \
			data.objs[i].color.argb.g, data.objs[i].color.argb.b, data.objs[i].color.argb.a);
		printf("pos = %f, %f, %f\n", \
			data.objs[i].pos.x, data.objs[i].pos.y, data.objs[i].pos.z);
		printf("dir = %f, %f, %f\n", \
			data.objs[i].dir.x, data.objs[i].dir.y, data.objs[i].dir.z);
		printf("normal = %f, %f, %f\n\n", \
			data.objs[i].normal.x, data.objs[i].normal.y, data.objs[i].normal.z);
	}
}

char	*pouic(char *str, double n, char *dst)
{
	str = strcpy_db(str, n);
	str[0] = '\0';
	ft_putendl(dst);
	str[0] = '&';
	return (str);
}

void	tests_strcpy()
{
	char		*str;
	char		*dst;

	str = ft_strnew(100);
	dst = str;
	str = pouic(str, -440, dst);
	str = pouic(str, 7300, dst);
	str = pouic(str, 550.12, dst);
	str = pouic(str, 337, dst);
	str[0] = '\0';
	ft_putendl(dst);
}

int		main(int ac, char **av)
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		ft_putstr("SDL_Init error :");
		ft_putendl(SDL_GetError());
		return (0);
	}
	g_data = data_init(ac, av);
	gtk_init(&ac, &av);
	if (create_ui() == 0)
		return (0);
	draw_image(g_data);
	tests_strcpy();
	//print_parsed_data(data);*/
	//ft_event(g_data);
	return (0);
}
