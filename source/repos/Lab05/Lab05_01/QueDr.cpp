// Test driver
#include <iostream>
#include <fstream>

#include "QueType.h"

using namespace std;

void ReplaceItem(QueType& queue, int oldItem, int newItem) {
	QueType queue2;
	while (!queue.IsEmpty()) {
		ItemType i;
		queue.Dequeue(i);
		if (oldItem == i) {
			queue2.Enqueue(newItem);
		}
		else {
			queue2.Enqueue(i);
		}
	}
	while (!queue2.IsEmpty()) {
		ItemType i;
		queue2.Dequeue(i);
		queue.Enqueue(i);
	}
};

bool Identical(QueType& queue1, QueType& queue2) {
	QueType queue1_1;
	QueType queue2_1;
	bool re = true;
	while (!queue1.IsEmpty() && !queue2.IsEmpty()) {
		ItemType item1;
		ItemType item2;
		queue1.Dequeue(item1);
		queue2.Dequeue(item2);
		queue1_1.Enqueue(item1);
		queue2_1.Enqueue(item2);
		if (item1 != item2) {
			re = false;
		}
	}
	if (!queue1.IsEmpty() != !queue2.IsEmpty()) {
		re = false;
	}
	while (!queue1.IsEmpty()) {
		ItemType item1;
		queue1.Dequeue(item1);
		queue1_1.Enqueue(item1);
	}
	while (!queue2.IsEmpty()) {
		ItemType item2;
		queue2.Dequeue(item2);
		queue2_1.Enqueue(item2);
	}
	while (!queue1_1.IsEmpty()) {
		ItemType item1;
		queue1_1.Dequeue(item1);
		queue1.Enqueue(item1);
	}
	while (!queue2_1.IsEmpty()) {
		ItemType item2;
		queue2_1.Dequeue(item2);
		queue2.Enqueue(item2);
	}
	return re;
};

int Length(QueType& queue) {
	QueType queue1;
	int leng = 0;
	while (!queue.IsEmpty()) {
		ItemType item1;
		queue.Dequeue(item1);
		leng++;
		queue1.Enqueue(item1);
	}
	while (!queue1.IsEmpty()) {
		ItemType item1;
		queue1.Dequeue(item1);
		queue.Enqueue(item1);
	}
	return leng;
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
  QueType queue(5);
  int numCommands;

  //queue.Enqueue(1);
  //queue.Enqueue(2);
  //queue.Enqueue(2);
  //queue.Enqueue(1);
  //ReplaceItem(queue, 2, 1);
  //queue.Dequeue(item);
  //cout << item;
  //queue.Dequeue(item);
  //cout << item;
  //queue.Dequeue(item);
  //cout << item;
  //queue.Dequeue(item);
  //cout << item;
  //queue.Enqueue(1);
  //queue.Enqueue(2);
  //queue.Enqueue(2);
  //queue.Enqueue(1);
  //queue.ReplaceItem(2, 1);
  //queue.Dequeue(item);
  //cout << item;
  //queue.Dequeue(item);
  //cout << item;
  //queue.Dequeue(item);
  //cout << item;
  //queue.Dequeue(item);
  //cout << item;

  //queue.Enqueue(1);
  //queue.Enqueue(2);
  //queue.Enqueue(2);
  //queue.Enqueue(1);
  //queue.Enqueue(1);
  //QueType queue1(5);
  //queue1.Enqueue(1);
  //queue1.Enqueue(2);
  //queue1.Enqueue(2);
  //queue1.Enqueue(1);

  //cout << Identical(queue, queue1);

  //queue.Enqueue(1);
  //queue.Enqueue(2);
  //queue.Enqueue(2);
  //queue.Enqueue(1);
  //queue.Enqueue(1);
  //QueType queue1(5);
  //queue1.Enqueue(1);
  //queue1.Enqueue(2);
  //queue1.Enqueue(2);
  //queue1.Enqueue(1);
  //queue1.Enqueue(1);

  //cout << queue.Identical(queue1);
  // 
  // 
  // 
  //QueType queue3(5);
  //queue3.Enqueue(1);
  //queue3.Enqueue(2);
  //queue3.Enqueue(2);
  //cout << Length(queue3)<<endl;

  //QueType queue4(5);
  //cout << queue4.Length();


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

  return 0;
}


