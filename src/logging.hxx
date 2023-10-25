#ifndef WEATHERMAP2FG_LOGGING_HXX
#define WEATHERMAP2FG_LOGGING_HXX

#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "singleton.hxx"
#include "utils.hxx"

class Logger: public Singleton<Logger> {
	public:
		enum class LogLevel: short {
			UNKNOWN,
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			FATAL,
		};
		
		Logger() {};
		
		template<typename T>
		void log(LogLevel level, const T& msg) {
			if (level >= _level) {
				if (level >= LogLevel::WARNING) {
					std::cerr << std::left << std::setw(11) << (std::stringstream() << "[" << level << "]").str() << strftime(std::time(nullptr), "%T") << "  " << msg << std::endl;
				} else {
					std::cout << std::left << std::setw(11) << (std::stringstream() << "[" << level << "]").str() << strftime(std::time(nullptr), "%T") << "  " << msg << std::endl;
				}
			}
		}
		friend std::ostream& operator<<(std::ostream&, Logger::LogLevel);
		
		static const LogLevel get_loglevel_for_string(std::string levelName);
		static const LogLevel get_loglevel_for_string(char* levelName);
		
		LogLevel loglevel() {
			return _level;
		}
		void set_loglevel(LogLevel level) {
			_level = level;
		}
		void set_loglevel(std::string level_name) {
			_level = get_loglevel_for_string(level_name);
		}
		void set_loglevel(char* levelName) {
			_level = get_loglevel_for_string({levelName});
		}
	
	private:
		LogLevel _level {LogLevel::WARNING};
};

std::ostream& operator<<(std::ostream& s, const Logger::LogLevel level);

std::string to_string(Logger::LogLevel level);

#define LOG(level, expr) \
	{ \
		std::stringstream ss; \
		ss << expr; \
		Logger::instance()->log(Logger::LogLevel::level, ss.str()); \
	}

#endif

