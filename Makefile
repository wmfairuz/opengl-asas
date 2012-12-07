CC = g++
CFLAGS = -g -DGL_GLEXT_PROTOTYPES -I./include/ -I/usr/X11R6/include -I/sw/include \
			-I/usr/sww/include -I/usr/sww/pkg/Mesa/include
LDFLAGS = -L./lib/nix -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib \
		-L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lglut -lGLU -lGL -lX11 -lGLEW 
 
RM = /bin/rm -f 
 
all: mytest
mytest: main.o
	$(CC) $(CFLAGS) -o mytest main.o $(INCFLAGS) $(LDFLAGS) 
main.o: main.cpp
	$(CC) $(CFLAGS) $(INCFLAGS) -c main.cpp
clean: 
	$(RM) *.o mytest