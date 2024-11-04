// Header file for Unsorted List ADT.  
template <class ItemType>
struct NodeType;

// Assumption:  ItemType is a type for which the operators "<" 
// and "==" are defined?ither an appropriate built-in type or
// a class that overloads these operators.

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
    void SumList(UnsortedType<ItemType> *result);
    void printList();
private:
    NodeType<ItemType>* listData;
    int length;
    NodeType<ItemType>* currentPos;
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
void UnsortedType<ItemType>::SumList(UnsortedType<ItemType>* result) {
    int leng = LengthIs();
    int i = 0;
    ResetList();
    ItemType Item1;
    int sum = 0;
    while(i < leng) {
        i += 1;
        (*this).GetNextItem(Item1);
        sum += Item1;
        (*result).InsertItem(sum);
    }
}

template<class ItemType>
void UnsortedType<ItemType>::printList() {
    ResetList();
    ItemType item1;
    int leng = LengthIs();
    int i = 0;
    while (i < leng) {
        i++;
        GetNextItem(item1);
        std::cout << item1<<'\n';
    }
}