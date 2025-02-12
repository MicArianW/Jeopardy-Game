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

// Function implementation for player_exists
bool player_exists(player *players, int num_players, char *name) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            return true;  // Player found
        }
    }
    return false; // Player not found
}

// Function implementation for update_score
void update_score(player *players, int num_players, char *name, int value) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].score += value;
            return;
        }
    }
}


