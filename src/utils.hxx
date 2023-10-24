#ifndef WEATHERMAP2FG_UTILS_HXX
#define WEATHERMAP2FG_UTILS_HXX

#include <ctime>
#include <string>

std::string strftime(std::time_t time, const std::string& format);
std::string strftime(std::time_t time, const char* format);

template<typename T>
std::string& to_string(T& string);

std::string to_lower(std::string& s);
std::string to_upper(std::string& s);

#endif

