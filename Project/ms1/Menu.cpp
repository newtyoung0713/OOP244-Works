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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <sstream>
#include "Menu.h"
using namespace std;

const int MIN_SELECT(0);
const int MAX_SELECT(2);

namespace seneca {
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
  Menu::Menu(const char* menuContent, int numberOfTabs) {
    m_numTab = numberOfTabs;
    m_text = 0;
    m_menuContent = new char[strlen(menuContent) + 1];
    strcpy(m_menuContent, menuContent);
  }

  // Deallocates the dynamically allocated memory.
  Menu::~Menu() {
    delete[] m_menuContent;
    m_menuContent = nullptr;
  }

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
  void Menu::display() const {
    if (m_numTab != 0) {
      istringstream menuWithNoNewLine(m_menuContent);
      string menuWithNewLine;
      while (getline(menuWithNoNewLine, menuWithNewLine)) {
        for (int i = 0; i < m_numTab; ++i) {
          cout << "   ";
        }
        cout << menuWithNewLine << endl;
      }
      for (int i = 0; i < m_numTab; ++i) {
        cout << "   ";
      }
      cout << "0- Exit" << endl;
      for (int i = 0; i < m_numTab; ++i) {
        cout << "   ";
      }
      cout << "> ";
    } else {
      cout << m_menuContent << "\n0- Exit\n> ";
    }
  }

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
  int& Menu::operator>>(int& Selection) {
    bool flag(true);
    display();
    do {
      flag = true;
      cin >> Selection;
      if (cin.fail()) {
        cleanBuffer();
        cout << "Bad integer value, try again: ";
        flag = false;
      } else if (cin.peek() == ' ') {
        cleanBuffer();
        cout << "Only enter an integer, try again: ";
        flag = false;
      } else if (Selection < MIN_SELECT || Selection > MAX_SELECT) {
        cout << "Invalid value enterd, retry[" << MIN_SELECT
             << " <= value <= " << MAX_SELECT << "]: ";
        flag = false;
      } else {
        flag = true;
      }
    } while (!flag);
    return Selection;
  }

  void Menu::cleanBuffer() const {
    cin.clear();            // Clean error buffer
    cin.ignore(1000, '\n'); // Ignore the wrong input
  }
}