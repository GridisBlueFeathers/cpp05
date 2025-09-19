# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 13:57:20 by svereten          #+#    #+#              #
#    Updated: 2025/09/19 14:29:44 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
################################################################################
#
#	Project variables
#
################################################################################
NAME = ex00

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -MMD -MP -g

INCLUDE = -I./include

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

FILES = Bureaucrat \

OBJS = ${FILES:%=${OBJ_DIR}/%.o}
DEPS = ${FILES:%=${OBJ_DIR}/%.d}

TESTS = ${FILES:%=${BIN_DIR}/%}
TEST_OBJS = ${FILES:%=${OBJ_DIR}/test%.o}

OBJ_DIRS = ${sort ${dir ${OBJS}}}
TEST_DIRS = ${sort ${dir ${TESTS}}}

DEBUG = 0

################################################################################
#
#	Project targets
#
################################################################################

all: ${NAME}

${NAME}: ${OBJS} ${OBJ_DIR}/main.o
	${CXX} ${CXXFLAGS} $^ -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp | ${OBJ_DIRS}
	bear --append -- ${CXX} ${CXXFLAGS} ${INCLUDE} -D DEBUG=${DEBUG} -c $< -o $@

${OBJ_DIRS}:
	mkdir -p $@

-include ${DEPS}

################################################################################
#
#	Tests targets
#
################################################################################

tests: bin/allTests
	valgrind ./bin/allTests

bin/allTests: ${TEST_OBJS} ${OBJS}
	mkdir -p bin
	${CXX} ${CXXFLAGS} $^ -o bin/allTests \
		-I/usr/src/googletest/googletest/include \
		-L/usr/lib \
		-lgtest -lgtest_main -pthread

test%: ${BIN_DIR}/%
	valgrind ./$<

${BIN_DIR}/%: ${OBJ_DIR}/test%.o ${OBJS} | ${TEST_DIRS}
	${CXX} ${CXXFLAGS} $^ -o $@ \
		-I/usr/src/googletest/googletest/include \
		-L/usr/lib \
		-lgtest -lgtest_main -pthread

${TEST_DIRS}:
	mkdir -p $@

################################################################################
#
#	Project rules
#
################################################################################

clean:
	rm -rf ${OBJ_DIR}
	rm -rf compile_commands.json
	rm -rf .cache

fclean: clean
	rm -rf ${NAME}
	rm -rf ${BIN_DIR}

re: fclean all

run: ${NAME}
	./${NAME} ${ARGS}

valgrind: ${NAME}
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		./${NAME} ${ARGS}

.PHONY: all clean fclean re run valgrind
