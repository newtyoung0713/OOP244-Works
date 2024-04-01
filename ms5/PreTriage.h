#ifndef SENECA_PRETRIAGE_H
#define SENECA_PRETRIAGE_H
#include <iostream>
#include "Menu.h"
#include "Time.h"
#include "Patient.h"
namespace seneca {
  const int MAX_NUM(100);
  class PreTriage {
    int m_numOfCT{0}, m_numOfT{0};
    char m_type{};
    /* Add two Time object attributes to the class 
    to keep track of the average wait time 
    for the Contaigen test and the Triage patients separately. */
    Time m_waitTimeCT;
    Time m_waitTimeT;
    /* Create an array of pointers to Patient objects. 
    The size of this array should be set to the maximum lineup value constant. 
    These pointers should be nullptr when the PreTirage class is instantiated.
    When Patients arrive, they will be dynamically instantiated 
    and their addresses will be kept in the elements of this array. 
    See register() method */
    Patient* m_lineUp[MAX_NUM]{nullptr};
    // A C-string to hold the path and name of the data file.
    char* m_fileName;
    /* This number can not exceed the maximum lineup value.
    Create an attribute to hold the actual number of patients in the lineup.  */
    int m_noOfPatient;
    void clear();
    /* getWaitTime (Query)
    Receives a constant Patient Reference 
    and returns the total estimated wait time 
    for that type of Patient (contagion or Triage) as follows:
    Find the number of Patients in the lineup 
    that match the type of the received Patient Reference.
    Returns the product of estimated wait time 
    (for that type of patient) to the number of patients found.
    This method does not change the state of the class. */
    const Time getWaitTime(const Patient& uneAutre) const;
    /* setAverageWaitTime (Modifier)
    Receives the reference of the admitting patient 
    and adjusts the average wait time of that type of patient 
    based on the admittance time of the patient.
    Modify and set the value of the average wait time 
    of the corresponding patient using the following formula:
      CT: Current Time
      PTT: Patient's Ticket Time
      AWT: Average Wait Time (Contagion or Triage)
      PTN: Patient's Ticket Number
      AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN */
    void setAverageWaitTime(Patient& uneAutre);
    /* indexOfFirstInLine (Query)
    Receives a character representing the type of patient (C for Contaigen, T for Triage).
    Finds the index of the first patient in line that matches a specified type.
    This function iterates over the lineup array of pointers from the beginning. 
    For each patient, it compares the patient's type 
    with the specified type (using overloaded operator==). 
    If a match is found, the function returns the found index. 
    If the function iterates over the entire lineup 
    without finding a match, it returns -1 */
    int indexOfFirstInLine(char type) const;
    /* load (Modifier)
    Loads the average wait times and the patient records 
    from the data file and stores them in the lineup array of pointers.
    Create a local patient-pointer
    In a loop from 0 to the maximum number of patients (or up to when reading fails)
        read the first character and ignore the comma
        if the character is 'C'
          in the current patient-pointer element instantiate a Contagion Test Patient
        otherwise, if the character is 'T'
          in the current patient-pointer element instantiate a Triage Patient
        endif
        If Instantiation successful
          Read the patient information from the file
          Add the local pointer value to the patient lineup array
          increase the lineup size
        end if
    end loop */
    void load();
    /* save (Query)
    Opens the data file for output.
    Inserts "Saving lineup...", into cout and goes to newline
    Inserts the average Contaigen Test and Triage wait times, 
    comma-separated into the data file and goes to newline.
    Iterates through the lineup array of Patient pointers
    Inserts them into the data file and goes to newline
    Inserts the number of records saved 
    for each type of patient into cout and goes to newline
    See the Exit option description for sample output. */
    void save();
    /* register (Modifier)
    Registers a new patient:
    Create a Menu object for a sub-menu 
    for patient type selection with one indentation (1 tab) 
    as follows to be displayed later. */
    void reg();
    /* admit (Modifier)
    Calls the next patient in line to be admitted 
    to the contagion test centre or Triage centre
    Create a Menu object for a sub-menu 
    for patient type selection with one indentation (1 tab) 
    as follows to be displayed later. */
    void admit();
    /* lineup (Query)
    Prints a report on patients currently in the lineup. */
    void lineup();
  public:
    PreTriage() = default;
    PreTriage(const PreTriage& uneAutre) = delete;
    PreTriage& operator=(const PreTriage& uneAutre) = delete;
    /* A PreTriage class is instantiated using the data file name. 
    This data file name is stored in the data filename attribute for load and save purposes. 
    The constructor also initializes the two Time attributes, 
    Contagion test and Triage, to 15 and 5 respectively.
    These Time values may be overwritten 
    by the corresponding values in the data file, if present. 
    The constructor then loads all the data from the data file, if possible. */
    PreTriage(const char* fileName);
    /* Saves the data.
    Iterates through the patient lineup 
    and deletes the elements one by one.
    If there are any other dynamically allocated memory, 
    it will delete them as well. */
    virtual ~PreTriage();
    /* run (Modifier)
    Runs the PreTriage main application.
    Create the Main system menu as follows
    General Healthcare Facility Pre-Triage Application
      1- Register
      2- Admit
      3- View Lineup
      0- Exit
      > */
    void run();
  };
}
#endif  //  !SENECA_PRETRIAGE_H
