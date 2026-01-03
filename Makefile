NAME = push_swap

SRC = main.c init.c error.c utils.c disorder.c stck_utils.c solver_utils.c \
	swap.c push.c rotate.c reverse_rotate.c simple.c complex.c complex_utils.c \
	stats.c stats_utils.c flag.c ft_printf.c medium.c medium_utils.c \
	ft_split.c args.c

OBJDIR = .obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
DEP = $(OBJ:%.o=%.d)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./ -MMD -MP

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
