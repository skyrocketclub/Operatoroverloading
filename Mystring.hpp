#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
class Mystring
{
     
private:
    char *str;    //pointer to a char[] that holds a C- style string
    
public:
    Mystring();                                          //Prototype of No arg constructor...
    Mystring(const char *s);                     //Overloaded constructor
    Mystring(const Mystring &source) ;  //copy constructor
    //Copy assignment
    //you write down the operator, you also write down what is on the right hand side...
    Mystring &operator = (const Mystring &rhs);
    
    //Move contructor
    Mystring (Mystring &&source);
    //Move assignment
    Mystring &operator = (Mystring &&rhs);
           

    ~Mystring();                                       //Destructor
    
    void display() const;                            //displays content of the string...
    int get_length() const;                         //to get the length of the string...
    const char *get_str() const;
    bool operator ==(const Mystring &rhs)const;
    bool operator !=(const Mystring &rhs)const;
    bool operator >(const Mystring &rhs)const;
     bool operator <(const Mystring &rhs)const;
     Mystring operator -() const;
     friend std::ostream &operator<< ( std::ostream& COUT, Mystring &rhs);
     Mystring operator + (const Mystring &rhs) const;
     Mystring operator += (const Mystring &rhs) ;
     Mystring operator * (const int);
    Mystring operator *= (const int);
    Mystring &operator ++();//preincrement
    Mystring operator ++(int); //post increment
    
};

#endif // _MYSTRING_H_
