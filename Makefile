all:
	g++ -Wall File.cpp pedido.cpp estafeta.cpp main.cpp -o output
clean:
	rm output