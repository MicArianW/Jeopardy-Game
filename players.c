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

#define NUM_QUESTIONS 12

// Define an array to hold questions
question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game
void initialize_game(void)
{
    // Define categories
    char *categories[] = {"Science", "History", "Geography"};
    
    // Populate the questions array
    int index = 0;
    for (int i = 0; i < 3; i++) {
        questions[index++] = (question){categories[i], "What is the chemical symbol for water?", "H2O", 100, false};
        questions[index++] = (question){categories[i], "Who discovered gravity?", "Newton", 200, false};
        questions[index++] = (question){categories[i], "Which is the largest continent?", "Asia", 300, false};
        questions[index++] = (question){categories[i], "What planet is known as the Red Planet?", "Mars", 400, false};
    }
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    printf("\nAvailable Categories:\n");
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (!questions[i].answered)
        {
            printf("%s - $%d\n", questions[i].category, questions[i].value);
        }
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value && !questions[i].answered)
        {
            printf("Question: %s\n", questions[i].question);
            return;
        }
    }
    printf("Question not found or already answered.\n");
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value)
        {
            if (strcmp(questions[i].answer, answer) == 0)
            {
                questions[i].answered = true;
                return true;
            }
        }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value)
        {
            return questions[i].answered;
        }
    }
    return false;
}
