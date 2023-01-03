
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int my_putstr(char const *str);
void my_putchar(char c);
int my_atoi_bsq(char *buffer);
int error_handling(char *buffer);
int is_file_valid(char *buffer);
int my_strlen(char const *str);

#define ERROR_ARG "This proram must take only the path to the file\n"
#define ERROR_FILE "this file is not valid\n"
#define ERROR_OPEN "could not open file\n"


void display(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n')
        i++;
    i++;
    for (; buffer[i] != '\0'; i++)
        my_putchar(buffer[i]);
}

int bsq(char const *filepath)
{
    int rd;
    int fd;
    char *buffer;
    struct stat st;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    stat(filepath, &st);
    buffer = malloc(st.st_size + 1);
    rd = read(fd, buffer, st.st_size);
    if (rd == -1 || rd == 0)
        return (84);
    if (error_handling(buffer) == 84)
        return (84);
    display(buffer);
    free(buffer);
    close(fd);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        write(2, ERROR_ARG, my_strlen(ERROR_ARG));
        return (84);
    }
    if (bsq(av[1]) == 84)
        return (84);
    return (0);
}


int is_file_valid(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n') {
        if (buffer[i] >= '0' && buffer[i] <= '9')
            i++;
        else
            return (84);
    }
    i++;
    while (buffer[i] != '\0') {
        if (buffer[i] == '.' || buffer[i] == 'o' || buffer[i] == '\n')
            i++;
        else
            return (84);
    }
    return (0);
}

int has_correct_char_nbr(char *buffer, int nbr_lines)
{
    int char_in_line = 0;
    int total_char;
    int total_file;
    int j = 0;
    int i;

    while (buffer[j] != '\n')
        j++;
    i = j + 1;
    for (; buffer[i] != '\0'; i++) {
        total_file++;
    }
    i = j + 1;
    for (; buffer[i] != '\n'; i++)
        char_in_line = char_in_line + 1;
    total_char = nbr_lines * char_in_line;
    if (total_char != (total_file - nbr_lines))
        return (84);
    return (0);
}

int correct_nbr_of_lines(char *buffer, int nbr_lines)
{
    int j = 0;
    int lines = 0;

    while (buffer[j] != '\n')
        j++;
    j++;
    for (; buffer[j] != '\0'; j++)
        if (buffer[j] == '\n')
            lines++;
    if (lines != nbr_lines)
        return (84);
    return (0);
}

int error_handling(char *buffer)
{
    int nbr_lines;

    if (is_file_valid(buffer) == 84)
        return (84);
    nbr_lines = my_atoi_bsq(buffer);
    if (has_correct_char_nbr(buffer, nbr_lines) == 84)
        return (84);
    if (correct_nbr_of_lines(buffer, nbr_lines) == 84)
        return (84);
    return (0);
}


int my_atoi_bsq(char *buffer)
{
    int nbr_lines = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        if (buffer[i] >= '0' && buffer[i] <= '9') {
            nbr_lines = nbr_lines * 10;
            nbr_lines = nbr_lines + (buffer[i] - '0');
        }
    return (nbr_lines);
}


void my_putchar(char c)
{
    write(1, &c, 1);
}


int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
