// Header file for Unsorted List ADT.  
template <class ItemType>
struct NodeType;

// Assumption:  ItemType is a type for which the operators "<" 
// and "==" are defined?ither an appropriate built-in type or
// a class that overloads these operators.

using namespace std;

template <class ItemType>
class UnsortedType
{
public:
    UnsortedType();     // Class constructor	
    ~UnsortedType();    // Class destructor

    bool IsFull() const;
    // Determines whether list is full.
    // Post: Function value = (list is full)

    int  LengthIs() const;
    // Determines the number of elements in list.
    // Post: Function value = number of elements in list.

    void MakeEmpty();
    // Initializes list to empty state.
    // Post:  List is empty.

    void RetrieveItem(ItemType& item, bool& found);
    // Retrieves list element whose key matches item's key 
    // (if present).
    // Pre:  Key member of item is initialized.
    // Post: If there is an element someItem whose key matches 
    //       item's key, then found = true and item is a copy 
    //       of someItem; otherwise found = false and item is 
    //       unchanged. 
    //       List is unchanged.

    void InsertItem(ItemType item);
    // Adds item to list.
    // Pre:  List is not full.
    //       item is not in list. 
    // Post: item is in list.
    void DeleteItem(ItemType item);
    // Deletes the element whose key matches item's key.
    // Pre:  Key member of item is initialized.
    //       One and only one element in list has a key matching
    //       item's key.
    // Post: No element in list has a key matching item's key.

    void ResetList();
    // Initializes current position for an iteration through the
    // list.
    // Post: Current position is prior to list.

    void GetNextItem(ItemType& item);
    // Gets the next element in list.
    // Pre:  Current position is defined.
    //       Element at current position is not last in list.
    // Post: Current position is updated to next position.
    //       item is a copy of element at current position.
    void Sort(NodeType<ItemType>* location);
    //b번의 sort 함수 정의
    void Print();
    void GetlistData(NodeType<ItemType>* &loc);
protected:
    NodeType<ItemType>* MinLoc(NodeType<ItemType>* location, NodeType<ItemType>* minPtr);
    //최소값을 찾는 함수 정의
    //minPtr은 리스트의 location 이전에 있는 minimum 노드를 가리키는 입력값임
private:
    NodeType<ItemType>* listData;
    NodeType<ItemType>* currentPos;
    int length;
};

template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
UnsortedType<ItemType>::UnsortedType()  // Class constructor
{
    length = 0;
    listData = NULL;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
// Class destructor
{
    MakeEmpty();
}
template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
    return length;
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item,
    bool& found)
    // Pre:  Key member(s) of item is initialized.
    // Post: If found, item's key matches an element's key in the 
    //       list and a copy of that element has been stored in item;
    //       otherwise, item is unchanged. 
{
    bool moreToSearch;
    NodeType<ItemType>* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        if (item == location->info)
        {
            found = true;
            item = location->info;
        }
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
// item is in the list; length has been incremented.
{
    NodeType<ItemType>* location;

    location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}

template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    // Locate node to be deleted.
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;		// Delete first node.
    }
    else
    {
        while (!(item == (location->next)->info))
            location = location->next;

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
    currentPos = NULL;
}

template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is current item.
{
    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    item = currentPos->info;
}

template<class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc(NodeType<ItemType>* location, NodeType<ItemType>* minPtr) {
    if (location != NULL) {
        if (location->info < minPtr->info)
            minPtr = location;
        return MinLoc(location->next, minPtr);
    }
    else
        return minPtr;
}

template<class ItemType>
void UnsortedType <ItemType>::Sort(NodeType<ItemType>* location) {
    NodeType<ItemType>* minPtr;//최소 값을 가리키는 포인터
    ItemType temp;

    if (location != NULL)//empty 리스트가 아니면
    {
        minPtr = MinLoc(location, location);//***
        temp = minPtr->info;
        minPtr->info = location->info;
        location->info = temp;
        //location에 저장된 값과 minPtr에 저장된 값을 exchange
        Sort(location->next);
        //다음 노드로(location->next)재귀함수 호출
    }
    //base case는 do nothing
}
//위 ***에서 현재 location이 마지막 노드이거나 리스트의 minimum 값을 갖는다면 어떻게 될까? 좀 더 efficient하게 수정하려면?

template<class ItemType>
void UnsortedType<ItemType>::Print() {
    NodeType<ItemType>* read = listData;
    while (read != NULL) {
        cout << read->info << endl;
        read = read->next;
    }
}

template<class ItemType>
void UnsortedType<ItemType>::GetlistData(NodeType<ItemType>* &loc) {
    loc = listData;
}