main:	main.cpp libUser libMessage libChat
	g++ -o main main.cpp -L. -lChat -L. -lUser -L. -lMessage

libChat:	include/Chat.cpp include/Chat.hpp	
	g++ -o Chat.o include/Chat.cpp -c
	ar rc libChat.a Chat.o

libUser:	include/User.cpp include/User.hpp	
	g++ -o User.o include/User.cpp -c
	ar rc libUser.a User.o

libMessage:	include/Message.cpp include/Message.hpp	
	g++ -o Message.o include/Message.cpp -c
	ar rc libMessage.a Message.o

clean:	
	rm *.o *.a
	
run-chat:
	./main