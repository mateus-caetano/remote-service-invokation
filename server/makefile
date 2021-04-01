all: proto ../client.pb.cc ../client.pb.h ./headers/dispatch.h ./headers/server.h ./src/main.cpp ./src/server.cpp ./src/dispatch.cpp
	c++ ./src/main.cpp ./src/server.cpp ../client.pb.cc -o server.app `pkg-config --cflags --libs protobuf`

proto: ../client.proto
	protoc -I=../ --cpp_out=../ ../client.proto

clean:
	rm -rf *.o