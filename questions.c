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

// Define an array to hold questions (only in questions.c)
question questions[NUM_QUESTIONS];

// Define categories
char categories[NUM_CATEGORIES][MAX_LEN] = {
    "Science", 
    "History", 
    "Geography"
};

// Initializes the array of questions for the game
void initialize_game(void)
{

    
    // Populate the questions array
    int index = 0;
    //Science question
    
        strcpy(questions[index].category, "Science");
        strcpy(questions[index].question, "What is the smallest unit of life?");
        strcpy(questions[index].answer, "Cell");
        questions[index].value = 100;
        questions[index].answered = false;
        index++;
        strcpy(questions[index].category, "Science");
        strcpy(questions[index].question, "What is the chemical symbol for water?");
        strcpy(questions[index].answer, "H2O");
        questions[index].value = 200;
        questions[index].answered = false;
        index++;
    
        strcpy(questions[index].category, "Science");
        strcpy(questions[index].question, "What is the chemical formula for table salt?");
        strcpy(questions[index].answer, "NaCl");
        questions[index].value = 300;
        questions[index].answered = false;
        index++;
    
        strcpy(questions[index].category, "Science");
        strcpy(questions[index].question, "Which famous equation describes the relationship between energy and mass?");
        strcpy(questions[index].answer, "E=mc²");
        questions[index].value = 400;
        questions[index].answered = false;
        index++;
    
//HISTORY QUESTION  

        strcpy(questions[index].category, "History");
        strcpy(questions[index].question, "Should You tell your man you got engaged?");
        strcpy(questions[index].answer, "HELL NO !!!");
        questions[index].value = 100;
        questions[index].answered = false;
        index++;

       
        strcpy(questions[index].category, "History");
        strcpy(questions[index].question, "Who discovered gravity?");
        strcpy(questions[index].answer, "Newton");
        questions[index].value = 200;
        questions[index].answered = false;
        index++;

        strcpy(questions[index].category, "History");
        strcpy(questions[index].question, "What was the name of the first man to walk on the moon?");
        strcpy(questions[index].answer, "Neil Armstrong");
        questions[index].value = 300;
        questions[index].answered = false;
        index++;
    
        strcpy(questions[index].category, "History");
        strcpy(questions[index].question, "What was the name of the agreement that created Canada as a country?");
        strcpy(questions[index].answer, "British North America Act (BNA Act)");
        questions[index].value = 400;
        questions[index].answered = false;
        index++;
// GEOGRAPHY QUESTION 
        strcpy(questions[index].category, "Geography");
        strcpy(questions[index].question, "what is the most populated country in the world?");
        strcpy(questions[index].answer, "India");
        questions[index].value = 100;
        questions[index].answered = false;
        index++;
        
        strcpy(questions[index].category, "Geography");
        strcpy(questions[index].question, "What continent is Nigeria located on?");
        strcpy(questions[index].answer, "South America");
        questions[index].value = 200;
        questions[index].answered = false;
        index++;
        
        strcpy(questions[index].category, "Geography");
        strcpy(questions[index].question, "Which is the largest continent?");
        strcpy(questions[index].answer, "Asia");
        questions[index].value = 300;
        questions[index].answered = false;
        index++;

        strcpy(questions[index].category, "Geography");
        strcpy(questions[index].question, "What planet is known as the Red Planet?");
        strcpy(questions[index].answer, "Mars");
        questions[index].value = 400;
        questions[index].answered = false;
        index++;    
    
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


// Returns true if all questions have been answered
bool all_questions_answered(void) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (!questions[i].answered) {
            return false; // At least one question is still available
        }
}
    return true; // All questions have been answered
}


void mark_question_answered(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            questions[i].answered = true;
            return;
        }
    }
}

