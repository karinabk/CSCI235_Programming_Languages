
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <sstream>
#include "string.h"


int main( int argc, char* argv [ ] ) {
  // string s = "have a ";
  // s.push_back("nice ");
  // s.push_back("day");
  // std::cout << s << '\n';
  // std::cout << s1 + s2 << '\n';
  // std::cout << string("good ") + string("morning") << '\n';
  // std::cout << "good " + string("morning") << '\n';
  // std::cout << string("good ") + "morning" << '\n';
  // std::cout << "good " + "morning"  << '\n';
  // std::cout << string("good ") +  << '\n';
  string zz = "zz";
  std::cout << "before:\n";
  string max = greater( greater( "aa", string( "b" ) + string( "c" )), greater( zz, string( "cc" )));
  std::cout << "after:\n";
  std::cout << "max = " << max << "\n";


}
