/***
 * Name: Steven R Stone, A99405998, cs100sft
 * Date: Apr 07 2016
 * Filename: BSTIterator.hpp
 * Description: This iterator class will be used to iterate and traverse 
 *              the BST object. 
 * Sources of help: N/A
 ***/

#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>
using namespace std;
template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr;

public:

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ 
  BSTIterator(BSTNode<Data>* curr) {
   this->curr = curr; 
  }

  /** Dereference operator. */
  Data operator*() const {
    return curr->data;
  }
  
  /** Pre-increment operator. */
  BSTIterator<Data>& operator++() {
    curr = curr->successor();
    return *this;
  }

  /** Post-increment operator. */
  BSTIterator<Data> operator++(int) {
    BSTIterator before = BSTIterator(curr);
    ++(*this);
    return before;
  }

  /** Equality test operator. */ 
  bool operator==(BSTIterator<Data> const & other) const {
    return other.curr == curr;
  }

  /** Inequality test operator. */
  bool operator!=(BSTIterator<Data> const & other) const {
    return curr != other.curr;
  }

};
#endif //BSTITERATOR_HPP
