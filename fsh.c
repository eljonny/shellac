/*
 * Original Author: Jonathan Hyry
 * Date Originally Written: 1/29/2012
 */

#include "shellTUIHdr.h"

int main(int argc, char **argv) {

  // Used to keep track of forked children
  pid_t childProc = 0;

  // If the command batch buffer gets full
  // we need to resize it. Knowing how many
  // times it has been resized makes this easy.
  timesResized = 0;

  printf("Shellac 0.3 Initializing...\n");

  // Allocate an array of char pointers for input buffer;
  // Allocate space for shell name and argument string.
  commandArgs =
    (char **)malloc(INPUT_BUFFER_SIZE*sizeof(char *));

  for ( i = 0; i < INPUT_BUFFER_SIZE; i++) {

    commandArgs[i] = (char *)malloc(INPUT_ARG_SIZE*sizeof(char));
    memset(commandArgs[i], (int)NULL, INPUT_ARG_SIZE*sizeof(char));
  }

  // Allocate space for command strings read from a batch
  // script
  commandBatch =
    (char **)malloc(BATCH_SIZE*sizeof(char *));

  for ( i = 0; i < BATCH_SIZE; i++) {

    commandBatch[i] = (char *)malloc(INPUT_ARG_SIZE*sizeof(char));
    memset(commandBatch[i], (int)NULL, INPUT_ARG_SIZE*sizeof(char));
  }

  // Shell name string for use with execl(5)
  commandArgs[EXECL_BIN_SH] = SH_NAME;

  // Get and print the Present working directory
  pwdir = get_current_dir_name();
  printf("\n%s\n", pwdir);

  // Memory management
  free(pwdir);

  do {

    // Wait for the user to enter a command;
    // If this process was forked store here
    childProc = cursorWait();

    // If we are in the child process
    if ( childProc == 0 )
      childProc =
        executeCommand ( childProc, commandArgs[EXECL_SH_CMD]);

    // If something went wrong, or if a built-in command
    // was used, Figure out what to do.
    else if ( childProc < 0 ) {

      // If the user used the built-in exit
      if ( strstr ( commandArgs[EXECL_SH_CMD], SHELL_EXIT ) != NULL ) {

        printf("Exiting with status %d\n\n", stat);
        return stat;
      }

      // If the user changed the working directory,
      // continue the shell session
      else if ( memcmp ( commandArgs[EXECL_SH_CMD],
                         &SHELL_CWDIR,
                         CD_CMD_LEN ) == (int)NULL ||
                commandArgs[EXECL_SH_CMD][0] == '.'  )
        continue;

      // Something went wrong. Fork did not
      // complete successfully, so we'll try
      // to figure out what happened and let
      // the user know.
      else {

        // Store the error message
        char * forkError = getError();

        printf("Fork not completed.\nError %d: %s",
               errno,
               forkError);

        // Deallocate error string.....
        free(forkError);
      }
    }
    else {

      waitForChildProc ( childProc );
    }

  } while ( TRUE ); // Run the shell session until someone or something stops it.

	return 0;
}
