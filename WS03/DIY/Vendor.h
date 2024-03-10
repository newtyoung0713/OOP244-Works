//*****************************************************************************
//  <assessment name example : Workshop - #3 (Part - 2)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Feb 07th, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************

#ifndef SENECA_VENDOR_H
#define SENECA_VENDOR_H
#include "Icecream.h"
namespace seneca {
  class Vendor {
    Icecream* m_cusOfIcecream{};
    int m_numOfIcecream{};
    const double m_tax = 0.13;
    double m_afterTax{};
    double m_subTotal{};
    double m_total{};
  public:
    // A member function to set the Vendor object to an empty state.
    void setEmpty();
    // A member function responsible for taking customer orders.
    // This function interacts with customers to gather order details.
    // It will get the number of orders for Icecreams
    // Gets each order for the Icecream
    void takeOrders();
    // Prints the details of all the orders
    // Prints the total price, tax (13%) and the Total price after tax.
    void displayOrders();
    // A member function for cleaning up
    // and releasing resources associated with the Vendor object.
    // This function is used to avoid memory leaks
    // and perform cleanup when the Vendor object is no longer needed.
    void clearData();
  };
}
#endif // !SENECA_VENDOR_H