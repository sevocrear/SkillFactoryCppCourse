privet:	main.cpp lib
	g++ -o privet main.cpp -L. -lMyLib

lib:	include/MyLib.cpp include/MyLib.hpp	
	g++ -o MyLib.o include/MyLib.cpp -c
	ar rc libMyLib.a MyLib.o
clean:	
	rm *.o *.a