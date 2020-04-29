/**
 * process_forward.c -- реализует обобщенную функцию обработки текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

void show_all(text1 * txt){
	for(auto iter = txt->li->begin(); iter != txt->li->end(); iter++){
		cout << *iter;
	}
}