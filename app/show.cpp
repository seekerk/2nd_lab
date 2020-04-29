/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>

#include <string.h>

#include <assert.h>
#include "common.h"
#include "text/text.h"
#include<bits/stdc++.h>

static void show_line(int index, string contents, int cursor, void *data);
//static void showclassified_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text1* txt)
{
    /* Применяем функцию show_line к каждой строке текста */
	process_forward(txt, show_line, NULL);
 //   show_all(txt);
    printf("\n");
}
/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, string contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
 //   assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
	
    if(cursor == -1){
		cout << contents;	
	}else{
	//	cursor = contents.size()-1;
		//cout << contents;
		for(int i = 0; i < cursor; i++)
			cout << contents[i];
		printf("|");

		for(int i = cursor; i < (int)contents.size(); i++){
			cout << contents[i];
		}

	}
    
}

