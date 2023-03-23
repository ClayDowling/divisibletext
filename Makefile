CXXFLAGS=-std=c++17

.PHONY: clean all samples

all: cleantext generate

cleantext: cleantext.o
	$(CXX) $^ -o $@

generate: generate.o text.txt words.txt
	$(CXX) generate.o -o $@

text.txt: pride-and-prejudice.txt cleantext
	./cleantext pride-and-prejudice.txt > text.txt

words.txt: text.txt cleantext
	./cleantext --unique text.txt > words.txt

samples: generate cleantext
	./generate > sample1.txt
	sleep 1
	./generate > sample2.txt
	sleep 1
	./generate > sample3.txt
	sleep 1
	./generate > sample4.txt
	sleep 1
	./generate > sample5.txt
	sleep 1
	./generate > sample6.txt
	sleep 1
	./generate > sample7.txt
	sleep 1
	./generate > sample8.txt
	sleep 1
	./generate > sample9.txt


clean:
	rm -f *.o
	rm -f *.exe
	rm -f cleantext
	rm -f generate
	rm -f words.txt
	rm -f text.txt