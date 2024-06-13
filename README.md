# Animal Guessing Game in Assembly
## Description

This assignment will test your proficiency in programming in x64 assembly language by implementing the "Animal Guessing Game." The game is a variation of "20 Questions," where the only category is animals. Your task is to write assembly code that constructs a tree of animals and questions to guess the animal the user is thinking of based on their responses to yes/no questions.

## File Structure
- animals.s: Assembly file where you will implement your code (this is the file to turn in).
- animals.h: Header file for animals.s.
- main.c: Contains the main function and related functions.
- c_animals.c: Contains C versions of the assembly functions to be implemented.
- c_animals.h: Header file for c_animals.c.
- node_utils.c: Auxiliary procedures provided.
- node_utils.h: Header file for node_utils.c.
- makefile: Compiles the program.
- Executable file: ben_animals (on macOS/Linux) or ben_animals.exe (Cygwin), compiled from the original version.
- Execution: Compile the program using the provided makefile. Execute it with ./animals and follow the prompts.
- Saving State: The game state is saved in data.dat (backed up by data.dat.bak) for resuming. Delete data.dat to start over.
