#ifndef MONITOR_H
#define MONITOR_H

#include <stdbool.h>


// Returns 1 if all vitals are OK, 0 if any are critical
int vitalsOk(float temperature, float pulseRate, float spo2);

// Pure vital check functions
bool isTemperatureCritical(float temperature);
bool isPulseRateCritical(float pulseRate);
bool isSpo2Critical(float spo2);

// I/O function for alert animation
void showAlert(const char* message);

#endif // MONITOR_H


