#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 10
#define MAX_PROCESSES 5

// Function prototypes
void firstFit(int blockSize[], int m, int processSize[], int n);
void bestFit(int blockSize[], int m, int processSize[], int n);
void worstFit(int blockSize[], int m, int processSize[], int n);

int main() {
    int blockSize[MAX_BLOCKS] = {100, 500, 200, 300, 600}; // Block sizes
    int processSize[MAX_PROCESSES] = {212, 417, 112, 426}; // Process sizes
    int m = 5, n = 4; // Number of blocks and processes

    printf("First Fit Allocation:\n");
    firstFit(blockSize, m, processSize, n);

    printf("\nBest Fit Allocation:\n");
    bestFit(blockSize, m, processSize, n);

    printf("\nWorst Fit Allocation:\n");
    worstFit(blockSize, m, processSize, n);

    return 0;
}

// First Fit Allocation
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; // Array to store the allocation results

    // Initialize all allocations to -1 (meaning not allocated)
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Traverse through all processes
    for (int i = 0; i < n; i++) {
        // Find the first block that can accommodate the process
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i]; // Reduce the available block size
                break;
            }
        }
    }

    // Print the allocation result
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("Process %d allocated to Block %d\n", i+1, allocation[i]+1);
        } else {
            printf("Process %d not allocated\n", i+1);
        }
    }
}

// Best Fit Allocation
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; // Array to store the allocation results

    // Initialize all allocations to -1 (meaning not allocated)
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Traverse through all processes
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;

        // Find the best block (smallest suitable block)
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        // Allocate the best block
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i]; // Reduce the available block size
        }
    }

    // Print the allocation result
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("Process %d allocated to Block %d\n", i+1, allocation[i]+1);
        } else {
            printf("Process %d not allocated\n", i+1);
        }
    }
}

// Worst Fit Allocation
void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; // Array to store the allocation results

    // Initialize all allocations to -1 (meaning not allocated)
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Traverse through all processes
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;

        // Find the worst block (largest available block)
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        // Allocate the worst block
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i]; // Reduce the available block size
        }
    }

    // Print the allocation result
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("Process %d allocated to Block %d\n", i+1, allocation[i]+1);
        } else {
            printf("Process %d not allocated\n", i+1);
        }
    }
}

