/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:56:24 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/07 20:19:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parameters_defs.h"
#include "file_interface.h"
#include "libft.h"

void	default_functions(t_ls_param *param)
{
	param->options[ALL_FILES] = FALSE;
	param->options[LONG_FORMAT] = FALSE;
	param->options[REVERSE_ORDER] = FALSE;
	param->options[RECURSIVE] = FALSE;
	param->options[SORT_BY_MODIF_TIME] = FALSE;
	param->ft_comp = comp_alpha_dir_entry;
	param->ft_get_file = get_dir_entry;
	param->ft_print_entry = print_name;
	param->ft_get_file = get_dir_entry;
	param->ft_loop_through = btree_iter_in_order;
	param->ft_loop_through_2 = btree_iter_two_param_in_order;
	param->ft_subdir = add_to_sub_dirs_list_dirent;
	param->ft_destroy_file = dir_entry_destroy;
}

void	need_stat(t_ls_param *ls_param)
{
	ls_param->ft_get_file = get_stat_dir;
	if (ls_param->ft_comp == comp_alpha_dir_entry)
		ls_param->ft_comp = comp_alpha_stat;
	if (ls_param->ft_print_entry == print_name)
		ls_param->ft_print_entry = print_name_stat;
	ls_param->ft_subdir = add_to_sub_dirs_list_stat;
	ls_param->ft_destroy_file = stat_entry_destroy;
}
void	apply_all_files(void *param)
{
	t_ls_param *ls_param;

	ls_param = param;
	ls_param->options[ALL_FILES] = TRUE;
}

void	apply_long_format(void *param)
{
	t_ls_param *ls_param;

	ls_param = param;
	ls_param->options[LONG_FORMAT] = TRUE;
	ls_param->ft_print_entry = print_long_format;
	need_stat(ls_param);
}

void	apply_reverse_order(void *param)
{
	t_ls_param *ls_param;

	ls_param = param;
	ls_param->ft_loop_through = btree_iter_in_rev_order;
	ls_param->ft_loop_through_2 = btree_iter_two_param_in_rev_order;
}

void	apply_recursive(void *param)
{
	t_ls_param *ls_param;

	ls_param = param;
	ls_param->options[RECURSIVE] = TRUE;
}

void	apply_sort_by_time(void *param)
{
	t_ls_param *ls_param;

	ls_param = param;
	ls_param->ft_comp = comp_time;
	need_stat(ls_param);
}

t_ls_param *settle_param(int arg_count, const char **arg_values)
{
	static t_ls_param	params;
	static t_bool		options[OPT_NBR];
	const t_apply_opt		apply[OPT_NBR] = {
		apply_all_files,
		apply_long_format,
		apply_reverse_order,
		apply_recursive,
		apply_sort_by_time
	};

	(void)arg_count;
	params.options = options;
	default_functions(&params);
	apply_cmdline_opt(CONST_SYNOPSIS_INIT, arg_values, &params, apply);
	return (&params);
}
