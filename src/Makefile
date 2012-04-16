include ../Makefile.rules

all: ${OBJ}
	${CC} ${FLAGS} -o ${BINTEST}
	mv ${BINTEST} ..

%.o:
	${CC} ${FLAGS} -c $(@:.o=.c)

clean:
	rm -fR *.o *.a *.so .*.swp

distclean: clean

