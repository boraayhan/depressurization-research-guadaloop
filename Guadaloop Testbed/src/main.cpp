#include <Arduino.h>
#include "constants.h"
#include "math/PID/PID.h"


pid hvsPID(HVS_PID);
pid thermocouplePID(thermocouple_PID);

weights w = weights{
    std::vector<pressureRangeWeight>{
        pressureRangeWeight{50, weight{0.7, 0.3}},
        pressureRangeWeight{100, weight{0.5, 0.5}},
        pressureRangeWeight{200, weight{0.3, 0.7}},
    }
};


void setup() {
    Serial.begin(115200);
}

void loop() {
  // Todo: fix hertz to synchronize both sensor's frequencies
  float p = getCurrentPressureTorr();
  float hvsCmd = hvsPID.compute(p, targetPressureTorr);
  float thermocoupleCmd = thermocouplePID.compute(getPressureDifferential(getTemperature()), 0); 
  setSolenoidDutyCycle(w.getWeight(p).hvsWeight * hvsCmd + w.getWeight(p).thermocoupleWeight * thermocoupleCmd);
}

void setSolenoidDutyCycle(float dutyCycle) {
  // FIXME: implement, such that 0: fully closed and 1: fully open
}

float getCurrentPressureTorr() {
  // FIXME: implement, return torr
  return 760;
}

float getTemperature() {
  // FIXME: implement, return temperature in Celsius
  return 25.0;
}

float getPressureDifferential(float temperature) {
  // FIXME: implement, basically partially differentiate pV = nRT with constant R and V
  return 0.0;
}

float smithPredictor(float input) {
  // FIXME: implement
  // Predict future state of input by looking at its trends https://en.wikipedia.org/wiki/Smith_predictor
  return input;
}