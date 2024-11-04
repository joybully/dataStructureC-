// Header file for Unsorted List ADT.  
template <class ItemType>
struct LineType;
#include <stddef.h>
#include <iostream>
#include <ostream>
using namespace std;
// Assumption:  ItemType is a type for which the operators "<" 
// and "==" are defined-either an appropriate built-in type or
// a class that overloads these operators.

template <class ItemType>
class TextEditor
{
public:
    TextEditor();     // Class constructor	
    ~TextEditor();    // Class destructor

    //bool IsFull() const;
    // Determines whether list is full.
    // Post: Function value = (list is full)

    int  LengthIs() const;
    // Determines the number of elements in list.
    // Post: Function value = number of elements in list.

    void MakeEmpty();
    // Initializes list to empty state.
    // Post:  List is empty.

    //void RetrieveItem(ItemType& item, bool& found);
    // Retrieves list element whose key matches item's key 
    // (if present).
    // Pre:  Key member of item is initialized.
    // Post: If there is an element someItem whose key matches 
    //       item's key, then found = true and item is a copy 
    //       of someItem; otherwise found = false and item is 
    //       unchanged. 
    //       List is unchanged.

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

    //void DeleteItem(ItemType item);
    void InsertLine(ItemType item);
    void GoToTop();
    void GoToBottom();
    void GoToTop(LineType<ItemType>*&linePtr);
    void GoToBottom(LineType<ItemType>*&linePtr);

private:
    LineType<ItemType>* listData;
    int length;
    LineType<ItemType>* getcurrentLine;
    LineType<ItemType>* currentLine;
    LineType<ItemType>* Header;
    LineType<ItemType>* Trailer;
};

template<class ItemType>
struct LineType
{
    ItemType info;
    LineType* next;
    LineType* back;
};

template <class ItemType>
TextEditor<ItemType>::TextEditor()  // Class constructor
{
    Header = new LineType<ItemType>;
    Trailer = new LineType<ItemType>;
    Header->next = Trailer;
    Header->back = Trailer;
    Trailer->back = Header;
    Trailer->next = Header;
    getcurrentLine = Header;
    currentLine = Header;
    length = 0;
    listData = Header;
}

//template<class ItemType>
//bool TextEditor<ItemType>::IsFull() const
//// Returns true if there is no room for another ItemType 
////  on the free store; false otherwise.
//{
//    LineType<ItemType>* location;
//    try
//    {
//        location = new LineType<ItemType>;
//        delete location;
//        return false;
//    }
//    catch (std::bad_alloc exception)
//    {
//        return true;
//    }
//}

template <class ItemType>
int TextEditor<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
    return length;
}

template <class ItemType>
void TextEditor<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    LineType<ItemType>* tempPtr;
    int leng = (*this).LengthIs();
    if (leng > 0) {
        listData = Header->next;
        for (int i = 0; i < leng ; i++)
        {
            tempPtr = listData;
            listData = listData->next;
            delete tempPtr;
        }
    }
    Header->next = Trailer;
    Header->back = Trailer;
    Trailer->back = Header;
    Trailer->next = Header;
    length = 0;
}

//template <class ItemType>
//void TextEditor<ItemType>::RetrieveItem(ItemType& item,
//    bool& found)
//{
//    bool moreToSearch;
//    LineType<ItemType>* location;
//
//    location = listData;
//    found = false;
//    moreToSearch = (location != NULL);
//    int leng = LengthIs();
//    int i = 0;
//    while (moreToSearch && !found)
//    {
//        if (location->info < item)
//        {
//            location = location->next;
//            i++;
//            moreToSearch = (i < leng);
//        }
//        else if (item == location->info)
//        {
//            found = true;
//            item = location->info;
//        }
//        else
//            moreToSearch = false;
//    }
//}


template <class ItemType>
void TextEditor<ItemType>::ResetList() {
    getcurrentLine = Header;
}

template <class ItemType>
void TextEditor<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is 
//        current item.
{
    if (getcurrentLine== Header)
        getcurrentLine = getcurrentLine->next;
    else if (getcurrentLine == Trailer) {
        getcurrentLine = getcurrentLine->next;
        getcurrentLine = getcurrentLine->next;
    }
    item = getcurrentLine->info;
    getcurrentLine = getcurrentLine->next;

}

template <class ItemType>
TextEditor<ItemType>::~TextEditor()
// Post: List is empty; all items have been deallocated.
{
    LineType<ItemType>* tempPtr;
    int leng = (*this).LengthIs();
    if (leng > 0) {
        for (int i = 0; i < leng + 2; i++)
        {
            tempPtr = listData;
            listData = listData->next;
            delete tempPtr;
        }
    }
    else {
        for (int i = 0; i < 2; i++)
        {
            tempPtr = listData;
            listData = listData->next;
            delete tempPtr;
        }
    }
}


template<class ItemType>
void TextEditor<ItemType>::InsertLine(ItemType item)
{
    LineType<ItemType>* newLine;
    newLine = new LineType<ItemType>;
    newLine->info = item;
    if (length > 0)
    {
        currentLine->next = newLine;
        Trailer->back = newLine;
        newLine->back = currentLine;
        newLine->next = Trailer;
        currentLine = newLine;
    }
    else {
        currentLine = newLine;
        listData = Header;
        Header->next = newLine;
        Trailer->back = newLine;
        newLine->back = Header;
        newLine->next = Trailer;
    }
    length++;
}

//template<class ItemType>
//void TextEditor<ItemType>::DeleteItem(ItemType item)
//{
//    LineType<ItemType>* location;
//    LineType<ItemType>* predLoc;
//    bool found;
//
//    FindItem(listData, item, location, predLoc, found);
//    if (predLoc == location) // Only node in list?
//        listData = NULL;
//    else
//    {
//        predLoc->next = location->next;
//        if (location == listData) // Deleting last node in list?
//            listData = predLoc;
//    }
//    delete location;
//    length--;
//}

//GoToTop의 경우 Trailer의 다음 노드가 Header인 경우에 Trailer를, 다음 노드가 Header가 아닌 경우에는 다음
//노드를 currentLine에 할당하면 된다.
//GoToBottom의 경우 Header의 이전 노드가 Trailer인 경우에 Header를, 이전 노드가 Trailer가 아닌 경우에는
//이전 노드를 currentLine에 할당하면 된다.
//이렇게 할 경우, GoToTop과 GoToBottom함수를 O(1)로 작성할 수 있다.
template <class ItemType>
void TextEditor<ItemType>::GoToTop() {
    if (length == 0) {
        while (currentLine != Trailer) {
            currentLine = currentLine->next;
        }
    }
    else {
        while (currentLine->next != Trailer) {
            currentLine = currentLine->next;
        }
    }
}   

template <class ItemType>
void TextEditor<ItemType>::GoToBottom() {
    if (length == 0) {
        while (currentLine != Header) {
            currentLine = currentLine->back;
        }
    }
    else {
        while (currentLine->back != Header) {
            currentLine = currentLine->back;
        }
    }
}

template <class ItemType>
void TextEditor<ItemType>::GoToTop(LineType<ItemType> *&linePtr) {
    linePtr = Trailer;
    if (length == 0) {
        while (linePtr != Trailer) {
            linePtr = linePtr->next;
        }
    }
    else {
        while (linePtr->next != Trailer) {
            linePtr = linePtr->next;
        }
    }
}

template <class ItemType>
void TextEditor<ItemType>::GoToBottom(LineType<ItemType> *&linePtr) {
    linePtr = Header;
    if (length == 0) {
        while (linePtr != Header) {
            linePtr = linePtr->back;
        }
    }
    else {
        while (linePtr->back != Header) {
            linePtr = linePtr->back;
        }
    }
}