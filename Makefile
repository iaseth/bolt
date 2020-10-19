AMP = @

CC = ${AMP}gcc
INCLUDE_FLAG = -Iinclude
LINK_FLAG = -lexample

RM = ${AMP}rm -f

CBENCH_NAMES = 
CBENCH_NAMES += cbench_common

CBENCH_OBJ_NAMES = ${addsuffix .o, ${CBENCH_NAMES}}
CBENCH_OBJS = ${addprefix build/, ${CBENCH_OBJ_NAMES}}

MAIN_SRC = src/main.c
MAIN_OBJ = build/main.o

BIN = build/cbench

default: ${BIN}

debug:
	${eval AMP := }

${MAIN_OBJ}: ${MAIN_SRC}
	${CC} -c $< -o $@ ${INCLUDE_FLAG}

${CBENCH_OBJS}: build/%.o: src/%.c include/%.h
	${CC} -c $< -o $@ ${INCLUDE_FLAG}

${BIN}: ${MAIN_OBJ} ${CBENCH_OBJS}
	${CC} $^ -o $@



BOLT_APP_NAMES = 
BOLT_APP_NAMES += example

BOLT_APP_EXE_PATHS = ${addsuffix .app, ${BOLT_APP_NAMES}}
BOLT_APP_EXES = ${addprefix build/app/, ${BOLT_APP_EXE_PATHS}}

${BOLT_APP_EXES}: build/app/%.app: app/%.c
	${CC} $^ -o $@ ${INCLUDE_FLAG}

app: ${BOLT_APP_EXES}
redo-app: clean-app app
clean-app:
	${RM} ${BOLT_APP_EXES}



redo: clean default

run: ${BIN}
	@${BIN}

move:
	sudo cp ${BIN} /usr/bin

clean:
	${RM} ${BIN}
	${RM} ${MAIN_OBJ}
	${RM} ${CBENCH_OBJS}


