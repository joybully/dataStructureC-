// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "SortedType.h"
#include "UnsortedType.h"

using namespace std;
//void PrintList(ofstream& outFile, SortedType<int>& list);

template<class ItemType>
void MergeLists(SortedType<ItemType>& l_a, SortedType<ItemType>& l_b, SortedType<ItemType>& result) {
	int a = l_a.LengthIs();
	int b = l_b.LengthIs();
	int c = 0;
	l_a.ResetList();
	l_b.ResetList();
	ItemType item;
	while (c < a) {
		c++;
		l_a.GetNextItem(item);
		result.InsertItem(item);
	}
	c = 0;
	while (c < b) {
		c++;
		l_b.GetNextItem(item);
		result.InsertItem(item);
	}
	l_a.ResetList();
	l_b.ResetList();
}

template<class ItemType>
void MergeLists(UnsortedType<ItemType>& l_a, UnsortedType<ItemType>& l_b, UnsortedType<ItemType>& result) {
	ItemType item1;
	UnsortedType<ItemType> l1;
	UnsortedType<ItemType> l2;
	l_b.ResetList();
	while (l_b.LengthIs() > 0) {
		l_b.ResetList();
		l_b.GetNextItem(item1);
		l_b.DeleteItem(item1);
		l1.InsertItem(item1);
		result.InsertItem(item1);
	}
	l1.ResetList();
	while (l1.LengthIs() > 0) {
		l1.ResetList();
		l1.GetNextItem(item1);
		l2.InsertItem(item1);
		l1.DeleteItem(item1);
	}
	l2.ResetList();
	while (l2.LengthIs() > 0) {
		l2.ResetList();
		l2.GetNextItem(item1);
		l_b.InsertItem(item1);
		l2.DeleteItem(item1);
	}
	l_a.ResetList();
	while (l_a.LengthIs() > 0) {
		l_a.ResetList();
		l_a.GetNextItem(item1);
		l_a.DeleteItem(item1);
		l1.InsertItem(item1);
		result.InsertItem(item1);
	}
	l1.ResetList();
	while (l1.LengthIs() > 0) {
		l1.ResetList();
		l1.GetNextItem(item1);
		l2.InsertItem(item1);
		l1.DeleteItem(item1);
	}
	l2.ResetList();
	while (l2.LengthIs() > 0) {
		l2.ResetList();
		l2.GetNextItem(item1);
		l_a.InsertItem(item1);
		l2.DeleteItem(item1);
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
  //SortedType<int> list;
  //bool found;
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
  //  if (command == "InsertItem")
  //  {
  //    inFile >> item; 
  //    list.InsertItem(item);
  //    outFile << item;
  //    outFile << " is inserted" << endl;
  //  }
  //  else if (command == "DeleteItem")
  //  {
  //    inFile >> item;
  //    list.DeleteItem(item);
  //    outFile << item;
  //    outFile << " is deleted" << endl;
  //  }
  //  else if (command == "RetrieveItem")
  //  {
  //    inFile >> item;

  //    list.RetrieveItem(item, found);
  //    if (found)
  //      outFile << item << " found in list." << endl;
  //    else outFile << item  << " not in list."  << endl;  
  //  } 
  //  else if (command == "LengthIs")  
  //    outFile << "Length is " << list.LengthIs() << endl;
  //  else if (command == "IsFull")
  //    if (list.IsFull())
  //      outFile << "List is full." << endl;
  //    else outFile << "List is not full."  << endl;  
  //
  //  else PrintList(outFile, list);
  //  numCommands++;
  //  cout <<  " Command " << command << " completed." 
  //       << endl;
  //  inFile >> command;
  //}
 
  //cout << "Testing completed."  << endl;
  //inFile.close();
  //outFile.close();

	//SortedType<int> Sorted1;
	//SortedType<int> Sorted2;
	//SortedType<int> Sorted3;
	//int item1;
	//Sorted1.InsertItem(9);
	//Sorted1.InsertItem(5);
	//Sorted1.InsertItem(3);
	//Sorted1.InsertItem(7);
	//Sorted1.InsertItem(1);
	//Sorted2.InsertItem(8);
	//Sorted2.InsertItem(4);
	//Sorted2.InsertItem(6);
	//Sorted2.InsertItem(10);
	//Sorted2.InsertItem(2);
	//MergeLists(Sorted1, Sorted2, Sorted3);
	//Sorted3.ResetList();
	//Sorted3.GetNextItem(item1);
	//std::cout << item1 << '\n';
	//Sorted3.GetNextItem(item1);
	//std::cout << item1 << '\n';
	//Sorted3.GetNextItem(item1);
	//std::cout << item1 << '\n';
	//Sorted3.GetNextItem(item1);
	//std::cout << item1 << '\n';
	//Sorted3.GetNextItem(item1);
	//std::cout << item1 << '\n';
	//Sorted3.GetNextItem(item1);
	//std::cout << item1 << '\n';
	//Sorted3.GetNextItem(item1);
	//std::cout << item1 << '\n';
	//Sorted3.GetNextItem(item1);
	//std::cout << item1 << '\n';
	//Sorted3.GetNextItem(item1);
	//std::cout << item1 << '\n';
	//Sorted3.GetNextItem(item1);
	//std::cout << item1 << '\n';
	//Sorted3.ResetList();

	//SortedType<int> Sorted4;
	//SortedType<int> Sorted5;
	//SortedType<int> Sorted6;
	//int item2;
	//Sorted4.InsertItem(9);
	//Sorted4.InsertItem(5);
	//Sorted4.InsertItem(3);
	//Sorted4.InsertItem(7);
	//Sorted4.InsertItem(1);
	//Sorted5.InsertItem(8);
	//Sorted5.InsertItem(4);
	//Sorted5.InsertItem(6);
	//Sorted5.InsertItem(10);
	//Sorted5.InsertItem(2);
	//Sorted4.MergeLists(Sorted5, Sorted6);
	//Sorted6.ResetList();
	//Sorted6.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Sorted6.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Sorted6.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Sorted6.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Sorted6.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Sorted6.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Sorted6.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Sorted6.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Sorted6.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Sorted6.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Sorted6.ResetList();

	//UnsortedType<int> Unsorted7;
	//UnsortedType<int> Unsorted8;
	//UnsortedType<int> Unsorted9;
	//int item2;
	//Unsorted7.InsertItem(9);
	//Unsorted7.InsertItem(5);
	//Unsorted7.InsertItem(3);
	//Unsorted7.InsertItem(7);
	//Unsorted7.InsertItem(1);
	//Unsorted7.InsertItem(8);
	//Unsorted8.InsertItem(4);
	//Unsorted8.InsertItem(6);
	//Unsorted8.InsertItem(10);
	//Unsorted8.InsertItem(2);
	//MergeLists(Unsorted7, Unsorted8, Unsorted9);
	//Unsorted9.ResetList();
	//Unsorted9.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted9.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted9.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted9.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted9.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted9.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted9.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted9.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted9.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted9.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted9.ResetList();
	//Unsorted7.ResetList();
	//Unsorted7.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted7.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted7.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted7.ResetList();
	//Unsorted8.ResetList();
	//Unsorted8.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted8.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted8.ResetList();
	
	//UnsortedType<int> Unsorted10;
	//UnsortedType<int> Unsorted11;
	//UnsortedType<int> Unsorted12;
	//int item2;
	//Unsorted10.InsertItem(9);
	//Unsorted10.InsertItem(5);
	//Unsorted10.InsertItem(3);
	//Unsorted10.InsertItem(7);
	//Unsorted10.InsertItem(1);
	//Unsorted10.InsertItem(8);
	//Unsorted11.InsertItem(4);
	//Unsorted11.InsertItem(6);
	//Unsorted11.InsertItem(10);
	//Unsorted11.InsertItem(2);
	//Unsorted10.MergeLists( Unsorted11, Unsorted12);
	//Unsorted12.ResetList();
	//Unsorted12.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted12.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted12.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted12.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted12.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted12.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted12.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted12.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted12.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted12.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted12.ResetList();
	//Unsorted10.ResetList();
	//Unsorted10.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted10.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted10.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted10.ResetList();
	//Unsorted11.ResetList();
	//Unsorted11.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted11.GetNextItem(item2);
	//std::cout << item2 << '\n';
	//Unsorted11.ResetList();

	//UnsortedType<int> Unsorted13;
	//int item4;
	//Unsorted13.InsertItem(9);
	//Unsorted13.InsertItem(3);
	//Unsorted13.InsertItem(2);
	//Unsorted13.InsertItem(7);
	//Unsorted13.DeleteItem_B(2);
	//Unsorted13.ResetList();
	//int leng = Unsorted13.LengthIs();
	//while (leng > 0) {
	//	leng--;
	//	Unsorted13.GetNextItem(item4);
	//	std::cout << item4 << '\n';
	//}

	/*UnsortedType<int> Unsorted14;
	int item2;
	Unsorted14.InsertItem(2);
	Unsorted14.InsertItem(2);
	Unsorted14.InsertItem(9);
	Unsorted14.InsertItem(3);
	Unsorted14.InsertItem(7);
	Unsorted14.InsertItem(2);
	Unsorted14.InsertItem(8);
	Unsorted14.InsertItem(4);
	Unsorted14.InsertItem(6);
	Unsorted14.InsertItem(10);
	Unsorted14.InsertItem(2);
	Unsorted14.InsertItem(2);
	Unsorted14.DeleteItem_B(2);
	Unsorted14.ResetList();
	int leng = Unsorted14.LengthIs();
	while (leng > 0) {
		leng--;
		Unsorted14.GetNextItem(item2);
		std::cout << item2 << '\n';
	}*/

	//SortedType<int> Sorted15;
	//int item10;
	//Sorted15.InsertItem(1);
	//Sorted15.InsertItem(2);
	//Sorted15.InsertItem(3);
	//Sorted15.InsertItem(4);
	//Sorted15.InsertItem(5);
	//Sorted15.InsertItem(6);
	//Sorted15.InsertItem(7);
	//Sorted15.InsertItem(8);
	//Sorted15.InsertItem(9);
	//Sorted15.InsertItem(10);
	//Sorted15.ResetList();
	//Sorted15.DeleteItem_A(8);
	//Sorted15.ResetList();
	//int leng4 = Sorted15.LengthIs();
	//while (leng4 > 0) {
	//	leng4--;
	//	Sorted15.GetNextItem(item10);
	//	std::cout << item10 << '\n';
	//}

	/*SortedType<int> Sorted16;
	int item11;
	Sorted16.InsertItem(1);
	Sorted16.InsertItem(2);
	Sorted16.InsertItem(3);
	Sorted16.InsertItem(4);
	Sorted16.InsertItem(5);
	Sorted16.InsertItem(7);
	Sorted16.InsertItem(7);
	Sorted16.InsertItem(7);
	Sorted16.InsertItem(9);
	Sorted16.InsertItem(10);
	Sorted16.ResetList();
	Sorted16.DeleteItem_B(7);
	Sorted16.ResetList();
	int leng4 = Sorted16.LengthIs();
	while (leng4 > 0) {
		leng4--;
		Sorted16.GetNextItem(item11);
		std::cout << item11 << '\n';
	}*/

	return 0;
}


//void PrintList(ofstream& dataFile, SortedType<int>& list)
//// Pre:  list has been initialized.      
////       dataFile is open for writing.   
//// Post: Each component in list has been written to dataFile.
////       dataFile is still open.         
//{
//  int length;
//  int item;
//  list.ResetList();
//  length = list.LengthIs();
//  dataFile << "List Items: " << endl;
//  for (int counter = 1; counter <= length; counter++)
//  {
//    list.GetNextItem(item);
//    dataFile << item << endl;
//  }
//  dataFile << endl;
//}


