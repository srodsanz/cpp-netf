/**
 *  Project definition on different challenges for programming
 *  tasks in C/C++
*/

#pragma once

#define AUTHOR 'Salvador Rodriguez Sanz'
#define YEAR '2024'

#define VERSION_MAJOR "0"
#define VERSION_MINOR "1"

#define APP_VERSION \
    APP_TOSTRING(APP_VERSION_MAJOR) "." \
    APP_TOSTRING(APP_VERSION_MINOR)

/* Status codes for execution */

constexpr static int SUCCESS_CODE = 0;
constexpr static int FAILURE_CODE = -1;