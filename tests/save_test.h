#ifndef SAVE_TEST_H
#define SAVE_TEST_H

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

TEST(saveTestPositive, split){
    string s = (const char*)INPUTDIRSAVE;
    s+="//textIn.txt";

    text1* txt = new text1;

    load(txt, s);

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






#endif // SAVE_TEST_H
