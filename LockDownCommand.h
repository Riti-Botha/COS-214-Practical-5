#ifndef LOCKDOWNCOMMAND_H
#define LOCKDOWNCOMMAND_H
#include<string>
#include"OperatorCommand.h"

class FacilitiesTeam;

class LockdownCommand : public OperatorCommand{
    private:
        FacilitiesTeam* receiver; 
        std::string area;
        bool locked;

    public:
        LockdownCommand(FacilitiesTeam* receiver, const std::string& area);
        ~LockdownCommand() override;
        void execute() override;
        void undo() override;
        std::string getDescription() const override;

};

#endif 