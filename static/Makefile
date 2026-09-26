PREFIX = /usr/local
INCDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib
 
.PHONY: all clean install uninstall
 
all: myprog
 
myprog: myprog.c mylib.h libmylib.a
	gcc myprog.c -L. -lmylib -o myprog
 
libvector.o: libvector.c mylib.h
	gcc -c libvector.c -o libvector.o
 
libmylib.a: libvector.o
	ar rs libmylib.a libvector.o
 
install: libmylib.a mylib.h
	cp mylib.h $(INCDIR)
	chmod 664 $(INCDIR)/mylib.h
	cp libmylib.a $(LIBDIR)
	chmod 664 $(LIBDIR)/libmylib.a
 
uninstall:
	rm -f $(INCDIR)/mylib.h
	rm -f $(LIBDIR)/libmylib.a
 
clean:
	rm -f libvector.o libmylib.a myprog