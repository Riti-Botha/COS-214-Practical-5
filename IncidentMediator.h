#ifndef INCIDENTMEDIATOR_H
#define INCIDENTMEDIATOR_H
#include<string>

class ResponseComponent;

class IncidentMediator{
    public:
        virtual ~IncidentMediator();
        virtual void registerComponent(ResponseComponent* component) = 0;
        virtual void notify(ResponseComponent* sender, const std::string& event, const std::string& location) = 0;

};

#endif