#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

using namespace std;

template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ // TODO
  BSTNode<Data>* successor() {
    // need to figure out the base cases
    BSTNode<Data> *currentNode = this;
    
    //node has a right child, so go over once and go all the way left
    if( currentNode->right != NULL )
    {
      currentNode = currentNode->right;
      while( currentNode->left != 0 )
        currentNode = currentNode->left;     
      return currentNode;
    }
   

    //node has no right child so we have to look up
    else
    {
      while(1){ //change back to true if no
        //if( (currentNode->parent ==  ) ) 
        //  return 0;

        //if the node has no right child and is the left child of parent then
        //the parent is the successor
        if ( currentNode == currentNode->parent->left )
        {  
          cout <<"ss"<< currentNode->parent->data << endl;
          return currentNode->parent; 
        }
        //the node has no right child and IS the right child of parent
        else if( currentNode == currentNode->parent->right )
        {          
          cout <<"ss"<< currentNode->parent->data << endl;
          currentNode = currentNode->parent;
        }
     }  

   }
 }    
}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
