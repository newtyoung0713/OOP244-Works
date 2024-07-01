#ifndef SENECA_PRETRIAGE_H
#define SENECA_PRETRIAGE_H
#include <iostream>
#include "Time.h"
#include "Patient.h"
namespace seneca {
  const int MAX_NUM(100);
  class PreTriage {
    int m_numOfCT{0}, m_numOfT{0};
    char m_type{};
    Time m_waitTimeCT;
    Time m_waitTimeT;
    Patient* m_lineUp[MAX_NUM]{nullptr};
    char* m_fileName;
    int m_noOfPatient;
    void clear();
    const Time getWaitTime(const Patient& uneAutre) const;
    /* setAverageWaitTime (Modifier)
      CT: Current Time
      PTT: Patient's Ticket Time
      AWT: Average Wait Time (Contagion or Triage)
      PTN: Patient's Ticket Number
      AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN */
    void setAverageWaitTime(Patient& uneAutre);
    int indexOfFirstInLine(char type) const;
    void load();
    void save();
    void reg();
    void admit();
    void lineup();
  public:
    PreTriage() = default;
    PreTriage(const PreTriage& uneAutre) = delete;
    PreTriage& operator=(const PreTriage& uneAutre) = delete;
    PreTriage(const char* fileName);
    virtual ~PreTriage();
    void run();
  };
}
#endif  //  !SENECA_PRETRIAGE_H
