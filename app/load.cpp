/**
 * load.c -- функция загрузки текста из файла
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */
#include<bits/stdc++.h>
#include <stdio.h>
#include "common.h"
#include "text/text.h"
using namespace std;
/**
 * Загружает содержимое указанного файла
 */
void load(text1*  txt, string filename)
{
    FILE *f;
	char str[100];
	strcpy(str, filename.c_str());
    string buf;
//	
    /* Открываем файл для чтения, контролируя ошибки */

	
    if ((f = fopen(str, "r")) == NULL) {
        cout << "The file "<<filename<<" cannot be opened\n";
        return;
    }else{
        //freopen(str, "r", stdin);
        //cout << "fsafsafsaffsfasfsafsaffafssafasfasfsa";
        /* Удаляем предыдущее содержимое */

        remove_all(txt);

        /* Считываем содержимое строка за строкой */
        char buf1[10000];
        while (fgets(buf1, 10001, f)) {
            buf = (char*)buf1;
            append_line(txt, buf);
        }
        printf("Total lines: %d\n", getlength(txt));
        return;

	
    }
}
