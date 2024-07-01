#ifndef SENECA_HERO_H
#define SENECA_HERO_H
#include <iostream>
#include "Power.h"

namespace seneca {
  const int MAX_NAME_LEN = 50;
	class Hero{
    char m_name[MAX_NAME_LEN + 1];
    Power* m_power;
    int m_numPower;
    int m_powerLevel;
    void updatePowerLevel();
	public:
    // Default constructor to set a hero to a safe empty state.
    Hero();
    // Overloaded constructor with 3 parameters to set the name, 
    // list of powers and the count of powers a hero has. 
    // This constructor will also set/update the powerlevel of a hero.
    Hero(const char* name, const Power* power, int num);
    ~Hero();
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
    std::ostream& display() const;
    // overload the += operator that accepts a power reference. 
    // The power should be added to the dynamic list of powers of your hero. 
    // Your heroes' power level and power count should be updated too.
    Hero& operator+= (const Power& power);
    // overload the -= operator that accepts an integer reference. 
    // This operator will decrease the power level of the hero by the integer value received.
    Hero& operator-= (int numLevel);
  // operator< : This operator takes two references to two hero parameters. 
  // It will return true if the first hero's power level is less than the second hero's power level. 
  // It will return false otherwise.
  friend bool operator< (const Hero& h1, const Hero& h2);
  // operator> : This operator takes two references to two hero parameters. 
  // It will return true if the first hero's power level is greater than the second hero's power level. 
  // It will return false otherwise.
  friend bool operator> (const Hero& h1, const Hero& h2);
  // operator>> : This operator will take two parameters. 
  // The left parameter is a reference to a power. 
  // The right parameter is a reference to a hero. 
  // This operator will add power to the hero and update the hero accordingly.
  // Note: this is not an istream extraction operator 
  // and you are not allowed to modify the power module
  friend void operator>>(const Power& power, Hero& hero);
  // operator<< : This operator will take two parameters. 
  // The left parameter is a reference to a hero. 
  // The right parameter is a reference to a power. 
  // This operator will add power to the hero and update the hero accordingly.
  // Note: this is not an ostream insertion operator
  friend void operator<<(Hero& hero, Power& power);
	};
}
#endif  //  !SENECA_HERO_H 