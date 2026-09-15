#include "State.h"
#include "Factory.h"

#include <iostream>

int main() {

    ResponseUnitFactory* securityFactory = new SecurityFactory();
    ResponseUnitFactory* medicalFactory = new MedicalFactory();

    ResponseUnit* securityUnit = securityFactory->createUnit();
    ResponseUnit* medicalUnit = medicalFactory->createUnit();

    securityUnit->respond();
    medicalUnit->respond();

    // destruction policy: caller deletes products and factories
    delete securityUnit;
    delete medicalUnit;
    delete securityFactory;
    delete medicalFactory;
    
    std::cout << "Test state \n";
    Incident* incident = new Incident(new ReportedState());

    // invalid operation
    incident->resolve(); 

    // valid state transition
    incident->dispatch();

    // another invalid operation
    incident->dispatch(); 

    // valid transition
    incident->resolve();

    // deleting the incident automatically deletes its state
    delete incident;

    return 0;
}