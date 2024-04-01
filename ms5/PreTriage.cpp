//*****************************************************************************
//  <assessment name example : Milestone - #5>
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
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "TestPatient.h"
#include "TriagePatient.h"
using namespace std;
namespace seneca {
  void PreTriage::clear() {
    for (int i = 0; i < m_noOfPatient; ++i) {
      delete m_lineUp[i];
      m_lineUp[i] = nullptr;
    }
  }
  /* getWaitTime (Query)
  Receives a constant Patient Reference 
  and returns the total estimated wait time 
  for that type of Patient (contagion or Triage) as follows:
  Find the number of Patients in the lineup 
  that match the type of the received Patient Reference.
  Returns the product of estimated wait time 
  (for that type of patient) to the number of patients found.
  This method does not change the state of the class. */
  // const Time PreTriage::getWaitTime(const Patient& uneAutre) const {}
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
  void PreTriage::setAverageWaitTime(Patient& uneAutre) {

  }
  /* indexOfFirstInLine (Query)
  Receives a character representing the type of patient (C for Contaigen, T for Triage).
  Finds the index of the first patient in line that matches a specified type.
  This function iterates over the lineup array of pointers from the beginning. 
  For each patient, it compares the patient's type 
  with the specified type (using overloaded operator==). 
  If a match is found, the function returns the found index. 
  If the function iterates over the entire lineup 
  without finding a match, it returns -1 */
  int PreTriage::indexOfFirstInLine(char type) const {
    return -1;
  }
  
  void PreTriage::load() {
    clear();
    ifstream importFile(m_fileName);
    Patient* temp{nullptr};
    cout << "Loading data..." << endl;
    importFile >> m_waitTimeCT;
    importFile.ignore(1000, ',');
    importFile >> m_waitTimeT;
    importFile.ignore(1000, '\n');
    while (m_noOfPatient < MAX_NUM && importFile.get(m_type)) {
      importFile.ignore(1000, ',');
      if (m_type == 'C') {
        temp = new TestPatient;
        ++m_numOfCT;
      } else if (m_type == 'T') {
        temp = new TriagePatient;
        ++m_numOfT;
      } else {
      	importFile.setstate(ios::failbit);
        break;
      }
      temp->read(importFile);
      m_lineUp[m_noOfPatient++] = temp;
    }
    if (m_noOfPatient > MAX_NUM) 
      cout << "Warning: number of records exceeded " << MAX_NUM
            << "\n" << MAX_NUM << " Records imported..." << endl;
    else if (m_noOfPatient > 0)
      cout << m_noOfPatient << " Records imported..." << endl;
    else
      cout << "No data or bad data file!" << endl;
    cout << endl;
  }
  
  void PreTriage::save() {
    ofstream expertFile(m_fileName);
    cout << "Saving lineup..." << endl;
    expertFile << m_waitTimeCT << ',' << m_waitTimeT << endl;
    for (int i = 0; i < m_noOfPatient; i++) {
      m_lineUp[i]->write(expertFile);
      expertFile << endl;
    }
    cout << m_numOfCT << " Contagion Tests and " << m_numOfT << " Triage records were saved!" << endl;
  }
  /* register (Modifier)
  Registers a new patient:
  Create a Menu object for a sub-menu 
  for patient type selection with one indentation (1 tab) 
  as follows to be displayed later. */
  void PreTriage::reg() {
    cout << "Select Type of Registration: " << endl
         << "1- Contagion Test" << endl
         << "2- Triage" << endl
         << "0- Exit" << endl
         << "> ";
  }
  /* admit (Modifier)
  Calls the next patient in line to be admitted 
  to the contagion test centre or Triage centre
  Create a Menu object for a sub-menu 
  for patient type selection with one indentation (1 tab) 
  as follows to be displayed later. */
  void PreTriage::admit() {

  }
  /* lineup (Query)
  Prints a report on patients currently in the lineup. */
  void PreTriage::lineup() {

  }
  
  PreTriage::PreTriage(const char* fileName)
   : m_waitTimeCT(15), m_waitTimeT(5), m_fileName(nullptr), m_noOfPatient(0) {
    if (fileName && fileName[0]) {
			m_fileName = new char[strlen(fileName) + 1];
			strcpy(m_fileName, fileName);
		}
    for (int i = 0; i < MAX_NUM; ++i) m_lineUp[i] = nullptr;
    load();
  }
  
  PreTriage::~PreTriage() {
    save();
    clear();
    if (m_fileName) {
      delete[] m_fileName;
      m_fileName = nullptr;
    }
  }
  
  void PreTriage::run() {
    int selection;
    bool flag(true);
    do {
      cout << "General Healthcare Facility Pre-Triage Application" << endl
          << "1- Register" << endl
          << "2- Admit" << endl
          << "3- View Lineup" << endl
          << "0- Exit" << endl
          << "> ";
      cin >> selection;
      switch (selection) {
        case 0:
          flag = true;
          break;
        case 1:
          reg();
          flag = false;
          break;
        case 2:
          admit();
          flag = false;
          break;
        case 3:
          lineup();
          flag = false;
          break;
        default:
          cout << "Invalid number, value should be in 0 to 3. Please try again." << endl;
          flag = false;
          break;
      }
    } while (!flag);
  }
}
