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

#ifndef UTYLS_H
# define UTYLS_H

#include "../fdf.h"

int	rotate(int axes, int angle, t_scene_data *scene);
int move(int axes, int force, t_scene_data *scene);

#endif
