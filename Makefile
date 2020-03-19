

test: Test.cpp PhoneticFinder.cpp
	/usr/bin/g++ -g Test.cpp PhoneticFinder.cpp -o test
	./test
