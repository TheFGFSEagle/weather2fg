#include "logging.hxx"

std::string string(FGaugeLogger::LogLevel level) {
	switch (level) {
		case FGaugeLogger::LogLevel::DEBUG:
			return {"DEBUG"};
		case FGaugeLogger::LogLevel::INFO:
			return {"INFO"};
		case FGaugeLogger::LogLevel::WARNING:
			return {"WARNING"};
		case FGaugeLogger::LogLevel::ERROR:
			return {"ERROR"};
		case FGaugeLogger::LogLevel::FATAL:
			return {"FATAL"};
		default:
			return {"UNKNOWN"};
	}
}

std::ostream& operator<<(std::ostream& s, FGaugeLogger::LogLevel level) {
	s << string(level);
	return s;
}

const FGaugeLogger::LogLevel FGaugeLogger::getLogLevelForString(std::string levelName) {
	std::string upper = toUpper(levelName);
	if (upper == "DEBUG") {
		return FGaugeLogger::LogLevel::DEBUG;
	} else if (upper == "INFO") {
		return FGaugeLogger::LogLevel::INFO;
	} else if (upper == "WARNING") {
		return FGaugeLogger::LogLevel::WARNING;
	} else if (upper == "ERROR") {
		return FGaugeLogger::LogLevel::ERROR;
	} else if (upper == "FATAL") {
		return FGaugeLogger::LogLevel::FATAL;
	} else {
		return FGaugeLogger::LogLevel::UNKNOWN;
	}
}

const FGaugeLogger::LogLevel FGaugeLogger::getLogLevelForString(char* levelName) {
	std::string s(levelName);
	return getLogLevelForString(s);
}

