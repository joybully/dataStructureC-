#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "PicPic.h"
int main() {
	int num;
	char color2;
	std::cin >> num;
	TextEditor<char> text(num);
	for (int i = 1; i < num+1; i++) {
		for (int k = 0; k < num+1; k++) {
			std::cin >> color2;
			text.ChangeIt(i, k, color2);
		}
	}
	text.Print();
	return 0;
}