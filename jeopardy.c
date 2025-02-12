/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens) {
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players) {
    printf("\nFinal Scores:\n");
    for (int i = 0; i < num_players - 1; i++) {
        for (int j = i + 1; j < num_players; j++) {
            if (players[j].score > players[i].score) {
                player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
    for (int i = 0; i < num_players; i++) {
        printf("%s: $%d\n", players[i].name, players[i].score);
    }
}
    
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    
    // initialize each of the players in the array
    printf("Enter the names of the %d players:\n", NUM_PLAYERS);
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
    
    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL) {
        // Call functions from the questions and players source files
        char player_name[50];
        char category[50];
        int value;
        char answer[100];

        display_categories();
        
        // Execute the game until all questions are answered
        printf("Enter player's name selecting the category: ");
        if (fgets(buffer, BUFFER_LEN, stdin) == NULL) {
            break;  // Exit loop if input fails
        }
        sscanf(buffer, " %[^\n]", player_name);

        if (!player_exists(players, NUM_PLAYERS, player_name)) {
            printf("Player not found. Try again.\n");
            continue;
        }
    

        printf("Enter category and dollar value: ");
        fgets(buffer, BUFFER_LEN, stdin);
        sscanf(buffer, "%s %d", category, &value);

        if (already_answered(category, value)) {
            printf("Question already answered. Choose another.\n");
            continue;
        }

        display_question(category, value);
        printf("Enter your answer: ");
        fgets(buffer, BUFFER_LEN, stdin);
        sscanf(buffer, " %[^\n]", answer);

        if (valid_answer(category, value, answer)) {
            printf("Correct! %s earns $%d\n", player_name, value);
            update_score(players, NUM_PLAYERS, player_name, value);
        } else {
            printf("Incorrect!\n");
        }

        mark_question_answered(category, value);
        memset(buffer, 0, BUFFER_LEN); // Clear buffer        
    }
    
    // Display the final results and exit
    show_results(players, NUM_PLAYERS);    
    return EXIT_SUCCESS;
}
