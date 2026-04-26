#ifndef __GAME_H
# define __GAME_H



# include <limits.h>
# include <ncurses.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

enum			e_const
{
	WIN_VALUE = 2048
};

enum e_game_state
{
    STATE_PLAYING,
    STATE_WIN_MENU,
    STATE_GAMEOVER,
    STATE_QUIT,
};


typedef struct s_cell
{
	long long	value;
	int			merged;
}				t_cell;

typedef struct s_grid
{
	int			row;
	int			column;
	int			score;
	t_cell		cell_grid[4][4];
}				t_grid;

typedef struct s_game_data
{
	int			nb_of_cell;
	int			key;
	int			cell_height;
	int			cell_width;
	int			board_height;
	int			board_width;
	int			margin;
	int			start_y;
	int			start_x;
    int         win_flag;
	int			pause_game;
	int 		current_state;
	t_grid		grid;
}				t_game_data;

void			draw_board(t_game_data *g_data);
void			calculate_dimensions(t_game_data *g_data);
void			key_hook(t_game_data *g_data);
int				ncurses_print_nbr(int nb, int x, int y);
int				count_len_number(int nb);
int				get_center_offset(int container_size, int item_size);
void			reset_merged(t_grid *grid);
int				going_left(t_grid *grid);
int				going_right(t_grid *grid);
int				going_up(t_grid *grid);
int				going_down(t_grid *grid);
int				count_zeros(t_grid grid);
int				gameover(t_grid grid);
void			add_number(t_grid *grid, int pos);
int				get_new_pos(t_grid grid);
int				check_win_cond_value(void);
void			ft_putstr_fd(int fd, char *s);
int	            is_win(t_grid grid);



int is_terminal_valid(t_game_data *g_data);



void    handle_too_small_screen();
void    handle_playing_state(t_game_data *g_data);
void  handle_gameover_state(t_game_data *g_data);
void  handle_win_state(t_game_data *g_data);


#endif