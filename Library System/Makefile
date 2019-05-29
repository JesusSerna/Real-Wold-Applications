# Makefile for Homework_4
CXXFLAGS = 

all: executable

debug: CXXFLAGS += -g
debug: executable

rebuild: clean executable
executable: menu.o view.o publications.o create.o check_status.o
	$(CXX) $(CXXFLAGS) menu.o view.o publications.o create.o check_status.o
menu.o: menu.cpp library.h view.h create.h check_status.h publications.h
	$(CXX) $(CXXFLAGS) -w -c menu.cpp
view.o: view.cpp view.h library.h publications.h
	$(CXX) $(CXXFLAGS) -w -c view.cpp
publications.o: publications.cpp publications.h std_lib_facilities.h
	$(CXX) $(CXXFLAGS) -w -c publications.cpp
create.o: create.cpp create.h std_lib_facilities.h publications.h library.h 
	$(CXX) $(CXXFLAGS) -w -c create.cpp
check_status.o: check_status.cpp check_status.h publications.h library.h
	$(CXX) $(CXXFLAGS) -w -c check_status.cpp
clean:
	rm -f *.o a.out
