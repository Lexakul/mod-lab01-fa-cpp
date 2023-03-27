// Kuznetsova Angelina 381907-3
#include <iostream>
#include <cstring>
#include "fun.h"

unsigned int faStr1(const char *str)
{
    int c = 0;
    bool word = false;
    bool number = false;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i]))
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
            if (isdigit(str[i]))
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

unsigned int faStr2(const char *str)
{
    int c = 0;
    bool word = false;
    bool latin = false;
    bool space = false;
    bool t = true;
    bool z = false;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i]))
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
                if (isalpha(str[i]))
                {
                    latin = true;
                    t = true;
                    if (isupper(str[i]))
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
                if (isalpha(str[i]))
                {
                    latin = true;
                }
                else
                {
                    latin = false;
                }
                if (isupper(str[i]))
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

unsigned int faStr3(const char *str)
{
    int c = 0;
    int symbol = 0;
    bool word = false;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i]))
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
    return round(lenght);
}