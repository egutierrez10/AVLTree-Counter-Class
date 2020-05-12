#pragma once

#include <iostream>
#include "avlt.h"

template<typename TElement>
class Counter{
private:
  avlt<TElement, int> counts;

public: 
  // default constructor
  Counter(){
    // tree is already created, anything else you need to do?
  }

  // destructor
  virtual ~Counter(){
    
  }

  // returns # of elements in the counter
  int size(){
    return counts.size();
  }

  // inserts e into the counter, setting the count to 1 if this is the 
  // first time or incrementing the count if e is already in the counter
  void insert(TElement e){
    int value;
    if(counts.search(e, value)){
      counts.insert(e, value+1);
    }else{
      counts.insert(e, 1);
    }
  }

  // returns count associated with element e, returns 0 if e is not found
  int operator[](TElement e){
    return counts[e];
  }

  // returns the elements of the counter, in ascending order
  vector<TElement> elements(){
    vector<TElement> vec;
    TElement key;
    counts.begin();
    while(counts.next(key)){
      vec.push_back(key);
    }
    return vec;
  }
};