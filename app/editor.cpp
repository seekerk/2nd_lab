/**
 * editor.cpp -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */
#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
//#include <string.h>
#include<string>
#include<list>
#include<cstring>
#include "text/text.h"
#include "common.h"

#define MAXLINE 255
using namespace std;
int main()
{

	text1* txt = new text1;
	//cursor_str * cursor1 = new cursor_str;
	
  //  int curS = 7 , curC = 4;
    /* Создаем объект для представления текста */
   // text txt = create_text();
	printf("\n\nAvailable commands:\nquit, show, load, showclassified, save, plb, s, move\n\n\n");
    /* Цикл обработки команд */
	
    while (1) {
        printf("ed > ");
 	char cmdline1[MAXLINE+1];
    string cmd;
	
    string arg;
        /* Получаем команду */
		 	
        fgets(cmdline1, MAXLINE, stdin);
		string cmdline;
		cmdline = (char*)cmdline1;
		//cout << cmdline;
		//	getline(cin, cmdline);

        /* Извлекаем имя команды */
		int u = 0;
		
        while(cmdline[u]!=' '&& cmdline[u]!='\n' && cmdline[u]!='\0'){
			
			cmd+=cmdline[u];
			u++;
		}
		
        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (cmd ==  "quit") {
            fprintf(stderr, "Bye!\n");
            break;
        }
		
        /* Загружаем содержимое файла, заданного параметром */
        if (cmd ==  "load") {
			 u++;
			int p = 0;
			 while(cmdline[u]!=' '&&cmdline[u]!='\n' && cmdline[u]!='\0'){
			//	cout << cmdline[u];
				arg+=cmdline[u];
				u++;
				p = 1;
			}
			//cout << cmdline;
            if (p == 0) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);

            }
			//fclose(stdin);
			//freopen("CON","r",stdin);

			
            continue;
			
        }
		/*save*/
		
		if (cmd == "save") {
			int p = 0;
			u++;
			while(cmdline[u]!=' '&&cmdline[u]!='\n' && cmdline[u]!='\0'){
				arg+=cmdline[u];
				u++;
				p = 1;
			}
			
            if (p == 0) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
			cout << endl;
            continue;
        }
		
        /* Выводим текст */
        if (cmd == "show") {
            show(txt);
            //rcout << endl;
            continue;
        }
		if (cmd ==  "s") {
            s1(txt);

            continue;
        }
		
		/*cursor*/
		//printf("1");
		if (cmd == "plb") {
			if(get_line(txt) > getlength(txt)){
				printf("String is not available\n");
				continue;
			}else{
				plb(txt);
			}
			printf("\n");
            continue;
        }

		if (cmd ==  "showclassified") {
            showclassified(txt);
			//cout << endl;
            continue;
        }
		if (cmd ==  "move") {
			string ind1, line1;
			int ind2, line2;
			u++;
			while(cmdline[u]!=' '&&cmdline[u]!='\n' && cmdline[u]!='\0'){
				line1+=cmdline[u];
				u++;
				//p = 1;
			}
			u++;
			while(cmdline[u]!=' '&&cmdline[u]!='\n' && cmdline[u]!='\0'){
				ind1+=cmdline[u];
				u++;
				//p = 1;
			}
			if(ind1.size() == 0 || line1.size() == 0){
				cout << "Need more arguments\n";
				continue;
            }
            int line3 = std::stoi(line1);
            line2 = line3;
            ind2 = std::stoi(ind1);
            move(txt, line2, ind2);
			//cout << endl;
            continue;
        }
        
        
        /* Если команда не известна */
        cout <<"Unknown command: " << cmdline << endl;
    }
    return 0;
}
