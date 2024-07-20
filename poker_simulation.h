#ifndef POKER_SIMULATION_H
#define POKER_SIMULATION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRIALS 2000000
#define HAND_SIZE 7
#define TOTAL_CARDS 52
#define NUM_SUITS 4

// Define the suit enum type.
typedef enum
{
    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS,
} suit;

// card data type.
typedef struct
{
    short value;
    suit suit;
} card;

// Define the deck data type
typedef struct
{
    card **cards;
    size_t n_cards;
} deck;

// Function declarations
card card_from_num(int c);
deck *new_hand(void);
int *get_match_counts(deck *hand);
int get_ranking(int *match_counts);
void print_probabilities(int rankings_count[], int trials);

#endif