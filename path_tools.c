/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:40:12 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/05 18:08:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_file_path(char *parent_path, int path_len, const char *file_name)
{
	parent_path[path_len] = '/';
	path_len++;
	ft_strcpy(parent_path + path_len, file_name);
}

void	restore_path(char *parent_path, int path_len)
{
	ft_strclr(parent_path + path_len);
}
