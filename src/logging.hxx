#ifndef WEATHERMAP2FG_LOGGING_HXX
#define WEATHERMAP2FG_LOGGING_HXX

#include <ctime>
#include <iostream>
#include <string>
#include <sstream>

#include "singleton.hxx"
#include "utils.hxx"

class Logger: public Singleton<Logger> {
	public:
		enum class LogLevel: short {
			DEBUG = 0,
			INFO = 1,
			WARNING = 2,
			ERROR = 3,
			FATAL = 4,
			UNKNOWN = 5,
		};
		
		Logger() {};
		
		template<typename T>
		void log(LogLevel level, const T& msg) {
			if (level >= _level) {
				if (level >= LogLevel::WARNING) {
					std::cerr << "[" << level << "] " << strftime(std::time(nullptr), "%T") << " " << msg << std::endl;
				} else {
					std::cout << "[" << level << "] " << strftime(std::time(nullptr), "%T") << " " << msg << std::endl;
				}
			}
		}
		friend std::ostream& operator<<(std::ostream&, Logger::LogLevel);
		
		static const LogLevel getLogLevelForString(std::string levelName);
		static const LogLevel getLogLevelForString(char* levelName);
		
		LogLevel logLevel() {
			return _level;
		}
		void setLogLevel(LogLevel level) {
			_level = level;
		}
		void setLogLevel(std::string levelName) {
			_level = getLogLevelForString(levelName);
		}
		void setLogLevel(char* levelName) {
			_level = getLogLevelForString({levelName});
		}
	
	private:
		LogLevel _level {LogLevel::WARNING};
};

std::ostream& operator<<(std::ostream& s, const Logger::LogLevel level);

std::string string(Logger::LogLevel level);

#define LOG(level, expr) \
	{ \
		std::stringstream ss; \
		ss << expr; \
		std::string str = ss.str(); \
		Logger::instance()->log(Logger::LogLevel::level, ss.str()); \
	}

#endif

