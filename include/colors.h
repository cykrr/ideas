#ifndef colors_h
#define colors_h
#include "util.h"
#define COLOR_WHITE (Color){0xff,0xff,0xff,0xff}
#define COLOR_GREY (Color){0x40,0x40,0x40,0xff}
#define COLOR_RED (Color){0xff,0x20,0x20,0xff}
#define COLOR_GREEN (Color){0x00,0xff,0x00,0xff}

#define COLOR_RANDOM (Color){                    \
    (unsigned char)random_number(0x00, 255),     \
        (unsigned char)random_number(0x00, 255), \
        (unsigned char)random_number(0x00, 255), \
        (unsigned char)random_number(0x20, 0xff) \
}
#endif
