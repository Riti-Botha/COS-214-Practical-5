#include "EmergencyProtocolFacade.h"
#include "ResponseComponent.h"
#include "Factory.h"
#include "AlertService.h"
#include "OperatorCommand.h"
#include <iostream>

EmergencyProtocolFacade::EmergencyProtocolFacade(ResponseComponent* security, ResponseComponent* medical, ResponseUnitFactory* unitFactory, AlertService* alertService) : security(security), medical(medical), unitFactory(unitFactory), alertService(alertService) {}

EmergencyProtocolFacade::~EmergencyProtocolFacade(){}

bool EmergencyProtocolFacade::activateEmergencyProtocol((const std::string& location, OperatorCommand* lockdownCommand){
    std::cout << "\n=== EMERGENCY PROTOCOL: " << location << " ===" << std::endl;
    if(!security->isAvailable()){
        std::cout << "[Facade] " << security->getName() << " unavailable - protocol aborted." << std::endl;
        return false;
    }

    ResponseUnit* unit = unitFactory->createUnit();
    unit->respond();

    security->dispatch(location);

    lockdownCommand->execute();

    bool alerted = alertService->sendAlert(location, "LOCKDOWN in effect at " + location);
    delete unit;

    std::cout << "=== PROTOCOL " << (alerted ? "COMPLETE" : "COMPLETED WITH WARNINGS")   << " ===" << std::endl;
    return alerted;
}

bool EmergencyProtocolFacade::evacuate(const std::string& location){
    if(security->isAvailable()) security->dispatch(location);
    if(medical->isAvailable()) medical->dispatch(location);
    return alertService->sendAlert(location, "Evacuate " + location + "immediately");
}