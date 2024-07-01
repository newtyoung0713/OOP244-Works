#ifndef SENECA_TIME_H
#define SENECA_TIME_H
#include <iostream>
namespace seneca {
  class Time {
  private:
    unsigned int m_minutes;
  public:
    // This method resets the Time object to the current time using the U.getTime() method, 
    // which is available in the Utils module. 
    // It then returns a reference to the current object.
    Time& reset();

    // This constructor initializes a Time object. 
    // It sets the number of minutes held in the object 
    // to the value provided in the min parameter. 
    // If no value is provided, it defaults to zero, 
    // effectively setting the time to zero.
    Time(unsigned int min = 0u); 

    // This operator overloads the cast to int for the Time class. 
    // If a Time object is cast to an integer, 
    // it will return the number of minutes held in the object.
    operator int()const;

    // This operator overloads the multiplication assignment *= for the Time class. 
    // It multiplies the number of minutes held in the Time object by val, 
    // then returns a reference to the current object.
    Time& operator*= (int val);

    // This operator overloads the subtraction assignment -= for the Time class. 
    // It calculates the time difference between the current Time object 
    // and the Time object D passed as an argument. 
    // Note that the difference can never be a negative value. 
    // If the result would be negative, 
    // it adds 24 hours (or 1440 minutes) to ensure the result is positive. 
    // Here are some examples:
    // 23:00 -= 9:00 results in 14:00.
    // 18:00 -= 16:00 results in 2:00.
    // 1:00 -= 22:00 results in 3:00. This is calculated as ((1:00 + 24:00) - 22:00).
    Time& operator-= (const Time& D);

    // This method writes the time into ostream in the HH:MM format. 
    // If the hours or minutes are single-digit numbers, 
    // it pads them with a leading zero. 
    // For example, it formats the times as 03:02, 16:55, and 234:06.
    void write(std::ostream& ostr) const;

    // This method reads the time from istream in the H:M format. 
    // It ensures that the two integers (hours and minutes) 
    // are separated by a colon (:). 
    // If they are not, it sets the istream object to a failure state.
    // Please note that this function does not handle any invalid data. 
    // It simply follows these steps:
    // Reads the integer for the hours using istream.
    // Check the next character and verifies if it is : and discards is. 
    // If it is not, it sets the istream object to a failure state 
    // by executing the method: istr.setstate(ios::failbit);.
    // Reads the integer for the minutes using istream.
    void read(std::istream& istr);

    // This operator performs the same calculation as the subtraction assignment -= overload, 
    // except that it does not have a side effect 
    // (i.e., it does not modify the current object).
    // It returns a new Time object representing the time difference 
    // between the current Time object and the Time object T.
    Time operator-(const Time& T)const;

    // Overload the insertion operator to be able to insert a Time object 
    // into an ostream object as described in the write method.
    friend std::ostream& operator<<(std::ostream& ostr, const Time& time);

    // Overload the extraction operator to be able to extract data 
    // from an istream object into the Time object as described in the read method.
    friend std::istream& operator>>(std::istream& istr, Time& time);
  };
}
#endif  //  !SENECA_TIME_H 