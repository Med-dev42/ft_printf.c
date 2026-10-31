NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar crs

HEADERS = ft_printf.h 
BONUS_HEADERS = ft_printf_bonus.h
SRC = ft_printf.c ft_print_char.c ft_print_str.c ft_print_point.c \
		ft_putnbrs.c ft_unsigned_nbr.c ft_print_sign.c \
		ft_puthexa.c
OBJ = $(SRC:.c=.o)
BONUS_SRC = ft_printf_bonus.c ft_putchar_bonus.c ft_putstr_bonus.c \
		ft_putnbr_bonus.c ft_puthex_bonus.c ft_print_ptr_bonus.c \
		ft_putunsigned_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): .mandatory

.mandatory: $(OBJ)
	rm -f $(NAME) .bonus 
	$(AR) $(NAME) $(OBJ)
	@touch .mandatory

bonus: .bonus

.bonus: $(BONUS_OBJ)
	rm -f $(NAME) .mandatory
	$(AR) $(NAME) $(BONUS_OBJ)
	@touch .bonus

$(OBJ): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ): %.o: %.c $(BONUS_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) .mandatory .bonus

re: fclean all

.PHONY: all bonus clean fclean re
