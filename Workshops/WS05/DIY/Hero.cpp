//*****************************************************************************
//  <assessment name example : Workshop - #5 (Part - 2)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Feb 21st, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace seneca {
  void Hero::setPowerLevel() {
    int sumRarity = 0;
    for (int i = 0; i < m_numPower; ++i) {
      sumRarity += m_power[i].checkRarity();
    }
    m_powerLevel = m_numPower * sumRarity;
  }

  // Default constructor to set a hero to a safe empty state.
  Hero::Hero() : m_power(nullptr), m_numPower(0), m_powerLevel(0) {
    m_name[0] = '\0';
  }

  // Overloaded constructor with 3 parameters to set the name, 
  // list of powers and the count of powers a hero has. 
  // This constructor will also set/update the powerlevel of a hero.
  Hero::Hero(const char* name, const Power* power, int num) : m_numPower(num) {
    strncpy(m_name, name, MAX_NAME_LEN);
    m_power = new Power[num];
    for (int i = 0; i < num; ++i) {
      m_power[i] = power[i];
    }
    setPowerLevel();
  }

  Hero::~Hero() {
    delete[] m_power;
    m_power = nullptr;
  }

  // A display function that will send the information 
  // about a hero to ostream in the following format 
  // and then return the reference of ostream;
  // Name: XXXXXXXXXXX<ENDL>
  // List of available powers:
  //   powers listed here...
  //   powers listed here...
  //   powers listed here...
  //   powers listed here...
  // Power Level: XXXX<ENDL>
  std::ostream& Hero::display() const {
    cout << "Name: " << m_name << endl;
    displayDetails(m_power, m_numPower);
    cout << "Power Level: " << m_powerLevel;
    return cout;
  }

  // overload the += operator that accepts a power reference. 
  // The power should be added to the dynamic list of powers of your hero. 
  // Your heroes' power level and power count should be updated too.
  Hero& Hero::operator+= (const Power& power) {
    Power* temp = new Power[m_numPower + 1];
    for (int i = 0; i < m_numPower; ++i) {
      temp[i] = m_power[i]; // Copy the original source
    }
    delete[] m_power; //  Clean everything from m_power
    temp[m_numPower] = power; //  Assign new data after the original source
    m_power = temp; //  Assign TEMP to m_power
    ++m_numPower;
    setPowerLevel();  //  Calling a function to update heros' power level
    return *this;
  }

  // overload the -= operator that accepts an integer reference. 
  // This operator will decrease the power level of the hero by the integer value received.
  Hero& Hero::operator-= (int numLevel) {
    m_powerLevel -= numLevel;
    return *this;
  }

  // operator< : This operator takes two references to two hero parameters. 
  // It will return true if the first hero's power level is less than the second hero's power level. 
  // It will return false otherwise.
  bool operator< (const Hero& h1, const Hero& h2) {
    return h1.m_powerLevel < h2.m_powerLevel;
  }

  // operator> : This operator takes two references to two hero parameters. 
  // It will return true if the first hero's power level is greater than the second hero's power level. 
  // It will return false otherwise.
  bool operator> (const Hero& h1, const Hero& h2) {
    return h1.m_powerLevel > h2.m_powerLevel;
  }

  // operator>> : This operator will take two parameters. 
  // The left parameter is a reference to a power. 
  // The right parameter is a reference to a hero. 
  // This operator will add power to the hero and update the hero accordingly.
  // Note: this is not an istream extraction operator 
  // and you are not allowed to modify the power module
  void operator>>(Power& power, Hero& hero) {
    hero += power;
  }

  // operator<< : This operator will take two parameters. 
  // The left parameter is a reference to a hero. 
  // The right parameter is a reference to a power. 
  // This operator will add power to the hero and update the hero accordingly.
  // Note: this is not an ostream insertion operator
  void operator<<(Hero& hero, Power& power) {
    hero += power;
  }
}