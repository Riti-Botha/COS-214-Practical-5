#ifndef STATE_H
#define STATE_H

class Incident;

// state INTERFACE
class IncidentState {
public:
    virtual ~IncidentState() = default; 
    virtual void dispatch(Incident* context) = 0;
    virtual void resolve(Incident* context) = 0;
    virtual void printStatus() const = 0;
};

// context
class Incident {
private:
    IncidentState* state; 
public:
    Incident(IncidentState* initialState);
    ~Incident(); 
    void setState(IncidentState* newState);
    void dispatch();
    void resolve();
    void printStatus() const;
};

// concrete states
class ReportedState : public IncidentState {
public:
    void dispatch(Incident* context) override;
    void resolve(Incident* context) override; 
    void printStatus() const override;
};

class DispatchedState : public IncidentState {
public:
    void dispatch(Incident* context) override; 
    void resolve(Incident* context) override;
    void printStatus() const override;
};

class ResolvedState : public IncidentState {
public:
    void dispatch(Incident* context) override; 
    void resolve(Incident* context) override; 
    void printStatus() const override;
};

#endif
