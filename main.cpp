/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  main
 *
 *        Version:  1.0
 *        Created:  05/07/2018 03:56:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "basic.h"
#include "colortheme.h"
#include "cwd_segment.h"

class colortheme m_colortheme;
class cwd_segment m_cwd;

int main(int argc, char *argv[])
{
	int i0 = 0, i1 = 0;
	char string_content[1024];
	int style;
	true_color fg;
	true_color bg;

	memset(string_content,0x0,sizeof(string_content));
	style = 38;
	// sprintf(string_content,"\e[%d;%d;%dm=======\n",i0,5,48);
	// printf("\e[38;5;%dm\e[48;5;240m test[%d] \e[48;5;166m\e[38;5;%dm\n",i0,i0,i0);

	m_colortheme.show_color_map();
	m_cwd.powerline_set_segment_value(NULL,fg,bg);
	return 0;
}


