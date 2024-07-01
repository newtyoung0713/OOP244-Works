#ifndef SENECA_TEST_PATIENT_H
#define SENECA_TEST_PATIENT_H
#include <iostream>
#include "Patient.h"
namespace seneca {
  extern int nextTestTicket;
  class TestPatient : public Patient {
  public:
    /* Default Constructor
    The default constructor passes the nextTestTicket global variable 
    to the constructor of the base class Patient 
    and then it will increase the value of nextTestTicket global variable by one. */
    TestPatient();

    TestPatient(const TestPatient& uneAutre) = delete;
    TestPatient& operator=(const TestPatient& uneAutre) = delete;

    /* the type() virtual function
    This function only returns the character 'C'; */
    virtual char type() const override;

    /* write virtual function override.
    If the ostream is cout it will insert "Contagion TEST" into the ostream object 
    and goes to newline.
    Then it will call the write() function of the base class Patient.
    At end it will return the ostream reference. */
    std::ostream& write(std::ostream& os) const override;

    /* read virtual function override.
    It will call the read function of the base class Patient.
    If the istream is not cin (reading from a file) 
    then it should set the nextTestTicket to the ticket number of this patient + 1. 
    This will make sure the ticket numbers are correctly restored 
    with records are being read from a file.
    Then it will return the istream reference. */
    std::istream& read(std::istream& is) override;

    /* Destructor
    This class does not need a custom destructor. */
    virtual ~TestPatient() = default;
  };
}
#endif  //  !SENECA_TEST_PATIENT_H 