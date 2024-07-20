#include "poker_simulation.h"

// getting a card data type out of a number
card card_from_num(int c)
{
    card temp;
    temp.suit = c / 13;
    temp.value = c % 13 + 2;
    return temp;
}

// create a new random hand
deck *new_hand()
{
    int deck_array[TOTAL_CARDS];
    // init deck array with cards
    for (int i = 0; i < TOTAL_CARDS; i++)
    {
        deck_array[i] = i;
    }

    // Fisher-Yates algorithm for shuffling cards
    for (int i = TOTAL_CARDS - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        // Swap deck_array[i] and deck_array[j]
        int temp = deck_array[i];
        deck_array[i] = deck_array[j];
        deck_array[j] = temp;
    }

    // Allocate memory for the deck
    deck *deck = malloc(sizeof(*deck));
    deck->n_cards = HAND_SIZE;
    deck->cards = malloc(sizeof(card*) * HAND_SIZE);

    // Assign the shuffled cards to the new_deck
    for (int k = 0; k < HAND_SIZE; k++)
    {
        card new_card = card_from_num(deck_array[k]);
        deck->cards[k] = malloc(sizeof(card));
        deck->cards[k]->value = new_card.value;
        deck->cards[k]->suit = new_card.suit;
    }

    return deck;
}

// creating an array with the number of times each card value is repeated in the hand.
int *get_match_counts(deck *hand)
{
    int *new_array = malloc(sizeof(int) * HAND_SIZE);
    for (int i = 0; i < HAND_SIZE; i++)
    {
        new_array[i] = 0;
        for (int j = 0; j < HAND_SIZE; j++)
        {
            if (hand->cards[i]->value == hand->cards[j]->value)
                new_array[i]++;
        }
    }
    return new_array;
}

// assign a ranking to that hand based on the match_count array.
int get_ranking(int *match_counts)
{
    int pair = 0;
    int three = 0;
    int four = 0;
    for (int i = 0; i < HAND_SIZE; i++)
    {
        if (match_counts[i] == 2)
        {
            pair++;
        }
        else if (match_counts[i] == 3)
        {
            three++;
        }
        else if (match_counts[i] == 4)
        {
            four++;
        }
    }
    int ranking = 0;
    if (four == 4)
    {
        ranking = 5;
    }
    else if (three >= 3 && pair >= 2)
    {
        ranking = 4;
    }
    else if (three >= 3)
    {
        ranking = 3;
    }
    else if (pair >= 4)
    {
        ranking = 2;
    }
    else if (pair == 2)
    {
        ranking = 1;
    }
    return ranking;
}

// print the probabilities
void print_probabilities(int rankings_count[], int trials)
{

    printf("Total iterations: %d\n\n", trials);
    printf("Hand\t\tCount\t\tProbability\n");
    printf("----------------------------------------\n");
    // print hand, hand count, probability as a percentage
    printf("No Pair\t\t%d\t\t%.2f %%\n", rankings_count[0], (100) * (float)rankings_count[0] / trials);
    printf("One Pair\t%d\t\t%.2f %%\n", rankings_count[1], (100) * (float)rankings_count[1] / trials);
    printf("Two Pair\t%d\t\t%.2f %%\n", rankings_count[2], (100) * (float)rankings_count[2] / trials);
    printf("Three of a Kind\t%d\t\t%.2f %%\n", rankings_count[3], (100) * (float)rankings_count[3] / trials);
    printf("Full House\t%d\t\t%.2f %%\n", rankings_count[4], (100) * (float)rankings_count[4] / trials);
    printf("Four of a Kind\t%d\t\t%.2f %%\n", rankings_count[5], (100) * (float)rankings_count[5] / trials);
}

int main(void)
{
    // seeding with time
    srand(time(0));
    // keeps count of all hands
    int rankings_count[6] = {0, 0, 0, 0, 0, 0};
    deck *hand;
    int *match_counts;
    int ranking;

    // Start every simulation.
    for (int i = 0; i < TRIALS; i++)
    {
        hand = new_hand();
        match_counts = get_match_counts(hand);
        ranking = get_ranking(match_counts);

        // Free all memory used
        for (int h = 0; h < HAND_SIZE; h++)
        {
            free(hand->cards[h]);
        }
        free(hand->cards);
        free(hand);
        free(match_counts);
        // Increase that hand ranking count.
        rankings_count[ranking]++;
    }

    // Call the new function to print the results
    print_probabilities(rankings_count, TRIALS);

    return 0;
}