    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int queue[] = {95, 180, 34, 119, 11, 123, 62, 64};
        int head = 50;
        int size = sizeof(queue) / sizeof(queue[0]);
        int total_seek_time = 0;
        int current_track;

        printf("FCFS Disk Scheduling\n");
        printf("Initial head position: %d\n", head);
        printf("Queue: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");

        printf("Seek Sequence: ");
        for (int i = 0; i < size; i++) {
            current_track = queue[i];
            total_seek_time += abs(current_track - head);
            printf("%d ", current_track);
            head = current_track;
        }
        printf("\n");

        printf("Total seek time: %d\n", total_seek_time);

        return 0;
    }