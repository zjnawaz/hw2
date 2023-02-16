#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
	while(s1.begin()!=s1.end() && s2.begin()!=s2.end()){
		set<T> result;
		typename s1<T>::iterator first;
		typename s2<T>::iterator second;
		typename result<T>::iterator end;
		if(first < second){
			first++;
		}
		else if(second < first){
			second++;
		}
		else{
			end = first;
			end++;
			first++;
			second++;
		}
	}
	return result;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
	set<T> result;
	while(true){
		if(s1.begin()==s1.end()){
			result = s2;
			return result;
		}
		if(s2.begin() == s2.end()){
			result = s1;
			return result;
		}
		typename s1<T>::iterator first;
		typename s2<T>::iterator second;
		typename result<T>::iterator end;
		if(first < second){
			end = first;
			first++;
		}
		else if(second < first){
			end = second;
			second++;
		}
		else{
			end = first;
			first++;
			second++;
		}
		end++;
	}

}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
