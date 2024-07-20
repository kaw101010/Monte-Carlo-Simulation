project = monte_carlo_simulation

input_file = poker_simulation
output_file = poker_simulation
compiler = gcc

make:
	$(compiler) -Wall -Wextra -o $(output_file) $(input_file).c -lm

clean:
	rm -f $(output_file)
