// Test driver
#include <iostream>
#include <fstream>

#include "StackType.h"

using namespace std;

//Exercise4
void ReplaceItem(StackType& st, int oldItem, int newItem) {
	StackType stack1;
	while (!st.IsEmpty()) {
		if (st.Top() == oldItem) {
			stack1.Push(newItem);
			st.Pop();
		}
		else {
			stack1.Push(st.Top());
			st.Pop();
		}
	}
	while (!stack1.IsEmpty()) {
		st.Push(stack1.Top());
		stack1.Pop();
	}
};


int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  
  ItemType item;
  StackType stack;
  int numCommands;


  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;

  inFile >> command;


  numCommands = 0;
  while (command != "Quit")
  { 
    try 
    {
      if (command == "Push")
      {
        inFile >> item; 
        stack.Push(item);
      }
      else if (command == "Pop")
        stack.Pop();
      else if (command == "Top")
      {
        item = stack.Top(); 
        outFile<< "Top element is " << item << endl;
      } 
      else if (command == "IsEmpty") 
        if (stack.IsEmpty())
          outFile << "Stack is empty." << endl;
        else 
          outFile << "Stack is not empty." << endl;
             
      else if (command == "IsFull")
        if (stack.IsFull())
          outFile << "Stack is full." << endl;
        else outFile << "Stack is not full."  << endl;  
    }
    catch (FullStack)
    {
      outFile << "FullStack exception thrown." << endl;
    }
    
    catch (EmptyStack)
    {
      outFile << "EmtpyStack exception thrown." << endl;
    }    
    numCommands++;
    cout <<  " Command number " << numCommands << " completed." 
         << endl;
    inFile >> command;
 
  };
 
  cout << "Testing completed."  << endl;
  inFile.close();
  outFile.close();

	//Exercise3 테스트용 코드
	/*doublestack stack1;
	for (int i = 1; i < 101; i++) {
		stack1.Push(i);
	}
	for (int i = 1001; i < 1101; i++) {
		stack1.Push(i);
	}
	stack1.Print();*/

	//Exercise4-1 테스트용 코드
	//StackType stack;
	//for (int i = 0; i < 10; i++) {
	//	stack.Push(2);
	//}
	//for (int i = 0; i < 10; i++) {
	//	stack.Push(3);
	//}
	//for (int i = 0; i < 10; i++) {
	//	stack.Push(4);
	//}
	//for (int i = 0; i < 10; i++) {
	//	stack.Push(2);
	//}
	//// stack에 Push연산을 통해 값을 입력함.
	//ReplaceItem(stack, 2, 3);
	//while (!stack.IsEmpty())	//스택 내용 출력
	//{
	//	int item = stack.Top();
	//	stack.Pop();
	//	cout << "Item : " << item << endl;
	//}
	//cout << endl;
	//cout << endl;
	//cout << endl;
	//Exercise4-2 테스트용 코드
	/*StackType stack2;
	for (int i = 0; i < 10; i++) {
		stack2.Push(2);
	}
	for (int i = 0; i < 10; i++) {
		stack2.Push(3);
	}
	for (int i = 0; i < 10; i++) {
		stack2.Push(4);
	}
	for (int i = 0; i < 10; i++) {
		stack2.Push(2);
	}*/
	// stack에 Push연산을 통해 값을 입력함.
	//stack2.ReplaceItem( 2, 3);
	//while (!stack2.IsEmpty())	//스택 내용 출력
	//{
	//	int item = stack2.Top();
	//	stack2.Pop();
	//	cout << "Item : " << item << endl;
	//}
  return 0;
}


