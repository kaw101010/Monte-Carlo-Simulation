# Monte Carlo Simulation

This project simulates poker hands to calculate the probabilities of getting various types of hands, such as a pair, two pairs, three of a kind, full house, and four of a kind. It uses the [Monte Carlo method](https://en.wikipedia.org/wiki/Monte_Carlo_method) to simulate millions of iterations and then calculates the probability of each hand type. For each iteration, the deck is being shuffled with the [Fischer-Yates Algorithm](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle).

## Getting Started

### Prerequisites

- A C compiler (e.g., gcc, clang)

### Compilation

To compile the program, you can use ```make``` to build the executable.
I have included a Makefile for convenience.

The executable is named ```poker_simulation```. You can run it using ```./poker_simulation``` to look at the probabilities.

### Sample Outputls 

```
Total iterations: 2000000

Hand            Count           Probability
----------------------------------------
No Pair         421414          21.07 %
One Pair        945022          47.25 %
Two Pair        480041          24.00 %
Three of a Kind 99179           4.96 %
Full House      51012           2.55 %
Four of a Kind  3332            0.17 %
```