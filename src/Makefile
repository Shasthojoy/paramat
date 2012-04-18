include ../Makefile.rules

all: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${BINTEST}

%.o:
	${CC} ${FLAGS} -c $(@:.o=.c)

clean:
	rm -fR *.o *.a *.so .*.swp

distclean: clean

