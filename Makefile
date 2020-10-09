# NAME		= iikh_team1.a

# SRCS		= main.cpp \
# 			./srcs/iikh.cpp \
# 			./srcs/greeter.cpp \
# 			./srcs/recipe.cpp \
# 			./srcs/recipe_database.cpp \
# 			./srcs/meal.cpp \
# 			./srcs/date.cpp \
# 			./srcs/plan.cpp \
# 			./srcs/planManager.cpp

# OBJS		= $(SRCS:.cpp=.o)
# INCS		= ./includes/
# RM			= rm -f
# LIBC		= ar rc
# CC			= g++
# FLAGS		= -std=c++14

# .c.o :
# 	$(CC) $(FLAGS) -o $(SRCS) $(OBJS) -I$(INCS)

# $(NAME) : $(OBJS)
# 	$(CC) $(FLAGS) $(NAME) $(OBJS)

# all : $(NAME)

# fclean : clean

# clean :
# 	$(RM) $(OBJS)

# re : fclean all

# .PHONY: all clean fclean re .c.o


NAME			= IIKH.a

CC				= g++
AR				= ar
ARFLAGS			= rcs


FILES			= main \
				iikh \
				greeter \
				recipe \
				recipe_database \
				meal \
				date \
				plan \
				planManager

SRC_DIR 		= ./srcs/

SRCS			= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

OBJ_DIR 		= ./objs/
OBJS 			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

INC				= -I./includes/
FLAGS			= -std=c++14
RM				= rm -f

$(OBJ_DIR)%.o :	$(SRC_DIR)%.cpp
				@mkdir -p $(OBJ_DIR)
				$(CC) $(FLAGS) $(INC) -c -o $@ $<

$(NAME):		$(OBJS)
				$(AR) $(ARFLAGS) $@ $(OBJS)

all : $(NAME)

clean :
		$(RM) $(OBJS)
		$(RM) $(NAME)

 fclean : clean

 re : fclean all

 .PHONY: all clean fclean re .c.o


