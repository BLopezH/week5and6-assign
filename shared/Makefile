PREFIX = /usr/local
INCDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib

.PHONY: all clean install uninstall

all: myprog

myprog: myprog.c mylib.h libmylib.so
	gcc myprog.c -L. -lmylib -o myprog -Wl,-rpath,. -o myprog

libvector.o: libvector.c mylib.h
	gcc -c -fPIC libvector.c -o libvector.o

libmylib.so: libvector.o
	gcc -shared libvector.o -o libmylib.so

install: libmylib.so mylib.h
	cp mylib.h $(INCDIR)
	chmod 664 $(INCDIR)/mylib.h
	cp libmylib.so $(LIBDIR)
	chmod 664 $(LIBDIR)/libmylib.so

uninstall:
	rm -f $(INCDIR)/mylib.h
	rm -f $(LIBDIR)/libmylib.so

clean:
	rm -f libvector.o libmylib.so myprog
