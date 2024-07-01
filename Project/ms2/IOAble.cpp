//*****************************************************************************
//  <assessment name example : Milestone - #2>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : March 16th, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my milestones and assignments.
//*****************************************************************************
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
      int height(0), width(0);
      cout << "Height: " << endl;
      is >> height;
      cout << "Width: " << endl;
      is >> width;
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
      return ioa.write(os);
    }

    /* 
    Overload the extraction operator to be able to extract information 
    from an istream into an IOAble object using the IOAble::read function. 
    */
    istream& operator>>(istream& is, IOAble& ioa) {
      return ioa.read(is);
    }
}