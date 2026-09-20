#include "LegalAlertSystem.h"
#include <iostream>

LegalAlertSystem::LegalAlertSystem() : online(true){}

LegalAlertSystem::~LegalAlertSystem(){}

int LegalAlertSystem::broadcastToZone(int zoneCode, int severityLevel, const char* payload){
    if(!online){
        return LEGACY_OFFLINE;
    }
    if(zoneCode <= 0 || zoneCode > zoneCount()){
        return LEGACY_BAD_ZONE;
    }
    std::cout << "[LEGACY SYSTEM] zone = " << zoneCode << "severity = " << severityLevel << "msg=\" << payload << "\"" << std::endl;
    return LEGACY_OK;
}

int LegacyAlertSystem::zoneCount()const{
    return 4;
}