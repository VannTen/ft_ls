/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 20:01:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/07 20:06:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_defs.h"

void	dir_entry_destroy(void **direntry)
{
	*(struct dirent**)direntry = NULL;
}

void	stat_entry_destroy(void **s_file)
{
	struct s_file	*file;

	file = *s_file;
	ft_bzero(file, sizeof(struct s_file));
	free(file);
	*s_file = NULL;
}
