/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:19:50 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 19:57:55 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_args_interface.h"
#include "parameters_defs.h"
#include "file_defs.h"
#include "list_dir_interface.h"
#include <sys/errno.h>

static void	f_print_error_cli(void *error_string)
{
	ft_putstr(error_string);
}

static void	push_error(t_ls_param *param, const char *arg)
{
	char			*error_string;

	ft_asprintf(&error_string, "%s: %s: %s\n",
			param->prog_name, arg, strerror(errno));
	btree_add(param->error_tree, error_string);
	param->has_error = TRUE;
}

static void	sort_cmd_line(const char **first_arg,
		t_btree *sort_reg_files, t_btree *sort_repos, t_ls_param *param)
{
	int				index;
	struct s_file	*file;

	index = 0;
	param->parent_path[0] = '\0';
	while (first_arg[index] != NULL)
	{
		errno = 0;
		file = param->ft_get_file(first_arg[index], param, 0);
		if (file == NULL)
			push_error(param, first_arg[index]);
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

	dir_file = v_dir_file;
	param = v_param;
	ft_strcpy(param->parent_path, dir_file->dir_entry);
	list_dir(ft_strlen(dir_file->dir_entry), param);
	ft_strclr(param->parent_path);
}

void		process_cmd_line_args(const char **argv,
		t_ls_param *params, t_fields *fields)
{
	t_btree		*file_cli;
	t_btree		*repo_cli;

	params->error_tree = btree_create(f_strcmp);
	file_cli = btree_create(params->ft_comp);
	repo_cli = btree_create(params->ft_comp);
	init_fields(fields);
	params->temp_fields = fields;
	sort_cmd_line(argv + params->options_number, file_cli, repo_cli,
			params);
	params->is_first = btree_count(file_cli) == 0;
	btree_iter_in_order(params->error_tree, f_print_error_cli);
	params->ft_loop_through(file_cli, params->ft_print_entry);
	params->ft_loop_through_2(repo_cli, list_dirs, params);
	btree_destroy(&file_cli, params->ft_destroy_file);
	btree_destroy(&repo_cli, params->ft_destroy_file);
	btree_destroy(&params->error_tree, ft_gen_strdel);
}
