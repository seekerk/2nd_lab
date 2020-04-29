/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void s1(text1* txt);
void show(text1* txt);
void showclassified(text1* txt);
void save_show(text1* txt);
void plb(text1 * txt);
/**
 * Загружает содержимое указанного файла
 */
void load(text1* txt, string filename);
void move(text1 * txt, int line, int ind);

void save(text1* txt, string filename);
int getlength(text1* txt);
#endif
