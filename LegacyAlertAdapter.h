#ifndef LEGACYALERTADAPTER_H
#define LEGACYALERTADAPTER_H
#include "AlertService.h"
#include <string>

class LegalAlertSystem;
class LegacyAlertAdapter : public AlertService {
    private:
        LegacyAlertSystem* legacy;                       // owned

        int zoneFor(const std::string& location) const;
        int severityFor(const std::string& message) const;

    public:
        LegacyAlertAdapter(LegacyAlertSystem* legacySystem);
        virtual ~LegacyAlertAdapter();

        virtual bool sendAlert(const std::string& location, const std::string& message);
};

#endif