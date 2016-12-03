/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 04:18:41 by rmoswela          #+#    #+#             */
/*   Updated: 2016/12/03 15:44:43 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

int			main(int argc, char **argv)
{
	t_list	*list_mpz;
	char	c;
	mpz_t	rop;
	mpz_t	op;

	(void)argc;
	(void)argv;
	list_mpz = NULL;
	mpz_inits(rop, op, NULL);
	while (read(0, &c, 1) > 0)
	{
		if (c == '\n')
		{
			ft_push_front(&list_mpz, &rop);
			mpz_set_ui(rop, 0);
		}
		else
		{
			mpz_mul_ui(rop, rop, 10);
			mpz_add_ui(rop, rop, c - '0');
		}
	}
	mpz_clears(rop, op, NULL);
	ft_prime_factor(list_mpz);
	return (0);
}
