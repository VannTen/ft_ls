/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:40:12 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 18:24:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_tools_interface.h"
#include "parameters_defs.h"
#include "libft.h"
#include <sys/errno.h>
#include <stdio.h>
#include <stddef.h>

void	set_file_path(t_ls_param *param, size_t path_len, const char *file_name)
{
	if (param->path_len_max < path_len + 1 + ft_strlen(file_name))
		resize_parent_path(param);
	if (path_len != 0)
	{
		param->parent_path[path_len] = '/';
		path_len++;
	}
	ft_strcpy(param->parent_path + path_len, file_name);
}

void	restore_path(t_ls_param *param, size_t path_len)
{
	ft_strclr(param->parent_path + path_len);
}

void	resize_parent_path(t_ls_param *param)
{
	char *new_path;

	if (param->path_len_max * 2 > param->path_len_max)
	{
		errno = 0;
		new_path = malloc(sizeof(char) * (param->path_len_max * 2 + 1));
		if (new_path == NULL)
		{
			perror(param->prog_name);
			exit(EXIT_FAILURE);
		}
		else
		{
			ft_strcpy(new_path, param->parent_path);
			ft_strdel(&param->parent_path);
			param->parent_path = new_path;
			param->path_len_max = param->path_len_max * 2;
		}
	}
}
