#include "./monitor.h"
#include <assert.h>
#include <windows.h>

// Pure functions for vital checks
bool isTemperatureCritical(float temperature) {
    return temperature > 102 || temperature < 95;
}

bool isPulseRateCritical(float pulseRate) {
    return pulseRate < 60 || pulseRate > 100;
}

bool isSpo2Critical(float spo2) {
    return spo2 < 90;
}

// I/O function for alert animation
void showAlert(const char* message) {
    printf("%s\n", message);
    for (int i = 0; i < 6; i++) {
        printf("* ");
        fflush(stdout);
        Sleep(1000);
        printf(" *\r");
        fflush(stdout);
        Sleep(1000); 
    }
    printf("\n");
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    if (isTemperatureCritical(temperature)) {
        showAlert("Temperature is critical!");
        return 0;
    }
    if (isPulseRateCritical(pulseRate)) {
        showAlert("Pulse Rate is out of range!");
        return 0;
    }
    if (isSpo2Critical(spo2)) {
        showAlert("Oxygen Saturation out of range!");
        return 0;
    }
    printf("All vitals are normal.\n");
    return 1;
}
