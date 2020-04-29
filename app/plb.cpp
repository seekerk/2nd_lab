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

static void plb_on_line(int index, string contents, int cursor, void *data);

/**
 * для вывода на экран части строки от начала до курсора plb;
 */
void plb(text1 * txt)
{
   /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, plb_on_line, NULL);
}
/**
 * Выводит содержимое указанного файла на экран
 */
static void plb_on_line(int index, string contents, int cursor, void *data)
{

	int crs= cursor;

    if(cursor != -1){

        //UNUSED(cursor);
        UNUSED(index);
        UNUSED(data);
		if(crs > (int)contents.size()-1)
			printf("cursor index is not available\n");
		else{
			for(int i = 0; i < crs; i++){
				printf("%c", contents[i]);
			}
		}
  	}
}

