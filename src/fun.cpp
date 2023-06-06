// Copyright 2022 UNN-IASR
//файл с реализацией функции

#include "fun.h" //заголовочный файл с заголовком функции.
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
unsigned int noNumber = 0;
unsigned int counter = 0;
bool wordIn = false;

for(const char* s = str; *s != '\0'; s++) {
if (isspace(*s)) {
        wordIn = false;
        } else if (!wordIn) {
    wordIn = true;
    counter++;
    bool yesNumber = false;
    for (const char* r = s; !isspace(*r) && *r != '\0'; r++) {
        if (isdigit(*r)) {
            yesNumber = true;
    break;
    }
    }
    if (!yesNumber) {
        noNumber++;
        }
    }
  }
  return noNumber;
  }

unsigned int faStr2(const char *str)  {
unsigned int counter = 0;
bool letterUp = false;
bool lettersLow = true;

  for (int i = 0; str[i] != '\0'; i++) {
    if (isalpha(str[i])) {
        if (islower(str[i])) {
            lettersLow = true;
        } else if (isupper(str[i])) {
    if (i == 0) {
    letterUp = true;
    } else if (isspace(str[i-1])) {
    letterUp = true;
    } else {
        letterUp = false;
    }
    if (!letterUp) {
        lettersLow = false;
    }
        }
    } else if (isspace(str[i])) {
        if (letterUp && lettersLow) {
            counter++;
        }
        letterUp = false;
        lettersLow = true;
    } else {
        letterUp = false;
        lettersLow = false;
    }
  }
  if (letterUp && lettersLow) {
    counter++;
  }
  return counter;
}

unsigned int faStr3(const char *str) {
    unsigned int counter = 0;
    unsigned int wordsSum = 0;
    bool word = false;

    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            if (!word) {
                word = true;
        }
        counter++;
    } else {
        if (word) {
            word = false;
            wordsSum += counter;
            counter = 0;
        }
    }
}
    if (word) {
    wordsSum += counter;
    }
return round(static_cast<double>(wordsSum) / faStr1(str));
}
