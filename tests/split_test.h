#ifndef SPLIT_TEST_H
#define SPLIT_TEST_H

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

TEST(splitTestPositive, split1){
    string s2 = (const char*)INPUTDIRSAVE;
    s2+="//textIn.txt";

    text1* txt = new text1;

    load(txt, s2);

    string pathDir = (const char*)INPUTDIRSAVE;

        move(txt, 1, 3);
        s1(txt);
        save(txt, pathDir + "/getFile.txt");
        string shouldBe;
        string out;

        char buffer[100];

        FILE * fout = fopen((pathDir + "/shouldFile.txt").c_str(), "r");
        FILE * fshould = fopen((pathDir + "/getFile.txt").c_str(), "r");

        while(fgets(buffer, 1000, fout)){
            shouldBe = ((char*)buffer);
            fgets(buffer, 1000, fshould);
            out = (char*)buffer;
            ASSERT_EQ(shouldBe, out);
        }

        fclose(fout);
        fclose(fshould);

    remove_all(txt);
}


TEST(splitTestPositive, lastdigit){
    string s = (const char*)INPUTDIRSPLIT;
    s+="//textIn.txt";

    text1* txt = new text1;

    load(txt, s);

    string pathDir = (const char*)INPUTDIRSPLIT;



        move(txt, 2, 20);
        s1(txt);
        save(txt, pathDir + "/getFile.txt");
        string shouldBe;
        string out;

        char buffer[100];

        FILE * fout = fopen((pathDir + "/shouldFile.txt").c_str(), "r");
        FILE * fshould = fopen((pathDir + "/getFile.txt").c_str(), "r");

        while(fgets(buffer, 1000, fout)){
            shouldBe = ((char*)buffer);
            fgets(buffer, 1000, fshould);
            out = (char*)buffer;
            ASSERT_EQ(shouldBe, out);
        }

        fclose(fout);
        fclose(fshould);

    remove_all(txt);
}






#endif // SPLIT_TEST_H
