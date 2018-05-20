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

#if 0
int
cwd_segment::segment_set_value(char* value, true_color fg, true_color bg)
{
	JCG("%s",__FUNCTION__);
	return 0;
}
#endif

int
cwd_segment::get_segment_value(char** value)
{
	char cwd_path[MAXLEN];

	JCG("%s",__FUNCTION__);
	getcwd(cwd_path,MAXLEN);
	segment_set_value(cwd_path);

	return 0;
}


