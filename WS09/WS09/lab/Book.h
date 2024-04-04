//
//  Book.h
//  WS09
//
//  Created by Yang on 2024/3/22.
//

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include "LibraryItem.h"
namespace seneca {
  class Book : public LibraryItem {
    char* m_author; // A pointer to store the name of the author of the book.
    void clear();
  public:
    /* This constructor should take three parameters: title, year, and author. 
    It should allocate memory for the title 
    and author strings on the heap 
    and make the respective pointers point to the appropriate heap memory. 
    Also, set the year to the provided year value. */
    Book(const char* title, int year, const char* author);
    
    /* Implement the rule of three 
    (copy constructor, copy assignment operator, and destructor) 
    to manage the allocated memory properly 
    when copying and assigning Book objects.
      Note that the copy constructor 
      and copy assignment of the derived class must manage the copying 
      and copy-assigning of the base class too. */
    Book(const Book& uneAutre);
    Book& operator=(const Book& uneAutre);
    virtual ~Book();
    
    /* This method should display the title, year, and author of the book as follows:
      Title: The book Title (the year)<new line>
      Author: The Author Name<no new line>
      For example:
      Title: The Great Gatsby (1925)<new line>
      Author: F. Scott Fitzgerald<no new line> */
    std::ostream& display(std::ostream& ostr = std::cout) const override;
    
    /* This method checks for non-null author names and checks to see 
    if the object's author name is lexicographically greater than the other object's author name, 
    it returns true; 
    otherwise, it returns false. */
    bool operator >(const Book& other)const;

  };

}

#endif /* Book_h */
