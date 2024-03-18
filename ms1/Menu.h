//*****************************************************************************
//  <assessment name example : Milestone - #1>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : March 13th, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my milestones and assignments.
//*****************************************************************************
#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
namespace seneca {
  class Menu {
  private:
    // A constant char pointer to hold the content of the menu to be displayed
    // An Integer to hold the number of options in the menu
    // An integer to hold the number of indentation tabs
    char* m_menuContent;
    int m_text;
    int m_numTab;
  public:
    // This constructor is designed to initialize a Menu object. 
    // It takes two parameters: a pointer to a character string menuContent, 
    // and an optional integer numberOfTabs with a default value of 0.
    // The constructor dynamically allocates memory to store the content 
    // pointed to by menuContent in the member variable m_text. 
    // It then scans m_text to count the number of newline characters (\n), 
    // which is used to determine the number of options in the menu.
    // The numberOfTabs parameter specifies the number of indentation tabs to be applied 
    // when displaying the menu. This allows for flexible formatting of the menu display. 
    // If not provided, no tabs will be applied by default.
    Menu(const char* menuContent, int numberOfTabs = 0);

    // Deallocates the dynamically allocated memory.
    ~Menu();

    // Makes sure the Menu can not be copied or assigned to another Menu object.
    // Copy and assignment
    // Can not be copy and assignment
    Menu(const Menu& other) = delete;
    Menu& operator=(const Menu& other) = delete;

    // The display method is responsible for presenting the Menu content to the user. 
    // It first outputs the menu options and a new line. 
    // Following the list of options, it prints:
    // 0- Exit
    // > _

    // This provides an option for the user to exit the menu and also indicates 
    // where the user can input their choice.
    // If the number of tabs attribute is not zero, 
    // the display method will indent the menu. 
    // Each tab corresponds to three spaces. 
    // This allows for adjustable formatting of the menu display.
    // Here are examples of how the menu would be displayed:
    // A menu with no indentation (i.e., number of tabs is 0):
    // Tester Options menu:
    // 1- Option one
    // 2- Option two
    // 0- Exit
    // >

    // A menu with number of tabs set to 2:
    //   Tester Options menu:
    //   1- Option one
    //   2- Option two
    //   0- Exit
    //   >
    // In the second example, each line of the menu is indented 
    // by six spaces (two tabs * three spaces per tab) 
    // for a more structured visual presentation. 
    // This feature enhances the flexibility and user-friendliness of your menu system.
    // std::ostream& display(std::ostream& ostr = std::cout) const;
    void display() const;

    // The member insertion operator first calls the display function 
    // and then receives the user's selection as an integer value. 
    // The integer reference selection argument is then set to this value and returned.
    // Make sure that the entered value is validated as an integer (with no trailing characters) 
    // and also the value should be between 0 and the number of options in the menu.
    // If the above conditions are not met, 
    // a proper error message should be displayed and re-entry requested(see below)
    // Assuming that the menu content is 
    // set to: "Tester Options menu:\n1- Option one\n2- Option two\n3- Option three" , 
    // (hence the number of selections will 3) the operator>> should run like this:
    // Tester Options menu:
    // 1- Option one
    // 2- Option two
    // 3- Option three
    // 0- Exit
    // > abc
    // Bad integer value, try again: 1 (with a space after 1)
    // Only enter an integer, try again: -1
    // Invalid value enterd, retry[0 <= value <= 3]: 4
    // Invalid value enterd, retry[0 <= value <= 3]: 2
    // 2 is returned as user's selection.
    int& operator>>(int& Selection);

    // For any class that requires a display or print functionality, 
    // the method should adhere to the following format, unless specified otherwise:
    // This displayMethod function takes an ostream reference as an argument, 
    // with a default value of cout. It returns an ostream reference, 
    // allowing for chained insertion operations. 
    // The const qualifier ensures that the method does not modify any class members.
    // std::ostream& displayMethod(std::ostream& ostr = std::cout) const;

    // For any class that requires scanning or reading from input, 
    // the method should adhere to the following format, 
    // unless specified otherwise:
    // The readMethod function takes an istream reference as an argument, 
    // with a default value of cin. It returns an istream reference, 
    // enabling chained extraction operations. 
    // This method is used to read or scan data into the class members.
    // std::istream& readMethod(std::istream& istr = std::cin);

    // These methods provide a standard interface for output and input operations, 
    // enhancing the usability and flexibility of your classes.

    void cleanBuffer() const;
  };
}
#endif  //  !SENECA_MENU_H 