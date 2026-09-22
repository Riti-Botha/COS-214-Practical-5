#ifndef EMERGENCYPROTOCOLFACADE_H
#define EMERGENCYPROTOCOLFACADE_H

class ResponseComponent;
class ResponseUnitFactory;
class AlertService;
class OperatorCommand;
#include <string>

class EmergencyProtocolFacade {
    private:
        ResponseComponent* security;
        ResponseComponent* medical;
        ResponseUnitFactory* unitFactory;
        AlertService* alertService;

    public:
        EmergencyProtocolFacade(ResponseComponent* security, ResponseComponent* medical, ResponseUnitFactory* unitFactory, AlertService* alertService);
        ~EmergencyProtocolFacade();
        bool activateEmergencyProtocol(const std::string& location, OperatorCommand* lockdownCommand);
        bool evacuate(const std::string& location);
};

#endif