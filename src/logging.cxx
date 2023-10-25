#include "logging.hxx"

std::string to_string(Logger::LogLevel level) {
	switch (level) {
		case Logger::LogLevel::DEBUG:
			return {"DEBUG"};
		case Logger::LogLevel::INFO:
			return {"INFO"};
		case Logger::LogLevel::WARNING:
			return {"WARNING"};
		case Logger::LogLevel::ERROR:
			return {"ERROR"};
		case Logger::LogLevel::FATAL:
			return {"FATAL"};
		default:
			return {"UNKNOWN"};
	}
}

std::ostream& operator<<(std::ostream& s, Logger::LogLevel level) {
	s << to_string(level);
	return s;
}

const Logger::LogLevel Logger::get_loglevel_for_string(std::string levelName) {
	std::string upper = to_upper(levelName);
	if (upper == "DEBUG") {
		return Logger::LogLevel::DEBUG;
	} else if (upper == "INFO") {
		return Logger::LogLevel::INFO;
	} else if (upper == "WARNING") {
		return Logger::LogLevel::WARNING;
	} else if (upper == "ERROR") {
		return Logger::LogLevel::ERROR;
	} else if (upper == "FATAL") {
		return Logger::LogLevel::FATAL;
	} else {
		LOG(WARNING, "Unknown log level: " << levelName);
		return Logger::LogLevel::UNKNOWN;
	}
}

const Logger::LogLevel Logger::get_loglevel_for_string(char* levelName) {
	std::string s(levelName);
	return get_loglevel_for_string(s);
}

