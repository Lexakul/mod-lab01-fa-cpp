// Copyright 2023 Kulikov
#include <iostream>
#include "fun.h"


unsigned int faStr1(const char* str) {
    int c = 0;
    bool word = false; // защита от первого пробела 
    bool number = false; // имеет ли цифры
    for (int i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i])) { // есть ли пробел
            if (word && !number) { //если слово и не содержит цифр
                c++; // увеличим кол-во слов
            }
            word = false;
            number = false;
        }
        else {
            if (!word) {
                word = true;
            }
            if (isdigit(str[i])) { //есть ли число
                number = true;
            }
        }
    }
    if (!number && word) {
        c++;
    }
    return c;
}

unsigned int faStr2(const char* str) {
    int c = 0;
    bool word = false;
    bool latin = false;
    bool space = false;
    bool t = true; // проверка на 1 заглавную
    bool z = false; // проверка на повторную заглавную букву
    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) { // пробел? da
            if (latin && word && t) {
                c++;
            }
            word = false;
            latin = false;
            space = true;
        }
        else { //net? Проверим стоит ли символ после пробела
            if (space) {
                space = false;
                if (isalpha(str[i])) { //латинская буква или нет
                    latin = true;
                    t = true;
                    if (isupper(str[i])) { // слово начинается с заглавной? da
                        word = true;
                        t = true;
                        z = true;
                    }
                    else t = false;
                }
                else t = false;
            }
            else {
                if (isalpha(str[i])) { //латинская буква или нет
                    latin = true;
                }
                else latin = false;
                if (isupper(str[i])) { // слово начинается с заглавной? da // как проверить является ли слово 2 раз заглавн
                    if (z) {//если 2 заглавная
                        word = false;
                    }
                    else {
                        word = true;
                        t = true;
                        z = true;
                    }
                }
            }
        }
    }
    if (latin && word && t) {
        c++;
    }
    return c;
}

unsigned int faStr3(const char* str) {

    int c = 0;
    int symbol = 0;
    bool word = false; // защита от первого пробела 
    for (int i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i])) { // есть ли пробел
            word = false;
        }
        else {
            if (!word) {
                word = true;
                c++;
            }
            symbol++;
        }
    }
    float lenght = static_cast<double>(symbol) / c; //посчитаем среднюю длину
    return round(lenght); //округлим
}