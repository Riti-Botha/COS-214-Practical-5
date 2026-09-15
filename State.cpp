#include "State.h"
#include <iostream>
#include <string>

void Incident::printStatus() const {
    if (state) {
        state->printStatus();
    }
}

// context
Incident::Incident(IncidentState* initialState) : state(initialState) {}

Incident::~Incident() {
    delete state;
}

void Incident::setState(IncidentState* newState) {
    delete state;
    state = newState;
}

void Incident::dispatch() {
    if (state) state->dispatch(this);
}

void Incident::resolve() {
    if (state) state->resolve(this);
}

// concrete state 1
void ReportedState::dispatch(Incident* context) {
    std::cout << "Dispatching responders to the incident.\n";
    context->setState(new DispatchedState());
}

void ReportedState::resolve(Incident* context) {
    std::cout << "Invalid operation! Cannot resolve an incident before dispatching responders.\n";
}

void ReportedState::printStatus() const {
    std::cout << "Status: Reported\n";
}

// concrete state 2
void DispatchedState::dispatch(Incident* context) {
    std::cout << "Invalid operation! Responders are already dispatched.\n";
}

void DispatchedState::resolve(Incident* context) {
    std::cout << "Responders have secured the situation.\n";
    context->setState(new ResolvedState());
}

void DispatchedState::printStatus() const {
    std::cout << "Status: Dispatched\n";
}

// concrete state 3
void ResolvedState::dispatch(Incident* context) {
    std::cout << "Invalid operation! Incident is already resolved.\n";
}

void ResolvedState::resolve(Incident* context) {
    std::cout << "Invalid operation! Incident is already resolved.\n";
}

void ResolvedState::printStatus() const {
    std::cout << "Status: Resolved\n";
}
