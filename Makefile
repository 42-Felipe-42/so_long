NAME        =   so_long
BONUS       =   so_long_bonus

CC          =   cc
FLAG        =   -Wall -Wextra -Werror -g3 

LIBFT_PATH  =   .libft
LIBFT_FILE  =   libft.a
MLX_FILE    =   libmlx.a

LIBFT_LIB   =   $(LIBFT_PATH)/$(LIBFT_FILE)
MLX_FLAGS   =   -lX11 -lXext -fPIE
MLX_PATH    =   ./.minilibx-linux
MLX_LIB     =   $(MLX_PATH)/$(MLX_FILE)
MLX_EX      =   $(MLX_LIB) $(MLX_FLAGS)

C_FILE      =   main.c \
                check_error.c \
                read_map.c \
                parse_map.c \
                define_img.c \
                movement_perso.c \
				init_assets.c \

BONUS_FILE  =   bonus/main.c \
               	bonus/parsing.c \
				bonus/game.c \
				bonus/init_map.c \
				bonus/movement_perso_bonus.c \
				bonus/npc_move.c \
				bonus/utils_game.c \
				bonus/check_error_bonus.c \
				bonus/free_game.c \
				init_assets.c \
				read_map.c \
				check_error.c \
                parse_map.c \
                define_img.c \
                movement_perso.c \

OBJS        =   $(C_FILE:.c=.o)
OBJS_BONUS  =   $(BONUS_FILE:.c=.o)

.c.o:
	@printf "\r\033[K[so_long] \033[0;32mBuilding : $<\033[0m"
	@$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

bonus: $(BONUS)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(MLX_LIB):
	@printf "\r\033[K[mlx] \033[0;32mLinking...\033[0m"
	@make -sC $(MLX_PATH)

$(BONUS): $(LIBFT_LIB) $(MLX_LIB) $(OBJS_BONUS)
	@printf "\r\033[K[so_long] \033[0;32mLinking...\033[0m"
	@$(CC) $(OBJS_BONUS) $(LIBFT_LIB) $(MLX_EX) -o $(BONUS) -lm
	@printf "\r\033[K[so_long_bonus] \033[0;32mDone!\033[0m\n"
	
$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	@printf "\r\033[K[so_long] \033[0;32mLinking...\033[0m"
	@$(CC) $(OBJS) $(LIBFT_LIB) $(MLX_EX) -o $(NAME) -lm
	@printf "\r\033[K[so_long] \033[0;32mDone!\033[0m\n"

clean:
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJS)
	@printf "[so_long] \033[1;31mCleaned .o!\033[0m\n"

clean_bonus:
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJS_BONUS) $(OBJS)
	@printf "[so_long] \033[1;31mCleaned .o bonus!\033[0m\n"

fclean: clean clean_bonus
	@rm -f $(NAME) $(BONUS)
	@make fclean -C $(LIBFT_PATH)
	@printf "[so_long] \033[1;31mCleaned all!\033[0m\n"

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re clean_bonus re_bonus
