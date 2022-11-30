#ifndef XIO_LIBRARY
#define XIO_LIBRARY

/*
 *  C console input & output utilities.
 *  https://github.com/ezenicofogar/xio-lib
*/

#include <stddef.h>
#include <stdarg.h>

// Print formated text.
void xio_print(const char* fmt, ...);

// Get string. Print formated text. Returns char count.
size_t xio_str(char* buff, size_t bfSize, const char* fmt, ...);

// Get int. Print formated text.
int xio_i(const char* fmt, ...);

// Get long. Print formated text.
long xio_l(const char* fmt, ...);

// Get unsigned int. Print formated text.
unsigned int xio_u(const char* fmt, ...);

// Get unsigned long. Print formated text.
unsigned long xio_ul(const char* fmt, ...);

// Get float. Print formated text.
float xio_f(const char* fmt, ...);

// Get double. Print formated text.
double xio_d(const char* fmt, ...);

// Get long double. Print formated text.
long double xio_ld(const char* fmt, ...);

// Prompt to press ENTER.
void xio_pause();

// Set the text shown when user input is not correctly written.
void xio_setTxt_wrongNumericInput(const char* text);

// Set the text shown when xio_pause() is called.
void xio_setTxt_pauseMessage(const char* text);

#endif // ndef XIO_LIBRARY
