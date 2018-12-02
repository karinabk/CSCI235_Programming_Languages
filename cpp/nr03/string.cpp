
#include "string.h"


#if 1

const string& greater( const string& s1, const string&s2){
    std::cout << "reference greater " << s1 << " " << s2 << "\n";
    if (s1 > s2) return s1;
    return s2;
}

string&& greater( string&& s1, string&& s2){
   std::cout << "moving greater " << s1 << " " << s2 << "\n";
   if (s1 > s2) return std::move( s1);
   return std::move(s2);

}

// as usual: Take the functions out one by one when you write them.
string& string::operator += ( char c ){
	char* temp = new  char[len+1];
	for (size_t k=0; k<len ; ++k){
		temp[k] = p[k];
	}
	temp[ len ]=c;
	delete[] p;
	p = temp;
	len+=1;
	return *this;
}
string& operator += ( string& s1, const string& s2 ){
	size_t len2 = s2.len;
	for(size_t i=0;i != len2;++i){
		s1+=s2[i];
	}
	return s1;
}
// string operator + ( string s1, const string& s2 ){
// 	return std::move( s1+=s2 );
// }

string operator + (const string& s1, const string& s2){
  string temp;
  temp.push_back(s1);
  temp.push_back(s2);
  std::cout << "const operator + " << '\n';
  return temp;
}

string && operator + (string&& s1, const string& s2){
  std::cout << "non const operator + " << '\n';
  std::cout << s1 + s2 << '\n';
  return s1 + s2;
}

#endif

char string::operator [] ( size_t i ) const{
	return p[i];
}
char& string::operator [] ( size_t i ){
	return p[i];
}
size_t string::size() const{
	return len;
}

bool operator == (const  string& s1, const string& s2 ){
	//if(s1.len !=s2.len) return false;
	for(size_t i=0;i!=s1.len || i!=s2.len;++i){
               if(s1[i]!=s2[i]) return false;
	}
	return true;
}
bool operator < ( const string& s1, const string& s2 ){
	for(size_t k = 0 ; k!=s1.len || k!=s2.len; ++k){
		if(s1[k]>s2[k]) {return false;}
		if(s1[k]<s2[k]){return true;}
	}
	return s1.len < s2.len;
}

std::ostream& operator << ( std::ostream& out, const string& s )
{  if (s.len ==0) out<< " empty string";
   for( char c:s )
	out<<c;
   return out;   // Always return the stream!
}
