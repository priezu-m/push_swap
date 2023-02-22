# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Filename: Makefile                                                        #
#    Author:   Peru Riezu <riezumunozperu@gmail.com>                           #
#    github:   https://github.com/priezu-m                                     #
#    Licence:  GPLv3                                                           #
#    Created:  2023/02/09 13:34:08                                             #
#    Updated:  2023/02/20 17:40:00                                             #
#                                                                              #
# **************************************************************************** #

#GNU Make 3.81

################################################################################

SHELL :=			bash
CC :=				clang
CFLAGS :=			-O0 -flto -g3 -fsanitize=address,undefined,leak -Weverything
AR :=				ar
ARFLAGS :=			rcs
NORMINETTE :=		$(shell command -v norminette)

################################################################################

NAME :=				push_swap

DEP_PATH :=			./DEP
OBJ_PATH :=			./OBJ

EXCLUDE_DIRS :=		$(DEP_PATH) $(OBJ_PATH) $(LIBFT_OBJ_PATH) ./.git
EXCLUDE_FILES :=	./tags ./random.c ./a.out

HDR :=				$(shell find . \
						$(foreach PATH, $(EXCLUDE_DIRS), -path "$(PATH)" -prune -o)\
						$(foreach FILE, $(EXCLUDE_FILES), -path "$(FILE)" -prune -o)\
						-type f -and -name "*.h" -print)
HDR :=				$(HDR:./%=%)
SRC :=				$(shell find . \
						$(foreach PATH, $(EXCLUDE_DIRS), -path "$(PATH)" -prune -o)\
						$(foreach FILE, $(EXCLUDE_FILES), -path "$(FILE)" -prune -o)\
						-type f -and -name "*.c" -print)
SRC :=				$(SRC:./%=%)
OBJ :=				$(addprefix $(OBJ_PATH)/,$(SRC:%.c=%.o))
DEP :=				$(addprefix $(DEP_PATH)/,$(SRC:.c=.d))
SUB_DIR :=			$(sort $(dir $(SRC)))
SUB_DIR :=			$(SUB_DIR:.%=%)
SUB_DIR :=			$(SUB_DIR:/%=%)
NEW_DIRS :=			$(addprefix $(OBJ_PATH)/,$(SUB_DIR))
NEW_DIRS +=			$(addprefix $(DEP_PATH)/,$(SUB_DIR))
NEW_DIRS +=			$(OBJ_PATH) $(DEP_PATH) $(LIBFT_OBJ_PATH)

CURRENT_DIR :=		$(shell pwd)

-include $(DEP)

################################################################################

.DEFAULT_GOAL :=	all

$(NEW_DIRS):
	@mkdir -p $@

$(DEP_PATH)/%.d: %.c | $(NEW_DIRS)
	@rm -f $(DEP_PATH)/$@; \
		$(CC) -M $< > $@.tmp; \
		sed 's,\($*\)\.o[ :]*,$(OBJ_PATH)/\1.o $@ : ,g' < $@.tmp > $@; \
		rm -f $@.tmp

$(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $^ -o $@

.PHONY :=	clean fclean all push question_libft question_libft_bonus update_manpath h help a m b e d tags

all: $(NAME)

clean:
	@rm $(DEP) $(OBJ) $(ALL_NORM) $(NORM) &> /dev/null || true
	@rmdir -p $(NEW_DIRS) $(DEP_PATH) $(OBJ_PATH) &> /dev/null || true

fclean: clean
	@rm $(NAME) &> /dev/null || true

re: fclean
	@make all

pull:
	@git pull

push:
	@git add $(SRC) $(HDR) Makefile
	@git commit
	@git push

tags:
	ctags -R --exclude=.git
