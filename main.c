#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void fill_numbers_array(int *numbers, size_t buffer_entries) {
    for (size_t i = 0; i <= buffer_entries; i++) {
        int random_number = rand()%((time(NULL)) - 10); // create buffer_entries amount of random numbers ranging between 10 and current time in seconds since 1970 1st of january
        numbers[(size_t)i] = random_number; // fill array with random numbers
    }
}

void swap_array_items(int *numbers, size_t iterator_pos) {
    int cache = numbers[iterator_pos]; // save item at current iterator position to cache
    
    numbers[iterator_pos] = numbers[iterator_pos+1]; // set current position to next item [2, 1] becomes [2, 2]
    numbers[iterator_pos+1] = cache; // set next item to current position, [2, 2] becomes [1, 2]
}

int main(void) {
    time_t start_seconds = time(NULL); // get time in seconds at start
    size_t buffer_entries = 39200; // allowed amount of items in INT[]
    int numbers[buffer_entries];

    fill_numbers_array(&numbers, buffer_entries);

    for (size_t j = buffer_entries; j > 0; j--) { // starting at the end of the buffer_entries size loop through the INT[] containing the random numbers
        for (size_t i = 0; i <= buffer_entries; i++) { // loop through it again, and compare the current item to every other item
            if (numbers[i] > numbers[i+1]) swap_array_items(&numbers, i); // swap items if A is bigger than B
        }
    }

    for (size_t i = 0; i <= buffer_entries; i++) {
        printf("%d\n", numbers[i]); // log all INT[] items to show that the array was succesfully bubblesorted
    }

    time_t end_seconds = time(NULL); // get time in seconds at the end of runtime
    printf("Process runtime: %d seconds\n", (int)(end_seconds - start_seconds)); // show how long the process took
    return 0;
}
