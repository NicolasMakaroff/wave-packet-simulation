CXX = g++ -std=c++17 -stdlib=libc++ 
CXXFLAGS = -g -lgtest -lgtest_main -lpthread
INCS = -I./ -I../../src -I/opt/gtest/include /usr/local/lib/libgtest_main.a
OBJS = ../src/solver.o TestSolver.o 

testAll: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCS) -o testAll  Main_TestAll.cpp $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
	rm testAll *.o testAll.xml