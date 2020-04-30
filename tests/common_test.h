#ifndef COMMON_TEST_H
#define COMMON_TEST_H
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

extern "C++" {
    #include "common.h"
    #include "text/text.h"
    #include "text/_text.h"
}
using namespace std;

TEST(commonTestPositive, itsOkay){


    string pathDir = (const char*)INPUTDIRCOMMON;

    FILE * f;
    if((f = fopen((pathDir + "/inCommandLine").c_str(), "r")) == NULL){
        FAIL();
        fclose(f);
        return;
    }

    string openFile, saveFile;

    char getl[1000];
    fgets(getl, 1000, f);
    string he1 = (char*)getl;
    openFile += pathDir + "/";
    openFile += he1.substr(5, he1.size() - 5-1);



    text1* txt = new text1;

    load(txt, openFile);

    fgets(getl, 99, f);

    string he = (char*)getl;
    ASSERT_EQ("move", he.substr(0, 4));
    move(txt, he[5]-'0', he[7]-'0');
    fgets(getl, 99, f);


        s1(txt);

        he = (char*)getl;
        saveFile = he.substr(5, he.size() - 5 - 1);
        save(txt, pathDir + "/" + saveFile);
        string shouldBe;
        string out;

        char buffer[100];

        FILE * fout = fopen((pathDir + "/" +  saveFile).c_str(), "r");
        FILE * fshould = fopen((pathDir + "/shouldFile.txt").c_str(), "r");

        while(fgets(buffer, 1000, fout)){
            shouldBe = ((char*)buffer);
            fgets(buffer, 1000, fshould);
            out = (char*)buffer;
            ASSERT_EQ(shouldBe, out);
        }

        fclose(fout);
        fclose(fshould);
        fclose(f);
    remove_all(txt);
}





#endif // COMMON_TEST_H
