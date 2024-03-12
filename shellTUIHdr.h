/*
 * Original Author: Jonathan Hyry
 * Date Originally Written: 1/30/2012
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

/*
 * Comment/Uncomment and recompile
 * for debugging output
 */
//#define DEBUG

// Command string properties
#define INPUT_ARG_SIZE 128
#define INPUT_BUFFER_SIZE 2
#define BATCH_SIZE 50

// sh information to pass to execl()
#define SH_PATH "/bin/sh"
#define SH_NAME "sh"
#define SH_OPT "-c"

// Array indices for main command
// string array
#define EXECL_BIN_SH 0
#define EXECL_SH_CMD 1

// Misc. stuff
#define SHELL_PROMPT "|)Shellac|> "
#define SHELL_EXIT "exit"
#define EXIT_ARG_OFFSET 5
#define SHELL_CWDIR "cd"
#define CD_CMD_LEN 2

typedef enum {

  FALSE,
  TRUE
} boolean_t;

// commandArgs Holds scanned program
// arguments for execl()
//
// commandBatch is an Array
// of strings that holds the
// commands gathered from a script.
char **commandArgs, **commandBatch;

// Holds the directory string,
// present working dir string,
// and the address to the dir
// substring in a cd command
// parse.
char *dirStr, *pwdir, *subStrAddress;

// Counters, cd path string length
int i, j, pathLength, timesResized;

// Process return status
int stat;

// External function for getting the
// current directory as a string
extern char * get_current_dir_name ( void );

// Text user interface for Shellac
pid_t cursorWait ( void );

// Minor error handling; this
// function returns a string
// describing the nature of the
// problem.
char * getError( void );

// This function parses a directory
// that starts with the tilde ( ~ )
// character.
void getTildeHomePath ( char *, char *, int );

// Serves as an extremely basic script
// handler. And by script I mean a
// list of commands in a text file.
void runShellacCommandBatch ( char * );

// If the command batch buffer is about
// to overfill, we need to call this
// function to get access to more space.
void reallocateCommandBatchBuffer ( void );

// Executes a batched command and waits for
//the child execution to finish.
pid_t executeCommand ( pid_t, char * );

// Waits for a child process of shellac
// to finish execution
void waitForChildProc ( pid_t );
