AMP = @

GCC = ${AMP}gcc
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
	${GCC} -c $< -o $@ ${INCLUDE_FLAG}

${CBENCH_OBJS}: build/%.o: src/%.c include/%.h
	${GCC} -c $< -o $@ ${INCLUDE_FLAG}

${BIN}: ${MAIN_OBJ} ${CBENCH_OBJS}
	${GCC} $^ -o $@ ${LINK_FLAG}

redo: clean default

run: ${BIN}
	@${BIN}

move:
	sudo cp ${BIN} /usr/bin

clean:
	${RM} ${BIN}
	${RM} ${MAIN_OBJ}
	${RM} ${CBENCH_OBJS}


