#ifndef ALERTSERVICE_H
#define ALERTSERVICE_H
//Target interface
#include <string>
class AlertService{
    public:
      virtual ~AlertService();
      virtual bool sendAlert(const std::string& location, const std::string& message) = 0;
};

#endif
