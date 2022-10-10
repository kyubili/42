/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:12 by imorina           #+#    #+#             */
/*   Updated: 2022/08/02 16:29:37 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_bucket
{
	int	*nb;
	int	current_size;
}	t_bucket;

typedef struct s_stacks
{
	int				max_size;
	int				sorted_size;
	t_bucket		*stack_a;
	t_bucket		*stack_b;
}	t_stacks;

// main functions
int				ft_printf(const char *input, ...);
void			init_struct(t_stacks *all, int size);
void			init_stacks(t_stacks *all);
void			indexation(t_stacks *all, int *tmp);
int				ft_satoi(const char *str, t_stacks *all);
char			*ft_strdup(const char *s1);
int				count_words(char const *s, char c);
int				ft_isdigit(int c);
char			*ft_substr(const char *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			**ft_split(char const *s, char c);

//errors
void			handle_error(void *str, t_stacks *all);
int				is_args_double(t_stacks *all);
int				is_args_sorted(t_stacks *all);
//int		is_args_nb(char **argv);

//free functions
void			free_all(t_stacks *all);

//commands
void			swap(t_bucket *n);
void			sa(t_stacks *all);
void			sb(t_stacks *all);
void			ss(t_stacks *all);

//rotate
void			rotate(t_bucket *n);
void			ra(t_stacks *all);
void			rb(t_stacks *all);
void			rr(t_stacks *all);

//reverse rotate
void			reverse_rotate(t_bucket *n);
void			rra(t_stacks *all);
void			rrb(t_stacks *all);
void			rrr(t_stacks *all);

//pa & pb
void			push(t_bucket *a, t_bucket *b);
void			pa(t_stacks *all);
void			pb(t_stacks *all);

//sorting
void			sort_3_elem(t_stacks *all);
void			sort_5_elem(t_stacks *all);
void			radix_sort(t_stacks *all, int max_bits);

//test sort
void			test_sort(t_stacks *all);
int				find_max(t_stacks *all);
void			selection_sort(t_stacks *all);

//simple sort
void			simple_sort(t_stacks *all);
void			selection_sort2(t_stacks *all);
unsigned int	find_max_i(t_stacks *all);

#endif
