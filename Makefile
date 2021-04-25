all:
	g++ main.cpp -o dwmstatus -lX11

clean:
	rm -rf *.o dwmstatus
