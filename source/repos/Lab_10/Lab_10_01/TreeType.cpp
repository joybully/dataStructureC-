
#include "TreeType.h"
#include <iostream>
#include "SortedType.h"
#include "UnsortedType.h"
using namespace std;

struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};

bool TreeType::IsFull() const
// Returns true if there is no room for another item 
//  on the free store; false otherwise.
{
  TreeNode* location;
  try
  {
    location = new TreeNode;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

bool TreeType::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
  return root == NULL;
}

int CountNodes(TreeNode* tree);

int TreeType::LengthIs() const
// Calls recursive function CountNodes to count the 
// nodes in the tree.
{
  return CountNodes(root);
}


int CountNodes(TreeNode* tree)
// Post: returns the number of nodes in the tree.
{
  if (tree == NULL)
    return 0;
  else 
    return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

void Retrieve(TreeNode* tree, 
     ItemType& item, bool& found);

void TreeType::RetrieveItem(ItemType& item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
  Retrieve(root, item, found);
}


void Retrieve(TreeNode* tree, 
     ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem; 
//       otherwise found is false and item is unchanged.
{
  if (tree == NULL)
    found = false;                     // item is not found.
  else if (item < tree->info)      
    Retrieve(tree->left, item, found); // Search left subtree.
  else if (item > tree->info)
    Retrieve(tree->right, item, found);// Search right subtree.
  else
  {
    item = tree->info;                 // item is found.
    found = true;
   }
} 

void Insert(TreeNode*& tree, ItemType item);

void TreeType::InsertItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
  Insert(root, item);
}


void Insert(TreeNode*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
  if (tree == NULL)
  {// Insertion place found.
    tree = new TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info)
    Insert(tree->left, item);    // Insert in left subtree.
  else
    Insert(tree->right, item);   // Insert in right subtree.
} 
void DeleteNode(TreeNode*& tree);

void Delete(TreeNode*& tree, ItemType item);

void TreeType::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
  Delete(root, item);
}


void Delete(TreeNode*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
  if (item < tree->info)
    Delete(tree->left, item);   // Look in left subtree.
  else if (item > tree->info)
    Delete(tree->right, item);  // Look in right subtree.
  else
    DeleteNode(tree);           // Node found; call DeleteNode.
}   

void GetPredecessor(TreeNode* tree, ItemType& data);

void DeleteNode(TreeNode*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no 
//       longer in the tree.  If tree is a leaf node or has only 
//       non-NULL child pointer the node pointed to by tree is 
//       deleted; otherwise, the user's data is replaced by its 
//       logical predecessor and the predecessor's node is deleted.
{
  ItemType data;
  TreeNode* tempPtr;

  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else if (tree->right == NULL)
  {
    tree = tree->left;
    delete tempPtr;
  }
  else
  {
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data);  // Delete predecessor node.
  }
}

void GetPredecessor(TreeNode* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}

void PrintTree(TreeNode* tree, std::ofstream& outFile) 
// Prints info member of items in tree in sorted order on outFile.
{
  if (tree != NULL)
  {
    PrintTree(tree->left, outFile);   // Print left subtree.
    outFile << tree->info;
    PrintTree(tree->right, outFile);  // Print right subtree.
  }
}

void TreeType::Print(std::ofstream& outFile) const
// Calls recursive function Print to print items in the tree.
{
  PrintTree(root, outFile);
}

TreeType::TreeType()
{
  root = NULL;
}

void Destroy(TreeNode*& tree);

TreeType::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
  Destroy(root);
}


void Destroy(TreeNode*& tree)
// Post: tree is empty; nodes have been deallocated.
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

void TreeType::MakeEmpty()
{
  Destroy(root);
  root = NULL;
}


void CopyTree(TreeNode*& copy, 
     const TreeNode* originalTree);

TreeType::TreeType(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
//  into root.
{
  CopyTree(root, originalTree.root);
}

void TreeType::operator= 
     (const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
// into root.
{
  {
  if (&originalTree == this)
    return;             // Ignore assigning self to self
  Destroy(root);      // Deallocate existing tree nodes
  CopyTree(root, originalTree.root);
  }

}
void CopyTree(TreeNode*& copy, 
     const TreeNode* originalTree)
// Post: copy is the root of a tree that is a duplicate 
//       of originalTree.
{
  if (originalTree == NULL)
    copy = NULL;
  else
  {
    copy = new TreeNode;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}
// Function prototypes for auxiliary functions.

void PreOrder(TreeNode*, QueType&);
// Enqueues tree items in preorder.


void InOrder(TreeNode*, QueType&);
// Enqueues tree items in inorder.


void PostOrder(TreeNode*, QueType&);
// Enqueues tree items in postorder.


void TreeType::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in 
// the desired order.
{
  switch (order)
  {
    case PRE_ORDER : PreOrder(root, preQue);
                     break;
    case IN_ORDER  : InOrder(root, inQue);
                     break;
    case POST_ORDER: PostOrder(root, postQue);
                     break;
  }
}


void PreOrder(TreeNode* tree, 
     QueType& preQue)
// Post: preQue contains the tree items in preorder.
{
  if (tree != NULL)
  {
    preQue.Enqueue(tree->info);
    PreOrder(tree->left, preQue);
    PreOrder(tree->right, preQue);
  }
}


void InOrder(TreeNode* tree, 
     QueType& inQue)
// Post: inQue contains the tree items in inorder.
{
  if (tree != NULL)
  {
    InOrder(tree->left, inQue);
    inQue.Enqueue(tree->info);
    InOrder(tree->right, inQue);
  }
}


void PostOrder(TreeNode* tree, 
     QueType& postQue)
// Post: postQue contains the tree items in postorder.
{
  if (tree != NULL)
  {
    PostOrder(tree->left, postQue);
    PostOrder(tree->right, postQue);
    postQue.Enqueue(tree->info);
  }
}


void TreeType::GetNextItem(ItemType& item, 
     OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true; 
//       otherwise finished is false.
{
  finished = false;
  switch (order)
  {
    case PRE_ORDER  : preQue.Dequeue(item);
                      if (preQue.IsEmpty())
                        finished = true;
                      break;
    case IN_ORDER   : inQue.Dequeue(item);
                      if (inQue.IsEmpty())
                        finished = true;
                      break;
    case  POST_ORDER: postQue.Dequeue(item);
                      if (postQue.IsEmpty())
                        finished = true;
                      break;
  }
}

void TreeType::Ancestors(ItemType value) {
    bool found = false;
    QueType path;

    TreeNode* currentNode = root;

    while (!found && currentNode!=NULL) {
        if (currentNode->info == value)
            found = true;
        else {
            path.Enqueue(currentNode->info);
            if (currentNode->info > value)
                currentNode = currentNode->left;
            else
                currentNode = currentNode->right;
        }
    }
    if (found) {
        ItemType item1;
        while (!path.IsEmpty()) {
            path.Dequeue(item1);
            cout << item1 << endl;
        }
    }
    else {
        cout << "Value is not found.";
    }
}

bool Ancestors_recursive(TreeNode* tree, ItemType item) {
    bool found = false;
    if (tree == NULL)
        return false;
    if (tree->info == item)
        return true;
    if (tree->info > item)
        found = Ancestors_recursive(tree->left, item);
    else
        found = Ancestors_recursive(tree->right, item);
    if (found)
        cout << tree->info << endl;
    return found;
}

void TreeType::Ancestors_re(ItemType value) {
    Ancestors_recursive(root, value);
}

int Smaller(TreeType tree, int value) {
    ItemType item;
    bool finished = false;
    int count = 0;

    tree.ResetTree(IN_ORDER);

    do {
        tree.GetNextItem(item, IN_ORDER, finished);
        if (item < value)
            count++;
        else
            finished = true;
    } while (!finished);

    return count;
}

void AddElement(TreeType& tree, int Array[], int front, int rear);
void MakeTree(TreeType& tree, SortedType<int>& list);

void MakeTree(TreeType& tree, SortedType<int>& list) {
    int length = list.LengthIs();
    int* array = new int[length];
    int item_info;
    int i;
    
    list.ResetList();

    for (i = 0; i < length; i++) {
        list.GetNextItem(item_info);
        array[i] = item_info;
    }
    AddElement(tree, array, 0, length - 1);

    delete[] array;
}

void AddElement(TreeType& tree, int Array[], int front, int rear) {
    int mid;
    if (rear >= front) {
        mid = (front + rear) / 2;
        tree.InsertItem(Array[mid]);
        AddElement(tree, Array, front, mid-1);
        AddElement(tree, Array, mid+1, rear);
    }
}

bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list) {
    int list_length = list.LengthIs();
    int tree_length = tree.LengthIs();

    if (list_length != tree_length) {
        return false;
    }
    else {
        ItemType item;
        bool found;
        list.ResetList();
        for (int i = 0; i < list_length; i++) {
            list.GetNextItem(item);
            tree.RetrieveItem(item, found);
            if (!found)
                return false;
        }
        return true;
    }
}

int main() {
    TreeType tree1;
    tree1.InsertItem(3);
    tree1.InsertItem(2);
    tree1.InsertItem(1);
    tree1.InsertItem(6);
    tree1.InsertItem(5);
    tree1.InsertItem(4);
    tree1.InsertItem(7);
    tree1.InsertItem(8);
    tree1.Ancestors(7);
    tree1.Ancestors_re(7);
    cout << Smaller(tree1, 7) << endl;
    TreeType tree2;
    SortedType<int> l1;
    for (int i = 1; i < 8; i++) {
        l1.InsertItem(i);
    }
    MakeTree(tree2, l1);
    std::ofstream Printed1;
    Printed1.open("PrintedTree.txt");
    tree2.Print(Printed1);
    Printed1.close();
    UnsortedType<int> l2;
    for (int i = 1; i < 8; i++) {
        l2.InsertItem(i);
    }
    UnsortedType<int> l3;
    UnsortedType<int> l4;
    for (int i = 1; i < 9; i++) {
        l3.InsertItem(i);
    }
    for (int i = 1; i < 8; i++) {
        l4.InsertItem(i);
    }
    l4.InsertItem(10);
    cout << MatchingItem_Unsorted(tree1, l2) << "l2 match" << endl;
    cout << MatchingItem_Unsorted(tree1, l3) << "l3 match" << endl;
    cout << MatchingItem_Unsorted(tree1, l4) << "l4 match" << endl;
    return 0;
}

