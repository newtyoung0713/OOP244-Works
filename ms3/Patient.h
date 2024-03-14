#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
namespace seneca {
  const int NAME_LEN(50);
  const unsigned int MIN_OHIP(100000000);
  const unsigned int MAX_OHIP(999999999);
  class Patient : public IOAble {
    char* m_name;
    unsigned int m_ohip;
    Ticket m_ticket;
  public:
    void clear();
    // Instantiate a Patient object by providing a ticket number (an integer). 
    // This ticket number will be utilized to initialize the Ticket member attribute.
    Patient(int ticketNum);
    
    /* Copying and assignment.
    Ensure that a Patient object can be safely copied 
    or assigned to another Patient without encountering memory leaks 
    or any associated issues. 
    */
    Patient(const Patient& uneAutre);
    Patient& operator=(const Patient& uneAutre);

    // Implement a destructor for the Patient class 
    // that effectively deallocates any dynamically allocated memory, 
    // thereby preventing memory leaks.
    ~Patient();

    /* Create a pure virtual function called type that returns a character 
    and is incapable of modifying the current object. 
    In future derived objects, 
    this function will return a single character 
    that identifies the type of the patient 
    (Contagion test patient or Triage patient). 
    */
    virtual char type() const = 0;

    /* Patient Comparison to a Character
    Overload the operator== to compare the current object with a single character (the right operand). 
    Return true if the values returned by the type function of this patient 
    and the provided single character are identical. 
    Note that this operator should not modify the current object. 
    */
    bool operator==(char rhs) const;

    /* Comparing to Another Patient
    Overload the operator== to compare the current object to another patient. 
    Return true if the type of the current patient is the same as the type of the other patient; 
    otherwise, return false. 
    This operator should not have the ability to modify either the current object 
    or the right operand. 
    */
    bool operator==(const Patient& uneAutre) const;

    /* Setting the Patient's Arrival Time
    Implement a modifier method named setArrivalTime within the Patient class. 
    This method sets the time of the patient's ticket to the current time. 
    It does not take any parameters and does not return any value. 
    */
    void setArrivalTime();

    /* Getting the Patient's Arrival TIme
    Create a query method named time 
    to retrieve the time of the patient's ticket and return it. 
    */
    Time time() const;

    /* Patient's Ticket Number
    Establish a query method named number 
    that returns the number associated 
    with the patient's ticket. 
    */
    int number() const;

    /* Boolean
    When a patient is casted to a boolean, 
    return true if the Patient is in a valid state; 
    otherwise, return false. */
    explicit operator bool() const;

    /* Const Character Pointer
    If a patient is casted to a constant character pointer, 
    return the address of the patient's name. 
    */
    operator const char*() const;

    /* This method inserts information into the ostream reference in three different formats 
    based on the instance of the ostream. 
    For cout, it inserts detailed information suitable for printing like a ticket in multiline format. 
    For clog, it presumes a list is being printed, 
    and therefore the information is inserted in a linear format suitable for a list. 
    For any other object, 
    it will insert the values in a comma-separated format suitable for saving in a file. 
    */
    std::ostream& write(std::ostream& os) const;

    /* Overwrite the read method to extract patient information from the istream as follows:
    If the information is being extracted from cin (user input over the console), 
    the following actions are taken: 
    */
    std::istream& read(std::istream& is);
  };
}
#endif  //  !SENECA_PATIENT_H 