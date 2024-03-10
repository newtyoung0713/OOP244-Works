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

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Customer.h"
using namespace std;

namespace seneca {
  bool Customer::isEmpty() const {
    return (m_name == nullptr || m_name[0] == '\0') || (m_car == nullptr);
  }

  void Customer::setEmpty() {
    m_id = 0;
    delete[] m_name;
    m_name = nullptr;
    delete m_car;
    m_car = nullptr;
  }

  void Customer::deallocateMemory() {
    setEmpty();
  }

  void Customer::set(int customerId, const char* name, const Car* car) {
    setEmpty(); // Initialized everything to empty status

    // Checking the input is valid or not
    if (name != nullptr && name[0] != '\0' && car != nullptr) {
      // Setting the customer's ID and using dynamic memory for m_name and m_car
      m_id = customerId;

      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);

      m_car = new Car(*car);
    }
  }
  
  void Customer::display() const {
    if (!isEmpty()) {
      cout << left << setw(15) << "Customer ID:" << right << setw(20) << m_id << endl;
      cout << left << setw(15) << "First Name:" << right << setw(20) << m_name << endl;

      if (m_car != nullptr) {
        m_car->display(); // Display the car information directly
      }

      cout << endl;
    }
  }

  const Car& Customer::car() const {
    return *m_car;
  }
}