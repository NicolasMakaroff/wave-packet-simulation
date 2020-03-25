CXX = g++ -std=c++17 -stdlib=libc++ 
CXXFLAGS = -g -lgtest -lgtest_main -lpthread
INCS = -I./ -I../../src -I/opt/gtest/include /usr/local/lib/libgtest_main.a
OBJS = src/solver.o test/TestSolver.o 

testAll: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCS) -o test/testAll  test/Main_TestAll.cpp $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
	rm -rf test/testAll *.o test/testAll.dSYM
	rm test/*.o 
	rm src/*.o 