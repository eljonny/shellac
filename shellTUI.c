/*
 * This program component is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Jonathan Hyry
 * Date Originally Written: 1/30/2012
 */

#include "shellTUIHdr.h"

/*
 * Function cursorWait is the actual shell prompt
 * and command parsing engine.
 */
pid_t cursorWait ( void ) {

  // Here is the shell prompt
  printf("\n%s", SHELL_PROMPT);

  fgets(commandArgs[EXECL_SH_CMD],
        INPUT_ARG_SIZE,
        stdin);

#ifdef DEBUG
  /*Normal output*/
  printf("Command string: %s", commandArgs[EXECL_SH_CMD]);
#endif

  // If user entered built-in command exit...
  if ( strstr ( commandArgs[EXECL_SH_CMD], SHELL_EXIT ) != NULL )
    return -1;

  // If the input command is a shell script
  else if ( commandArgs[EXECL_SH_CMD][0] == '.' ) {

    runShellacCommandBatch ( strtok ( commandArgs[EXECL_SH_CMD], "\n" ) );

    printf("Batch run finished for file %s.", commandArgs[EXECL_SH_CMD]);
    return -1;
  }

  // If the user entered cd < path >...
  else if ( memcmp ( commandArgs[EXECL_SH_CMD],
                     &SHELL_CWDIR,
                     CD_CMD_LEN ) == (int)NULL  ) {

    // Allocate space for the directory path substring
    dirStr =
      (char *)malloc(INPUT_ARG_SIZE*sizeof(char));

    // Clean up the newly allocated memory
    memset (dirStr,
            (int)NULL,
            strlen(commandArgs[EXECL_SH_CMD])*sizeof(char));

#ifdef DEBUG
    // DEBUG Normal output
    printf("\nCommand string: %s", commandArgs[EXECL_SH_CMD]);
#endif

    if ( strstr ( commandArgs[EXECL_SH_CMD], " " ) == NULL )
      pathLength = 0;

    else {

      // The length of the actual path string in the substring
      pathLength =
        strlen ( strstr ( commandArgs[EXECL_SH_CMD], " " ) ) - 2;
    }

    if ( pathLength == 0)
      strcpy(dirStr,
             getenv("HOME"));

    else {

#ifdef DEBUG
      // DEBUG Detected string path length
      printf("Detected path length: %d\n", pathLength);
#endif

      // Address to the first char in the substring
      subStrAddress =
        strstr(commandArgs[EXECL_SH_CMD], " ");

      // Copy the path string into dirStr
      if(*++subStrAddress == '~' && pathLength > 2) {

        getTildeHomePath ( subStrAddress, /* Parses this string into a readable
                                           * home folder subdirectory path */
                           dirStr,        /* Returns the resulting path here */
                           pathLength - 1 /* Length of subdirectory path */     );
      }

      else if (*subStrAddress == '~')
        strcpy(dirStr,
               getenv("HOME"));
      else
        strncpy(dirStr,
                subStrAddress,
                pathLength);
#ifdef DEBUG
      // DEBUG Computed substring address
      printf("SubStr address: 0x%x\n", (unsigned int)subStrAddress);

      // DEBUG A lot better... still not really there yet.*/
      printf("Passing the following to chdir(): %s\n", dirStr);
#endif
    }

    // Try to change the working directory
    if ( chdir(dirStr) < 0) {
      char * chDirErr = getError();
      printf("Error %d: %s", errno, chDirErr);
      free(chDirErr);
    }
    else {

      // Get and print the Present working directory
      pwdir = get_current_dir_name();
      printf("\n%s\n", pwdir);

      // Memory management
      free(pwdir);
    }
#ifdef DEBUG
    // DEBUG Value before deallocation*/
    printf("\nDeallocating: %s\n", dirStr);

    // Deallocate directory path string
    free(dirStr);
#endif

    return -1;
  }

  // If the arguments entered are not a built-in command,
  // fork this process.
  return fork();
}
