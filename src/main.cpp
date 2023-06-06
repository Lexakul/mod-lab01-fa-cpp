// Copyright 2022 UNN-IASR
//демонстрационная программа

#include <iostream>
#include "fun.h"

int main()
 {
    const char *str = "Hello, world!";
    std::cout << faStr1(str) << std::endl;
    std::cout << faStr2(str) << std::endl;
    std::cout << faStr3(str) << std::endl;
    return 0;
      }