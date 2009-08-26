#include <string.h>
#include <stdio.h>
#include <gpxe/command.h>
#include <gpxe/input_ui.h>

FILE_LICENCE ( GPL2_OR_LATER );

static int input_exec ( int argc, char **argv ) {
	int rc;

	if ( argc != 3 ) {
		printf ( "Usage: %s <setting> <prompt>\n"
			 "Prompt for arbitrary input string and store it in setting\n", argv[0] );
		return 1;
	}

	if ( ( rc = input_ui(argv[1], argv[2]) ) != 0 ) {
		printf ( "Could not get input: %s\n",
			 strerror ( rc ) );
		return 1;
	}

	return 0;
}

struct command input_command __command = {
	.name = "input",
	.exec = input_exec,
};
