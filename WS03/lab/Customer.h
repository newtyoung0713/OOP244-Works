//*****************************************************************************
//  <assessment name example : Workshop - #3 (Part - 1)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Feb 3rd, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************

#ifndef SENECA_CUSTOMER_H
#define SENECA_CUSTOMER_H
#include "Car.h"
namespace seneca {
  class Customer {
    int m_id{};
    char* m_name{};
    Car* m_car{};
  public:
    bool isEmpty() const;
    void setEmpty();
    void deallocateMemory();
    void set(int customerId, const char* name, const Car* car);
    void display() const;
    const Car& car() const;
  };
}
#endif // !SENECA_CUSTOMER_H
