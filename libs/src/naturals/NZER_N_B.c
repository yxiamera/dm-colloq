#pragma once

int NZER_N_B(int *input) {
    // Execution time: 10 minutes
    // Logical lines of code: 11
    int size = input[0]; // Size of the number
    int c, i;

    c = 0;
    for (i = 2; i <= size; i++) { // If each digit of a number is zero
        if (input[i] != c) {
            c = 1;
        }
    }
    if (c == 0) {
        return 1;
    } else {
        return 0; // The number is not zero
    }
}
