template<class ItemType>
class ListIterator;
template<class ItemType>
class ListNode;


template <class ItemType>
class List
{
	friend class ListIterator<ItemType>;
public:
	List();
	~List();
	// 기타 연산자들
	int  LengthIs() const;
	void MakeEmpty();
	void ResetList();
	void GetNextItem(ItemType& item);
	void InsertItem(ItemType item);
private:
	ListNode<ItemType>* listData;
	int length;
	ListNode<ItemType>* getcurrentLine;
	ListNode<ItemType>* currentLine;
	ListNode<ItemType>* Header;
	ListNode<ItemType>* Trailer;
};

template<class ItemType>
class ListIterator
{
public:
	ListIterator(const List<ItemType> &l) : list(l), current(l.listData) {}
	bool NotNull();
	bool NextNotNull();
	void ResetList();
	int GetCurrentItem(ItemType& item);
private:
	const List<ItemType>& list;
	ListNode<ItemType>* current;

};

//template<class ItemType>
//ListIterator<ItemType>::ListIterator(const List<ItemTye>& list) {
//	
//}

template<class ItemType>
class ListNode
{

	friend class List<ItemType>;
	friend class ListIterator<ItemType>;
private:
	ItemType data;
	ListNode* next;
	ListNode* back;
};



template<class ItemType>
List<ItemType>::List() {
	Header = new ListNode<ItemType>;
	Trailer = new ListNode<ItemType>;
	Header->next = Trailer;
	Header->back = Trailer;
	Trailer->back = Header;
	Trailer->next = Header;
	getcurrentLine = Header;
	currentLine = Header;
	length = 0;
	listData = Header;
}

template <class ItemType>
int List<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
	return length;
}

template <class ItemType>
void List<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	ListNode<ItemType>* tempPtr;
	int leng = (*this).LengthIs();
	if (leng > 0) {
		listData = Header->next;
		for (int i = 0; i < leng; i++)
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

template <class ItemType>
void List<ItemType>::ResetList() {
	getcurrentLine = Header;
}

template <class ItemType>
void List<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is 
//        current item.
{
	if (getcurrentLine == Header)
		getcurrentLine = getcurrentLine->next;
	else if (getcurrentLine == Trailer) {
		getcurrentLine = getcurrentLine->next;
		getcurrentLine = getcurrentLine->next;
	}
	item = getcurrentLine->data;
	getcurrentLine = getcurrentLine->next;

}

template<class ItemType>
void List<ItemType>::InsertItem(ItemType item)
{
	ListNode<ItemType>* newLine;
	newLine = new ListNode<ItemType>;
	newLine->data = item;
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

template <class ItemType>
List<ItemType>::~List()
// Post: List is empty; all items have been deallocated.
{
	ListNode<ItemType>* tempPtr;
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







template <class ItemType>
bool ListIterator<ItemType>::NotNull() {
	if (current)	return true;
	else	return false;
}

template<class ItemType>
bool ListIterator<ItemType>::NextNotNull() {
	if (current && current->next)	return true;
	else	return false;
}

template <class ItemType>
void ListIterator<ItemType>::ResetList() {
	current = list.listData;
}

template<class ItemType>
int ListIterator<ItemType>::GetCurrentItem(ItemType& item) {
	if (NotNull()) {
		if (list.Header == current) {
			current = current->next;
		}
		else if(list.Trailer == current) {
			current = current->next;
			current = current->next;
		}
		item = current->data;
		current = current->next;
		return 1;
	}
	else return 0;
}

//int sum(const List<int> & 1) {
//	Iterator iter(1);
//	int sum = 0;
//
//	iter.ResetList();
//	while (iter.GetCurrentItem(item))
//		sum += item;
//}