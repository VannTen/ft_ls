/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:20:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/12 18:13:53 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_dir_interface.h"
#include "file_defs.h"
#include "long_format.h"
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
	char			*error_string;

	index = 0;
	ft_strcpy(param->parent_path, ".");
	while (first_arg[index] != NULL)
	{
		errno = 0;
		file = param->ft_get_file(first_arg[index], param->parent_path, 1);
		if (file == NULL)
		{
			ft_asprintf(&error_string, "%s: %s: %s\n",
					first_arg[-1], first_arg[index], strerror(errno));
			btree_add(param->error_tree, error_string);
			param->has_error = TRUE;
		}
		else
		{
			if (is_dir(file))
				btree_add(sort_repos, file);
			else
			{
				file->fields = check_fields(file, param->temp_fields);
				btree_add(sort_reg_files, file);
			}
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

static int	f_strcmp(const void *str1, const void *str2)
{
	return (ft_strcmp(str1, str2));
}

static void f_print_error_cli(void *error_string)
{
	ft_putstr(error_string);
}

int	main(int argc, const char **argv)
{
	char		path[PATH_MAX];
	t_ls_param	*params;
	t_btree		*file_cli;
	t_btree		*repo_cli;
	t_fields		fields;

	params = settle_param(argc, argv);
	params->parent_path = path;
	if (params->options_number == USAGE_ERROR)
		return (EXIT_FAILURE);
	params->put_dir_name_before = argc - params->options_number > 1;
	if (argc > params->options_number)
	{
		params->error_tree = btree_create(f_strcmp);
		file_cli = btree_create(params->ft_comp);
		repo_cli = btree_create(params->ft_comp);
		init_fields(&fields);
		params->temp_fields = &fields;
		sort_cmd_line(argv + params->options_number, file_cli, repo_cli,
				params);
		params->is_first = btree_count(file_cli) == 0;
		btree_iter_in_order(params->error_tree, f_print_error_cli);
		params->ft_loop_through(file_cli, params->ft_print_entry);
		params->ft_loop_through_2(repo_cli, list_dirs, params);
	}
	else
	{
		ft_strcpy(path, ".");
		list_dir(path, ft_strlen("."), params);
	}
	return (params->has_error ? EXIT_FAILURE : EXIT_SUCCESS);
}
