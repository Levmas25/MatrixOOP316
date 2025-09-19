build:
	g++ main.cpp app_manager.cpp console_manager.cpp line.cpp symbol.cpp random_engine.cpp -o solution
run:
	./solution
destroy:
	rm ./solution