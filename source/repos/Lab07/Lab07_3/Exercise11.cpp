#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "LineType.h"
int main() {
	TextEditor<string> text1;
	string item1;
	text1.InsertLine("gogogo");
	text1.InsertLine("dododo");
	text1.InsertLine("bobobo");
	text1.InsertLine("bababa");
	text1.InsertLine("lalala");
	text1.InsertLine("lelele");
	text1.InsertLine("tututu");
	int leng1 = text1.LengthIs();
	for (int i = 0; i < leng1; i++) {
		text1.GetNextItem(item1);
		std::cout << item1<<endl;
	}
	text1.GoToBottom();
	text1.GoToTop();
	TextEditor<string> text2;
	text2.GoToBottom();
	text2.GoToTop();
	LineType<string>* linePtr;
	text1.GoToTop(linePtr);
 	text1.GoToBottom(linePtr);
	text2.GoToBottom(linePtr);
	text2.GoToTop(linePtr);
	text1.MakeEmpty();
	return 0;
}