/*
 * =====================================================================================
 *
 *       Filename:  debug_utils.h
 *
 *    Description:  debug utils header
 *
 *        Version:  1.0
 *        Created:  03/02/2019 04:54:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */


#ifndef __DEBUG_UTILS_HEADER__
#define __DEBUG_UTILS_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>
#include <stdarg.h>
#include <basic.h>

class debug_utils
{
public:
	debug_utils ();
	virtual ~debug_utils ();

	static int log(char* format, ...);

private:
	/* data */
};

#endif /* ifndef __DEBUG_UTILS_HEADER__ */

