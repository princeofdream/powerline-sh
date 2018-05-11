/*
 * =====================================================================================
 *
 *       Filename:  cwd_segment.cpp
 *
 *    Description:  cwd_segment
 *
 *        Version:  1.0
 *        Created:  05/09/2018 11:25:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#include <cwd_segment.h>

cwd_segment::cwd_segment ()
{
	JCG("%s",__FUNCTION__);
}


cwd_segment::~cwd_segment ()
{
	JCG("%s",__FUNCTION__);
}

int
cwd_segment::powerline_segment_set_value(char* value, true_color fg, true_color bg)
{
	printf("by JamesL<%s:%d>\n",__FILE__,__LINE__);
	return 0;
}



