/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 20:01:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 19:48:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_defs.h"
#include "libft.h"

void	stat_entry_destroy(void **s_file)
{
	struct s_file	*file;

	file = *s_file;
	if (file->path_len != 0)
		ft_strdel((char**)&file->dir_entry);
	ft_bzero(file, sizeof(struct s_file));
	free(file);
	*s_file = NULL;
}
