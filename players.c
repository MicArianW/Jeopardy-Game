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

// Function to compare players by score (for sorting)
int compare_players(const void *a, const void *b) {
    player *playerA = (player *)a;
    player *playerB = (player *)b;
    return playerB->score - playerA->score; // Descending order
}

// Function to print player rankings and declare winner
void print_player_rankings(player *players, int num_players) {
    // Sort players by score (highest to lowest)
    qsort(players, num_players, sizeof(player), compare_players);

    // Print rankings
    printf("\n---- Final Player Rankings ----\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s - $%d\n", i + 1, players[i].name, players[i].score);
    }

    // Declare the winner
    if (num_players > 0) {
        printf("\n🏆 Winner: %s with $%d! 🏆\n", players[0].name, players[0].score);
    }
}

print_player_rankings(players, num_players);

