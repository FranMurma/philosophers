# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 17:40:49 by frmurcia          #+#    #+#              #
#    Updated: 2023/05/23 16:53:06 by frmurcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN			:= \033[32m
ORANGE 			:= \033[1;31m
NC				:= \033[m

NAME = philosophers_bonus

SRC_DIR = src_bonus

OBJ_DIR = obj_bonus

INC_DIR = inc_bonus

# la variable _I  indica que ahi esta el directorio de inclusion (header) y lo buscara
INC = -I $(INC_DIR)

# OBJ. Lista de archivos objeto (archivos .o) que se generan a partir de los archivos 
# de origen (archivos .c) del proyecto. addprefix anade el prefijo OBJ_DIR (o sea obj)
# $(SRC:.c=.o) significa que cogera cada elemento de SRC que sea .c y hara un .o
# Hara una lista de archivos objeto a partir de la lista de origen 
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# DEP. Contiene el archivo de dependencias correspondientte a cada arvhico. 
# Agregara ademas el sufijo .d; extrae el nombre base de los archivos objeto (sin .o) 
# En el proceso de compilación, un archivo de origen (con extensión .c) se compila para 
# generar un archivo objeto (con extensión .o). Durante este proceso, el compilador 
# GCC (GNU Compiler Collection) también puede generar un archivo de dependencias que 
# contiene información sobre las dependencias del archivo de origen.
DEP	= $(addsuffix .d, $(basename $(OBJ)))

CC = gcc 
SRC = main_bonus.c philo_auxil_bonus.c philo_check_bonus.c philo_init_bonus.c philo_start_bonus.c philo_routine_bonus.c philo_print_bonus.c philo_time_bonus.c philo_close_bonus.c

# la opcion -MMD de gcc le indica que genere los archivos de dependencias como archivos 
# separados, además de los archivos objeto, y que los guarde con la extensión .d
# -lpthread garantiza que la biblioteca de hilos POSIX esté enlazada con el programa.
FLAGS = -Werror -Wall -Wextra -MMD $(INC)
PTHREADS = -lpthread
RM_DIR = rm -rf
MKDIR = mkdir -p

# PRIMERA linea: se deben buscar los archivos fuente (%.c) en el directorio $(SRC_DIR) 
# y los archivos objeto (%.o) en el directorio $(OBJ_DIR). La dependencia de compilación 
# para un archivo objeto es su archivo fuente correspondiente (%.c) y el archivo Makefile
# SEGUNDA linea: La @ hace que no se vea en pantalla. crea el directorio correspondiente 
# para el archivo objeto ($@), utilizando la variable $(dir $@) que obtiene el directorio 
# que contiene el archivo objetivo ($@). $@ se utiliza para referirse al archivo objeto. 
# Por ejemplo, si el archivo objetivo es obj/philo_main.o, entonces $(dir $@) obtendrá obj/
# TERCERA linea: compila con gcc, opciones -c (crea un archivo objeto en vez de n ejecutable)
# -o especifica el archivo de salida. $@ es una variable automática que contiene la ruta 
#  y el nombre del archivo objeto que se está compilando actualmente.
#  En general, esta regla de compilación le dice a Make que tome un archivo fuente *.c de 
#  la carpeta src, lo compile utilizando las banderas de compilación definidas en CFLAGS, 
#  y produzca un archivo objeto *.o en la carpeta obj.
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c Makefile
	@$(MKDIR) $(dir $@)
	@gcc -c -g $(CFLAGS) -o $@ $<
	@echo "$(ORANGE) Compiling...$(NC)"

#  all: $(NAME) indica que el objetivo predeterminado del archivo Makefile es construir 
#  el archivo ejecutable del programa.
all: $(NAME)

# -include $(DEP) indica a Make que incluya los archivos de dependencia generados en el 
#  proceso de compilación en el Makefile. La opción -include indica que si los archivos 
#  especificados no existen, Make ignorará el error y continuará con la compilación.
-include $(DEP)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(PTHREADS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

clean :
	@$(RM) $(OBJ)
	@$(RM_DIR) $(OBJ_DIR)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

fclean : clean
	@$(RM) $(NAME)

re : fclean all

norm:
	@norminette philosophers_bonus | sh ../norminette.sh

PHONY: clean re fclean all
