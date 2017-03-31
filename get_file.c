/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:12:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/31 18:49:51 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/dir.h>

void	*get_dir_entry(DIR *dir)
{
	return (readdir(dir));
}

void	do_something_with_it(void *entry)
{
	struct dirent *file;

	file = entry;
	ft_putendl(file->d_name);
}

int		comp_alpha(void *entry_1, void *entry_2)
{
	struct dirent *file_1;
	struct dirent *file_2;

	file_1 = entry_1;
	file_2 = entry_2;
	if (ft_strcmp(file_1->d_name, file_2->d_name) > 0)
		return (1);
	else
		return (-1);
}
