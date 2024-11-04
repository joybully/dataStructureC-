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
  return (length >= maxQue );
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
    rear = (rear +1) % maxQue;
    length += 1;
    items[rear] = newItem;
  }
}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    front = (front + 1) % maxQue;
    length -= 1;
    item = items[front];
  }
}

void QueType::ReplaceItem(ItemType oldItem, ItemType newItem) {
    for (int i = 0; i < maxQue; i++) {
        if (items[i] == oldItem) {
            items[i] = newItem;
        }
    }
}

bool QueType::Identical(QueType& queue) {
    QueType queue1;
    QueType queue2;
    bool re = true;
    while (!queue.IsEmpty()&&(!((*this).IsEmpty()))) {
        ItemType item1;
        ItemType item2;
        queue.Dequeue(item1);
        (*this).Dequeue(item2);
        if (item1 != item2) {
            re = false;
        }
        queue1.Enqueue(item1);
        queue2.Enqueue(item2);
    }
    if (queue.IsEmpty() != (*this).IsEmpty()) {
        re = false;
    }
    while (!queue.IsEmpty()) {
        ItemType item1;
        queue.Dequeue(item1);
        queue1.Enqueue(item1);
    }
    while (!(*this).IsEmpty()) {
        ItemType item1;
        (*this).Dequeue(item1);
        queue2.Enqueue(item1);
    }
    while (!queue1.IsEmpty()) {
        ItemType item1;
        queue1.Dequeue(item1);
        queue.Enqueue(item1);
    }
    while (!queue2.IsEmpty()) {
        ItemType item1;
        queue2.Dequeue(item1);
        (*this).Enqueue(item1);
    }
    return re;
}

int QueType::Length() {
    return length;
};
