
#ifndef STRING_INCLUDED
#define STRING_INCLUDED 1

#include <iostream>
#include <cstring>
class string;
std::ostream& operator << ( std::ostream&, const string& );
// p is always allocated, and len is the size of the string.

struct string
{
   size_t len;
   char *p;

   // Default constructor currently switched off.
   // You may switch it on if you want.


   string( )
      : len{0},
        p{nullptr}
   {
      std::cout << " default constructor\n";
   }


   string( const char* c )
      : len{ strlen(c) },
        p{ new char[ len ] }
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = c[i];
      std::cout<<"This is my constructor for "<< *this <<"\n" ;
   }

   string( const string& s )
      : len{ s. len },
        p{ new char[ len ] }
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = s.p[i];

      std::cout << "This is the copy constructor for " << *this << "\n";
   }

   string( string&& s) noexcept
	:len{s.len},
	p{s.p}
	{
          s.len = 0 , s.p = nullptr;
 	std::cout<<"This is moving constructor for "<< *this<< "\n";}

   const string& operator = (string&& s) noexcept
   {
     std::swap(p , s.p);
     std::swap(len, s.len);
     std::cout<<"This is moving assignment for "<<*this<<"\n";
     return *this;
   }

   string& operator = ( const string& s )
   {
      // Not only for efficiency, but also for assignment:

      if( len != s. len )
      {
         delete[] p;
         p = new char[ s. len ];
         len = s. len;
      }
      for( size_t i = 0; i != len; ++ i )
         p[i] = s.p[i];

      std::cout << "assignment operator for "<< *this << "\n";
      return *this;
   }

   void push_back(const string& s){
     char* temp = new char[len+s.len];
     for (size_t i = 0; i < len; i++) {
       temp[i] = p[i];
     }
     for (size_t i = 0; i < s.len; i++) {
       temp[i+len] = s[i];
     }
     len+=s.len;
     delete [] p;
     p = temp;
   }

   ~string( )
   {
      std::cout << "This is the the destructor for "<< *this<<"\n";

      delete[] p;
   }





   string& operator += ( char c );
   using iterator = char* ;
   using const_iterator = const char* ;
   const_iterator begin( ) const { return p; }
   const_iterator end( ) const { return p + len; }
   iterator begin( ) { return p; }
   iterator end( ) { return p + len; }
   char operator [] ( size_t i ) const;
   char& operator [] ( size_t i );
   size_t size() const;
};



string& operator += ( string& s1, const string& s2 );

std::ostream& operator << ( std::ostream& out, const string& s );

string operator + ( const string& s1, const string& s2 );

bool operator == ( const string& s1, const string& s2 );
bool operator < ( const string& s1, const string& s2 );
   // add others as inline.

  inline bool operator !=(const string& s1, const string& s2){ return !(s1==s2);}
  inline bool operator > (const string& s1, const string& s2){ return !(s1<s2)&&!(s1==s2);}
  inline bool operator <=(const string& s1, const string& s2){ return !(s1>s2);}
  inline bool operator >=(const string& s1, const string& s2){ return s1>s2||s1==s2;}


  const string& greater(const string& s1, const string& s2);
  string&& greater( string&& s1, string&& s2);

#endif
