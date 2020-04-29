 /**
 * load.c -- функция загрузки текста из файла
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include "common.h"

#include <assert.h>

#include "text/text.h"
#include<bits/stdc++.h>

/**
 * Загружает содержимое указанного файла
 */
static void save_line(int index, string contents, int cursor, void *data);

void save(text1 * txt, string filename)
{

//    char buf[MAXLINE + 1];
	FILE *k;
	char str[100];
	strcpy(str, filename.c_str());
    string buf;
	//cout << str;
    /* Открываем файл для чтения, контролируя ошибки */
    if ((k = fopen(str, "w")) == NULL) {
        printf("The file %s cannot be opened\n", filename.c_str());
        return;
    }
	
    process_forward(txt, save_line, k);

	fclose(k);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void save_line(int index, string contents, int cursor, void *data)
{
	FILE* k =(FILE*)data;
    /* Функция обработчик всегда получает существующую строку */
//   assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
   //cout << contents << endl;
	char buf1[10000];
	strcpy(buf1, contents.c_str());
	fputs(buf1, k);
    /* Выводим строку на экран */
  //  fprintf(k, "%s", contents);
}
