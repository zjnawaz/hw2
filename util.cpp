#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
	set<string> my_words;
	stringstream word(rawWords);
	stringstream ss;
	string my_input;
	string split;
	bool broken;
	broken = false;
  while(word >> my_input){
		broken = false;
		for(int i = 0; i < my_input.length(); i++){
			ss << my_input[i];
			if(ispunct(my_input[i])){
				getline(ss, split, my_input[i]);
				if(split.length()>1){
					my_words.insert(split);
					broken = true;
				}
				ss.clear();
			}
		}
		if(!broken){
			if(my_input.length()>1){
				my_words.insert(my_input);
			}
		}
	}
	return my_words;

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}


