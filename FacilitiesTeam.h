#ifndef FACILITIESTEAM_H
#define FACILITIESTEAM_H
#include<string>
#include"ResponseComponent.h"

class FacilitiesTeam : public ResponseComponent{
    private:
        std::string lockedArea; 

    public:
        FacilitiesTeam(const std::string& name, IncidentMediator* mediator);
        ~FacilitiesTeam() override;
        void dispatch(const std::string& location) override;
        void lockArea(const std::string& area);
        void unlockArea(const std::string& area);
        bool isAreaLocked(const std::string& area) const;
        std::string getType() const override;

};

#endif