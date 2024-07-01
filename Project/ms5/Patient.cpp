//*****************************************************************************
//  <assessment name example : Milestone - #3>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : March 14th, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my milestones and assignments.
//*****************************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Patient.h"
using namespace std;
namespace seneca {
  // Instantiate a Patient object by providing a ticket number (an integer). 
  // This ticket number will be utilized to initialize the Ticket member attribute.
  Patient::Patient(int ticketNumber) : m_name(nullptr), m_ohip(0), m_ticket(ticketNumber) {}
  
  /* Copying and assignment.
  Ensure that a Patient object can be safely copied 
  or assigned to another Patient without encountering memory leaks 
  or any associated issues. */
  Patient::Patient(const Patient& uneAutre) : m_name(nullptr), m_ohip(0), m_ticket(0) {
    if (uneAutre.m_name != nullptr) {
      m_name = new char[strlen(uneAutre.m_name) + 1];
      strcpy(m_name, uneAutre.m_name);
    }
    m_ohip = uneAutre.m_ohip;
    m_ticket = uneAutre.m_ticket;
  }

  Patient& Patient::operator=(const Patient& uneAutre) {
    if (this != &uneAutre) {
      clear();
      m_ohip = 0;
      m_ticket = 0;
      
      if (uneAutre.m_name != nullptr) {
        m_name = new char[strlen(uneAutre.m_name) + 1];
        strcpy(m_name, uneAutre.m_name);
      }
        else {
        m_name = nullptr;
      }
      m_ohip = uneAutre.m_ohip;
      m_ticket = uneAutre.m_ticket;
    }
    return *this;
  }

  // Implement a destructor for the Patient class 
  // that effectively deallocates any dynamically allocated memory, 
  // thereby preventing memory leaks.
  Patient::~Patient() {
    clear();
  }

  /* Create a pure virtual function called type that returns a character 
  and is incapable of modifying the current object. 
  In future derived objects, 
  this function will return a single character 
  that identifies the type of the patient 
  (Contagion test patient or Triage patient). */
  // char Patient::type() const {
    // return 'W';
  // }

  /* Patient Comparison to a Character
  Overload the operator== to compare the current object with a single character (the right operand). 
  Return true if the values returned by the type function of this patient 
  and the provided single character are identical. 
  Note that this operator should not modify the current object. */
  bool Patient::operator==(char rhs) const {
    return type() == rhs;
  }

  /* Comparing to Another Patient
  Overload the operator== to compare the current object to another patient. 
  Return true if the type of the current patient is the same as the type of the other patient; 
  otherwise, return false. 
  This operator should not have the ability to modify either the current object 
  or the right operand. */
  bool Patient::operator==(const Patient& uneAutre) const {
    return type() == uneAutre.type();
  }

  /* Setting the Patient's Arrival Time
  Implement a modifier method named setArrivalTime within the Patient class. 
  This method sets the time of the patient's ticket to the current time. 
  It does not take any parameters and does not return any value. */
  void Patient::setArrivalTime() {
    m_ticket.resetTime();
  }

  /* Getting the Patient's Arrival TIme
  Create a query method named time 
  to retrieve the time of the patient's ticket and return it. */
  Time Patient::time() const {
    return m_ticket.time();
  }

  /* Patient's Ticket Number
  Establish a query method named number 
  that returns the number associated 
  with the patient's ticket. */
  int Patient::number() const {
    return m_ticket.number();
  }

  /* Boolean
  When a patient is casted to a boolean, 
  return true if the Patient is in a valid state; 
  otherwise, return false. */
  Patient::operator bool() const {
    return m_name != nullptr && m_ohip != 0;
  }

  /* Const Character Pointer
  If a patient is casted to a constant character pointer, 
  return the address of the patient's name. */
  Patient::operator const char*() const {
    return m_name;
  }

  /* This method inserts information into the ostream reference in three different formats 
  based on the instance of the ostream. 
  For cout, it inserts detailed information suitable for printing like a ticket in multiline format. 
  For clog, it presumes a list is being printed, 
  and therefore the information is inserted in a linear format suitable for a list. 
  For any other object, 
  it will insert the values in a comma-separated format suitable for saving in a file. */
  std::ostream& Patient::write(std::ostream& os) const {
    if (&os == &clog) {
      (m_name) ?
        os << left << setw(53) << setfill('.') << m_name << m_ohip
            << setw(5) << right << setfill(' ') << number() << ' ' << time() :
        os << "Invalid Patient Record";
    } else if (&os == &cout) {
      if (m_name) {
        m_ticket.write(os) << endl;
        os << m_name << ", OHIP: " << m_ohip << endl;
      } else {
        os << "Invalid Patient Record" << endl;
      }
    } else {
      os << type() << "," << m_name << "," << m_ohip << ",";
      m_ticket.write(os);
    } 
    return os;
  }

  /* Overwrite the read method to extract patient information from the istream as follows:
  If the information is being extracted from cin (user input over the console), 
  the following actions are taken: */
  std::istream& Patient::read(std::istream& is) {
    bool flag(true);
    char name[NAME_LEN + 1];
    clear();
    if (&is == &cin) {
      cout << "Name: ";
      is.get(name, NAME_LEN + 1, '\n');
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);
      is.ignore(1000, '\n');
      cout << "OHIP: ";
      do {
        flag = true;
        is >> m_ohip;
        if (is.fail()) {
          is.clear();
          is.ignore(1000, '\n');
          cout << "Bad integer value, try again: ";
          flag = false;
        } else if (m_ohip < MIN_OHIP || m_ohip > MAX_OHIP) {
          is.clear();
          is.ignore(1000, '\n');
          cout << "Invalid value enterd, retry[" << MIN_OHIP << " <= value <= " << MAX_OHIP << "]: ";
          flag = false;
        }
      } while (!flag);
    } else {
      is.get(name, NAME_LEN + 1, ',');
      m_name = new char[NAME_LEN + 1];
      strcpy(m_name, name);
      is.ignore(1000, ',');
      is >> m_ohip;
      is.ignore(1000, ',');
      m_ticket.read(is);
    }
    return is;
  }

  void Patient::clear() {
    if (m_name != nullptr) {
      delete[] m_name;
      m_name = nullptr;
    }
  }
}