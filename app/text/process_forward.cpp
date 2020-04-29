 /**
 * process_forward.c -- реализует обобщенную функцию обработки текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Обрабатывает список, применяя заданную функцию к каждой строке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text1 * txt,
    void (*process)(int index, string contents, int cursor, void *data),
    void *data
)
{   
    /* Проверяем, имеется ли текст */
    if (txt->li->size() == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    } 
    
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
//    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Стартуем с начальной строки текста */
    int index = 0;
    int cursor_position = -1;
	int cur1 = txt->li->size();
    /* К каждой строке текста применяем обработчик */
	auto iter = txt->li->begin();
    while (index != cur1) {
		if(index == txt->line){
			cursor_position = txt->ind;
		}else
			cursor_position = -1;
        process(index, *iter, cursor_position, data);
        index++;
		iter++;
    }
}
int getlength1(text1 * txt){
	return txt->li->size();
} 
