//
// Created by pad on 1/3/23.
//

#ifndef BSQ_BSQ_ERROR_H
#define BSQ_BSQ_ERROR_H

#define ERROR_CANT_OPEN_FILE 1
#define ERROR_CANT_READ_FILE 2
#define ERROR_INVALID_PATTERN 3
#define ERROR_CANT_ALLOCATE_MEMORY 4

/**
 * Print a message linked to "errcode" and add content of "context" in it
 * @param errcode The error code as defined in bsq.h
 * @param context Some context to add to the error (eg. filename)
 * @return errcode
 */
int print_error(int errcode, const char* context);

#endif //BSQ_BSQ_ERROR_H
