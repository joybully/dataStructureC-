// File: StackType.cpp

#include "StackType.h"
#include <iostream>
StackType::StackType()
{
  top = -1;
}

//Exercise3
doublestack::doublestack() {
    top_big = 200;
    top_small = -1;
}

bool StackType::IsEmpty() const
{
  return (top == -1);
}

bool StackType::IsFull() const
{
  return (top ==  MAX_ITEMS-1);
}

void StackType::Push(ItemType newItem)
{
  if( IsFull() )
    throw FullStack();
  top++;
  items[top] = newItem;
}


//Exercise3
void doublestack::Push(int item) {
    if (top_small + 1 == top_big)
        throw FullStack();
    if (item <= 1000) {
        top_small++;
        items[top_small] = item;
    }
    else {
        top_big--;
        items[top_big] = item;
    }
}

//Exercise3
void doublestack::Print() {
    for (int i = top_small; i >=0; i--) {
        std::cout << items[i] << '\n';
    }
    for (int i = top_big; i <200; i++) {
        std::cout << items[i] << '\n';
    }
}

//Exercise4
void StackType::ReplaceItem(int oldItem, int newItem) {
    StackType stack1;
    while (!(*this).IsEmpty()) {
        if ((*this).Top() == oldItem) {
            stack1.Push(newItem);
            (*this).Pop();
        }
        else {
            stack1.Push((*this).Top());
            (*this).Pop();
        }
    }
    while (!stack1.IsEmpty()) {
        (*this).Push(stack1.Top());
        stack1.Pop();
    }
}


void StackType::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  top--;
}

ItemType StackType::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}    



