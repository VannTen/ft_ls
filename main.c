/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:20:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/10 14:56:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_dir_interface.h"
#include "file_defs.h"
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
		t_btree *sort_reg_files, t_btree *sort_repos, t_ls_param *param)
{
	int				index;
	struct s_file	*file;
	char			path[PATH_MAX];

	index = 0;
	ft_strcpy(path, ".");
	while (first_arg[index] != NULL)
	{
		file = param->ft_get_file(first_arg[index], NULL, 0);
		if (file == NULL)
		{
			perror(first_arg[index]);
			break ;
		}
		else
		{
			if (is_dir(file))
				btree_add(sort_repos, file);
			else
				btree_add(sort_reg_files, file);
		}
		index++;
	}
}

static void	list_dirs(void *v_dir_file, void *v_param)
{
	struct s_file	*dir_file;
	t_ls_param		*param;
	char			path[PATH_MAX];

	dir_file = v_dir_file;
	param = v_param;
	ft_strcpy(path, dir_file->dir_entry);
	list_dir(path, ft_strlen(dir_file->dir_entry), param);
}
int	main(int argc, const char **argv)
{
	char		path[PATH_MAX];
	t_ls_param	*params;
	t_btree		*file_cli;
	t_btree		*repo_cli;

	params = settle_param(argc, argv);
	file_cli = btree_create(params->ft_comp);
	repo_cli = btree_create(params->ft_comp);
	if (argc > params->options_number)
	{
		sort_cmd_line(argv + params->options_number, file_cli, repo_cli,
				params);
		params->ft_loop_through(file_cli, params->ft_print_entry);
		params->ft_loop_through_2(repo_cli, list_dirs, params);
	}
	else
	{
		ft_strcpy(path, ".");
		list_dir(path, ft_strlen("."), params);
	}
	return (0);
}
