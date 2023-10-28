#include <stdio.h>
#include <time.h>

int main() {
    struct tm start_time = {0};
    struct tm end_time = {0};


    // Input timestamps in the format 'Year-Month-Day Hour:Minute:Second'
    char start_time_str[20];
    char end_time_str[20];

    printf("Start Time: ");
    if (fgets(start_time_str, sizeof(start_time_str), stdin) == NULL) {
        printf("Error reading start time\n");
        return 1;
    }

    printf("End Time: ");
    if (fgets(end_time_str, sizeof(end_time_str), stdin) == NULL) {
        printf("Error reading end time\n");
        return 1;
    }

    // Convert the timestamp strings to struct tm
    if (strptime(start_time_str, "%Y-%m-%d %H:%M:%S", &start_time) == NULL ||
        strptime(end_time_str, "%Y-%m-%d %H:%M:%S", &end_time) == NULL) {
        printf("Invalid timestamp format\n");
        return 1;
    }

    // Convert struct tm to time_t (seconds since epoch)
    time_t start_timestamp = mktime(&start_time);
    time_t end_timestamp = mktime(&end_time);

    // Calculate the time duration in seconds
    time_t duration = end_timestamp - start_timestamp;

    printf("Duration: %ld sec\n", duration);

    return 0;
}
