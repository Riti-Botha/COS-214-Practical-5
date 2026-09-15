#ifndef FACTORY_H
#define FACTORY_H


#include <string>

// product INTERFACE
class ResponseUnit {
public:
    virtual ~ResponseUnit() = default; 
    virtual void respond() = 0;
    virtual std::string getType() const = 0;
};

// concrete products
class CampusSecurity : public ResponseUnit {
public:
    void respond() override;
    std::string getType() const override;
};

class MedicalResponder : public ResponseUnit {
public:
    void respond() override;
    std::string getType() const override;
};

class FacilitiesStaff : public ResponseUnit {
public:
    void respond() override;
    std::string getType() const override;
};

// creator INTERFACE
class ResponseUnitFactory {
public:
    virtual ~ResponseUnitFactory() = default; 
    virtual ResponseUnit* createUnit() = 0; 
};

// concrete creators
class SecurityFactory : public ResponseUnitFactory {
public:
    ResponseUnit* createUnit() override; 
};

class MedicalFactory : public ResponseUnitFactory {
public:
    ResponseUnit* createUnit() override;
};

class FacilitiesFactory : public ResponseUnitFactory {
public:
    ResponseUnit* createUnit() override;
};

#endif