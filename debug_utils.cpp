/*
 * =====================================================================================
 *
 *       Filename:  debug_utils.cpp
 *
 *    Description:  debug utils
 *
 *        Version:  1.0
 *        Created:  03/02/2019 04:54:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */


#include "debug_utils.h"


debug_utils::debug_utils()
{
}

debug_utils::~debug_utils()
{
}

int debug_utils::log(char* format, ...)
{
	va_list arg;
	va_start(arg, format);

	while (*format)
	{
		char ret = *format;
		if (ret == '%')
		{
			printf("---%s:%d--%s-\n",__FILE__,__LINE__,format);
			switch (*++format)
			{
			case 'c':
				{
					char ch = va_arg(arg, char);
					putchar(ch);
					break;
				}
			case 's':
				{
					char *pc = va_arg(arg, char *);
					printf("%s", pc);
					break;
				}
			case 'x':
				{
					char ch = va_arg(arg, char);
					printf("%x",ch);
					break;
				}
			default:
				break;
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(arg);
}

