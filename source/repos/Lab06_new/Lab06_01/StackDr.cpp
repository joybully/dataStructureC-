// Test driver
#include <iostream>
#include <fstream>

#include "StackType.h"

using namespace std;

void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem) {
    StackType temp_stack;
    ItemType temp_Item;
    while (!stack.IsEmpty()) {
        temp_Item = stack.Top();
        if (oldItem == temp_Item) {
            stack.Pop();
            temp_stack.Push(newItem);
        }
        else {
            stack.Pop();
            temp_stack.Push(temp_Item);
        }
    }
    while (!temp_stack.IsEmpty()) {
        temp_Item = temp_stack.Top();
        temp_stack.Pop();
        stack.Push(temp_Item);
    }
}

int main()
{

  //ifstream inFile;       // file containing operations
  //ofstream outFile;      // file containing output
  //string inFileName;     // input file external name
  //string outFileName;    // output file external name
  //string outputLabel;     
  //string command;        // operation to be executed
  //
  //ItemType item;
  //StackType stack;
  //int numCommands;


  //// Prompt for file names, read file names, and prepare files
  //cout << "Enter name of input command file; press return." << endl;
  //cin  >> inFileName;
  //inFile.open(inFileName.c_str());

  //cout << "Enter name of output file; press return." << endl;
  //cin  >> outFileName;
  //outFile.open(outFileName.c_str());

  //cout << "Enter name of test run; press return." << endl;
  //cin  >> outputLabel;
  //outFile << outputLabel << endl;

  //inFile >> command;


  //numCommands = 0;
  //while (command != "Quit")
  //{ 
  //  try 
  //  {
  //    if (command == "Push")
  //    {
  //      inFile >> item; 
  //      stack.Push(item);
  //    }  
  //    else if (command == "Pop")
  //      stack.Pop();
  //    else if (command == "Top")
  //    {
  //      item = stack.Top(); 
  //      outFile<< "Top element is " << item << endl;
  //    } 
  //    else if (command == "IsEmpty") 
  //      if (stack.IsEmpty())
  //        outFile << "Stack is empty." << endl;
  //      else 
  //        outFile << "Stack is not empty." << endl;
  //           
  //    else if (command == "IsFull")
  //      if (stack.IsFull())
  //        outFile << "Stack is full." << endl;
  //      else outFile << "Stack is not full."  << endl;  
  //  }
  //  catch (FullStack)
  //  {
  //    outFile << "FullStack exception thrown." << endl;
  //  }
  //  
  //  catch (EmptyStack)
  //  {
  //    outFile << "EmtpyStack exception thrown." << endl;
  //  }    
  //  numCommands++;
  //  cout <<  " Command number " << numCommands  << " completed." 
  //       << endl;
  //  inFile >> command;
 
  //};
 
  //cout << "Testing completed."  << endl;
  //inFile.close();
  //outFile.close();

    //StackType stack1;
    //ItemType item1;
    //stack1.Push(1);
    //stack1.Push(2);
    //stack1.Push(3);
    //stack1.Push(2);
    //stack1.Push(5);
    //ReplaceItem(stack1, 2, 10);
    //item1 = stack1.Top();
    //std::cout << item1 << '\n';
    //stack1.Pop();
    //item1 = stack1.Top();
    //std::cout << item1 << '\n';
    //stack1.Pop();
    //item1 = stack1.Top();
    //std::cout << item1 << '\n';
    //stack1.Pop();
    //item1 = stack1.Top();
    //std::cout << item1 << '\n';
    //stack1.Pop();
    //item1 = stack1.Top();
    //std::cout << item1 << '\n';
    //stack1.Pop();
    //
    //StackType stack2;
    //ItemType item2;
    //stack2.Push(1);
    //stack2.Push(2);
    //stack2.Push(3);
    //stack2.Push(2);
    //stack2.Push(5);
    //stack2.ReplaceItem( 2, 10);
    //item2 = stack2.Top();
    //std::cout << item2 << '\n';
    //stack2.Pop();
    //item2 = stack2.Top();
    //std::cout << item2 << '\n';
    //stack2.Pop();
    //item2 = stack2.Top();
    //std::cout << item2 << '\n';
    //stack2.Pop();
    //item2 = stack2.Top();
    //std::cout << item2 << '\n';
    //stack2.Pop();
    //item2 = stack2.Top();
    //std::cout << item2 << '\n';
    //stack2.Pop();

  return 0;
}


