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

    /* the type() virtual function
    This function only returns the character 'C'; */
    virtual char type() const override;

    /* csvWrite virtual function override.
    This function only calls the csvWrite function of the base class Patient 
    and returns the ostream reference. */
    std::ostream& csvWrite(std::ostream& os) const override;

    /* csvRead virtual function override
    First this function will call the csvRead function of the base class Patient, 
    then it will set the nextTestTicket global variable 
    to the return value of the number() function of the Patient class plus one.
    Finally, it will return the istream reference. */
    std::istream& csvRead(std::istream& is) override;

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