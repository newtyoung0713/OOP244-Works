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
#include "LibraryItem.h"
using namespace std;

namespace seneca {
  // This constructor should set the title pointer to null and year to 0.
  LibraryItem::LibraryItem() : m_title(nullptr), m_year(0) {}
  
  /* This constructor should take two parameters: title and year. 
  It should allocate memory for the title string on the heap 
  and make the title pointer point to the appropriate heap memory. 
  Also, set the year to the provided year value. */
  LibraryItem::LibraryItem(const char* title, int year) : m_year(year) {
    if (title != nullptr) {
      m_title = new char[strlen(title) + 1];
      strcpy(m_title, title);
    } else {
      m_title = nullptr;
    }
  }
  
  /* Implement the rule of three 
  (copy constructor, copy assignment operator, and destructor) 
  to manage the allocated memory properly 
  when copying and assigning LibraryItem objects. */
LibraryItem::LibraryItem(const LibraryItem& uneAutre) : m_year(uneAutre.m_year) {
    if (uneAutre.m_title != nullptr) {
      m_title = new char[strlen(uneAutre.m_title) + 1];
      strcpy(m_title, uneAutre.m_title);
    } else {
        m_title = nullptr;
    }
  }

  LibraryItem& LibraryItem::operator=(const LibraryItem& uneAutre) {
    if (this != &uneAutre) {
      clear();
      m_year = uneAutre.m_year;
      if (uneAutre.m_title != nullptr) {
        m_title = new char[strlen(uneAutre.m_title) + 1];
        strcpy(m_title, uneAutre.m_title);
      }
    }
    return *this;
  }

  LibraryItem::~LibraryItem() {
    clear();
  }
  
  /* This method should display the title and year of the library item as follows:
    Title: The book Title (the year)<no new line>
    For example:
    Title: The Great Gatsby (1925)<no new line> */
  ostream& LibraryItem::display(ostream& ostr) const {
    return ostr << "Title: " << m_title << " (" << m_year << ")";
  }

  void LibraryItem::clear() {
    if (m_title != nullptr) {
      delete[] m_title;
      m_title = nullptr;
    }
  }
}
