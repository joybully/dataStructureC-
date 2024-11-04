// Test driver
#include <iostream>
#include <fstream>

#include "QueType.h"

using namespace std;

template<class ItemType>
void ReplaceItem(QueType<ItemType>& queue, ItemType oldItem, ItemType newItem) {
	QueType<ItemType> queue1;
	ItemType item1;
	while (!queue.IsEmpty()) {
		queue.Dequeue(item1);
		if (item1 == oldItem) {
			queue1.Enqueue(newItem);
		}
		else {
			queue1.Enqueue(item1);
		}
	}
	while (!queue1.IsEmpty()) {
		queue1.Dequeue(item1);
		queue.Enqueue(item1);
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
  //int item;
  //QueType<int> queue;
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
  //    if (command == "Enqueue")
  //    {
  //      inFile >> item; 
  //      queue.Enqueue(item);
  //      outFile << item << " is enqueued." << endl;
  //    }
  //    else if (command == "Dequeue")
  //    {
  //      queue.Dequeue(item); 
  //      outFile<< item  << " is dequeued. " << endl;
  //    } 
  //    else if (command == "IsEmpty") 
  //      if (queue.IsEmpty())
  //        outFile << "Queue is empty." << endl;
  //      else 
  //        outFile << "Queue is not empty." << endl;
  //           
  //    else if (command == "IsFull")
  //      if (queue.IsFull())
  //        outFile << "Queue is full." << endl;
  //      else outFile << "Queue is not full."  << endl;  
  //  }
  //  catch (FullQueue)
  //  {
  //    outFile << "FullQueue exception thrown." << endl;
  //  }
  //  
  //  catch (EmptyQueue)
  //  {
  //    outFile << "EmtpyQueue exception thrown." << endl;
  //  }    
  //  numCommands++;
  //  cout <<  " Command number " << numCommands << " completed." 
  //       << endl;
  //  inFile >> command;
 
  //};
 
  //cout << "Testing completed."  << endl;
  //inFile.close();
  //outFile.close();

	//QueType<int> queue1;
	//queue1.Enqueue(1);
	//queue1.Enqueue(2);
	//queue1.Enqueue(3);
	//queue1.Enqueue(2);
	//queue1.Enqueue(5);
	//ReplaceItem(queue1, 2, 10);
	//int item1;
	//queue1.Dequeue(item1);
	//std::cout << item1 << '\n';
	//queue1.Dequeue(item1);
	//std::cout << item1 << '\n';
	//queue1.Dequeue(item1);
	//std::cout << item1 << '\n';
	//queue1.Dequeue(item1);
	//std::cout << item1 << '\n';
	//queue1.Dequeue(item1);
	//std::cout << item1<<'\n';

	//QueType<int> queue2;
	//queue2.Enqueue(1);
	//queue2.Enqueue(2);
	//queue2.Enqueue(3);
	//queue2.Enqueue(2);
	//queue2.Enqueue(5);
	//queue2.ReplaceItem( 2, 10);
	//int item1;
	//queue2.Dequeue(item1);
	//std::cout << item1 << '\n';
	//queue2.Dequeue(item1);
	//std::cout << item1 << '\n';
	//queue2.Dequeue(item1);
	//std::cout << item1 << '\n';
	//queue2.Dequeue(item1);
	//std::cout << item1 << '\n';
	//queue2.Dequeue(item1);
	//std::cout << item1<<'\n';

	return 0;
}


