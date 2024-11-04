#include "ItemType.h"

//   The user of this file must provied a file "ItemType.h" that defines:
//       ItemType : the class definition of the objects on the stack.
//       MAX_ITEMS: the maximum number of items on the stack. 

//   Class specification for Stack ADT in file Stack1.h

//Exercise3
const int MAX_ITEMS2 = 200;


//Exercise3
class doublestack
{
private:
	int top_small; //1000보다 작거나 같은 스택의 top
	int top_big; // 1000보다 큰 스택의 top
	int items[MAX_ITEMS2];
public:
	doublestack();
	void Push(int item); //C에서 구현할 push 연산
	void Print(); //stack 의 상황을 보여줄 수 있는 함수(채점시)
	// … (필요하다 생각되는…)
};


class FullStack
// Exception class thrown by Push when stack is full.
{};

class EmptyStack
// Exception class thrown by Pop and Top when stack is emtpy.
{};


class StackType
{
public:

  StackType();
  // Class constructor.
  bool IsFull() const;
  // Function: Determines whether the stack is full.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is full)
  bool IsEmpty() const;
  // Function: Determines whether the stack is empty.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is empty)
  void Push(ItemType item);
  // Function: Adds newItem to the top of the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is full), FullStack exception is thrown;
  //     otherwise, newItem is at the top of the stack.
  void Pop();
  // Function: Removes top item from the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is empty), EmptyStack exception is thrown;
  //     otherwise, top element has been removed from stack.
  ItemType Top();
  // Function: Returns a copy of top item on the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is empty), EmptyStack exception is thrown;
  //     otherwise, top element has been removed from stack.
  void ReplaceItem(int oldItem, int newItem);

       
private:
  int top;
  ItemType  items[MAX_ITEMS];		
};

