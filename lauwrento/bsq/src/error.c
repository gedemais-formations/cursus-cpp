#include <error.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
/*
 * This function is designed to display error messages depending
 * on the value return by the error chain, if anyone.
 */

void	error_handler(unsigned char code)
{ // Usage message
	const char	*msg;
	printf("%d", code);

	if (code >= ERROR_MAX) // If code does not correspond to any existing code
		return ;

	msg = &errors[code].msg[0]; // Get the current error message

	// Display it
	if (write(2, "Program : ", 10) == 0
		|| write(2, "error : ", 8) == 0
		|| write(2, msg, strlen(msg)) == 0
		|| write(2, "\n", 1) == 0)
		return ;

}
