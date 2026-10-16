#pragma once
#include <vector>

// Data Structs

struct pidSetting {
    float kP;
    float kI;
    float kD;
};

struct weight {
    float hvsWeight;
    float thermocoupleWeight;
};

struct pressureRangeWeight {
    float lowerBound;
    weight w;
};