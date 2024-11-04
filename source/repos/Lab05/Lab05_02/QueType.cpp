#include "QueType.h"

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = max;
    front = maxQue - 1;
    rear = maxQue - 1;
    length = 0;
    items = new ItemType[maxQue];
    minimum_pos = maxQue - 1;
    for (int i = 0; i < maxQue; i++) {
        items[i] = -1;
    }
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = 500;
    front = maxQue - 1;
    rear = maxQue - 1;
    length = 0;
    items = new ItemType[maxQue];
    minimum_pos = maxQue - 1;
    for (int i = 0; i < maxQue; i++) {
        items[i] = -1;
    }
}
QueType::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
  length = 0;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
    return (length == 0);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return (length >= maxQue);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
      if (IsEmpty()) {
          minimum_pos = maxQue-1;
          items[maxQue - 1] = newItem;
          length += 1;
      }
      else {
          int count = 0;
          for (int i = 0; i < maxQue && count == 0; i++) {
              if (items[i] == -1) {
                  items[i] = newItem;
                  count = 1;
                  length += 1;
                  if (newItem < items[minimum_pos]) {
                      minimum_pos = i;
                  }
              }
          }
      }
  }
}

//void QueType::Dequeue(ItemType& item)
//// Post: If (queue is not empty) the front of the queue has been 
////       removed and a copy returned in item; 
////       othersiwe a EmptyQueue exception has been thrown.
//{
//  if (IsEmpty())
//    throw EmptyQueue();
//  else
//  {
//      front = (front + 1) % maxQue;
//      length -= 1;
//      item = items[front];
//  }
//}

void QueType::MinDequeue(ItemType& item) {
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        item = items[minimum_pos];
        items[minimum_pos] = -1;
        length -= 1;
        int count = 0;
        if (IsEmpty()) {
            minimum_pos = maxQue-1;
        }
        else {
            for (int i = 0; ((i < maxQue)&&(count==0)); i++) {
                if (items[i] != -1) {
                    minimum_pos = i;
                    count += 1;
                }
            }
            for (int i = 0; i < maxQue; i++) {
                if ((items[i] != -1)&&(items[i]<items[minimum_pos])) {
                    minimum_pos = i;
                }
            }
        }
    }
};