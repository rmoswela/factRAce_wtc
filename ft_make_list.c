/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 05:15:22 by rmoswela          #+#    #+#             */
/*   Updated: 2016/12/03 15:57:02 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

/*assign values to the members of a struct*/
t_list		*new_list(mpz_t *nbrptr)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	mpz_init(ret->nbr);
	mpz_set(ret->nbr, *nbrptr);
	ret->next = NULL;
	return (ret);
}

/*insert every new node at the beginning of the list*/
void		ft_push_front(t_list **head, mpz_t *nbrptr)
{
	t_list	*new_elem;

	new_elem = new_list(nbrptr);
	new_elem->next = *head;
	*head = new_elem;
}
