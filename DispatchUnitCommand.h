#ifndef DISPATCHUNITCOMMAND_H
#define DISPATCHUNITCOMMAND_H
#include<string>
#include"OperatorCommand.h"

class ResponseComponent;

class DispatchUnitCommand : public OperatorCommand{
    private:
        ResponseComponent* receiver;
        std::string location;
        bool dispatched;

    public:
        DispatchUnitCommand(ResponseComponent* receiver, const std::string& location);
        ~DispatchUnitCommand() override;
        void execute() override;
        void undo() override;
        std::string getDescription() const override;

};

#endif 