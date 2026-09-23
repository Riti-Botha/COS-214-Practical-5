// DON'T DELETE - STORY 1!!!!

#include <iostream>
#include "ResponseComponent.h"

#include "State.h"
#include "Factory.h"
#include "EmergencyProtocolFacade.h"
#include "LegacyAlertAdapter.h"
#include "IncidentCoordinator.h"
#include "FacilitiesTeam.h"
#include "SecurityTeam.h"
#include "LockDownCommand.h"
#include "LegalAlertSystem.h"

int main() {

    // STATE
    // A student reports a chemical spill. The system logs the new incident.
    // By starting in the 'Reported' state, the system naturally prevents the operator 
    // from accidentally marking it 'Resolved' before help is actually sent.
    Incident* chemicalSpill = new Incident(new ReportedState());
    chemicalSpill->printStatus();
    std::cout << "\n";

    // FACTORY
    // The dispatcher realises they need extra, specialized medical units on standby.
    // Instead of hardcoding concrete classes, the dispatcher uses the Medical Depot (Factory) 
    // to dynamically spawn the correct response unit for the job.
    ResponseUnitFactory* medicalDepot = new MedicalFactory();
    ResponseUnit* extraMedic = medicalDepot->createUnit();
    extraMedic->respond(); 
    std::cout << "\n";

    IncidentCoordinator* campusMediator = new IncidentCoordinator();
    FacilitiesTeam* facilities = new FacilitiesTeam("Maintenance Alpha", campusMediator);
    SecurityTeam* security = new SecurityTeam("Security Bravo", campusMediator);
    
    // here we register the teams with the mediator so they can communicate
    LegacyAlertSystem* oldAlarm = new LegacyAlertSystem();
    AlertService* campusAlarm = new LegacyAlertAdapter(oldAlarm);

    // command
    // Story: The operator needs to lock down the Science Lab to prevent students from entering.
    // They wrap this request into a LockdownCommand object. This decouples the operator 
    // from the Facilities Team, allowing the command to be passed around or delayed if needed.
    OperatorCommand* lockLab = new LockdownCommand(facilities, "Science Lab");

    // FACADE
    // In a massive emergency, the operator doesn't have time to manually ring the alarm, 
    // call security, and execute the lockdown command one by one. 
    // The Facade takes all these complex subsystems and triggers them in one automated sequence.
    EmergencyProtocolFacade* emergencySystem = new EmergencyProtocolFacade(
        security, nullptr, medicalDepot, campusAlarm
    );
    
    emergencySystem->activateEmergencyProtocol("Science Lab", lockLab);
    std::cout << "\n";

    // STATE UPDATE
    // Now that the Facade has successfully deployed the teams and locked the doors,
    // the system safely updates the incident's lifecycle status.
    chemicalSpill->dispatch();
    chemicalSpill->printStatus();
    std::cout << "\n";

    // After a few hours, the hazardous materials team cleans the spill.
    // The operator safely closes the ticket.
    chemicalSpill->resolve();
    chemicalSpill->printStatus();
    std::cout << "\n";

     // ADAPTER 
    std::cout << "\n########## ADAPTER TEST: Direct sendAlert calls ##########\n" << std::endl;

    // Branch 1: zone mapped -> reaches LegacyAlertSystem, returns true
    bool goodAlert = campusAlarm->sendAlert("Library Quad", "LOCKDOWN in effect");
    std::cout << "Mapped zone result: " << (goodAlert ? "sent" : "unexpectedly rejected") << "\n" << std::endl;

    // Branch 2: zone unmapped -> never reaches LegacyAlertSystem, returns false
    bool badAlert = campusAlarm->sendAlert("Parking Lot Z", "TEST ALERT");
    std::cout << "Unmapped zone result: " << (badAlert ? "unexpectedly sent" : "rejected as expected") << "\n" << std::endl;

    //  FACADE TEST: unavailable component
    // Simulates a security team already dispatched elsewhere, to show
    // the facade aborts the whole protocol rather than partially running it.
    std::cout << "\n########## FACADE TEST: Unavailable Team ##########\n" << std::endl;
    security->dispatch("Other Incident");   // marks it unavailable, if your dispatch() does that
    OperatorCommand* secondLock = new LockdownCommand(facilities, "Library Quad");
    bool protocolResult = emergencySystem->activateEmergencyProtocol("Library Quad", secondLock);
    std::cout << "Protocol result: " << (protocolResult ? "succeeded" : "aborted as expected") << "\n" << std::endl;

    delete secondLock;
    delete chemicalSpill;
    delete extraMedic;
    delete medicalDepot;        
    delete lockLab;
    delete emergencySystem;
    delete campusAlarm;
    delete facilities;
    delete security;
    delete campusMediator;
    

    return 0;
}
