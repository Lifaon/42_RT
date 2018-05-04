/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:49:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/04 13:08:43 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		mouse_actions(int key, int x, int y, t_data *data)
{
	return (0);
}

int		key_actions(int key, t_data *data)
{
	if (key == K_ESC)
		exit_all(data);
	return (0);
}

int		main(int ac, char **av)
{
	t_data	data;
	t_obj	*objs;
	t_ray	light;

	//data_init(&data);
	////	là j'initialise les objets : sphère et plan, et la lumière de manière
	////	dégueulasse
	//objs = (t_obj *)malloc(sizeof(t_obj) * 2);
	//objs[0].r = 200;
	//objs[0].c.x = 0;
	//objs[0].c.y = 0;
	//objs[0].c.z = 1300;
	//objs[0].oc = vec_substract(data.ray.o, objs[0].c);
	//objs[0].intersect = intersect_sphere;
	//objs[0].get_normal = get_sphere_normal;
	//objs[1].c.x = 0;
	//objs[1].c.y = 0;
	//objs[1].c.z = 1300;
	//objs[1].norm.x = 0;
	//objs[1].norm.y = -1;
	//objs[1].norm.z = 0.1;
	//objs[1].norm = vec_normalize(objs[1].norm);
	//objs[1].oc = vec_substract(data.ray.o, objs[1].c);
	//objs[1].intersect = intersect_plane;
	//objs[1].get_normal = get_plane_normal;
	//light.o.x = -400;
	//light.o.y = 150;
	//light.o.z = 900;
	//draw_image(&data, objs, light);
	//mlx_mouse_hook(data.mlx.win, mouse_actions, &data);
	//mlx_hook(data.mlx.win, 2, 3, key_actions, &data);
	//mlx_hook(data.mlx.win, 17, 0, exit_all, &data);
	//return (mlx_loop(data.mlx.mlx));
	if (ac > 1)
		parse(&data, av[1]);
	else
		ft_putendl("patate");
	printf("pos : %f / %f / %f\n", \
		data.cams[0].pos.x, data.cams[0].pos.y, data.cams[0].pos.z);
	printf("pos : %f / %f / %f\n", \
		data.cams[0].dir.x, data.cams[0].dir.y, data.cams[0].dir.z);
	printf("fov : %f\n\n", data.cams[0].fov);
	printf("pos : %f / %f / %f\n", \
		data.cams[1].pos.x, data.cams[1].pos.y, data.cams[1].pos.z);
	printf("pos : %f / %f / %f\n", \
		data.cams[1].dir.x, data.cams[1].dir.y, data.cams[1].dir.z);
	printf("fov : %f\n", data.cams[1].fov);
	return (0);
}
