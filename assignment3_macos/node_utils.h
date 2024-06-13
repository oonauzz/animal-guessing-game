
#define BOOL int
#define TRUE 1
#define FALSE 0

#define STRING_SIZE 200

typedef struct node {
  char question_or_animal[STRING_SIZE];
  struct node *left;
  struct node *right;
} NODE;


//This reads a line from the standard input.
//It returns true if a line was actually read.
//It returns false if end-of-file was encountered
//before any data could be read.

BOOL read_line(char *p, int max);


//Recursively performs a pre-order traversal of the
//tree starting at node p, printing the question_or_animal field to
//the file specified by the file pointer.

void write_tree(NODE *p, FILE *f);


//Reads the file specified by the file pointer and 
//creates a tree based on the contents of the file.
//Returns a pointer to the root node of the tree.

NODE *read_tree(FILE *f);


// This is the root of the root. It is actually
// defined in main.c

extern NODE *root;
