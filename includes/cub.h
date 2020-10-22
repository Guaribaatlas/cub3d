#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include "../Get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"


#define X 0
#define Y 1
#define R 1
#define NO 2
#define SO 4
#define WE 8
#define EA 16
#define S 32
#define F 64
#define C 128
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3
#define SPRITE 4
#define TEXTURES 5

typedef struct s_text
{
	void 	*data;
	int 	*txt;
	int		height;
	int 	width;
	int 	bpp;
	int 	sl;
	int 	endian;
}				t_text;
typedef struct s_sprite
{
	double 	*x;
	double 	*y;
	int 	*order;
	double	*spritedist;
	int 	text;
};

typedef struct s_cub
{
	int		ext;
	double 	wallx;
	int 	textured;
	t_text 	text[5];
	double 	cam;
	int		map[2];
	double	raydir[2];
	double	pos[2];
	double	dir[2];
	double	plane[2];
	double  sidedist[2];
	double	ddist[2];
	int 	step[2];
	int		hit;
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	void	*mlx;
	void	*win;
	int		exit;
	double	movespeed;
	double	rotspeed;
	int 	bpp;
	int 	texy;
	int 	texx;
	double 	texpos;
	int 	color;
	double 	stp;
	int 	*data;
	void 	*frame;
	int 	sl;
	int 	endian;
}				t_cub;

typedef	struct	s_infos
{
	char 	*r;
	int		re[2];
	char 	*path[5];
	char 	*f;
	int		fl[3];
	char 	*c;
	int		ceil[3];
	char 	**map;
	int		raw;
	int		player;
	int		check;
	int 	numsprite;
}				t_infos;

typedef struct s_hook
{
	t_infos	*infos;
	t_cub	*cub;
	int 	up;
	int 	down;
	int 	right;
	int		left;
}				t_hook;


void	ft_initialize(t_infos *infos);
int		ft_get_cub3d(t_infos *infos);
char	*ft_strdupstr(char *s1, t_infos *infos, int type);
int		ft_allocmap(char *line, t_infos *infos);
int		ft_check_map(char **map, t_infos *infos);
int		ft_atoi_pt(char **str);
int		parser_info(t_infos *infos);
void	ft_cub3d(t_infos *infos);
void	ft_resize(t_infos *infos);
void	get_dir(char pos, t_cub *cub);
void	ft_calsidedist(t_cub *cub);
void	ft_dda(t_cub *cub, t_infos *infos);
void	ft_perpwall_drawstart_end(t_cub *cub, t_infos *infos);
void	ft_draw(t_cub *cub, int x, t_infos *infos);
void	ft_initcub(t_infos *infos, t_cub *cub);
void	initwhile(t_cub *cub, int x, t_infos *infos);
void	ft_rc(t_hook *k_struct);
int		key_hook(int keycode, t_hook *k);
void 	ft_get_texture(t_cub *cub, t_infos *infos);
char	*skip(char *s1);
t_text 	select_text(t_cub *cub);
