#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A simple test driver for the BST class template.
 * P1 CSE 100 2013
 * Author: P. Kube (c) 2013
 */
int main() {

  /* Create an STL vector of some ints */
  /*test*/
  vector<int> v;
  v.push_back(3);
  v.push_back(4);
  v.push_back(1);
  v.push_back(100);
  v.push_back(-33);

  /* Create an instance of BST holding int */
  BST<int> b;

  /* Insert a few data items. */
  vector<int>::iterator vit = v.begin();
  vector<int>::iterator ven = v.end();
  for(; vit != ven; ++vit) {
    // all these inserts are unique, so should return a std::pair
    // with second part true
    bool pr = b.insert(*vit);
    if(! pr ) {
      cout << "Incorrect bool return value when inserting " << *vit << endl;
      return -1;
    }
  }
  cout<< "Testing insert done"<< endl;
  /* Test size. */

  cout << "Size is: " << b.size() << endl;
  if(b.size() != v.size()) {
    cout << "... which is incorrect." << endl;
    return -1;
  }


  /* Test find return value. */

  cout << "Testing find return value on first BST" << endl;

  vit = v.begin();
  for(; vit != ven; ++vit) {
    //cout << "current vit is: " << *vit << endl;
    if(*(b.find(*vit)) != *vit) {
      cout << "Incorrect return value when finding " << *vit << endl;
      return -1;
    }
  }
 
  cout << "OK" << endl;
 
  /*Sort the vector, to compare with inorder iteration on the BST */
  sort(v.begin(),v.end());


  /* Test BST iterator; should iterate inorder */

  cout << "traversal using iterator:" << endl;
  vit = v.begin();
  BST<int>::iterator en = b.end();
  BST<int>::iterator it = b.begin();
  for(; vit != ven; ++vit) {
    if(! (it != en) ) {
      cout << *it << "," << *vit << ": Early termination of BST iteration." << endl;
      return -1;
    }
    cout << *it << endl;
    if(*it != *vit) {
      cout << *it << "," << *vit << ": Incorrect inorder iteration of BST." << endl;
      return -1;
    }
    ++it;
  }

  cout << "OK." << endl;

  /* Second test case (strings)*/
  
  vector<std::string> vn;
  set<std::string> names;
  
  BST<std::string> b2;
  vn.push_back("GEORG, SPIDERS");
  vn.push_back("NEVER, GONNA GIVE");
  vn.push_back("YOU, UP");
  vn.push_back("ASTLEY, RICK");
  vn.push_back("GEORG, GDB");
  vn.push_back("ASTLEY, MARVIN");
  vn.push_back("BRIONES, KAL-EL");

  vector<std::string>::iterator vnit = vn.begin();
  for(; vnit != vn.end(); vnit++)
    {
      b2.insert(*vnit);
          names.insert(*vnit);
    }
  
  cout << "Testing 2nd BST traversal" << endl;
       
  /* Traverse 2nd BST in order */
  set<std::string>::iterator nit = names.begin();
  BST<std::string>::iterator bit = b2.begin(); 
 for(; bit != b2.end(); bit++)
    {
      cout << *bit << "\n";
          if(*nit != *bit)
          {
        	cout << "Error. Expected: " << *nit << "\n";
        	return -1;
          }
          nit++;
    }
   cout << "OK" << endl;

 
   cout << "Testing find for 2nd BST" << endl;   
    
   /* Test find for 2nd BST */
   vnit = vn.begin();
   for(; vnit != vn.end(); ++vnit) {
     if(*(b2.find(*vnit)) != *vnit) {
      cout << "Incorrect return value when finding " << *vnit << endl;
      return -1;
     }
   }

   cout << "OK" << endl;


   cout << "Testing insert on data that already exists" << endl;
   
   BST<int> bt;

   bt.insert(1);
   bt.insert(200);
   bt.insert(3);
   bt.insert(-31);
   bt.insert(100);
   bool forFive;
   forFive = bt.insert(5);
   bool for100;
   for100 = bt.insert(100);



   if( forFive == false ){
     cout << "Error inserting 5. Got :" << forFive << endl;
     return -1;
   }
   
   if( for100  == true){
     cout << "Error inserting 100. Got: " << for100 << endl;
     return -1;
   }

   cout << "OK" << endl;

  return 0;
}
