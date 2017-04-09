/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:20:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/09 15:28:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mode_and_perms_interface.h"
#include "list_dir_interface.h"
#include "file_interface.h"
#include "options_interface.h"
#include "parameters_defs.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/ucred.h>
#include <sys/syslimits.h>
#include <sys/errno.h>
#include <stdio.h>

void	sort_cmd_line(const char **first_arg,
		t_btree *sort_reg_files, t_btree *sort_repos)
{
	int			index;
	struct stat	file;

	index = 0;
	while (first_arg[index] != NULL)
	{
		errno = 0;
		if (lstat(first_arg[index], &file) == -1)
			perror(first_arg[index]);
		else
		{
			if (file_type(file.st_mode) == 'd')
				btree_add(sort_repos, first_arg[index]);
			else
				btree_add(sort_reg_files, first_arg[index]);
		}
		index++;
	}
}

static int comp_str(const void *str1, const void *str2)
{
	return (ft_strcmp((const char*)str1, (const char*)str2));
}

static void print_str(void *str1)
{
	ft_putendl(str1);
}

int	main(int argc, const char **argv)
{
	char		path[PATH_MAX];
	t_ls_param	*params;
	t_btree		*file_cli;
	t_btree		*repo_cli;

	params = settle_param(argc, argv);
	file_cli = btree_create(&comp_str);
	repo_cli = btree_create(&comp_str);
	if (argc > params->options_number)
	{
		sort_cmd_line(argv + params->options_number, file_cli, repo_cli);
		btree_iter_in_order(file_cli, &print_str);
		btree_iter_in_order(repo_cli, &print_str);
	}
	else
	{
		ft_strcpy(path, ".");
		list_dir(path, ft_strlen("."), params);
	}
	return (0);
}
