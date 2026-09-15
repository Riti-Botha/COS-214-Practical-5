#ifndef OPERATORCOMMAND_H
#define OPERATORCOMMAND_H
#include<string>

class OperatorCommand{
    public:
        virtual ~OperatorCommand();
        virtual void execute() = 0;
        virtual void undo();
        virtual std::string getDescription() const = 0;
};

#endif