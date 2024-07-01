//*****************************************************************************
//  <assessment name example : Workshop - #9 (Part - 1)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Mar , 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;

namespace seneca {
  /* This constructor should take three parameters: title, year, and author. 
  It should allocate memory for the title 
  and author strings on the heap 
  and make the respective pointers point to the appropriate heap memory. 
  Also, set the year to the provided year value. */
  Book::Book(const char* title, int year, const char* author) : LibraryItem(title, year) {
    if (author != nullptr) {
      m_author = new char[strlen(author) + 1];
      strcpy(m_author, author);
    } else {
      m_author = nullptr;
    }
  }
  
  /* Implement the rule of three 
  (copy constructor, copy assignment operator, and destructor) 
  to manage the allocated memory properly 
  when copying and assigning Book objects.
    Note that the copy constructor 
    and copy assignment of the derived class must manage the copying 
    and copy-assigning of the base class too. */
  Book::Book(const Book& uneAutre) : LibraryItem(uneAutre), m_author(nullptr) {
    if (uneAutre.m_author != nullptr) {
      m_author = new char[strlen(uneAutre.m_author) + 1];
      strcpy(m_author, uneAutre.m_author);
    }
  }

  Book& Book::operator=(const Book& uneAutre) {
    if (this != &uneAutre) {
      LibraryItem::operator=(uneAutre);
      clear();
      if (uneAutre.m_author != nullptr) {
        m_author = new char[strlen(uneAutre.m_author) + 1];
        strcpy(m_author, uneAutre.m_author);
      } else {
        m_author = nullptr;
      }
    }
    return *this;
  }

  Book::~Book() {
    clear();
  }
  
  /* This method should display the title, year, and author of the book as follows:
    Title: The book Title (the year)<new line>
    Author: The Author Name<no new line>
    For example:
    Title: The Great Gatsby (1925)<new line>
    Author: F. Scott Fitzgerald<no new line> */
  ostream& Book::display(ostream& ostr) const {
    LibraryItem::display(ostr);
    ostr << endl << "Author: " << m_author;
    return ostr;
  }
  
  /* This method checks for non-null author names and checks to see 
  if the object's author name is lexicographically greater than the other object's author name, 
  it returns true; 
  otherwise, it returns false. */
  bool Book::operator >(const Book& other)const {
    return (strcmp(m_author, other.m_author) > 0) ? true : false;
//    if (m_author == nullptr || other.m_author == nullptr) {
//        return false;
//    }
//    return (strcmp(m_author, other.m_author) > 0);
  }

  void Book::clear() {
    if (m_author != nullptr) {
      delete[] m_author;
      m_author = nullptr;
    }
  }
}
