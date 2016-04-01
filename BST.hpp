#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

using namespace std;

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Height of this BST. */
  unsigned int iheight;
  
public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  //change back to nullptr: that was the original parameter
  BST() : root(0), isize(0), iheight(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */ // TODO
  virtual ~BST() {
   deleteAll(this->root); 
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=)  For the reasoning
   *  behind this, see the assignment writeup.
   */ // TODO
  virtual bool insert(const Data& item) {
    //always insert nodes as leaves
    //use this to access the calling BST object data fields
    BSTNode<Data> currentNode = this->root;
    BSTNode<Data> onePrevious = this->root; 
    //determining if the node should be in left or right subtree of root
    while( currentNode != NULL ){
      onePrevious = currentNode;
      
      if( ((item < currentNode->data)  && (item > currentNode->data)) == true) 
        return false;
      else if( item < currentNode->data )
        currentNode = currentNode->left;
      else
        currentNode = currentNode->right;
    } 
    
    if( item < onePrevious->data ){
      BSTNode<Data> *toAdd = new BSTNode<Data>(item);   
      toAdd->parent = onePrevious;
      onePrevious->left = toAdd;
      isize++;
    } 

    else{
      BSTNode<Data> *toAdd = new BSTNode<Data>(item);
      toAdd->parent = onePrevious;
      onePrevious->right = toAdd;
      isize++;
    }
  
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=).  For the reasoning
   *  behind this, see the assignment writeup.
   */ // TODO
  iterator find(const Data& item) const {
    BSTNode<Data> *theNode = this->root;
    
    while(theNode != NULL){
      //checking to see if the nodes are equal
      if( (theNode->data < item) && (item < theNode->data) == false )
        return BSTIterator<Data>(theNode);

      else if( theNode->data < item )
        theNode = theNode->right;
      
      else
        theNode = theNode->left;
    }

    if( theNode == NULL )
      return 0;
    else
      return BSTIterator<Data>(theNode);      
  }

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
    return this->isize;  //just need to return the variable we keep to store the size
  }
  
  /** Return the height of the BST.
   */ // TODO
  unsigned int height() const {
    //height is equal to the number of layers minus one
    return this->iheight;
  }


  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
    if( isize > 0 )
      return false;
    return true;
  }

  /** Return an iterator pointing to the first item in the BST (not the root).
   */ // TODO
  iterator begin() const {
   return BSTIterator<Data>(first(this->root)); 
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }

  /** Perform an inorder traversal of this BST.
   */
  void inorder() const {
    inorder(root);
  }


private:

  /** Recursive inorder traversal 'helper' function */

  /** Inorder traverse BST, print out the data of each node in ascending order.
      Implementing inorder and deleteAll base on the pseudo code is an easy way to get started.
   */ // TODO
  void inorder(BSTNode<Data>* n) const {
    /* Pseudo Code:
      if current node is null: return;
      recursively traverse left sub-tree
      print current node data
      recursively traverse right sub-tree
    */
    if( n == NULL )
      return;
    inorder(n->left);
    cout << n->data;
    inorder(n->right);
  }

  /** Find the first element of the BST
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  /** do a postorder traversal, deleting nodes
   */ // TODO
  static void deleteAll(BSTNode<Data>* n) {
    /* Pseudo Code:
      if current node is null: return;
      recursively delete left sub-tree
      recursively delete right sub-tree
      delete current node
    */
  if( n == NULL )
    return;
  deleteAll(n->left);
  deleteAll(n->right);
  delete(n);
  }


 };


#endif //BST_HPP
