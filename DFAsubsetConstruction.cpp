#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100
#define NUM_STATES 3
#define NUM_CHARS 2

// Struct for representing a state in the DFA
typedef struct {
    bool is_final;
    int transition[NUM_CHARS];
} State;

int main(void) {
    char str[MAX_LEN+1];
    printf("Enter a string: ");
    scanf("%100s", str);

    // Initialize the NFA with three states:
    //   0 = start state
    //   1 = first 1 encountered
    //   2 = second 1 encountered
    State nfa[NUM_STATES] = {
        { .is_final = false, .transition = { 1, 0 } }, // state 0
        { .is_final = false, .transition = { 2, 0 } }, // state 1
        { .is_final = true,  .transition = { 2, 2 } }, // state 2
    };

    // Initialize the DFA with a single start state and no final states
    State dfa[MAX_LEN+1] = {
        { .is_final = false, .transition = { 0, 0 } },
    };
    int num_states = 1;

    // Set of states that are currently being processed
    int curr_states[MAX_LEN+1];
    int num_curr_states = 0;
    curr_states[num_curr_states++] = 0; // start with the initial state of the NFA

    // Set of states that have been processed
    int processed_states[MAX_LEN+1];
    int num_processed_states = 0;

    // Process the states one by one
    while (num_curr_states > 0) {
        // Take the first state from the list of current states
        int state = curr_states[0];
        for (int i = 1; i < num_curr_states; i++) {
            curr_states[i-1] = curr_states[i];
        }
        num_curr_states--;

        // Mark the state as processed
        processed_states[num_processed_states++] = state;

        // Check if the state is final in the NFA
        for (int i = 0; i < NUM_STATES; i++) {
            if (state & (1 << i)) {
                dfa[state].is_final |= nfa[i].is_final;
            }
        }

        // Calculate the transitions for this state
        for (int c = 0; c < NUM_CHARS; c++) {
            // Calculate the next set of states for this input character
            int next_state = 0;
            for (int i = 0; i < NUM_STATES; i++) {
                if (state & (1 << i)) {
                    next_state |= (1
