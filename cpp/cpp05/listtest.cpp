
#include "listtest.h"

#include <random>
#include <chrono>
#include <algorithm>
#include <vector>
#include <iostream>

void listtest::sort_assign( std::list< std::string > & v ) {
  for(std::list<std::string>::iterator point1=v.begin(); point1 != v.end(); ++point1 ){
       for( std::list<std::string>::iterator point2 = v.begin(); point2!=point1; ++point2 ){
          if(*point1 > *point2 ){
              std::string s = *point2;
              *point1 = *point2;
              *point2 = s;
          }
       }
  }
}

std::list<std::string> listtest::converter(const std::vector<std::string>& v){
    std::list<std::string> result;
    for (size_t i=0; i < v.size() ; i++){
	result.push_back(v[i]);

   }
   return result;
}

void listtest::sort_move( std::list< std::string > & v ){
    for( std::list<std::string>::iterator point1 = v.begin(); point1 !=v.end(); ++point1 ){
       for( std::list<std::string>::iterator point2 = v.begin(); point2!=point1; ++point2 ){
          if( *point2 > *point1 ) std::swap( *point1, *point2 );
       }
    }

  }

std::ostream&
operator << ( std::ostream& out , const std::list< std::string> & myList ){
    out<<"{ ";
    for (std::list<std::string>::const_iterator pointer = myList.begin(); pointer != myList.end() ; pointer ++){
  	   out<<*pointer;
	   pointer++;
	if (pointer!=myList.end()){
	   out<<" , ";
	}
	pointer--;
	}
    out<<" }";
    return out;
}
