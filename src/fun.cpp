// Copyright 2022 UNN-IASR
//файл с реализацией функции

#include "fun.h" //заголовочный файл с заголовком функции.
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
unsigned int coNumber = 0;
unsigned int counter = 0;
bool word = false, wiNumber = false;
while (*str) {
    if ((*str != ' ') && (word == false)) {
        word = true;
        counter++;
    }
    if ((*str != ' ') && (*str >= '0') && (*str <= '9')) {
        wiNumber = true;
    }
    if ((*str == ' ') && (word == true)) {
        if (wiNumber == true) {
            coNumber++;
            word = false;
            wiNumber = false;
        } else {
            word = false;
        }
    }
    str++;
}
  return (counter - coNumber);
}

unsigned int faStr2(const char *str)  {
unsigned int counter = 0;
bool letterO = false, letterT = false; one = false, word = false;
while (*str) {
    if ((*str != ' ') && (word == false)) {
        word = true;
        if ((*str >= 'A') && (*str <= 'Z')) {
            letterO = true;
            letterT = true;
        }
    }
    if (*str != ' ') {
        if ((letterO == true) && (word == true)) {
            if (((*str >= 'a') && (*str <= 'z')) || (one == true)) {
                letterT = true;
                if (first == true) {
                    one = false;
                }
             } else {
                letterT = false;
                }
        }
    }
    if ((*str +== ' ') && (word == true)) {
        if ((letterO == true) && (letterT == true)) {
            counter++;
            word = false;
            letterO = false;
            letterT = false;
        } else {
        word = false;
        letterO = false;
        letterT = false;
        }
    }
    str++;
    }
  return counter;
}

unsigned int faStr3(const char *str) {
unsigned int counter = 0;
unsigned int wordsSum = 0;
bool word = false;
while (*str) {
        if (*str != ' ') {
            if (word == false) {
                counter++;
                word = true;
            }
            wordsSum++;
        } 
        if ((*str == ' ') && (word == true)) {
            word = false;
        }
        str++;
}
    return (wordsSum + 1) / counter;
}
