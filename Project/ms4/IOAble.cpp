#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "IOAble.h"

using namespace std;

namespace seneca {
    /* 
    This pure virtual function is for future ostream outputs. 
    It receives a reference of an ostream and returns a reference of an ostream. 
    This function is incapable of changing the current object. 
    */
    ostream& IOAble::write(ostream& os) const {
      return os;
    }

    /* 
    This pure virtual function is for future istream inputs. 
    It receives a reference of istream and returns a reference of an istream. 
    */
    istream& IOAble::read(istream& is) {
      return is;
    }

    /* 
    This class also has an empty virtual destructor.
    Because we already declared it as a default empty destructor, 
    the compiler creates it automatically for us. 
    */
    // IOAble::~IOAble() {};

    /* 
    Overload the insertion operator to be able to insert the information 
    of an IOAble object into ostream using the IOAble::write function. 
    */
    ostream& operator<<(ostream& os, const IOAble& ioa) {
      ioa.write(os);
      return os;
    }

    /* 
    Overload the extraction operator to be able to extract information 
    from an istream into an IOAble object using the IOAble::read function. 
    */
    istream& operator>>(istream& is, IOAble& ioa) {
      ioa.read(is);
      return is;
    }
}