#pragma once

#include <string_view>
#include <string>

namespace BuildInfo
{
    const std::string_view VERSION_STRV = "Alpha 1.0.0";
    const std::string VERSION_STR = "Alpha 1.0.0";
    const char * VERSION_CHR = "Alpha 1.0.0";
    const std::string_view BUILD_DATE = __DATE__;
    const std::string_view BUILD_TIME = __TIME__;
}