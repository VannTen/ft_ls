/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:56:24 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 18:25:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parameters_defs.h"
#include "apply_options_interface.h"
#include "file_interface.h"
#include "libft.h"

void		default_functions(t_ls_param *param)
{
	param->options[ALL_FILES] = FALSE;
	param->options[LONG_FORMAT] = FALSE;
	param->options[REVERSE_ORDER] = FALSE;
	param->options[RECURSIVE] = FALSE;
	param->options[SORT_BY_MODIF_TIME] = FALSE;
	param->ft_comp = comp_alpha_stat;
	param->ft_get_file = get_stat_dir;
	param->ft_print_entry = print_name_stat;
	param->ft_loop_through = btree_iter_in_order;
	param->ft_loop_through_2 = btree_iter_two_param_in_order;
	param->ft_subdir = add_to_sub_dirs_list_stat;
	param->ft_destroy_file = stat_entry_destroy;
	param->has_error = FALSE;
	param->is_first = TRUE;
	param->parent_path = ft_memalloc(PATH_MAX + 1);
	param->path_len_max = PATH_MAX;
}

t_ls_param	*settle_param(int arg_count, const char **arg_values)
{
	static t_ls_param	params;
	static t_bool		options[OPT_NBR];
	const t_apply_opt	apply[OPT_NBR] = {
		apply_all_files,
		apply_long_format,
		apply_reverse_order,
		apply_recursive,
		apply_sort_by_time
	};

	(void)arg_count;
	params.options = options;
	default_functions(&params);
	if (params.parent_path == NULL)
		return (NULL);
	params.options_number =
		apply_cmdline_opt(CONST_SYNOPSIS_INIT, arg_values, &params, apply);
	return (&params);
}
