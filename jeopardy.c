/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Define constants
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Function to tokenize the input answer
void tokenize(char *input, char **tokens) {
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
}

// Function to display the game results
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

int main(int argc, char *argv[]) {
    // Array of players
    player players[NUM_PLAYERS];
    
    // Input buffer
    char buffer[BUFFER_LEN] = { 0 };
    
    // Initialize game
    initialize_game();

    // Get player names
    printf("Enter the names of the %d players:\n", NUM_PLAYERS);
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
    
    // Main game loop
    while (1) {
        display_categories();
        
        char player_name[50];
        char category[50];
        int value;
        char answer[100];
        
        printf("Enter player's name selecting the category: ");
        fgets(buffer, BUFFER_LEN, stdin);
        sscanf(buffer, "%s", player_name);
        
        if (!player_exists(players, NUM_PLAYERS, player_name)) {
            printf("Invalid player name!\n");
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
        sscanf(buffer, " %[^"]", answer);
        
        if (valid_answer(category, value, answer)) {
            printf("Correct! %s earns $%d\n", player_name, value);
            update_score(players, NUM_PLAYERS, player_name, value);
        } else {
            printf("Incorrect!\n");
        }
        
        mark_question_answered(category, value);
        memset(buffer, 0, BUFFER_LEN); // Clear buffer
    }
    
    // Display final results
    show_results(players, NUM_PLAYERS);
    
    return EXIT_SUCCESS;
}
