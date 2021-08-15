#include "Mystring.hpp"
#include <cstring>
#include <iostream>
//using namespace std;
//No-args constructor is called here...
//
Mystring::Mystring()
     :str{nullptr} //str is a nullpinter..
{
    str = new char[1]; //Allocate space for one character... 
    *str = '\0'; // A terminator has been inputed in there... 
}

//Overloaded constructor
Mystring::Mystring(const char *s) //What is passed is the pointer that is dereferenced on arrival
        :str{nullptr}{
            if (s == nullptr){
                str = new char[1];
                *str = '\0';
            }
            else {
                str = new char[std::strlen(s) + 1];// Plus 1 because of the terminating character
                std::strcpy(str, s); //s is copied to str...
            }
        }


//Copy constructor performing a deep copy for when an object is passed into the method...
Mystring::Mystring(const Mystring &source)
:str{nullptr}{
    std::cout<<"The copy constructor is called"<<std::endl;
    str = new char [std::strlen(source.str) + 1]; // the +1 is added there for the terminator...
    std::strcpy(str, source.str);
}

//this points to the current object...
Mystring &Mystring::operator = (const Mystring &rhs){
    if(this == &rhs){
        return *this;
    }
    else{
        delete [] str;
        str = new char[std::strlen(rhs.str)+1];
        std::strcpy(str,rhs.str);
    }
    return *this;
}

//Move constructor
Mystring ::Mystring (Mystring &&source)
:str{source.str}{
std::cout<<"Move constructor used"<<std::endl;   
 source.str =nullptr;
    
}

//Move assignment
Mystring &Mystring::operator = (Mystring &&rhs){
    std::cout<<"Using move assignment"<<std::endl;
    if(this == &rhs){
        return *this;
    }
    else{
        delete[]str;
        str = rhs.str;
        rhs.str = nullptr;
    }
    return *this;
}

Mystring::~Mystring()
{
    delete [] str;
}

//Display Method
void Mystring::display() const{
    std::cout<<str<<" : "<<get_length()<<std::endl;
}
//length getter
int Mystring::get_length() const {
    return std::strlen(str);
}

//string getter
const char *Mystring::get_str() const {
    return str;
}

bool Mystring::operator== (const Mystring &rhs)const{
    return (std::strcmp(str,rhs.str)==0);
}

bool Mystring::operator != (const Mystring &rhs)const{
    return (std::strcmp(str,rhs.str)!=0);
}

bool Mystring::operator >(const Mystring &rhs)const{
    bool status {false};
    if ( this->str > rhs.str){
        status = true;
    }
    else{
        status = false;
    }
    return status;
}

bool Mystring::operator <(const Mystring &rhs)const{
    bool status {false};
    if ( this->str < rhs.str){
        status = true;
    }
    else{
        status = false;
    }
    return status;
}
Mystring Mystring::operator -()const{
    char *buff = new char [ std::strlen(this->str)+1];
    buff= std::strcpy(buff,str);
    for (size_t i {0}; i< std::strlen(buff); i++){
        buff[i]=tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

std::ostream &operator << (std::ostream & COUT, Mystring & rhs){
    COUT<<rhs.str;
    return COUT;
}

Mystring Mystring::operator + (const Mystring &rhs) const{
    char *buff = new char [ std::strlen(this->str) + std::strlen(rhs.str) + 1];
    buff = std::strcpy(buff, str);
    buff= std::strcat(buff,rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring Mystring::operator += (const Mystring &rhs) {
    str = std::strcat(str,rhs.str);
   Mystring tems {str};
    return tems;
}

Mystring Mystring::operator * (const int n){
    char *buff = new char[(std::strlen(this->str))*n+1];
    buff = std::strcpy(buff,str);
    for(int i {0}; i <n-1; i++){

        buff = std::strcat(buff,str);
    }
    Mystring temp {buff};
    delete[] buff;
    return temp;
}

Mystring Mystring::operator *= (const int n){

     char *buff = new char[ std::strlen(str)+1];
    buff = std::strcpy(buff,str);
    for(int i {0}; i <n-1; i++){

        str= std::strcat(str,buff);
    }
    Mystring temp {str};
    delete[] buff;
    return temp;

}

Mystring &Mystring::operator ++(){//preincrement
    char *buff = new char [ std::strlen(this->str)+1];
    buff= std::strcpy(buff,str);
    for (size_t i {0}; i< std::strlen(buff); i++){
        buff[i]=toupper(buff[i]);
    }
    str = std::strcpy(str,buff);
//    Mystring temp {buff};
    delete [] buff;
    return *this;
}
    
    Mystring Mystring::operator ++(int){ 
        Mystring temp (*this);
        operator++();
        return temp;
    }
    