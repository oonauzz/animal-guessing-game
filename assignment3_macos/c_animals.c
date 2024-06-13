#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node_utils.h"
#include "animals.h"

// Returns true if user types "yes" or "y" (upper or lower case)
// and returns false if user types "no" or "n". Keeps
// prompting otherwise.

// Note: This functon is not actually used, since the assembly code
// for yes_response() is already provided in animals.s

BOOL yes_response_c()
{
  char response[STRING_SIZE];
  BOOL result;

  while (TRUE) {
    read_line(response, STRING_SIZE);
    if (!strcasecmp(response,"yes") || !strcasecmp(response,"y")) {
      result = TRUE;
      break;
    }
    else if (!strcasecmp(response,"no") || !strcasecmp(response,"n")) {
      result = FALSE;
      break;
    }
    printf("Please enter \"yes\" or \"no\" > ");
  } // end of while loop
  
  return result;
}


// This procedure creates a new NODE and copies
// the contents of string s into the 
// question_or_animal field.  It also initializes
// the left and right fields to NULL.
// It should return a pointer to the new node


NODE *new_node_c(char *s)
{
  NODE *p = (NODE *) malloc(sizeof(NODE));
  p->left = p->right = NULL;
  strcpy(p->question_or_animal, s);
  return p;
}


// This is the procedure that performs the guessing.
// If the animal is not correctly guessed, it prompts
// the user for the name of the animal and inserts a
// new node for that animal into the tree.

void guess_animal_c()
{
  // If the root is NULL, then there are no animals in 
  // the tree. Prompt the player for the name of an 
  // animal, create a node for that animal, and make
  // that node the root of the tree.

    char new_question_or_animal[STRING_SIZE];
    NODE *p;
    NODE *new_n;

  
  if (root == NULL) {
    p = (NODE *) malloc(sizeof(NODE));
    p->left = p->right = NULL;
    printf("I give up! What animal is it? > ");
    read_line(p->question_or_animal,STRING_SIZE);
    root = p;
  }
  else {

    /*
      Otherwise (i.e. if the root is not NULL)
      Then descend down the tree. At each node encountered:

      If the left and right fields of the node are not NULL, i.e. the node
      is an interior node and must contain a question, then:
      - print the question_or_answer field, which will be a yes/no question.
      - read the response from the user
      - If the response is yes, follow the left field to the next node. Otherwise,
        follow the right field.
      

      Otherwise, if the left and right fields are NULL (i.e. the node is a leaf), 
      then the question_or_animal field contains an animal. Print the
      the question_or_animal field as the guess and prompt the user
      if the guess was correct. If the guess was correct, then 
      return. Otherwise, do the following:
           - prompt the user for the name of the new animal she was thinking of
           - prompt the user for a yes or no question distinguishing the new animal from the guessed animal
           - ask the user what the answer for the new animal would be (yes or no)
           - create a new node with the new animal in the question_or_animal field
           - create another new node that has the guessed animal in the question_or_animal field
           - make the two new nodes the children of the current node, where the animal for which the
             answer to the question is "yes" is the left child and the other animal is the right child.
           - overwrite the question_or_animal field of the current node with the new question.

      Note that the tree is a strictly binary tree, i.e. left and right fields of each node are either both NULL or 
      both valid pointers to child nodes (in other words, each node is a leaf or has exactly two children).
    */
    p = root;
    while (TRUE) {
      if ((p->left == NULL) && (p->right == NULL)) { //leaf, guess the animal
        printf("I'm guessing: %s\n", p->question_or_animal);
        printf("Am I right? > ");
        if (yes_response()) {
          printf("I win!\n");
          break;
        }
        else { //guess was wrong
          printf("\noops.  What animal were you thinking of? > ");
          read_line(new_question_or_animal,STRING_SIZE);
          new_n = new_node(new_question_or_animal);
          printf("Enter a yes/no question to distinguish between a %s and a %s > ", 
                 new_question_or_animal, p->question_or_animal);
          read_line(new_question_or_animal,STRING_SIZE);
          printf("What is the answer for a %s (yes or no) > ",
                 new_n->question_or_animal);
          if (yes_response()) {
            p->left = new_n;
            p->right = new_node(p->question_or_animal);
          }
          else {
            p->right = new_n;
            p->left = new_node(p->question_or_animal);
          }
          strcpy(p->question_or_animal, new_question_or_animal);
          break;
        }
      } //end left case
      else { //not a leaf
        printf("%s (yes/no) > ", p->question_or_animal);
        if (yes_response())
          p = p->left;
        else
          p = p->right;
      }
    }
  }
}


