AMP = @

CC = ${AMP}gcc
CC_FLAGS = -fPIC -Wall

INCLUDE_FLAG = -Iinclude
LINK_FLAG = -lbolt

AR = ${AMP}ar
RM = ${AMP}rm -f


BOLT_SOURCE = lib/bolt.c
BOLT_HEADER = include/bolt.h
BOLT_OBJ = build/bolt.o

BOLT_STATIC_LIB = build/libbolt.a
BOLT_DYNAMIC_LIB = build/libbolt.so


MAIN_SRC = src/main.c
MAIN_OBJ = build/main.o

BIN = build/bolt


default: lib run
lib: ${BOLT_STATIC_LIB} ${BOLT_DYNAMIC_LIB}


${MAIN_OBJ}: ${MAIN_SRC}
	${CC} -c $< -o $@ ${INCLUDE_FLAG}

${BIN}: ${MAIN_OBJ} ${BOLT_OBJ}
	${CC} $^ -o $@


${BOLT_OBJ}: ${BOLT_SOURCE} ${BOLT_HEADER}
	${CC} -c ${CC_FLAGS} $< -o $@ ${INCLUDE_FLAG}

${BOLT_STATIC_LIB}: ${BOLT_OBJ}
	${AR} rcs $@ $^

${BOLT_DYNAMIC_LIB}: ${BOLT_OBJ}
	${CC} -shared $^ -o $@


debug:
	${eval AMP := }


redo: clean default

run: ${BIN}
	@${BIN}

move:
	sudo cp ${BIN} /usr/bin

clean:
	${RM} ${BIN}
	${RM} ${MAIN_OBJ}
	${RM} ${BOLT_OBJ}
	${RM} ${BOLT_STATIC_LIB}
	${RM} ${BOLT_DYNAMIC_LIB}
	${RM} ${BOLT_APP_EXES}


