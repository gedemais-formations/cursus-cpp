#ifndef ERROR_LIB
#define ERROR_LIB

#include <stdbool.h>

enum e_error_id {
  ERROR_NONE,
  ERROR_MEM,
  ERROR_POINTER,
  ERROR_BOARD,
  ERROR_MAX
};

typedef struct s_error {
  char msg[64];  // Error message
} t_error;

static const t_error errors[ERROR_MAX] = {
    [ERROR_MEM] = {"Memory allocation failed\n"},
    [ERROR_POINTER] = {"NULL Pointer\n"},
    [ERROR_BOARD] = {"The board is not right\n"},
};

#endif
