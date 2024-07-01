//
//  LibraryItem.h
//  WS09
//
//  Created by Yang on 2024/3/22.
//

#ifndef SENECA_LIBRARY_ITEM_H
#define SENECA_LIBRARY_ITEM_H
#include <iostream>
namespace seneca {
  class LibraryItem {
    char* m_title;  // A pointer to store the title of the item.
    int m_year; // An integer to store the publication year of the item.
    void clear();
  public:
    // This constructor should set the title pointer to null and year to 0.
    LibraryItem();
    
    /* This constructor should take two parameters: title and year. 
    It should allocate memory for the title string on the heap 
    and make the title pointer point to the appropriate heap memory. 
    Also, set the year to the provided year value. */
    LibraryItem(const char* title, int year);
    
    /* Implement the rule of three 
    (copy constructor, copy assignment operator, and destructor) 
    to manage the allocated memory properly 
    when copying and assigning LibraryItem objects. */
    LibraryItem(const LibraryItem& uneAutre);
    LibraryItem& operator=(const LibraryItem& uneAutre);
    virtual ~LibraryItem();
    
    /* This method should display the title and year of the library item as follows:
      Title: The book Title (the year)<no new line>
      For example:
      Title: The Great Gatsby (1925)<no new line> */
    virtual std::ostream& display(std::ostream& ostr = std::cout) const;
  };
}


#endif /* LibraryItem_h */
