NAME = fractol

SRCS = srcs/av_checker.c\
		srcs/complex.c\
		srcs/error.c\
		srcs/julia.c\
		srcs/main.c\
		srcs/mandelbrot.c\
		srcs/utils.c\
		srcs/mandelbrot_hook.c\
		srcs/julia_hook.c\
		srcs/rgb.c

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

CC = cc

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all