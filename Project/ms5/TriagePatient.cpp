//*****************************************************************************
//  <assessment name example : Milestone - #4>
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
#include "TriagePatient.h"
using namespace std;
namespace seneca {
  int nextTriageTicket(1);
  /* Default Constructor
  The default constructor initializes the character pointer member variable to null, 
  passes the nextTriageTicket global variable to the constructor of the base class Patient, 
  and then increases the value of nextTriageTicket by one. */
  TriagePatient::TriagePatient() : Patient(nextTriageTicket++), m_symptom(nullptr) {}

  /* the type() virtual function
  This function returns the character 'T'; */
  char TriagePatient::type() const {
    return 'T';
  }

  /* write virtual function override.
  This function inserts the patient information into different instances of ostream.
  If the ostream reference is cout, it prints a "TRIAGE" label, inserts the patient, 
  and displays the symptoms. 
  If it is clog, it only prints the patient information in a linear format with no symptoms. 
  If it is neither cout nor clog, it inserts the information in a comma-separated format.
  If the ostream reference is cout
    Inserts the word "TRIAGE" into the ostream and goes to a newline.
  Calls the patient's write method.
  If the ostream reference is cout
    Inserts "Symptoms: " into the ostream.
    Inserts the patient's symptoms into the ostream.
    Goes to a newline.
  If the ostream reference is not clog (clog is only used for linear printouts)
    Inserts a "," and then the patient's symptoms.
  The function ends by returning the ostream reference. */
  std::ostream& TriagePatient::write(std::ostream& os) const {
    if (&os == &cout) {
      os << "TRIAGE" << endl;
      Patient::write(os);
      os << "Symptoms: ";
      os << m_symptom << endl;
    } else if (&os == &clog) {
      Patient::write(os);
    } else {
      Patient::write(os);
      os << "," << m_symptom;
    }
    return os;
  }

  /* read virtual function override.
  This function extracts patient information from different instances of istream:
    Console entry via cin
    Comma-separated values entry via any other istream objects.
  It performs the following steps:
  Deletes the memory pointed to by the symptoms member variable.
  Calls the Read function of the base class Patient.
  If the istream reference is not cin:
    Ignores the comma character.
    Reads the symptoms of the patient into a local Cstring character array, 
    up to 511 characters or until a newline ('\n') is encountered.
    Allocates memory and copies the local symptoms Cstring into the allocated memory.
    Sets the nextTriageTicket global variable 
    to the return value of the number() member function of the Patient class plus one.
  Otherwise:
    Displays the prompt "Symptoms: ".
    Reads the symptoms into the local Cstring, up to 511 characters.
    Allocates memory and copies the local symptoms Cstring into the allocated memory.
  In case the istream fails, 
  it deletes the dynamically allocated memory and sets the pointer to nullptr.
  The function concludes by returning the istream reference. */
  std::istream& TriagePatient::read(std::istream& is) {
    char symptom[SYM_LEN + 1];
    clear();
    Patient::read(is);
    if (&is != &cin) {
      is.ignore();
      is.get(symptom, SYM_LEN + 1, '\n');
      is.ignore(1000, '\n');
      m_symptom = new char[strlen(symptom) + 1];
      strcpy(m_symptom, symptom);
      nextTriageTicket = Patient::number() + 1;
    } else {
      cout << "Symptoms: ";
      is.ignore(1000, '\n');
      is.get(symptom, SYM_LEN + 1, '\n');
      is.ignore(1000, '\n');
      m_symptom = new char[strlen(symptom) + 1];
      strcpy(m_symptom, symptom);
    }
    return is;
  }

  /* Destructor
  Deletes the memory pointed by the symptoms member variable */
  TriagePatient::~TriagePatient() {
    clear();
  }

  void TriagePatient::clear() {
    if (m_symptom != nullptr) {
      delete[] m_symptom;
      m_symptom = nullptr;
    }
  }
}