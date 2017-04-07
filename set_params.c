/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:56:24 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/07 13:42:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parameters_defs.h"
#include "file_interface.h"
#include "libft.h"

t_ls_param *settle_param(int arg_count, char **arg_values)
{
	static t_ls_param	params;
	static t_bool		options[OPT_NBR];

	(void)arg_count;
	(void)arg_values;
	options[ALL_FILES] = TRUE;
	options[LONG_FORMAT] = FALSE;
	options[REVERSE_ORDER] = FALSE;
	options[RECURSIVE] = FALSE;
	options[SORT_BY_MODIF_TIME] = FALSE;
	params.options = options;
	params.ft_comp = &comp_alpha_dir_entry;
	params.ft_print_entry = do_something_with_it;
	params.ft_get_file = get_dir_entry;
	params.ft_loop_through = btree_iter_in_rev_order;
	params.ft_loop_through_2 = btree_iter_two_param_in_rev_order;
	return (&params);
}
