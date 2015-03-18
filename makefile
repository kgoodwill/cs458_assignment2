GPP = g++ -g -std=c++11 -lcrypto

all: fscrypt

fscrypt: fscrypt.o
	$(GPP) fscrypt.o -o fscrypt

fscrypt.o: main.cc
	$(GPP) -c main.cc

clean:
	rm -f *.o *~core fscrypt