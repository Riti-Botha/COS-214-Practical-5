#include "Factory.h"
#include <iostream>


// concrete products
void CampusSecurity::respond() {
    std::cout << getType() << " -> securing the perimeter and patrolling.\n";
}

std::string CampusSecurity::getType() const { return "Campus Security"; }

void MedicalResponder::respond() {
    std::cout << getType() << " -> establishing triage and providing medical assistance.\n";
}

std::string MedicalResponder::getType() const { return "Medical Responder"; }

void FacilitiesStaff::respond() {
    std::cout << getType() << "-> shutting off utilities and securing physical access.\n";
}

std::string FacilitiesStaff::getType() const { return "Facilities Staff"; }

// concrete creators
ResponseUnit* SecurityFactory::createUnit() {
    return new CampusSecurity();
}

ResponseUnit* MedicalFactory::createUnit() {
    return new MedicalResponder();
}

ResponseUnit* FacilitiesFactory::createUnit() {
    return new FacilitiesStaff();
}