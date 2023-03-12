// Copyright 2023 Kulikov
#include <iostream>
#include "fun.h"


unsigned int faStr1(const char* str) {
    int c = 0;
    bool word = false; // ������ �� ������� ������� 
    bool number = false; // ����� �� �����
    for (int i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i])) { // ���� �� ������
            if (word && !number) { //���� ����� � �� �������� ����
                c++; // �������� ���-�� ����
            }
            word = false;
            number = false;
        }
        else {
            if (!word) {
                word = true;
            }
            if (isdigit(str[i])) { //���� �� �����
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
    bool t = true; // �������� �� 1 ���������
    bool z = false; // �������� �� ��������� ��������� �����
    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) { // ������? da
            if (latin && word && t) {
                c++;
            }
            word = false;
            latin = false;
            space = true;
        }
        else { //net? �������� ����� �� ������ ����� �������
            if (space) {
                space = false;
                if (isalpha(str[i])) { //��������� ����� ��� ���
                    latin = true;
                    t = true;
                    if (isupper(str[i])) { // ����� ���������� � ���������? da
                        word = true;
                        t = true;
                        z = true;
                    }
                    else t = false;
                }
                else t = false;
            }
            else {
                if (isalpha(str[i])) { //��������� ����� ��� ���
                    latin = true;
                }
                else latin = false;
                if (isupper(str[i])) { // ����� ���������� � ���������? da // ��� ��������� �������� �� ����� 2 ��� �������
                    if (z) {//���� 2 ���������
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
    bool word = false; // ������ �� ������� ������� 
    for (int i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i])) { // ���� �� ������
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
    float lenght = static_cast<double>(symbol) / c; //��������� ������� �����
    return round(lenght); //��������
}