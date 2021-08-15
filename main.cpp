#include <iostream>
#include "Mystring.hpp"
#include <string>


// Uing member methods
using namespace std;
int main() {
   cout<<boolalpha<<endl;
//  
//   Mystring a {"frank"}; //Overloaded Constructor
//   Mystring b {"frank"}; //Overloaded COnstructor
   
//   cout<<(a==b)<<endl;
//
//   cout<<(a!=b)<<endl;
//     
//   b= "george"; //Move constructor is called, after which move assignment ioperator is called
//     
//   cout<<(a==b)<<endl;
//   cout<<(a!=b)<<endl;
// 
//    cout<<(a>b)<<endl; 
//  
//   cout<<(a<b)<<endl;
// 
   
   Mystring s1("FRANK");
   s1 = -s1; //lowercase......
   cout<<s1<<endl;
   
   s1 = s1 + "****";

   cout<<s1<<endl;
   
   s1+="++++";
   cout<<s1<<endl;
  
   Mystring s2{"12345"};
   s1= s2*3;
   cout<<s1<<endl;
    
   Mystring s3{"abcdef"};
   s3*=5;
   cout<<s3<<endl;

   Mystring s = "Frank";
   ++s;
   cout<<s<<endl;
      
   s =- s;
   cout<<s<<endl;
   
   Mystring result;
   result = ++s;
   cout<<s<<endl;
   cout<<result<<endl;
   
   s= "Frank";
   s++;
   cout<<s<<endl;
   
   s =- s;
   cout<<s<<endl;
   result = s++;//Result is equals to s, after which s is incremented...   
   cout<<s<<endl;
   cout<<result<<endl;
   
    return 0;
}