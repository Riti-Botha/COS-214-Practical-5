#ifndef RESPONSECOMPONENT_H
#define RESPONSECOMPONENT_H
#include<string>

class IncidentMediator;

class ResponseComponent{
    protected:
        void notifyMediator(const std::string& event, const std::string& location);
        std::string name;
        bool available;
        IncidentMediator* mediator;
        
    public:
        ResponseComponent(const std::string& name, IncidentMediator* mediator);
        virtual ~ResponseComponent();
        virtual void dispatch(const std::string& location);
        virtual void recall();
        virtual std::string getType() const = 0;
        std::string getName() const;
        bool isAvailable() const;

};

#endif