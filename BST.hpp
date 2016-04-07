/***
 * Name: Steven R Stone, A99405998, cs100sft             
 * Date: Apr 04 2016
 * Filename: BST.hpp
 * Description: This class constructs the BST container for storing data
 *              and provides an interator pattern to traverse the container.
 * Sources of help: Tutors
 ***/


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
  BST() : root(0), isize(0), iheight(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */ 
  virtual ~BST() {
   deleteAll(this->root);
   isize = 0;
   iheight = 0; 
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=)  For the reasoning
   *  behind this, see the assignment writeup.
   */ 
  virtual bool insert(const Data& item) {
    
    //handling the case where no nodes exist yet
    if( this->root == 0){
      BSTNode<Data> *toAdd = new BSTNode<Data>(item);
      this->root = toAdd;
      isize++;
      return true;
    }

    BSTNode<Data> *currentNode = this->root;
    BSTNode<Data> *onePrevious = this->root; 
    
    //determining if the node should be in left or right subtree of root
    while( currentNode != 0 ){
      onePrevious = currentNode;
   
      if( item < currentNode->data)
        currentNode = currentNode->left;
      else if( currentNode->data < item )
        currentNode = currentNode->right;
      else
        return false;
    } 
    
    //inserts the new node as a left child
    if( item < onePrevious->data ){  //change back to onePrevious
      BSTNode<Data> *toAdd = new BSTNode<Data>(item);   
      toAdd->parent = onePrevious;
      onePrevious->left = toAdd;
      isize++;
      //cout << *toAdd << endl;
      return true;
    } 

    //inserts the new node as a right child
    else{
      BSTNode<Data> *toAdd = new BSTNode<Data>(item);
      toAdd->parent = onePrevious;
      onePrevious->right = toAdd;
      isize++;
      //cout << *toAdd << endl;
      return true;
    } 
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=).  For the reasoning
   *  behind this, see the assignment writeup.
   */ 
  iterator find(const Data& item) const {
    BSTNode<Data> *theNode = this->root;
    
    while(theNode != 0){
      if( theNode->data < item )
        theNode = theNode->right;
      else if( item < theNode->data )
        theNode = theNode->left;
      else{
        return BST<Data>::iterator(theNode);
      }
    }
    return 0; //change pack to 0 if break
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
   return findHeight(this->root); 
    
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
    if(n == 0 )
      return;
    inorder(n->left);
    cout << n->data << endl;
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
    if( n == 0 )
      return;
    deleteAll(n->left);
    deleteAll(n->right);
    delete(n);
  }

   /***
   * Function name: findHeight         
   * Function Prototype: static int findHeight(BSTNode<Data> *theNode)
   * Description: This function determines the height of a tree by 
   *              recursively traversing the left and right subtrees.        
   * Parameters: BSTNode<Data> *theNode
   *             -the node to start traversing from; this function will only
   *              ever be called passing the root as *theNode
   * Side Effects: Doesn't manipulate the BST, just determines the height.
   * Error Conditions: None.   
   * Returns: Returns an int
   *          -the int is the height of the tree            
   ***/
   static int findHeight(BSTNode<Data> *theNode){
     if( theNode == 0 )
       return -1; //has to be -1 because we are counting the amount of links
                  //not the number of nodes
     
     int heightOfLeft = findHeight(theNode->left);
     int heightOfRight = findHeight(theNode->right);

     /* Determining if left or right subtree has larger height value */
     if( heightOfRight < heightOfLeft )
       return heightOfLeft + 1;
     else
       return heightOfRight + 1; 
   }
  
 };
#endif //BST_HPP
