#include "LegacyAlertAdapter.h"
#include "LegalAlertSystem.h"
#include <iostream>

namespace{
    truct ZoneEntry { const char* name; int code; };
    const ZoneEntry ZONES[] = {
        {"Library Quad", 1},
        {"Engineering Block", 2},
        {"Residence A", 3},
        {"Sports Grounds", 4}
    };
    const int ZONE_COUNT = 4;
}

LegacyAlertAdapter::LegacyAlertAdapter(LegacyAlertSystem* legacySystem) : legacy(legacySystem){}

LegacyAlertAdapter::~LegacyAlertAdapter(){
    if(legacy != nullptr){
        delete legacy;
    }
}

int LegacyAlertAdapter::zoneFor(const std::string& location)const{
    for(int i = 0; i < ZONE_COUNT; ++i){
        if(location == ZONES[i].name){
            return ZONES[i].code;
        }
    }
    return -1;
}

int LegacyAlertAdapter::severityFor(const std::string& message) const {
    if (message.find("EVACUATE") != std::string::npos) return 3;
    if (message.find("LOCKDOWN") != std::string::npos) return 2;
    return 1;
}

bool LegacyAlertAdapter::sendAlert(const std::string& location, const std::string& message){
    int zone = zoneFor(location);
    if(zone == -1){
        std::cout << "[Adpater] No legacy zone mapped for \"" << location << "\" -alert not broadcast. " <<std::endl;
        return false;
    }
    int status = legacy->broadcastToZone(zone, severityFor(message), message.c_str());

    if (status != LegacyAlertSystem::LEGACY_OK) {
        std::cout << "[Adapter] Legacy system rejected broadcast (code " << status << ")." << std::endl;
        return false;
    }

    std::cout << "[Adapter] Alert delivered to zone " << zone << " (" << location << ")" << std::endl;
    return true;
}