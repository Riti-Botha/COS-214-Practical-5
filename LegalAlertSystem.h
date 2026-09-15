#ifndef LEGALALERTSYSTEM_H
#define LEGALALERTSYSTEM_H
//This is the adaptee
class LegalAlertSystem{
    public:
       static const int LEGACY_OK = 0;
       static const int LEGACY_BAD_ZONE  = 7;
       static const int LEGACY_OFFLINE   = 9;

       LegalAlertSystem();
       ~LegalAlertSystem();
        int broadcastToZone(int zoneCode, int severityLevel, const char* payload);
        int zoneCount() const;

    private:
        bool online;
};

#endif
