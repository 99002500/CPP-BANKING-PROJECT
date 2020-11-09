![.github/workflows/cppcheck.yml](https://github.com/99002500/CPP-BANKING-PROJECT/workflows/.github/workflows/cppcheck.yml/badge.svg)












# C++ Updates

## Debug Tactics
1. preprocessor macros for debug
   * #define DEBUG   or   g++ file.cc -D DEBUG -O...
2. cmake variation macro
    * #define _cmake    or    g++ file.cc -D _CMAKE_ -o out -static libraries.
    ```#ifdef DEBUG
    #define debug(msg) std::cout << msg << std::endl    
    #else
    #define debug(msg) " "
    #endif
    ```

## Make File

```
Gtest: bankingtest.cc banking.h
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
GtestDebug: bankingtest.cc
	g++ $^ -D DEBUG -o $@ -lgtest -lgtest_main -lpthread
out: banking.cc 
	g++ $^ -o $@
```

### Alias Names

```
# C++ alias names for commands
alias buildGtest='g++ *.c* -lgtest -lgtest_main -lpthread -o out && ./out'

#c++ make files 
alias buildMake='make out && ./out'
alias run='./out'
alias test='make Gtest && ./Gtest'
alias testDebug='make GtestDebug && ./GtestDebug'

```

## Modular Programming
* ignore 2 mains
