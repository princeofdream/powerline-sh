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

#if 0
int
host_segment::segment_set_value(char* value, true_color fg, true_color bg)
{
	JCG();
	return 0;
}
#endif


int
host_segment::get_segment_value(char* name, char** value)
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

