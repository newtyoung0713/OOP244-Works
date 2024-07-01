#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H
#include <iostream>
namespace seneca {
  class IOAble {
  public:
    /* 
    This pure virtual function is for future ostream outputs. 
    It receives a reference of an ostream and returns a reference of an ostream. 
    This function is incapable of changing the current object. 
    */
    virtual std::ostream& write(std::ostream& os) const = 0;

    /* 
    This pure virtual function is for future istream inputs. 
    It receives a reference of istream and returns a reference of an istream. 
    */
    virtual std::istream& read(std::istream& is) = 0;

    // This class also has an empty virtual destructor.
    virtual ~IOAble() = default;

    /* 
    Overload the insertion operator to be able to insert the information 
    of an IOAble object into ostream using the IOAble::write function. 
    */
    friend std::ostream& operator<<(std::ostream& os, const IOAble& ioa);

    /* 
    Overload the extraction operator to be able to extract information 
    from an istream into an IOAble object using the IOAble::read function. 
    */
    friend std::istream& operator>>(std::istream& is, IOAble& ioa);
  };
}
#endif  //  !SENECA_IOABLE_H 