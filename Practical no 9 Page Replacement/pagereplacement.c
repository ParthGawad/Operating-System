#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 10
#define FRAME_SIZE 4

// Function to simulate FIFO page replacement
void fifo(int pages[], int n) {
int frames[FRAME_SIZE] = {-1, -1, -1, -1};
int pageFaults = 0, pointer = 0;

printf("FIFO Page Replacement:\n");
for (int i = 0; i < n; i++) {
    int page = pages[i];
    int found = 0;

    // Check if page is already in frames
    for (int j = 0; j < FRAME_SIZE; j++) {
        if (frames[j] == page) {
            found = 1;
            break;
        }
    }

    if (!found) {
        frames[pointer] = page;
        pointer = (pointer + 1) % FRAME_SIZE;
        pageFaults++;
    }

    printf("Page %d: ", page);
    for (int j = 0; j < FRAME_SIZE; j++) {
        if (frames[j] != -1) {
            printf("%d ", frames[j]);
        }
    }
    printf("\n");
}
printf("Total Page Faults in FIFO: %d\n", pageFaults);


}

// Function to simulate LRU page replacement
void lru(int pages[], int n) {
int frames[FRAME_SIZE] = {-1, -1, -1, -1};
int pageFaults = 0;

printf("LRU Page Replacement:\n");
for (int i = 0; i < n; i++) {
    int page = pages[i];
    int found = 0;

    // Check if page is already in frames
    for (int j = 0; j < FRAME_SIZE; j++) {
        if (frames[j] == page) {
            found = 1;
            break;
        }
    }

    if (!found) {
        int leastRecentIndex = -1, minTime = -1;

        // Find least recently used page
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] == -1) {
                leastRecentIndex = j;
                break;
            }

            int pageFound = 0;
            for (int k = i - 1; k >= 0; k--) {
                if (pages[k] == frames[j]) {
                    pageFound = 1;
                    if (minTime == -1 || k < minTime) {
                        minTime = k;
                        leastRecentIndex = j;
                    }
                    break;
                }
            }

            if (!pageFound) {
                leastRecentIndex = j;
                break;
            }
        }

        frames[leastRecentIndex] = page;
        pageFaults++;
    }

    printf("Page %d: ", page);
    for (int j = 0; j < FRAME_SIZE; j++) {
        if (frames[j] != -1) {
            printf("%d ", frames[j]);
        }
    }
    printf("\n");
}
printf("Total Page Faults in LRU: %d\n", pageFaults);

}

// Function to simulate Optimal page replacement
void optimal(int pages[], int n) {
int frames[FRAME_SIZE] = {-1, -1, -1, -1};
int pageFaults = 0;

printf("Optimal Page Replacement:\n");
for (int i = 0; i < n; i++) {
    int page = pages[i];
    int found = 0;

    // Check if page is already in frames
    for (int j = 0; j < FRAME_SIZE; j++) {
        if (frames[j] == page) {
            found = 1;
            break;
        }
    }

    if (!found) {
        int farthest = -1, indexToReplace = -1;

        // Find the page that will not be used for the longest period
        for (int j = 0; j < FRAME_SIZE; j++) {
            int pageFound = 0;
            for (int k = i + 1; k < n; k++) {
                if (pages[k] == frames[j]) {
                    pageFound = 1;
                    if (farthest == -1 || k > farthest) {
                        farthest = k;
                        indexToReplace = j;
                    }
                    break;
                }
            }

            if (!pageFound) {
                indexToReplace = j;
                break;
            }
        }

        frames[indexToReplace] = page;
        pageFaults++;
    }

    printf("Page %d: ", page);
    for (int j = 0; j < FRAME_SIZE; j++) {
        if (frames[j] != -1) {
            printf("%d ", frames[j]);
        }
    }
    printf("\n");
}
printf("Total Page Faults in Optimal: %d\n", pageFaults);
}

int main() {
int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 7};  // Example page reference string
int n = sizeof(pages) / sizeof(pages[0]);

// Run FIFO page replacement
fifo(pages, n);

// Run LRU page replacement
lru(pages, n);

// Run Optimal page replacement
optimal(pages, n);
return 0;
}
