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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // Define categories
    char *categories[] = {"Science", "History", "Geography"};
    
    // Populate the questions array
    int index = 0;
    for (int i = 0; i < 3; i++) {
        strcpy(questions[index].category, categories[i]);
        strcpy(questions[index].question, "What is the chemical symbol for water?");
        strcpy(questions[index].answer, "H2O");
        questions[index].value = 100;
        questions[index].answered = false;
        index++;

        strcpy(questions[index].category, categories[i]);
        strcpy(questions[index].question, "Who discovered gravity?");
        strcpy(questions[index].answer, "Newton");
        questions[index].value = 200;
        questions[index].answered = false;
        index++;

        strcpy(questions[index].category, categories[i]);
        strcpy(questions[index].question, "Which is the largest continent?");
        strcpy(questions[index].answer, "Asia");
        questions[index].value = 300;
        questions[index].answered = false;
        index++;

        strcpy(questions[index].category, categories[i]);
        strcpy(questions[index].question, "What planet is known as the Red Planet?");
        strcpy(questions[index].answer, "Mars");
        questions[index].value = 400;
        questions[index].answered = false;
        index++;    
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
