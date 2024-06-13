#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node_utils.h"
#include "animals.h"
#include "c_animals.h"

void debug_print()
{
  printf("Bing\n");
}


// This is the main procedure
int main()
{ int i;
  BOOL done = FALSE;

  //Open the file data.dat to read in data from
  //previous game sessions to build an initial tree.

  FILE *datafile = fopen("data.dat", "r");
  if (datafile == NULL) {
    printf("data.dat not found, creating a new one\n");
    datafile = fopen("data.dat", "w");
    if (datafile == NULL) {
      printf("Cannot open data.dat for writing, exiting\n");
      exit(1);
    }
    // Initializing the file with a single line that says NULL
    fprintf(datafile,"NULL\n");
    rewind(datafile);  // go back to beginning to proceed
  }

  //Since data.dat will be overwritten with new tree data
  //at the end of the current game session, 
  //It opens data.dat.bak to save the current tree data

  FILE *backupfile = fopen("data.dat.bak", "w");

  // call read_tree() to read in an initial tree. Set
  // root to point to the tree.

  root = read_tree(datafile);

  //call write_tree() to write the initial tree to the
  //backup file.
  write_tree(root,backupfile);

  //close both files (for now)
  fclose(backupfile);
  fclose(datafile);

  printf("Welcome to the animal guessing game (like 20 questions).\n");
  do { 
    printf("\nThink of an animal...\n");

    /********************************************
     ONCE YOU HAVE WRITTEN THE ASSEMBLY CODE FOR guess_animal(),
     change the call below to guess_animal().
     ******************************************** */
    guess_animal_c();  //play the game

    printf("\nDo you want to play again? (yes/no) > ");
    
  } while (yes_response());  //keep looping as long as the user wants to.


  //done playing, so open data.dat for writing
  datafile = fopen("data.dat", "w");

  if (datafile == NULL) {
    printf("Can't open data.dat to write\n");
    exit(1);
  }

  //write the current tree to data.dat
  write_tree(root, datafile);

  //close the data.dat file
  fclose(datafile);

}

