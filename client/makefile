all: proto ../client.pb.cc ../client.pb.h ./headers/client.h ./headers/proxy.h ./src/main.cpp ./src/proxy.cpp ./src/client.cpp
	c++ ./src/main.cpp ./src/proxy.cpp ./src/client.cpp ../client.pb.cc -o client.app `pkg-config --cflags --libs protobuf`

proto: ../client.proto
	protoc -I=../ --cpp_out=../ ../client.proto

clean:
	rm -rf *.o