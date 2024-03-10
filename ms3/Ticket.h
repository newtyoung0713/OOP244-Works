#ifndef SENECA_TICKET_H_
#define SENECA_TICKET_H_
#include <iostream>
#include "Time.h"
#include "IOAble.h"
namespace seneca {
  class Ticket:public IOAble{
    // The time the Ticket was issued
    Time m_time;
    // The ticket number; 
    // A sequential integer, 
    // starting from one and unique for each lineup.
    int m_number;
  public:
    // Constructs a Ticket by setting the m_number member variable
    Ticket(int number);
    // A query that returns the time when the ticket was issued.
    Time time()const;
    // A query returning the number of the ticket
    int number()const;
    // Sets the Ticket time to the current time.
    void resetTime();
    /* 
    Inserts a ticket into the ostream to be displayed on the console 
    or inserts comma-separated ticket number and time into ostream 
    based on the ostream reference being cout or not. 
    */
    std::ostream& write(std::ostream& ostr )const;
    // Extracts the ticket number and time in a comma-separated format from istream.
    std::istream& read(std::istream& istr);
  };
}
#endif // !SENECA_TICKET_H_
