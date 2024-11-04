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
    StackType stack1;
    for (int i = 0; i < 5; i++) {
        stack1.Push(i);
    }
    StackType stack2;
    stack1.Copy(stack2);
    for (int i = 0; i < 5; i++) {
        int item2;
        item2 = stack2.Top();
        std::cout << item2;
        stack2.Pop();
    }
  return 0;
}


