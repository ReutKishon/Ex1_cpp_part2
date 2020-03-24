

test: Test.cpp PhoneticFinder.cpp
	/usr/bin/g++ -g Test.cpp PhoneticFinder.cpp -o test
	./test

demo: demo.cpp PhoneticFinder.cpp
	/usr/bin/g++ -g demo.cpp PhoneticFinder.cpp -o demo
	./demo

clean: 
	rm ./demo
	rm ./test

	
