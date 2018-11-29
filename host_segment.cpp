/*
 * =====================================================================================
 *
 *       Filename:  host_segment.cpp
 *
 *    Description:  host_segment
 *
 *        Version:  1.0
 *        Created:  05/11/2018 02:40:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#include <host_segment.h>


host_segment::host_segment()
{
	JCG("%s",__FUNCTION__);
}

host_segment::~host_segment()
{
	JCG("%s",__FUNCTION__);
}

int
host_segment::segment_get_foreground(char* name, segment_color** value)
{
	return 0;
}

int
host_segment::segment_get_background(char* name, segment_color** value)
{
	return 0;
}

int
host_segment::segment_get_value(char* name, char** value, void* param)
{
	char host_name[MAXLEN];

	JCG("%s",__FUNCTION__);
	gethostname(host_name,MAXLEN);

	if (host_name!= NULL && strlen(host_name) > 0)
	{
#if 1
		*value = (char*)malloc(MAXLEN);
		sprintf(*value,"%s",host_name);
#else
		segment_set_value(host_name);
#endif
	}

	return 0;
}

int
host_segment::segment_get_color(char* fg_color_name, char* bg_color_name, segment_color* value)
{
	return 0;
}


