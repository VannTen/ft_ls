/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:20:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/31 17:47:21 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_dir_interface.h"
#include "dir_entry_interface.h"
#include "libft.h"
#include "options_interface.h"
#include <sys/types.h>
#include <sys/dir.h>

int main(void)
{
	DIR *dir = opendir(".");
	list_dir(dir, &comp_alpha);

	return (0);
}
