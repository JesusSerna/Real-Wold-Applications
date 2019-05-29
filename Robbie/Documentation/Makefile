
CXX	= $(shell fltk-config --cxx)
CXXOPTS = -std=c++11
DEBUG = -g
CXXFLAGS = $(shell fltk-config --use-gl --use-images --cxxflags ) $(CXXOPTS)
LDFLAGS = $(shell fltk-config --use-gl --use-images --ldflags )
LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags )
LINK = $(CXX)
TARGET = a.out
OBJS = main.o shop.o controller.o customer.o order.o globals.o robotpart.o view.o robotmodel.o salesassoc.o torso.o locomotor.o arm.o battery.o 
SRCS = main.cxx shop.cxx controller.cxx customer.cxx order.cxx globals.cxx robotpart.cxx view.cxx robotmodel.cxx salesassoc.cxx torso.cxx locomotor.cxx arm.cxx battery.cxx 
.SUFFIXES: .o .cxx
%.o: %.cxx
	$(CXX) $(CXXFLAGS) $(DEBUG) -c $(CXXOPTS) $<
all: $(TARGET)
	$(LINK) -o $(TARGET) $(OBJS) $(LDSTATIC)
$(TARGET): $(OBJS)
main.o: main.cpp shop.h order.h
shop.o: shop.cpp shop.h  order.h robotmodel.h globals.h view.h controller.h
controller.o: controller.cpp controller.h  boss.cpp cust.cpp PM.cpp Sales.cpp
customer.o: customer.cpp customer.h 
view.o: view.cpp view.h globals.h robotmodel.h
robotmodel.o: robotmodel.cpp robotmodel.h globals.h robotpart.h
salesassoc.o: salesassoc.cpp salesassoc.h 
globals.o: globals.cpp globals.h  head.h arm.h battery.h locomotor.h torso.h
robotpart.o: robotpart.cpp robotpart.h 
arm.o: arm.cpp arm.h robotpart.h
battery.o: battery.cpp battery.h robotpart.h
locomotor.o: locomotor.cpp locomotor.h robotpart.h
torso.o: torso.cpp torso.h robotpart.h
boss.o: boss.cpp

clean: $(TARGET) $(OBJS)
	rm -f *.o 2> /dev/null
	rm -f $(TARGET) 2> /dev/null

