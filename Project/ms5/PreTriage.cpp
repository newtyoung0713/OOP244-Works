//*****************************************************************************
//  <assessment name example : Milestone - #5>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : April 03rd, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my milestones and assignments.
//*****************************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <typeinfo>
#include "Menu.cpp"
#include "Time.h"
#include "PreTriage.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Utils.h"
using namespace std;
namespace seneca {
  void PreTriage::clear() {
    for (int i = 0; i < m_noOfPatient; ++i) {
      delete m_lineUp[i];
      m_lineUp[i] = nullptr;
    }
  }

  const Time PreTriage::getWaitTime(const Patient& uneAutre) const {
    char tempType = (typeid(uneAutre) == typeid(TestPatient)) ? 'C' : 'T';
    int matched = 0;
    // EWT as known as Estimated Wait Time
    int EWT = (tempType == 'C') ? m_waitTimeCT : m_waitTimeT;
    for (int i = 0; i < m_noOfPatient; ++i) {
      if (m_lineUp[i]->type() == tempType) {
        matched++;
      }
    }
    return matched * EWT;
  }

  /* setAverageWaitTime (Modifier)
  Modify and set the value of the average wait time 
  of the corresponding patient using the following formula:
    CT: Current Time
    PTT: Patient's Ticket Time
    AWT: Average Wait Time (Contagion or Triage)
    PTN: Patient's Ticket Number
    AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN */
  void PreTriage::setAverageWaitTime(Patient& uneAutre) {
    Time CT;
    int ctTime = CT.reset();
    Time PTT = uneAutre.time();
    int PTN = uneAutre.number();
    Time& AWT = uneAutre.type() == 'C' ? m_waitTimeCT : m_waitTimeT;
    AWT = ((ctTime - PTT) + (AWT * (PTN - 1))) / PTN;
  }
  
  int PreTriage::indexOfFirstInLine(char type) const {
    for (int i = 0; i < m_noOfPatient; i++)
      if (*m_lineUp[i] == type)
        return i;
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
      m_lineUp[m_noOfPatient] = temp;
      m_noOfPatient++;
    }
    if (m_noOfPatient >= MAX_NUM) 
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
  
  void PreTriage::reg() {
    if (m_noOfPatient >= MAX_NUM) {
      cout << "Line up full!" << endl;
      return;
    }
    seneca::Menu sub_menu("Select Type of Registration:\n1- Contagion Test\n2- Triage\n", 1);
    int selection;
    Time time;
    sub_menu >> selection;
    if (selection == 1) {
      m_lineUp[m_noOfPatient] = new TestPatient;
      ++m_numOfCT;
    } else if (selection == 2) {
      m_lineUp[m_noOfPatient] = new TriagePatient;
      ++m_numOfT;
    } else {return;}
    m_lineUp[m_noOfPatient]->setArrivalTime();
    cout << "Please enter patient information: " << endl;
    cin.ignore();
    cin >> *m_lineUp[m_noOfPatient];
    cout << endl << "******************************************" << endl
         << *m_lineUp[m_noOfPatient] 
         << "Estimated Wait Time: " << getWaitTime(*m_lineUp[m_noOfPatient]);
    cout << endl << "******************************************" << endl << endl;
    m_noOfPatient++;
  }

  void PreTriage::admit() {
    seneca::Menu sub_menu("Select Type of Admittance:\n1- Contagion Test\n2- Triage\n", 1);
    int selection, index;
    Time time;
    sub_menu >> selection;
    if (selection == 1) {
      m_type = 'C';
      --m_numOfCT;
    } else if (selection == 2) {
      m_type = 'T';
      --m_numOfT;
    } else {return;}
    index = indexOfFirstInLine(m_type);
    if (index == -1) {
      cout << "Lineup is empty!\n";
      return;
    }
    cout << endl;
    cout << "******************************************" << endl;
    cout << "Call time: [" << time.reset() << "]" << endl;
    cout << "Calling at for " << *m_lineUp[index];
    cout << "******************************************" << endl << endl;
    setAverageWaitTime(*m_lineUp[index]);
    U.removeDynamicElement(m_lineUp, index, m_noOfPatient);
  }

  void PreTriage::lineup() {
    seneca::Menu sub_menu("Select The Lineup:\n1- Contagion Test\n2- Triage\n", 1);
    int selection, count;
    bool flag(true);
    sub_menu >> selection;
    flag = (selection == 1 || selection == 2) ? false : true;

    if (!flag) {
      count = 0;
      cout << "Row - Patient name                                          OHIP     Tk #  Time\n"
          << "-------------------------------------------------------------------------------" << endl;
      for (int i = 0; i < m_noOfPatient; ++i) {
        if ((selection == 1 && typeid(*m_lineUp[i]) == typeid(TestPatient)) ||
            (selection == 2 && typeid(*m_lineUp[i]) == typeid(TriagePatient))) {
          (m_lineUp[i]) ? 
          clog << left << setw(4) << setfill(' ') << (++count) << "- " << *m_lineUp[i] << endl : 
          cout << "Line up is empty!\n";
        }
      }
      cout << "-------------------------------------------------------------------------------" << endl;
    }
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
