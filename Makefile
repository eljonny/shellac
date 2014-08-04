CC= gcc
CFLAGS= -Wall -O  -g
SRCS= errorHandler.c fsh.c shellOps.c shellTUI.c
OBJS= errorHandler.o fsh.o shellOps.o shellTUI.o
PROGRAMS = shellac
MKDEP= gccmakedep

shellac: errorHandler.o fsh.o shellOps.o shellTUI.o
		${CC} ${CFLAGS} errorHandler.o fsh.o shellOps.o shellTUI.o -o shellac
all: shellac

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f ${OBJS} ${PROGRAMS}

depend:
	${MKDEP} ${CFLAGS} ${SRCS}
