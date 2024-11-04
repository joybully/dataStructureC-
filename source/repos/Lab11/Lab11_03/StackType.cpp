// Implementation file for StackType.h

#include <cstddef>
#include <new>
#include "StackType.h"
#include<iostream>

using namespace std;

int Time_Stamp = 0;

void StackType::Push(ItemType newItem)
// Adds newItem to the top of the stack.
// Pre:  Stack has been initialized.
// Post: If stack is full, FullStack exception is thrown;
//       else newItem is at the top of the stack.

{
    pq.Enqueue(Time_Stamp);
    array[Time_Stamp] = newItem;
    Time_Stamp++;
    length++;
}
void StackType::Pop()
// Removes top item from Stack and returns it in item.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else top element has been removed.
{
  if (IsEmpty())
    throw EmptyStack();
  else
  {  
      Time_Stamp--;
      ItemType item = 1;
      pq.Dequeue(item);
      length--;
  }
}
ItemType StackType::Top()
// Returns a copy of the top item in the stack.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else a copy of the top element is returned.
{
  if (IsEmpty())
    throw EmptyStack();
  else
    return array[Time_Stamp-1];
}
bool StackType::IsEmpty() const
// Returns true if there are no elements on the stack; false otherwise.
{
    return (length == 0);
}
//bool StackType::IsFull() const
//// Returns true if there is no room for another ItemType 
////  on the free store; false otherwise.
//{
//  NodeType* location;
//  try
//  {
//
//      pq.Enqueue();
//  }
//  catch(std::bad_alloc)
//  {
//    return true;
//  }
//}

StackType::~StackType()
// Post: stack is empty; all items have been deallocated.
{
}

StackType::StackType()	// Class constructor.
{
    length = 0;
}


//The Push operation has O(1) complexity, because it doesn¡¯t matter where the item is
//stored in the structure. The Pop operation has O(N) complexity, because the item with
//the largest time stamp must be searched for.Therefore, Push is the same in both implementations, but Pop is not.If the priority queue is implemented using a heap with the
//largest value having the highest priority, Popand Push have O(log2N) complexity.

int main() {
    StackType st;
    st.Push(5);
    st.Push(3);
    st.Push(2);
    st.Push(8);
    st.Push(4);
    st.Push(0);
    st.Push(9);
    while (!st.IsEmpty()) {
        cout << st.Top() << endl;
        st.Pop();
    }
    return 0;
}