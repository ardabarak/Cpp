// Arda Barak
// 300129340
// Exercise 2

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <stdexcept>

enum class LogLevel {Info,Warning,Error};

std::string toString(LogLevel level) {
    switch (level) {
    case LogLevel::Info:
        return "INFO";
    case LogLevel::Warning:
        return "WARNING";
    case LogLevel::Error:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}

class Logger {
private:
    std::ofstream logFile;

    std::string currentTime() const {//current time
        std::time_t now = std::time(nullptr);
        char buffer[80];
        std::tm* localtm = std::localtime(&now);
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtm);
        return std::string(buffer);
    }

public:
    void openLogFile(const std::string& filename) {//open
        logFile.open(filename, std::ios_base::app);
        if (!logFile.is_open()) {throw std::runtime_error("Cannot open file.");}
    }

    void closeLogFile() {if (logFile.is_open()) //close
        {logFile.close();}}

    Logger& operator<<(const std::string& message) { //<< operator
        if (logFile.is_open()) {logFile << currentTime() << " " << message << std::endl;}
        return *this;
    }
    //logging message withspecific log level
    void logWithLevel(const std::string& message, LogLevel level) {*this << "[" + toString(level) + "] " + message;}
};

int main() {
    Logger logger;
    try {
        logger.openLogFile("log.txt");
        logger << "[INFO] Application started.  ";
        logger << "[WARNING] Warning message.   ";
        logger << "[ERROR] Error message.       ";
        logger.logWithLevel("System message.    ", LogLevel::Info);
        logger.logWithLevel("Memory message.    ", LogLevel::Warning);
        logger.logWithLevel("Program message.   ", LogLevel::Error);
        logger.closeLogFile();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
// copy of the output of the log.txt
/* 2024-11-09 19:01:38 [INFO] Application started.  
2024-11-09 19:01:38 [WARNING] Warning message.   
2024-11-09 19:01:38 [ERROR] Error message.       
2024-11-09 19:01:38 [INFO] System message.    
2024-11-09 19:01:38 [WARNING] Memory message.    
2024-11-09 19:01:38 [ERROR] Program message.   
 */
