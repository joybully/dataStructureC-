// The following definitions go into file ItemType.cpp. 
#include <fstream>
#include <iostream>
#include "ItemType.h"
using namespace std;

ItemType::ItemType()
{ 
  value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const 
{
  if (value < otherItem.value)
    return LESS;
  else if (value > otherItem.value)
    return GREATER;
  else return EQUAL;
}

void ItemType::Initialize(int number) 
{
  value = number;
}

void ItemType::Print(std::ostream& out) const 
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
  out << value;
}

int BinarySearch(int array[], int sizeOfArray, int value)
{
    int midPoint;
    int first = 0;
    int last = sizeOfArray - 1;

    bool moreToSearch = first <= last;
    bool found = false;
    while (!found)
    {
        midPoint = (first + last) / 2;
        if (moreToSearch == false) {


            //A-question code
            //To execute code below, you should comment out B,C-question code
            return -1;
            break;


            //B-question code
            //To execute code below, you should comment out A,C-question code
            /*if (midPoint - 1 <= 0) {
                return array[0];
            }
            else {
                return array[midPoint];
            }
            break;*/


            //C-question code
            //To execute code below, you should comment out A,B-question code
            /*if (midPoint + 1 >= sizeOfArray) {
                return array[sizeOfArray - 1];
            }
            else if (midPoint == 0) {
                return array[midPoint];
            }
            else {
                return array[midPoint + 1];
            }
            break;*/


        }
        else if (value < array[midPoint]) {
            last = midPoint - 1;
            moreToSearch = first <= last;
        }
        else if (value > array[midPoint]) {
            first = midPoint + 1;
            moreToSearch = first <= last;
        }
        else if (value == array[midPoint]) {
            found = true;
            moreToSearch = first <= last;
            return midPoint;
            break;
        }
    }
}

int main() {
    int array1[5];
    array1[0] = 1;
    array1[1] = 3;
    array1[2] = 8;
    array1[3] = 9;
    array1[4] = 12;
    cout << BinarySearch(array1, 5, 8) << endl;
    cout << BinarySearch(array1, 5, 10) << endl;
    int list[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
    int result = BinarySearch(list, 11, 13);
    cout << result << endl;
    result = BinarySearch(list, 11, 7);
    cout << result << endl;
    result = BinarySearch(list, 11, 0);
    cout << result << endl;
    return 0;

};