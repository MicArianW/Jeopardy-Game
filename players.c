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
#include "players.h"
dddddddddd

// Function to check if a player exists in the game
// Iterates through the list of players and compares names
bool player_exists(player *players, int num_players, char *name) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            return true;  // Player found
        }
    }
    return false; // Player not found
}

// Function to update the score of a player
// Finds the player by name and adds the given value to their score
void update_score(player *players, int num_players, char *name, int value) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].score += value;
            return;
        }
    }
}

// Function to compare players by score for sorting purposes
// Used for ranking players in descending order of their scores
int compare_players(const void *a, const void *b) {
    player *playerA = (player *)a;
    player *playerB = (player *)b;
    return playerB->score - playerA->score; // Descending order
}

