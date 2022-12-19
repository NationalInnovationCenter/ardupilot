#include "AP_SimpleOutput.h"

#if HAL_PARACHUTE_ENABLED

#include <AP_Relay/AP_Relay.h>
#include <GCS_MAVLink/GCS.h>

extern const AP_HAL::HAL& hal;


// singleton instance
AP_NICSimpleOutput *AP_NICSimpleOutput::_singleton;

namespace AP {
    void AP_NICSimpleOutput::release() {
        gcs().send_text(MAV_SEVERITY_INFO,"Simple output activated");
    }
    
    AP_NICSimpleOutput::AP_NICSimpleOutput() {

    }

    AP_NICSimpleOutput *simpleOutput() {
        return AP_NICSimpleOutput::get_singleton();
    }
}
#endif // HAL_PARACHUTE_ENABLED
