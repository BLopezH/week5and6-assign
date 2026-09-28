PREFIX = /usr/local
INCDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib

.PHONY: all clean install uninstall

all: myprog

myprog: myprog.c vector.h libvector.so
	gcc myprog.c -L. -lvector -o myprog

libvector.o: libvector.c vector.h
	gcc -c -fPIC libvector.c -o libvector.o

libvector.so: libvector.o
	gcc -shared libvector.o -o libvector.so

install: libvector.so vector.h
	cp vector.h $(INCDIR)
	chmod 664 $(INCDIR)/vector.h
	cp libvector.so $(LIBDIR)
	chmod 664 $(LIBDIR)/libvector.so

uninstall:
	rm -f $(INCDIR)/vector.h
	rm -f $(LIBDIR)/libvector.so

clean:
	rm -f libvector.o libvector.so myprog
