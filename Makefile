Gtest: bankingtest.cc banking.h
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
GtestDebug: bankingtest.cc
	g++ $^ -D DEBUG -o $@ -lgtest -lgtest_main -lpthread
out: banking.cc 
	g++ $^ -o $@