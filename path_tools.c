/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:40:12 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/12 18:48:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_file_path(char *parent_path, int path_len, const char *file_name)
{
	if (path_len != 0)
	{
		parent_path[path_len] = '/';
		path_len++;
	}
	ft_strcpy(parent_path + path_len, file_name);
}

void	restore_path(char *parent_path, int path_len)
{
	ft_strclr(parent_path + path_len);
}
