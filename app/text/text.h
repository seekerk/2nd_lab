/**
 * text.h -- внешний интерфейс библиотеки для работы с текстом
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef TEXT_H
#define TEXT_H
#include<string>
#include<list>
#include<bits/stdc++.h>

#define MAXLINE 255
using namespace std;
/**
 * Абстрактный тип текстовых объектов
 */
//typedef struct _list *text;

/**
 * Абстрактный тип курсора
 */
struct body{
	string s;
	int ind;
	int line;
};
typedef struct _crsr *cursor;
//typedef std::list<string> text1;

struct text1{
		int ind = 0;
		int line = 0;
		typedef list<string> text;
		text* li = new text;
	};

typedef struct _crsr_str *cursor_str;

/**
 * Создает новый текстовый объект
 * @returns текст
 */

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text1* txt, string contents);

int get_line(text1 * txt);
int get_ind(text1 * txt);
void s(text1 * txt);
void move1(text1 * txt, int line, int ind);
/**
 * Обрабатывает текст, применяя заданную функцию к каждой строке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text1* txt,
    void (*process)(int index, string contents, int cursor_position, void *data),
    void *data
);
int getlength1(text1 * txt);
void show_all(text1 * txt);
/**
 * Удаляет весь текст
 * 
 * @param txt текст
 * @returns none
 */
void remove_all(text1 * txt);

#endif
