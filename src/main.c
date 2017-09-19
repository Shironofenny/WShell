/* Main entry for WShell
 * 
 * This program is written in my best effort to avoid
 * using classes or implementing classes using structures
 * with absolutely no good reason. I just feel like
 * doing so to have a taste of the barbarian age of 
 * programming.
 */

/* Also, please tolerate my habit of abusing spaces, 
 * and I DO hate tabs more than 2 spaces wide. I
 * understand that this is the standard, but I still
 * hate it.
 */

#include <stdio.h>
#include <string.h>

#include "parser.h"

/* Enumerator for running status */
enum WSHELL_STATUS {RUN, EXIT, ERROR};
enum WSHELL_STATUS runShell();

/* Does anyone care about argc and argv? */
void main(int argc, char ** argv) {
	
	/* Running the main loop */
	enum WSHELL_STATUS rVal = RUN;
	while (rVal != EXIT) {

		rVal = runShell();

	}

}

enum WSHELL_STATUS runShell() {

	/* Print the prompt */
	printf("$ ");

	/* Initialize parameters */
	char command [1024];
	char * fgetsReturnValue;

	fgetsReturnValue = fgets(command, 1024, stdin);
	if ( strcmp(command, "exit\n") == 0) {
		return EXIT;
	} else if ( strcmp(command, "\n") == 0 ) {
	} else {
		printf("%s is not found as a valid command in WShell.\n", command);
	}
	return RUN;
}
