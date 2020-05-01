#ifndef MOVE_TEST_H
#define MOVE_TEST_H
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>

extern "C++" {
    #include "common.h"
    #include "text/text.h"
    #include "text/_text.h"
}
using namespace std;
TEST(moveTestPositive, functional){
    ofstream ostr;
    string s = (const char*)INPUTDIRMOVE;
    s+="/textIn.txt";

    text1* txt = new text1;

    load(txt, s);

    move(txt, 1, 3);

    int index = txt->ind;
    int line = txt->line;

    ASSERT_EQ(line, 1);
    ASSERT_EQ(index, 3);

    remove_all(txt);
}

TEST(moveTestNegative, wrongPos){
    ofstream ostr;
    string s = (const char*)INPUTDIRMOVE;
    s+="//textIn.txt";
    //ostr.open(s.c_str());

    text1* txt = new text1;

    load(txt, s);

    move(txt, 1, 30);

    int index = txt->ind;
    int line = txt->line;


    int cur = 0;
    auto iter = txt->li->begin();
    while(cur != line){
        iter++;
        cur++;
    }
    ASSERT_EQ(line, 1);
    ASSERT_EQ(index, iter->size()-1);

    remove_all(txt);
}



TEST(moveTestPositive, console){
    string s = (const char*)INPUTDIRMOVE;
    s+="//textIn.txt";
    //ostr.open(s.c_str());

    text1* txt = new text1;

    load(txt, s);

    string s1 = (const char*)INPUTDIRMOVE;

    string pathDir = (const char*)INPUTDIRMOVE;
    FILE * f;
    s1+="/inCommandLine";

    if ((f = fopen(s1.c_str(), "r")) == NULL) {
        FAIL();
    }else{

        /* Считываем содержимое строка за строкой */
        char buf1[100];
        fgets(buf1, 10001, f);
        string first = (char*)buf1;

        string command = first.substr(0, 4);
        ASSERT_EQ("move", command);
        move(txt, first[5]-'0', first[7]-'0');

        int index = txt->ind;
        int line = txt->line;

        ASSERT_EQ(line, 1);
        ASSERT_EQ(index, 3);

     }

    //ostr.open(s.c_str());
    fclose(f);
    remove_all(txt);
}



#endif // MOVE_TEST_H
