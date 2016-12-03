/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prime_factor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 05:29:38 by rmoswela          #+#    #+#             */
/*   Updated: 2016/12/03 15:46:59 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

int			ft_strlen(char *str)
{
	int		loop;

	loop = 0;
	while (str[loop] != '\0')
		loop++;
	return (loop);
}
/*converts nbr to str of digits in base 10 and displays it*/
void		ft_print_str(mpz_t *nbr)
{
	char	*str;

	str = NULL;
	str = mpz_get_str(str, 10, *nbr);
	write (1, str, ft_strlen(str));
}

void		ft_print_decomposition(mpz_t *nbr, mpz_t *p)
{
	mpz_t	div;

	mpz_init(div);
	mpz_cdiv_q(div, *nbr, *p);
	ft_print_str(nbr);//number that was divided
	write (1, "=", 1);
	ft_print_str(p);//number that divided
	write (1, "*", 1);
	ft_print_str(&div);//the quotient
	write (1, "\n", 1);
	mpz_clear(div);
}

int			ft_find_prime(t_list *list, mpz_t *prime)
{
	t_list	*previous;
	t_list	*temp;

	previous = list;
	temp = list;
	while (temp)
	{
		if (mpz_divisible_p(temp->nbr, *prime))
		{
			ft_print_decomposition(&(temp->nbr), prime);
			if (previous == list)
				return (0);
			else
			{
				previous->next = NULL;
				return (1);
			}
		}
		previous = temp;
		temp = temp->next;
	}
	return (1);
}
/*checks if the give value is prime number, and continues to
 * set next prime numbers larger than the previous*/
void		ft_prime_factor(t_list *list)
{
	mpz_t	prime;

	mpz_init(prime);
	mpz_set_ui(prime, 2);
	while (1)
	{
		if (ft_find_prime(list, &prime) == 0)
			return ;
		mpz_nextprime(prime, prime);
	}
	mpz_clear(prime);
}
