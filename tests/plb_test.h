#ifndef PLB_TEST_H
#define PLB_TEST_H

#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
//#include <conio.h>
extern "C++" {
    #include "common.h"
    #include "text/text.h"
    #include "text/_text.h"
}
using namespace std;

TEST(plbTestPositive, console1){
    string s = (const char*)INPUTDIRPLB;
    s+="//textIn.txt";

    text1* txt = new text1;

    load(txt, s);

    string s1 = (const char*)INPUTDIRPLB;

    string pathDir = (const char*)INPUTDIRPLB;
    FILE * f;
    s1+="/inCommandLine";

    if ((f = fopen(s1.c_str(), "r")) == NULL) {
         FAIL();
    }else{

        /* Считываем содержимое строка за строкой */
        char buf1[100];
        fgets(buf1, 10001, f);
        string first = (char*)buf1;

        string command = first.substr(0, 3);
        ASSERT_EQ("plb", command);

        move(txt, 1, 3);

        freopen((pathDir+"/outCommandLine").c_str(), "w", stdout);
        plb(txt);
        freopen("CONOUT$", "r+", stdout);

        string shouldBe;
        string out;

        char buffer[100];

        FILE * fout = fopen((pathDir + "/textOut.txt").c_str(), "r");
        FILE * fshould = fopen((pathDir + "/outCommandLine").c_str(), "r");

        while(fgets(buffer, 1000, fout)){
            shouldBe+= ((char*)buffer);
            fgets(buffer, 1000, fshould);
            out+=(char*)buffer;
        }
        ASSERT_EQ(shouldBe, out);
        fclose(fout);
        fclose(fshould);


     }

    fclose(f);
    remove_all(txt);
}

TEST(plbTestPositive, console2){
    string s = (const char*)INPUTDIRPLB;
    s+="//textIn.txt";

    text1* txt = new text1;

    load(txt, s);

    string s1 = (const char*)INPUTDIRPLB;

    string pathDir = (const char*)INPUTDIRPLB;
    FILE * f;
    s1+="/inCommandLine";

    if ((f = fopen(s1.c_str(), "r")) == NULL) {
        FAIL();
    }else{

        /* Считываем содержимое строка за строкой */
        char buf1[100];
        fgets(buf1, 10001, f);
        string first = (char*)buf1;

        string command = first.substr(0, 3);
        ASSERT_EQ("plb", command);

        move(txt, 5, 7);

        freopen((pathDir+"/outCommandLine2").c_str(), "w", stdout);
        plb(txt);
        freopen("CONOUT$", "r+", stdout);

        string shouldBe;
        string out;

        char buffer[100];

        FILE * fout = fopen((pathDir + "/textOut2.txt").c_str(), "r");
        FILE * fshould = fopen((pathDir + "/outCommandLine2").c_str(), "r");

        while(fgets(buffer, 1000, fout)){
            shouldBe+= ((char*)buffer);
            fgets(buffer, 1000, fshould);
            out+=(char*)buffer;
        }
        ASSERT_EQ(shouldBe, out);
        fclose(fout);
        fclose(fshould);


     }

    fclose(f);
    remove_all(txt);
}




#endif // PLB_TEST_H
