#include "monitor.h"
#include <assert.h>
#include <stdio.h>

void test_vitalsOk() {
    // Temperature tests
    assert(vitalsOk(94.9, 80, 95) == 0); // Low temp
    assert(vitalsOk(102.1, 80, 95) == 0); // High temp
    assert(vitalsOk(95.0, 80, 95) == 1); // Lower bound
    assert(vitalsOk(102.0, 80, 95) == 1); // Upper bound

    // Pulse rate tests
    assert(vitalsOk(98, 59.9, 95) == 0); // Low pulse
    assert(vitalsOk(98, 100.1, 95) == 0); // High pulse
    assert(vitalsOk(98, 60.0, 95) == 1); // Lower bound
    assert(vitalsOk(98, 100.0, 95) == 1); // Upper bound

    // SpO2 tests
    assert(vitalsOk(98, 80, 89.9) == 0); // Low SpO2
    assert(vitalsOk(98, 80, 90.0) == 1); // Lower bound
    assert(vitalsOk(98, 80, 95.0) == 1); // Normal

    // All normal
    assert(vitalsOk(98, 80, 95) == 1);

    // Success cases: all vitals in range
    assert(vitalsOk(98.6, 72, 98) == 1); // Typical normal values
    assert(vitalsOk(97.5, 65, 92) == 1); // All vitals in safe range
    assert(vitalsOk(100.0, 80, 99) == 1); // All vitals in safe range
    assert(vitalsOk(96.0, 61, 91) == 1); // All vitals just above lower bounds
    assert(vitalsOk(101.9, 99, 90) == 1); // All vitals just below upper bounds
}

int main() {
    test_vitalsOk();
    printf("All tests passed!\n");
    return 0;
}
