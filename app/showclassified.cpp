/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>

#include <string.h>
#include<bits/stdc++.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void showclassified_line(int index, string contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
int getlength(text1 * txt){
	return getlength1(txt);
}

void showclassified(text1 * txt)
{
	int o = getlength(txt);
	int *p = &o;
	void *o1 = static_cast<void *>(p);
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, showclassified_line, o1);
}

static void showclassified_line(int index, string contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
//    assert(contents != NULL);
   // int y = (int)data;
	int *y1 = static_cast<int*>(data);
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
	int y = *y1;
	for(int i = 0; i < contents.size()-1; i++){
        if((contents[i] >= 'a' && contents[i] <= 'z') || (contents[i] >= 'A' && contents[i] <= 'Z'))
			printf("*");
		else
			printf("%c", contents[i]);
	}
    //if(index == y-1)
    //	printf("*");
	printf("\n");
    
}

