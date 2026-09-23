#ifndef LEGACYALERTADAPTER_H
#define LEGACYALERTADAPTER_H
#include "AlertService.h"
#include <string>

class LegalAlertSystem;
class LegacyAlertAdapter : public AlertService {
    private:
        LegalAlertSystem* legacy;                       // owned

        int zoneFor(const std::string& location) const;
        int severityFor(const std::string& message) const;

    public:
        LegacyAlertAdapter(LegalAlertSystem* legacySystem);
        virtual ~LegacyAlertAdapter();

        virtual bool sendAlert(const std::string& location, const std::string& message);
};

#endif