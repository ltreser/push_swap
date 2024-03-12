/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:25:49 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/12 09:57:45 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_all	t_all;
typedef struct s_node	t_node;
typedef struct s_deque	t_deque;
typedef struct s_row	t_row;
typedef struct s_tiny	t_tiny;

struct					s_tiny
{
	long				*moves;
	long				ideal_moves;
	t_deque				*copy_a;
	t_deque				*copy_b;
};

struct					s_row
{
	int					count;
	int					start;
	int					end;
	int					*array;
	int					*lis;
	int					*len;
	int					*prev_index;
	int					*sorted_copy;
};

struct					s_node
{
	long int			value;
	int					sleep;
	int					has_swap;
	int					swap_below;
	int					index;
	int					push_price;
	int					lower_half;
	int					target_pos;
	t_node				*next;
	t_node				*prev;
};

struct					s_deque
{
	int					size;
	t_node				*head;
	t_node				*tail;
	int					size_total;
	int					min_index;
	int					min;
	int					max_index;
	int					max;
	int					cheapest_index;
	int					cheapest_todo;
	int					average;
	int					sleep_count;
};

struct					s_all
{
	t_deque				*a;
	t_deque				*b;
	t_tiny				*tiny;
	t_row				*lis;
	int					size_total;
	char				*instructions;
	int					instruction_count;
	char				*new_ins;
	int					i;
	double				divider;
};

long					ft_atol(const char *av);
int						ft_isdigit(int c);
char					ra(t_deque *a, int times, char *print_flag);
char					rb(t_deque *b, int times, char *print_flag);
char					rr(t_deque *a, t_deque *b, int times, char *print_flag);
char					rra(t_deque *a, int times, char *print_flag);
char					rrb(t_deque *b, int times, char *print_flag);
char					rrr(t_deque *a, t_deque *b, int times,
							char *print_flag);
char					sa(t_deque *a, char *print_flag);
char					sb(t_deque *b, char *print_flag);
char					ss(t_deque *a, t_deque *b, char *print_flag);
char					pa(t_deque *b, t_deque *a, char *print_flag);
char					pb(t_deque *a, t_deque *b, char *print_flag);
void					init_p(t_deque *a, t_deque *b);
void					print_moves(char *print_flag);
int						stack_sorted(t_deque *a);
void					append_node(t_deque *a, int value);
void					create_stack(t_all *all, char **av, int ac);
int						argument_error(int i, char **av, t_all *all, int j);
int						*bubble_sort(int *copy, int size, int i, int j);
void					normalize_by_index(int size, t_all *all);
int						duplicate_found(int *array, int n, int size);
void					parse_and_index(char **av, t_all *all);
t_deque					*copy_deque(t_deque *deque);
void					free_deque(t_deque *deque);
void					calculate_moves(long nbr, long i, int level_depth,
							t_tiny *tiny);
void					tiny_ops(t_deque *a, t_deque *b, long move, int print);
long					check_level(t_all *all, long width, long depth);
int						tiny_sort(t_all *all);
void					exec_tiny(t_deque *a, t_deque *b, long moves);
void					free_all(t_all *all);
void					init(t_all *all);
void					push_last(t_deque *b, t_deque *a);
void					push_swap(t_all *all);
void					sleep_test(t_all *all, double divider); // DELETE IT!
void					put_to_sleep(t_deque *a, t_row *lis_a, int lis_len);
void					init_lis(t_row *lis, int size);
int						find_last(t_row *lis, int i, int j, int size);
int						get_lis(t_row *lis, int i);
int						find_lis(t_row *lis, int size_a, int i, int j);
void					get_ideal_lis(t_all *all);
void					rotate_array(int *array, int size, int x);
void					put_index(t_deque *deque);
void					back_to_a(t_all *all);
void					put_index(t_deque *deque);
void					set_target_position(t_all *all);
int						find_price(t_all *all, t_node *travel, int *dir,
							int mid_a);
void					calculate_price(t_all *all);
void					push_to_a(t_all *all);
void					mixed_placement(t_all *all, t_node *travel);
void					high_placement(t_all *all, t_node *travel);
void					low_placement(t_all *all, t_node *travel);
void					calculate_average(t_deque *deque, int lis_size);
void					decode_and_print(t_all *all, int i);
void					check_best_moves(t_all *all);
void					post_optimizer(t_all *all);
void					optimizer_extension(char *ins, int i);
void					divider_bf(t_all *all, int i);

#endif
