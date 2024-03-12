/*
 * Original Author: Jonathan Hyry
 * Date Originally Written: 2/1/2012
 */

#include "shellTUIHdr.h"

/*
 * Function getTildeHomePath allows users of Shellac to
 * jump to their home directory, as defined by the
 * environment variable HOME.
 *
 * Usage pertaining to built-in command cd:
 *
 *  - If a user enters "cd ~/", the working directory
 *    will be changed to the directory defined in the
 *    HOME environment variable.
 *
 *  - The user may also enter a command such as
 *    "cd ~/Documents" or any deeper subdirectory in
 *    the directory tree.
 *
 * Parameters:
 *
 *  char * fullDirStr,       / __in /
 *
 *    - This should be the directory string including
 *      the tilde char
 *
 *  char * parsedHomeDir,    / __out /
 *
 *    - This will be where the parsed directory path
 *      string will be returned.
 *
 *  int homeSubDirPathLength / __in /
 *
 *    - This is the length of the parsed subdirectory.
 *      This should be fullDirPathLength - 1.
 */
void getTildeHomePath ( char * fullDirStr,       /* __in */
                        char * parsedHomeDir,    /* __out */
                        int homeSubDirPathLength /* __in */  ) {

  // Temp string for holding the subdir path
  char   *tempStr =
         (char *)malloc(INPUT_ARG_SIZE*sizeof(char));

  // Clean up the newly allocated memory
  memset (tempStr,
          (int)NULL,
          strlen(fullDirStr)*sizeof(char));

  // If tilde, go to home dir.
  strncpy(tempStr,
          ++fullDirStr,
          homeSubDirPathLength);

#ifdef DEBUG
  // DEBUG HOME path stuff
  printf("HOME path length: %d\n", homeSubDirPathLength);
  printf("Home SubStr address: 0x%x\n", (unsigned int)fullDirStr);
  printf("Temp string: %s\n", tempStr);
#endif

  strcpy(parsedHomeDir, getenv("HOME"));
  strcat(parsedHomeDir, tempStr);

#ifdef DEBUG
  // DEBUG After the dir is processed
  printf("After HOME processing: %s\n", parsedHomeDir);
#endif

  // Cleaning
  free(tempStr);

  // End function getTildeHomePath
  return;
}

/*
 * Opens the file "filePath" and reads a batch
 * of commands from the open stream.
 */
void runShellacCommandBatch ( char * filePath ) {

  //Place to store forked process ID
  pid_t tempPID = 0;

  // Use fopen with read-only permissions,
  // as Shellac has no reason to modify
  // the batch file.
  FILE *script = fopen(++filePath, "r");

  if ( script == NULL ) {

    char * fOpenErr = getError();

    printf("An error occurred while opening the");
    printf(" file at %s.\n Error %d: %s",
           filePath, errno, fOpenErr );

    // Make sure to free up the space
    // used by the error string
    free(fOpenErr);
  }

  else {

    // Get the commands from the file
    // specified by filePath
    for ( j = 0;

          // Get command string j from the file.
          fgets ( commandBatch[j],
                  INPUT_ARG_SIZE,
                  script ) != NULL;) { // End for loop header

#ifdef DEBUG
      printf("\nCurrent index: %d\nCurrentCommand: %s\n",
             j,
             commandBatch[j]);
#endif

      // Fork a new process to run the scripted
      // command.
      tempPID = fork();

      //Execute the command
      tempPID =
        executeCommand( tempPID, commandBatch[j] );

      // Wait for the child process to finish
      // execution
      waitForChildProc( tempPID );

      // If the batch array is too small to
      // hold all of the commands, we need to
      // reallocate the array to fit more stuff.
      // Otherwise continue reading.
      if ( ++j < (timesResized*BATCH_SIZE) + BATCH_SIZE ) continue;

      else reallocateCommandBatchBuffer();
    }
  }
}

/*
 * If the commandBatch script buffer is full,
 * yet there are still more commands to read,
 * we need to resize the buffer to accomadate
 * the rest of the commands.
 */
void reallocateCommandBatchBuffer ( void ) {

  // Calculate the new size of the
  // command batch buffer...
  int newSize =
    ( (++timesResized) * BATCH_SIZE ) + BATCH_SIZE;

#ifdef DEBUG
  printf("\nResizing batch command buffer to %d\n", newSize);
#endif

  // Reallocate the outer array that holds
  // the head pointer for each string.
  commandBatch =
    (char **)realloc( commandBatch, newSize * sizeof(char *));

  // Allocate more space for new strings
  for ( i = newSize - BATCH_SIZE; i < newSize; i++ ) {

    commandBatch[i] = (char *)malloc(INPUT_ARG_SIZE * sizeof(char));
    memset(commandBatch[i], (int)NULL, INPUT_ARG_SIZE * sizeof(char));
  }
}

/*
 * Executes a command.
 */
pid_t executeCommand ( pid_t forkedPID, char * command ) {

#ifdef DEBUG
  printf("Current process ID is %d", forkedPID);
#endif

  // Execute the command
  if ( forkedPID == 0 )
    execl ( SH_PATH,
            SH_NAME,
            SH_OPT,
            command,
            (char *)NULL );

  // Or figure out what happened
  // if something went wrong
  else if ( forkedPID < 0 ) {

    // Store the error message
    char * forkError = getError();

    printf("Fork not completed.\nError %d: %s",
           errno,
           forkError);

    // Deallocate error string.....
    free(forkError);
  }

  return forkedPID;
}

/*
 * Takes a pid_t as an argument and returns
 * the exit status of the process in stat.
 */
void waitForChildProc ( pid_t childPID ) {

    // Wait for the process to finish its
    // execution cycle.
    while( wait ( &stat ) != childPID );

#ifdef DEBUG
    // DEBUG Prints process ID and PID
    // childProc exit status via stat.
    printf("\nProcess %d ended with status %d.\n", childPID, stat);
#endif
}
