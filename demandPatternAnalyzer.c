#include <stdio.h>

const char* determinePattern(float oneWeekInput[], float oneWeekAve);

int main() {
    // Example Data (7 days of Cacao usage)
    float data[7] = {100.0, 105.0, 95.0, 102.0, 98.0, 100.0, 101.0};
    float average = 100.14;

    // Call the function
    printf("The Demand Pattern is: %s\n", demandPatternAnalyzer(data, average));

    return 0;
}

const char* demandPatternAnalyzer(float oneWeekInput[], float oneWeekAve) {
    
    // Calculate the 20% margin
	float tolerance = oneWeekAve * 0.20;        // The 20% cushion    
	float stableMin = oneWeekAve - tolerance;   // The bottom of the stable range
	float stableMax = oneWeekAve + tolerance;   // The top of the stable range
    
    // Initialize counters
    int stableCounter = 0;
    int increasingCounter = 0; // Days spiking high
    int decreasingCounter = 0; // Days dropping low
    
    int i;
    // Loop 7 times to evaluate each day input for 7 days
    for(i = 0; i < 7; i++) {
        if(oneWeekInput[i] >= stableMin && oneWeekInput[i] <= stableMax) {
            stableCounter++;
        } else { // It is unstable. Check if it is high or low.
            if(oneWeekInput[i] < stableMin) {
                decreasingCounter++;
            } 
            else if(oneWeekInput[i] > stableMax) {
                increasingCounter++;
            }
        }
    }
    
    // Determine the Result
    // Rule: If most days (e.g., 5 or more) are stable, the whole week is stable.
    if(stableCounter >= 5) {
        return "Stable";
    } 
    // If not stable, is it mostly high or mostly low?
    else if (increasingCounter > decreasingCounter) {
        return "Fluctuating (Increasing)";
    } 
    else {
        return "Fluctuating (Decreasing)";
    }
}
