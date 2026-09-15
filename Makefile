all: campusguard

campusguard:
	g++ -std=c++11 -g *.cpp -o campusguard

run: campusguard
	./campusguard

valgrind: campusguard
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./campusguard

clean:
	rm -f campusguard