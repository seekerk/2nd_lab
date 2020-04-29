/**
 * append_line.c -- функции для добавления строк
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"



/**
 * Разделение строки по курсору
 */
void s(text1 * txt)
{
	int cur = 0;
	int curStr = txt->line;
	int curCrs = txt->ind++;
	auto iter = txt->li->begin();
	
	while(cur != curStr){
		iter++;	
		cur++;
	}	

	string str;
	string str1 = *iter;
	
	int u = 0;
	int o = str1.size();
	for(int i = curCrs; i < o; i++){
		str+=str1[i];
	}

	string str2 = str1;
	str2.resize(curCrs);
	str2+='\n';

	*iter = str2;
	if(txt->ind >= str2.size()-1){
		txt->line++;
        txt->ind = 0;
	}
	iter++;
	txt->li->emplace(iter, str);	
}
