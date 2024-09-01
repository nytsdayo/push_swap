#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				value;
	int				index;
	int				order;
}					t_list;

typedef struct s_cycle
{
	t_list			*top;
	t_list			*bottom;
}					t_cycle;
typedef struct s_stack
{
	t_cycle			cycle;
	int				count_value;
}					t_stack;

typedef struct s_pair_stack
{
	t_stack			stack_a;
	t_stack			stack_b;
}					t_pair_stack;

// /srcs/
void				arg_check(int argc, char **argv);
void				set_stack(t_pair_stack *pair_stack, int argc, char **argv);
// /utils/
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isdigit(int c);
int					ft_isspace(char c);
int					ft_issimbol(char c);
void				*ft_memset(void *s, int c, size_t n);
// error_exit.c
void				error_exit(void);

// /srcs/sort/
void				case_values_three(t_pair_stack *pair_stack);
void				case_values_four(t_pair_stack *pair_stack);

// /srcs/sort_method/
// swap
void				sa(t_pair_stack *pair_stack);
void				sb(t_pair_stack *pair_stack);
// push
void				pa(t_pair_stack *pair_stack);
void				pb(t_pair_stack *pair_stack);

// rotate
void				ra(t_pair_stack *pair_stack);
void				rb(t_pair_stack *pair_stack);
void				rra(t_pair_stack *pair_stack);
void				rrb(t_pair_stack *pair_stack);
#endif