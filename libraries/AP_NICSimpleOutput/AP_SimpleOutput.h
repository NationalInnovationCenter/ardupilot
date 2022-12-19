/// @file   AP_Parachute.h
/// @brief  Parachute release library
#pragma once

#include <AP_Param/AP_Param.h>
#include <AP_Common/AP_Common.h>
#include <AP_Relay/AP_Relay.h>

#ifndef HAL_PARACHUTE_ENABLED
// default to parachute enabled to match previous configs
#define HAL_PARACHUTE_ENABLED 1
#endif

#if HAL_PARACHUTE_ENABLED


/// @class  AP_Parachute
/// @brief  Class managing the release of a parachute
class AP_NICSimpleOutput {

public:
    /// Constructor
    AP_NICSimpleOutput()
    {
        // setup parameter defaults
#if CONFIG_HAL_BOARD == HAL_BOARD_SITL
        if (_singleton != nullptr) {
            AP_HAL::panic("Parachute must be singleton");
        }
#endif
        _singleton = this;
        //AP_Param::setup_object_defaults(this, var_info);
    }

    /* Do not allow copies */
    CLASS_NO_COPY(AP_NICSimpleOutput);

    /// release - release parachute
    void release();
    static AP_NICSimpleOutput *get_singleton() { return _singleton; }
private:
    static AP_NICSimpleOutput *_singleton;
        
};

namespace AP {
    AP_NICSimpleOutput *simpleOutput();
};

#endif // HAL_PARACHUTE_ENABLED
