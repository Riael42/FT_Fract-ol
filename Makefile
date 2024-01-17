SRCDIR = srcs/
OBJDIR = obj/
SRC	= complex_math.c      ft_init_data.c    ft_menu_two.c ft_render_clubnova.c ft_strncmp.c \
complex_math_two.c  ft_init_events.c  ft_move_zoom.c     ft_render_julia.c  ft_track_julia.c \
events.c            ft_init_fract.c   ft_pixie.c         ft_render_mandel.c   main.c \
ft_atod.c           ft_julia.c        ft_print_usage.c   ft_render_mathsishard.c \
ft_clubnova.c       ft_mandelbrot.c   ft_putstr.c        ft_report_incident.c \
ft_color.c          ft_mathsishard.c  ft_refresh_frac.c  ft_skip_spaces.c \
ft_fractol.c        ft_menu.c         ft_remap.c         ft_start_menu.c \
ft_ship.c			ft_render_ship.c

all :mlx

MLX_PATH    = mlx-linux
MLX_TAR     = minilibx-linux.tgz
LINKS       += -lXext -lX11
INC         += -Ilinux
INC         += -I${MLX_PATH}
LINKS       += -L./${MLX_PATH} -lmlx


FLAGS = -O3 -Werror -Wextra -Wall
HEADER = includes
NAME = fractol

OBJ = $(SRC:%.c=$(OBJDIR)%.o)


bonus: FLAGS:=$(filter-out -O3,$(FLAGS))
bonus: fclean $(NAME)

$(BONUS): $(OBJ)
	@cc $(BONUSFLAGS) $(OBJ) ${LINKS} -o $(NAME)
	@echo "Launch the program with: ./$(NAME) mathsishard"

mlx :
	make getmlxlib
	make -C mlx-linux
	make ${NAME}


$(NAME): $(OBJ)
	@cc $(FLAGS) $(OBJ) ${LINKS} -o $(NAME)
	@echo "Launch the program with: ./$(NAME) mandelbrot"

$(OBJDIR)%.o:$(SRCDIR)%.c
	@mkdir -p $(dir $@)
	@cc -c $< -o $@ $(FLAGS) -I $(HEADER)

getmlxlib:
	@if [ ! -d ${MLX_PATH} ]; then \
	@echo "Downloading miniLibX..."; \
	wget https://cdn.intra.42.fr/document/document/21645/${MLX_TAR}; \
	mkdir ${MLX_PATH}; \
	tar -xzf minilibx-linux.tgz --strip-components=1 -C ${MLX_PATH}; \
	rm minilibx-linux.tgz; \
	fi

clean:
	@if [ "$(wildcard $(OBJ))" ]; then\
		echo "Cleaning objects";\
		/bin/rm -f $(OBJ);\
	else\
		echo "Nothing to be done for clean.";\
	fi
	@if [ -d "$(OBJDIR)" ]; then\
		echo "Cleaning object directory";\
		/bin/rm -rf $(OBJDIR);\
	else\
		echo "Missing object directory.";\
	fi

fclean: clean
	@if [ "$(wildcard $(addprefix ./, $(NAME)))" ]; then\
		echo "Cleaning executable";\
		/bin/rm -f $(NAME);\
	else\
		echo "Missing executabe";\
	fi

re: fclean all

.PHONY: all clean fclean re
