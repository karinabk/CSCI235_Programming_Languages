
#include <fstream>
#include <iostream>
#include <random>
#include <map>
#include <unordered_map>
#include "listtest.h"
#include "vectortest.h"
#include "timer.h"

struct case_insensitive_cmp {
	 bool operator() (const std::string& s1, const std::string& s2){
		 unsigned int val1, val2;
		 auto p = s1.cbegin(), p2 = s2.cbegin();
		 for (;p!=s1.cend()&&p2!=s2.cend();++p,++p2){
					val1 = *p;
					val2 = *p2;
					if (val1 > 96){
						val1+= - 32;
					}
					if(val2 > 96){
						val2+= - 32;
					}
					if (val1>val2) return false;
					else if (val1<val2) return true;
					}
		if (p!=s1.cend()) return false;
		if(p2 != s2.cend()) return true;
		return false;
	}
};

struct case_insensitive_hash
{
	size_t operator ( ) ( const std::string& s ) const{
		std::hash<char> hash;
		size_t result=0;
		for (size_t i =0;i!=s.size();++i){
			if (s[i]>96) result+=hash(s[i]-32);
			else result+=hash(s[i]);
		}
		return result;
	}
};


struct case_insensitive_equality
{
	bool operator ( ) ( const std::string& s1,
										const std::string& s2 ) const{

			std::hash<char> hash_func1;
			std::hash<char> hash_func2;

			size_t sum_hash1 = 0, sum_hash2 = 0;

			if (s1.size() != s2.size()) {
				return false;
			}

			for (size_t i = 0; i < s1.size(); i++) {
				if(tolower(s1[i]) != tolower(s2[i])){
					return false;
				}
				sum_hash1+=hash_func1(tolower(s1[i]));
				sum_hash2+=hash_func2(tolower(s2[i]));

			}
			return sum_hash1==sum_hash2;
	}
};


std::ostream& operator << ( std::ostream& out,
	const std::map<std::string, unsigned int, case_insensitive_cmp> & freq);

std::ostream& operator << ( std::ostream& out,
	const std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality> & freq);

std::string toL(std::string str){
	std::string result = "";
	for (size_t i =0; i!= str.size(); ++i){
		result+=std::tolower(str[i]);
	}
	return result;
}

void traverseWord (const std::map<std::string, unsigned int, case_insensitive_cmp>& s, const std::string& target){
	for (std::map<std::string,unsigned int,case_insensitive_cmp> ::const_iterator p=s.begin(); p!= s.end();++p){
		if (toL(p -> first) == toL(target))
			std::cout<< p -> first <<"----->"<<p -> second<<"\n";
	}
}

void mostFre (const std::map<std::string, unsigned int, case_insensitive_cmp>& s	){
	unsigned int max =0;
	std::string word ;
	for (std::map<std::string,unsigned int,case_insensitive_cmp> ::const_iterator p=s.begin(); p!= s.end();++p){
		if (max < p -> second){
			max = p-> second;
			word = p -> first;
		}
	}
	std::cout<< "  most frequent   " <<max << "  ----->  " << word<< "\n";
}

std::map< std::string, unsigned int, case_insensitive_cmp > frequencytable( const std::vector<std::string>& text){
    std::map <std::string, unsigned int, case_insensitive_cmp> table;
    for (const auto &p : text){
			++table[p];
    }
    return table;
}

std::unordered_map< std::string, unsigned int, case_insensitive_hash, case_insensitive_equality >
hashed_frequencytable( const std::vector< std::string > & text ){
std::unordered_map <std::string, unsigned int, case_insensitive_hash, case_insensitive_equality> table;
    for (const auto &p : text){
			++table[p];
    }
    return table;
}


int main( int argc, char* argv [] )
{

	case_insensitive_cmp c;
	std::cout << c( "a", "A" ) << c( "a","b" ) << c( "THIS", "THISS" ) << "\n";

	case_insensitive_hash h;
	std::cout << h( "xxx" ) << " " << h( "XXX" ) << "\n";
	std::cout << h( "Abc" ) << " " << h( "abC" ) << "\n";


   std::cout << hashed_frequencytable( std::vector< std::string >
	{ "AA", "aA", "Aa", "this", "THIS" } );

	case_insensitive_equality e;
	std::cout << e( "xxx", "XXX" ) << "\n";


	std::ifstream inp{ "1.html" };
  std::vector< std::string> test = vectortest::readfile(inp);


	std::cout<< frequencytable(test);

  auto map1 = frequencytable(test);

  traverseWord(map1 ,"memoria");
	std::cout << map1["memoria"]<<"\n";
	mostFre (map1);


	return 0;
}

std::ostream& operator << ( std::ostream& out,
	const std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality> & freq){
		std::string str;
    unsigned int num;
    for (const auto& p: freq){
 		 str = p.first;
 	 	 num = p.second;
 	 	 out<< str<<" -> "<<num<<" \n";
    }
    return out;
	}

std::ostream& operator << (std::ostream& out,
	const std::map<std::string, unsigned int, case_insensitive_cmp>& freq){
   std::string str;
   unsigned int num;
   for (const auto& p: freq){
		 str = p.first;
	 	 num = p.second;
	 	 out<< str<<" -> "<<num<<" \n";
   }
   return out;
}
