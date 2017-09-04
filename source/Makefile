cc=gcc
output=krsearch

all:
	$(cc) krs.c -o $(output)
	chmod 755 $(output)

install:
	cp $(output) /usr/bin/krsearch
	chmod 755 $(output)
remove:
	rm /usr/bin/krsearch 
