#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>

template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr;

public:

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ // TODO
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

  /** Equality test operator. */ // TODO
  bool operator==(BSTIterator<Data> const & other) const {
    if(this == NULL && other == NULL)
      return true;
    else if((this->curr == NULL && other.curr != NULL) || (this->curr != NULL && other.curr == NULL))
      return false;
    else if( this->curr->data == other.curr->data )
      return true;
    return false; 
  }

  /** Inequality test operator. */ // TODO
  bool operator!=(BSTIterator<Data> const & other) const {
    if(this == NULL && other == NULL)
      return false;
    else if((this->curr == NULL && other.curr != NULL) || (this->curr != NULL && other.curr == NULL))
      return true;
    else if( ((this->curr->data < other.curr->data ) && (other.curr->data < this->curr->data ))== false)
      return false;
    return true; 
  }

};

#endif //BSTITERATOR_HPP
