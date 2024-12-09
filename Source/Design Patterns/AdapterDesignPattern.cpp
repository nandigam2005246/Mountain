#include <iostream>
#include <vector>
#include <memory>
#include <string_view>

enum class LogLevel
{
    Error,
    Info,
    Debug
};
class Logger
{
    
    public:
    
    void logMessage(LogLevel level, std::string message)
    {
        std::cout << getLogLevelString(level).data() << ": " << message << std::endl;
    }
    
    private:
    std::string_view getLogLevelString(LogLevel level)
    {
        switch (level) {
            case LogLevel::Error:
            return "ERROR";
            case LogLevel::Info:
            return "INFO";
            case LogLevel::Debug:
            return "DEBUG";
        }
        throw std::runtime_error("Invalid log level.");
    }
};

class INewLoggerAdapter
{
    public:
    virtual void logMessage(std::string_view message) = 0;
};

class NewLoggerAdapter: public INewLoggerAdapter
{
  public:
  NewLoggerAdapter()
  {
      std::cout<< "ctor" <<std::endl;
  }
  void logMessage(std::string_view message)
  {
      m_logger.logMessage(LogLevel::Info, message.data());
  }
  
  private:
  Logger m_logger;
};


int main()
{
    Logger logMessage;
    NewLoggerAdapter newLoggerAdapter;
    newLoggerAdapter.logMessage("Testing the logger");
    
    return 0;
}
