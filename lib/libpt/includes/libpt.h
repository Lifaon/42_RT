/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:05:06 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 18:07:45 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPT_H
# define LIBPT_H

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef struct		s_ptfl
{
	float	x;
	float	y;
}					t_ptfl;

typedef struct		s_ptdb
{
	double	x;
	double	y;
}					t_ptdb;

typedef struct		s_vector
{
	int		x;
	int		y;
	int		z;
}					t_vector;

t_point				pt_bc(t_point crd, char operand, int nb);
t_point				pt_op(t_point crd1, char operand, t_point crd2);
t_point				pt_set(int x, int y);
t_point				pt_yplus(t_point src, int ymin, int ymax);
t_point				pt_ypluseg(t_point src, int ymin, int ymax);
void				ft_putcrd(t_point crd);
void				pt_swap(t_point *pt1, t_point *pt2);
t_ptfl				ptfl_op(t_ptfl crd1, char operand, t_ptfl crd2);
t_ptfl				ptfl_bc(t_ptfl crd, char operand, float nb);
t_ptfl				ptfl_set(float x, float y);
t_ptfl				ptfl_yplus(t_ptfl src, t_ptfl incr, float ymin,
		float ymax);
t_ptfl				ptfl_ypluseg(t_ptfl src, t_ptfl incr, float ymin,
		float ymax);
void				ptfl_swap(t_ptfl *pt1, t_ptfl *pt2);
t_ptdb				ptdb_op(t_ptdb crd1, char operand, t_ptdb crd2);
t_ptdb				ptdb_bc(t_ptdb crd, char operand, double nb);
t_ptdb				ptdb_set(double x, double y);
void				vec_swap(t_vector *pt1, t_vector *pt2);
t_vector			vec_bc(t_vector crd, char operand, int nb);
t_vector			vec_set(int x, int y, int z);
t_vector			vec_op(t_vector crd1, char operand, t_vector crd2);

#endif
