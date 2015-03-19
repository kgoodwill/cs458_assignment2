GPP = g++ -g -std=c++11 -lcrypto

all: fscrypt

fscrypt: fscrypt.o main.o
	$(GPP) fscrypt.o main.o -o fscrypt

main.o: main.cpp
	$(GPP) -c main.cpp

fscrypt.o: fscrypt.cpp
	$(GPP) -c fscrypt.cpp

clean:
	rm -f *.o *~core fscrypt
