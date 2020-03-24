##
## EPITECH PROJECT, 2020
## cpp_rush3_2019
## File description:
## Makefile
##

.PHONY : all clean fclean re sign

SRC				=			./Module/Module.cpp\
							./Module/MemoryModule.cpp\
							./Module/CPUModule.cpp\
							./Module/HeapModule.cpp\
							./Module/InfoModule.cpp\
							./Module/TextualModule.cpp\
							./Module/NetworkModule.cpp\
							./info/cpu/getFile.cpp\
							./info/cpu/getStat.cpp\
							./info/config/applyConfig.cpp\
							./info/heap/getHeap.cpp\
							./info/mem/getMem.cpp\
							./info/network/getNetworkStats.cpp\
							./info/sysinfo/sysinfo.cpp\
							./info/sysinfo/usr_host_name.cpp\
							./info/time/getTime.cpp\
							./list_fs/list_fs.cpp\
							./front/GWindow.cpp\

MAIN			=			main.cpp\

NAME			=			MyGKrellm

OBJ				=			$(MAIN:.cpp=.o) $(SRC:.cpp=.o)

LIBS			=			-lsfml-graphics -lsfml-window -lsfml-system -lX11 -lXext -lncurses 

CXXFLAGS		=			-Wall -Wextra -I./info/config -I./info -I./ -g3

CPPFLAGS		=			$(CXXFLAGS) $(LIBS)

CC				=			g++

all : $(NAME) sign

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

sign :
	@echo -e "\e[1m\e[32mcpp_rush3_2019:\e[0m"
	@echo -e "\tnaoufel.berrada@epitech.eu"
	@echo -e "\tcyril.de-lajudie@epitech.eu"
	@echo -e "\tjonas.pfuff@epitech.eu"
	@echo -e "\tpaul.cochet@epitech.eu"./Module/CPUModule.cpp
