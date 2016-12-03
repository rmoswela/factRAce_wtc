/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 04:06:10 by rmoswela          #+#    #+#             */
/*   Updated: 2016/12/03 15:35:56 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTRACE_H
# define FACTRACE_H

# include "gmp.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	mpz_t			nbr;
	struct s_list	*next;
}					t_list;

void				ft_prime_factor(t_list *list);
void				ft_push_front(t_list **head, mpz_t *nbrptr);

#endif
