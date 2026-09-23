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
#include "MedicalTeam.h"
#include "OperatorConsole.h"
#include "SecureAreaCommand.h"
#include "DispatchUnitCommand.h"
#include "CancelCommand.h"
#include "OperatorCommand.h"

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
    MedicalTeam* medical = new MedicalTeam("Medic Team Bravo", campusMediator);
    
    // here we register the teams with the mediator so they can communicate
    campusMediator->registerComponent(security);
    campusMediator->registerComponent(facilities);
    campusMediator->registerComponent(medical);
    campusMediator->setSecurityTeam(security);
    campusMediator->setFacilitiesTeam(facilities);
    campusMediator->setMedicalTeam(medical);

    LegacyAlertSystem* oldAlarm = new LegacyAlertSystem();
    AlertService* campusAlarm = new LegacyAlertAdapter(oldAlarm);

    // COMMAND + MEDIATOR "Zone secured ripple"
    // security is sent to secure the Chemistry Wing. The operator wraps
    // this in a SecureAreaCommand and issues it through the console (Invoker).
    // Console.execute() -> Command -> Security.secureArea(area) -> the team
    // notifies the mediator, which ripples the event out to Facilities
    // (lockArea) and Medical (dispatch) -- Security never talks to either
    // of them directly.
    OperatorConsole* console = new OperatorConsole();
    OperatorCommand* secureZone = new SecureAreaCommand(security, "Chemistry Wing");
    console->issueCommand(secureZone);
    std::cout << "\n";

    // command
    // Story: The operator needs to lock down the Science Lab to prevent students from entering.
    // They wrap this request into a LockdownCommand object. This decouples the operator 
    // from the Facilities Team, allowing the command to be passed around or delayed if needed.
    OperatorCommand* lockLab = new LockDownCommand(facilities, "Science Lab");

    // FACADE
    // In a massive emergency, the operator doesn't have time to manually ring the alarm, 
    // call security, and execute the lockdown command one by one. 
    // The Facade takes all these complex subsystems and triggers them in one automated sequence.
    EmergencyProtocolFacade* emergencySystem = new EmergencyProtocolFacade(
        security, nullptr, medicalDepot, campusAlarm
    );
    
    emergencySystem->activateEmergencyProtocol("Science Lab", lockLab);
    std::cout << "\n";

    // COMMAND: undo via a Command whose receiver is another Command.
    // The Science Lab is confirmed safe, so the operator lifts the
    // lockdown by issuing a CancelCommand wrapped around the original
    // lockLab command. CancelCommand::execute() calls lockLab->undo(),
    // which calls facilities->unlockArea("Science Lab").
    OperatorCommand* cancelLockLab = new CancelCommand(lockLab);
    console->issueCommand(cancelLockLab);
    std::cout << "\n";

    std::cout << "[OperatorConsole] " << console->historySize() << " commands issued; last was: " << console->getLastCommand()->getDescription() << "\n\n";

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
<<<<<<< HEAD
=======
    delete oldAlarm;
    delete console;
>>>>>>> b818670abfb21636e2312800349fd8de58e8a64f
    delete facilities;
    delete security;
    delete medical;
    delete campusMediator;

    // DON'T DELETE - STORY 2 (Command + Mediator)
    // Fire alarm in the Engineering building. An operator dispatches
    // security through the console (Command/Invoker). Security secures
    // the zone, which ripples through the mediator to auto-lock
    // facilities and dispatch medical without security knowing about
    // either of them directly. An explicit lockdown and a cancel close
    // out the story.

    IncidentCoordinator* engMediator = new IncidentCoordinator();
    SecurityTeam* engSecurity = new SecurityTeam("Security Charlie", engMediator);
    MedicalTeam* engMedical = new MedicalTeam("Medic Team Delta", engMediator);
    FacilitiesTeam* engFacilities = new FacilitiesTeam("Maintenance Echo", engMediator);

    // wire the colleagues into the mediator so notify() can reach them
    engMediator->registerComponent(engSecurity);
    engMediator->registerComponent(engMedical);
    engMediator->registerComponent(engFacilities);
    engMediator->setSecurityTeam(engSecurity);
    engMediator->setMedicalTeam(engMedical);
    engMediator->setFacilitiesTeam(engFacilities);

    OperatorConsole* engconsole = new OperatorConsole();

    // 1) operator dispatches security to the building
    OperatorCommand* dispatchSecurity = new DispatchUnitCommand(engSecurity, "Engineering Building");
    engconsole->issueCommand(dispatchSecurity);
    std::cout << "\n";

    // 2) security secures the zone -> notifyMediator("ZoneSecured", event, loc)
    //    IncidentCoordinator::notify() ripples to facilities (lockArea) and medical (dispatch)
    OperatorCommand* secureZone = new SecureAreaCommand(engSecurity, "Engineering Building");
    engconsole->issueCommand(secureZone);
    std::cout << "\n";

    // 3) explicit lockdown of a specific room via Facilities directly
    OperatorCommand* lockServerRoom = new LockDownCommand(engFacilities, "Engineering Server Room");
    engconsole->issueCommand(lockServerRoom);
    std::cout << "\n";

    // 4) cancel the server room lockdown (Command whose receiver is another Command)
    OperatorCommand* cancelLockdown = new CancelCommand(lockServerRoom);
    engconsole->issueCommand(cancelLockdown);
    std::cout << "\n";

    std::cout << "[OperatorConsole] " << engconsole->historySize() << " commands issued; last was: " << engconsole->getLastCommand()->getDescription() << "\n\n";

    // console owns every command it was issued and deletes them on destruction
    delete engconsole;
    delete engFacilities;
    delete engMedical;
    delete engSecurity;
    delete engMediator;

    return 0;
}
