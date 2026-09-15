#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H
#include<string>
#include"ResponseComponent.h"

class SecurityTeam : public ResponseComponent{
    private:
        std::string securedArea;

    public:
        SecurityTeam(const std::string& name, IncidentMediator* mediator);
        ~SecurityTeam() override;
        void dispatch(const std::string& location) override;
        void secureArea(const std::string& area);
        void reopenArea(const std::string& area);
        std::string getType() const override;

};

#endif 