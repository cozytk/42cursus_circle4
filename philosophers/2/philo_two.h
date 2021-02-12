#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <semaphore.h>
# include <stdio.h>

# define TAKEN_FORK	0
# define EATING		1
# define SLEEPING	2
# define THINKING	3
# define DEAD		4

typedef struct		s_table
{
	int				num_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				num_eat;

	unsigned long	base_time;
	int				eat;
	int				dead;

	sem_t			*enter;
	sem_t			*write_msg;
}					t_table;

typedef struct		s_philo
{
	int				nbr;
	int				eat;
	unsigned long	last_eat;
	pthread_t		tid;
}					t_philo;

t_table		table;
t_philo		*philos;

void				*philo_act(void *philo);
void				*philo_monitor(void *philo);
void				init_sem(void);
void				clear_sem(void);
void				init_philos(void);
void				less_error_sleep(unsigned long itime);
void				init_table(void);

char				*ft_itoa(int n);
char				*get_name(int i);

int					ft_atoi(char *str);
int					ft_strlen(char *s);
int					parse(char **argv);
int					msg(t_philo *philo, int msg, unsigned long current_time);
int					eat(t_philo *philo);

unsigned long		get_time(void);

#endif
