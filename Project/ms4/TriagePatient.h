#ifndef SENECA_TRIAGE_PATIENT_H
#define SENECA_TRIAGE_PATIENT_H
#include <iostream>
#include "Patient.h"
namespace seneca {
  extern int nextTriageTicket;
  const int SYM_LEN(511);
  class TriagePatient : public Patient {
    char* m_symptom;
    void clear();
  public:
    /* Default Constructor
    The default constructor initializes the character pointer member variable to null, 
    passes the nextTriageTicket global variable to the constructor of the base class Patient, 
    and then increases the value of nextTriageTicket by one. */
    TriagePatient();

    /* the type() virtual function
    This function returns the character 'T'; */
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
    std::ostream& write(std::ostream& os) const override;

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
    std::istream& read(std::istream& is) override;

    /* Destructor
    Deletes the memory pointed by the symptoms member variable */
    virtual ~TriagePatient();
  };
}
#endif  //  !SENECA_TRIAGE_PATIENT_H 