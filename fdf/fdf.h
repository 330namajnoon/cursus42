/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simajnoo <simajnoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:13:39 by simajnoo          #+#    #+#             */
/*   Updated: 2023/11/26 18:24:50 by simajnoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

#define M_PI 3.14159265358979323846

typedef struct {
    float x;
    float y;
    float z;
} t_point3d;

typedef struct {
    t_point3d start;
    t_point3d end;
} t_line;

typedef struct {
    void *mlx_ptr;
    void *win_ptr;
    t_line  lines[12];
    t_point3d rotation_point;
    float rotation_x;
    float rotation_y;
    float rotation_z;
} t_env;

#endif
