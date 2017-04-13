/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:20:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/13 19:29:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_dir_interface.h"
#include "parameters_defs.h"
#include "command_line_args_interface.h"
#include "libft.h"
#include <sys/errno.h>
#include <stdio.h>

int			main(int argc, const char **argv)
{
	t_ls_param	*params;
	t_fields	fields;

	errno = 0;
	params = settle_param(argc, argv);
	if (params == NULL)
	{
		perror(argv[0]);
		return (EXIT_FAILURE);
	}
	params->prog_name = argv[0];
	if (params->options_number == USAGE_ERROR)
		return (EXIT_FAILURE);
	params->put_dir_name_before = argc - params->options_number > 1;
	if (argc > params->options_number)
		process_cmd_line_args(argv, params, &fields);
	else
	{
		ft_strcpy(params->parent_path, ".");
		list_dir(ft_strlen("."), params);
	}
	ft_strdel(&params->parent_path);
	return (params->has_error ? EXIT_FAILURE : EXIT_SUCCESS);
}
