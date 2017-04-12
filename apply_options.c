/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:53:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/12 18:55:58 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parameters_defs.h"

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
}
