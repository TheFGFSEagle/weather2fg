#include "utils.hxx"

std::string strftime(std::time_t time, const std::string& format) {
	std::tm* local_time = std::localtime(&time);
	char output[256];
	std::strftime(output, sizeof(output), format.c_str(), local_time);
	return output;
}
std::string strftime(std::time_t time, const char* format) {
	std::tm* local_time = std::localtime(&time);
	char output[256];
	std::strftime(output, sizeof(output), format, local_time);
	return output;
}

template<typename T>
std::string to_string(T& other) {
	return {other};
}

std::string to_lower(std::string& s) {
	for(char& c : s) {
		c = std::tolower(c);
	}
	return s;
}
std::string to_upper(std::string& s) {
	for(char& c : s) {
		c = std::toupper(c);
	}
	return s;
}

