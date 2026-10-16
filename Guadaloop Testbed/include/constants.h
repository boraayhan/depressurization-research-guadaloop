#pragma once
#include "data_structs.h"

const pidSetting HVS_PID = pidSetting{1, 0.1, 0.5}; // FIXME: Tune
const pidSetting thermocouple_PID = pidSetting{1, 0.1, 0.5}; // FIXME: Tune

float targetPressureTorr = 100; // FIXME: sync to team requirement

weight DEFAULT_WEIGHT = weight{1.0, 1.0};

struct weights
{
    std::vector<pressureRangeWeight> pressureWeights;
    weight getWeight(float pressure) {
        for (const pressureRangeWeight& range : pressureWeights) {
            if (pressure <= range.lowerBound) {
                return range.w;
            }
        }
        return DEFAULT_WEIGHT;
    }
};