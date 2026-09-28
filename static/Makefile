PREFIX = /usr/local
INCDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib
 
.PHONY: all clean install uninstall
 
all: myprog
 
myprog: myprog.c vector.h libvector.a
	gcc myprog.c -L. -lvector -o myprog
 
libvector.o: libvector.c vector.h
	gcc -c libvector.c -o libvector.o
 
libvector.a: libvector.o
	ar rs libvector.a libvector.o
 
install: libvector.a vector.h
	cp vector.h $(INCDIR)
	chmod 664 $(INCDIR)/vector.h
	cp libvector.a $(LIBDIR)
	chmod 664 $(LIBDIR)/libvector.a
 
uninstall:
	rm -f $(INCDIR)/vector.h
	rm -f $(LIBDIR)/libvector.a
 
clean:
	rm -f libvector.o libvector.a myprog