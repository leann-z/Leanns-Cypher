CXX = g++
CXXFLAGS = -Wall

proj4: Cipher.o Caesar.o RailFence.o Ong.o Vigenere.o CipherTool.o proj4.cpp
	$(CXX) $(CXXFLAGS) Cipher.o Caesar.o RailFence.o Ong.o Vigenere.o CipherTool.o proj4.cpp -o proj4

CipherTool.o: Cipher.o RailFence.o Caesar.o Ong.o Vigenere.o CipherTool.h CipherTool.cpp
	$(CXX) $(CXXFLAGS) -c CipherTool.cpp

Vigenere.o: Cipher.o Vigenere.h Vigenere.cpp
	$(CXX) $(CXXFLAGS) -c Vigenere.cpp

RailFence.o: RailFence.h RailFence.cpp Cipher.o
	$(CXX) $(CXXFLAGS) -c RailFence.cpp

Ong.o: Cipher.o Ong.h Ong.cpp
	$(CXX) $(CXXFLAGS) -c Ong.cpp

Caesar.o: Cipher.o Caesar.h Caesar.cpp
	$(CXX) $(CXXFLAGS) -c Caesar.cpp

Cipher.o: Cipher.h Cipher.cpp
	$(CXX) $(CXXFLAGS) -c Cipher.cpp

run1:
	./proj4 proj4_test1.txt

run2:
	./proj4 proj4_test2.txt

run3:
	./proj4 proj4_test3.txt

run4:
	./proj4 proj4_test4.txt

ec1:
	./proj4 proj4_ec1.txt

vec1:
	valgrind ./proj4 proj4_ec1.txt

val1:
	valgrind ./proj4 proj4_test1.txt

val2:
	valgrind ./proj4 proj4_test2.txt

val3:
	valgrind ./proj4 proj4_test3.txt

val4:
	valgrind ./proj4 proj4_test4.txt

clean:
	rm *.o
	rm *~
