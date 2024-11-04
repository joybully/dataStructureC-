// Test driver
#include <iostream>
#include <fstream>

#include "StackTType.hpp"

using namespace std;

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  
  int item;
  StackType<int> stack;
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
 
  //Exercise1
  //StackType<int> stack1;
  //stack1.Push(1);
  //stack1.Push(2);
  //stack1.Push(3);
  //stack1.Push(4);
  //stack1.Push(5);
  //stack1.Push(6);
  //while (!stack1.IsEmpty()) {
  //    int result = stack1.Top();
  //    stack1.Pop();
  //    cout << result << endl;
  //}

	//Exercise2
	//StackType<int> stack2;
	//StackType<int> stack3;
	//StackType<int> stack4;
	//stack2.Push(3);
	//stack2.Push(5);
	//stack2.Push(7);
	//stack2.Push(4);
	//stack2.Push(8);
	//stack2.Push(9);
	//while (!stack2.IsEmpty()) {
	//	int result = stack2.Top();
	//	cout << result << endl;
	//	stack3.Push(stack2.Top());
	//	stack2.Pop();
	//}
	//while (!stack3.IsEmpty()) {
	//	int result = stack3.Top();
	//	cout << result << endl;
	//	stack4.Push(stack3.Top());
	//	stack3.Pop();
	//}
	return 0;
	
}


