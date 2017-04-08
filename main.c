/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:20:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/08 16:34:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_dir_interface.h"
#include "file_interface.h"
#include "options_interface.h"
#include "parameters_interface.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/ucred.h>
#include <sys/syslimits.h>

int	main(int argc, const char **argv)
{
	char		path[PATH_MAX];
	t_ls_param	*params;

	params = settle_param(argc, argv);
	ft_strcpy(path, ".");
	list_dir(path, ft_strlen("."), params);
	while (1);
	return (0);
}
