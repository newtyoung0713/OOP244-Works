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
#include "TestPatient.h"
using namespace std;
namespace seneca {
    int nextTestTicket(1);

    /* Default Constructor
    The default constructor passes the nextTestTicket global variable 
    to the constructor of the base class Patient 
    and then it will increase the value of nextTestTicket global variable by one. */
    TestPatient::TestPatient() : Patient(nextTestTicket++) {}

    /* the type() virtual function
    This function only returns the character 'C'; */
    char TestPatient::type() const {
      return 'C';
    }

    /* write virtual function override.
    If the ostream is cout it will insert "Contagion TEST" into the ostream object 
    and goes to newline.
    Then it will call the write() function of the base class Patient.
    At end it will return the ostream reference. */
    std::ostream& TestPatient::write(std::ostream& os) const {
      if (&os == &cout) {
        cout << "Contagion TEST" << endl;
      }
      Patient::write(os);
      return os;
    }

    /* read virtual function override.
    It will call the read function of the base class Patient.
    If the istream is not cin (reading from a file) 
    then it should set the nextTestTicket to the ticket number of this patient + 1. 
    This will make sure the ticket numbers are correctly restored 
    with records are being read from a file.
    Then it will return the istream reference. */
    std::istream& TestPatient::read(std::istream& is) {
      Patient::read(is);
      is.ignore(1000, '\n');
      if (&is != &cin) nextTestTicket = Patient::number() + 1;
      return is;
    }

    /* Destructor
    This class does not need a custom destructor. */
    // TestPatient::~TestPatient() {}
}