#include "xio.h"
#include <stdio.h>
#include <stdlib.h>

#define XIO_BFSIZE 128U
#define XIO_TRYS 10U

static const char* xiotxt_wrongNumericInput = NULL;
static const char* xiotxt_pauseEnter = "< PRESS ENTER >";

size_t __getline(char* buff, size_t bfSize)
{
    int c = -1;
    size_t readed = 0;
    do {
        if (c >= 32 && readed < bfSize - 1)
			{
				buff[readed] = (char)c;
				if (c != '\n')
					readed++;
			}
        c = getc(stdin);
        if (c == '\r')
            c = '\n';
    } while (c != '\n' && c != EOF);
    buff[readed] = '\0';
    return readed;
}

void xio_print(const char* fmt, ...)
{
    va_list ap;
	if (fmt)
    {
        va_start(ap, fmt);
		vprintf(fmt, ap);
        va_end(ap);
    }
	return;
}

size_t xio_str(char* buff, size_t bfSize, const char* fmt, ...)
{
    va_list ap;
	if (fmt)
    {
        va_start(ap, fmt);
		vprintf(fmt, ap);
        va_end(ap);
    }
	return __getline(buff, bfSize);
}

int xio_i(const char* fmt, ...)
{
    va_list ap;
	char buff[XIO_BFSIZE];
	int ret;
	for (size_t i = 0; i < XIO_TRYS; i++)
	{
		if (fmt)
        {
            va_start(ap, fmt);
            vprintf(fmt, ap);
            va_end(ap);
        }
		__getline(buff, XIO_BFSIZE);
		ret = (int)strtol(buff, NULL, 10);
		if (ret || (ret == 0 && buff[0] == '0'))
			return ret;
        if (xiotxt_wrongNumericInput)
            printf("%s\n", xiotxt_wrongNumericInput);
	}
	return 0;
}

long xio_l(const char* fmt, ...)
{
    va_list ap;
	char buff[XIO_BFSIZE];
	long ret;
	for (size_t i = 0; i < XIO_TRYS; i++)
	{
		if (fmt)
        {
            va_start(ap, fmt);
            vprintf(fmt, ap);
            va_end(ap);
        }
		__getline(buff, XIO_BFSIZE);
		ret = strtol(buff, NULL, 10);
		if (ret || (ret == 0L && buff[0] == '0'))
			return ret;
		if (xiotxt_wrongNumericInput)
            printf("%s\n", xiotxt_wrongNumericInput);
	}
	return 0L;
}

unsigned int xio_u(const char* fmt, ...)
{
    va_list ap;
	char buff[XIO_BFSIZE];
	unsigned int ret;
	for (size_t i = 0; i < XIO_TRYS; i++)
	{
		if (fmt)
        {
            va_start(ap, fmt);
            vprintf(fmt, ap);
            va_end(ap);
        }
		__getline(buff, XIO_BFSIZE);
		ret = (unsigned int)strtoul(buff, NULL, 10);
		if (ret || (ret == 0U && buff[0] == '0'))
			return ret;
		if (xiotxt_wrongNumericInput)
            printf("%s\n", xiotxt_wrongNumericInput);
	}
	return 0U;
}

unsigned long xio_ul(const char* fmt, ...)
{
    va_list ap;
	char buff[XIO_BFSIZE];
	unsigned long ret;
	for (size_t i = 0; i < XIO_TRYS; i++)
	{
		if (fmt)
        {
            va_start(ap, fmt);
            vprintf(fmt, ap);
            va_end(ap);
        }
		__getline(buff, XIO_BFSIZE);
		ret = strtoul(buff, NULL, 10);
		if (ret || (ret == 0UL && buff[0] == '0'))
			return ret;
		if (xiotxt_wrongNumericInput)
            printf("%s\n", xiotxt_wrongNumericInput);
	}
	return 0UL;
}

float xio_f(const char* fmt, ...)
{
    va_list ap;
	char buff[XIO_BFSIZE];
	float ret;
	for (size_t i = 0; i < XIO_TRYS; i++)
	{
		if (fmt)
        {
            va_start(ap, fmt);
            vprintf(fmt, ap);
            va_end(ap);
        }
		__getline(buff, XIO_BFSIZE);
		ret = strtof(buff, NULL);
		if (ret != 0.0F || (ret == 0.0F && buff[0] == '0'))
			return ret;
		if (xiotxt_wrongNumericInput)
            printf("%s\n", xiotxt_wrongNumericInput);
	}
	return 0.0F;
}

double xio_d(const char* fmt, ...)
{
    va_list ap;
	char buff[XIO_BFSIZE];
	double ret;
	for (size_t i = 0; i < XIO_TRYS; i++)
	{
		if (fmt)
        {
            va_start(ap, fmt);
            vprintf(fmt, ap);
            va_end(ap);
        }
		__getline(buff, XIO_BFSIZE);
		ret = strtod(buff, NULL);
		if (ret != 0.0 || (ret == 0.0 && buff[0] == '0'))
			return ret;
		if (xiotxt_wrongNumericInput)
            printf("%s\n", xiotxt_wrongNumericInput);
	}
	return 0.0;
}

long double xio_ld(const char* fmt, ...)
{
    va_list ap;
	char buff[XIO_BFSIZE];
	long double ret;
	for (size_t i = 0; i < XIO_TRYS; i++)
	{
		if (fmt)
        {
            va_start(ap, fmt);
            vprintf(fmt, ap);
            va_end(ap);
        }
		__getline(buff, XIO_BFSIZE);
		ret = strtold(buff, NULL);
		if (ret != 0.0L || (ret == 0.0L && buff[0] == '0'))
			return ret;
		if (xiotxt_wrongNumericInput)
            printf("%s\n", xiotxt_wrongNumericInput);
	}
	return 0.0L;
}

void xio_pause()
{
    if (xiotxt_pauseEnter)
        printf("\n%s\n", xiotxt_pauseEnter);
    getchar();
	return;
}

void xio_setTxt_wrongNumericInput(const char* text)
{
    xiotxt_wrongNumericInput = text;
    return;
}

void xio_setTxt_pauseMessage(const char* text)
{
    xiotxt_pauseEnter = text;
    return;
}
