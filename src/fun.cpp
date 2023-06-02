// Kuznetsova Angelina 381907-3
//файл с реализацией функции

#include <iostream>
#include <cstring>
#include "fun.h" //заголовочный файл с заголовком функции.

unsigned int faStr1(const char *str) //ф-ция в переданной строке определяет слова, не содержащие цифр и подсчитывает кол-во таких слов
{
    int c = 0; //кол-во нужных слов
    bool word = false;
    bool number = false;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i]))//ф-ция, проверяющая пробел (меняет character)
        {
            if (word && !number)
            {
                c++;
            }
            word = false;
            number = false;
        }
        else
        {
            if (!word)
            {
                word = true;
            }
            if (isdigit(str[i]))//перебираем на наличие цифр
            {
                number = true;
            }
        }
    }
    if (!number && word)
    {
        c++;
    }
    return c;
}

unsigned int faStr2(const char *str)//ф-ция подсчитывает кол-во слов, начинающихся с загл лат буквы, другие символы только лат строчн в переданной строке
{
    int c = 0; //кол-во нужных слов
    bool word = false;
    bool latin = false;
    bool space = false;
    bool t = true;
    bool z = false;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i]))//ф-ция, проверяющая пробел (меняет character)
        {
            if (latin && word && t)
            {
                c++;
            }
            word = false;
            latin = false;
            space = true;
        }
        else
        {
            if (space)
            {
                space = false;
                if (isalpha(str[i]))//перебираем на наличие букв алфавита
                {
                    latin = true;
                    t = true;
                    if (isupper(str[i]))//перебираем на наличие прописных букв
                    {
                        word = true;
                        t = true;
                        z = true;
                    }
                    else
                    {
                        t = false;
                    }
                }
                else
                {
                    t = false;
                }
            }
            else
            {
                if (isalpha(str[i]))//перебираем на наличие букв алфавита
                {
                    latin = true;
                }
                else
                {
                    latin = false;
                }
                if (isupper(str[i]))//перебираем на наличие прописных букв
                {
                    if (z)
                    {
                        word = false;
                    }
                    else
                    {
                        word = true;
                        t = true;
                        z = true;
                    }
                }
            }
        }
    }
    if (latin && word && t)
    {
        c++;
    }
    return c;
}

unsigned int faStr3(const char *str)//находит сред длину слова в строке, округляя до цел
{
    int c = 0;
    int symbol = 0;
    bool word = false;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i]))//ф-ция, проверяющая пробел (меняет character)
        {
            word = false;
        }
        else
        {
            if (!word)
            {
                word = true;
                c++;
            }
            symbol++;
        }
    }
    float lenght = static_cast<double>(symbol) / c;
    return round(lenght);//округляет значение с плавающей запятой до ближайшего целочисленного значения
}