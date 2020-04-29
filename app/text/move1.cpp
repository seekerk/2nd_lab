#include "_text.h"



void move1(text1 * txt, int line, int ind){
	int cur = 0;
	if(txt->li->size() < line){
        txt->line = txt->li->size()-1;
        auto iter = --txt->li->end();
        txt->ind = (iter)->size();
		return;
	}
	auto iter = txt->li->begin();
	while(cur != line){
		iter++;
		cur++;
	}
	string s = *iter;
	if(ind > s.size()-1){
        txt->line = line;
        txt->ind = s.size()-1;
		return;
	}
	txt->line = line;
	txt->ind = ind;
}
