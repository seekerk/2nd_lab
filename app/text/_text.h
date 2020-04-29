/**
 * _text.h -- внутренние структуры представления текста
 * 
 * Этот файл не должен включаться в клиентские модули
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef _TEXT_H
#define _TEXT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include<list>
#include<string>
#include "text.h"
/*
struct text1{
		int ind = 0;
		int line = 0;
		typedef list<string> text;
		text* li = new text;
	};`
*/
typedef struct _node {
    char contents[MAXLINE + 1]; 
    struct _node *previous;     
    struct _node *next;         
} node;


typedef struct _crsr {
    struct _node *line;         
    int position;               
} crsr;


typedef struct _list {
    size_t length;              
    struct _node *begin;        
    struct _node *end;          
    struct _crsr *cursor;       
} list;

typedef struct _crsr1{
	int ind = 1;
	int line = 1;
}crsr_cpp;


//typedef std::list<std::string> text1;
//std::list<std::string> *text;
//typedef struct _list *text;
#endif
