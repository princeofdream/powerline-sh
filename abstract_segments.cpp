/*
 * =====================================================================================
 *
 *       Filename:  abstract_segments.cpp
 *
 *    Description:  abstract_segments
 *
 *        Version:  1.0
 *        Created:  05/09/2018 11:30:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#include "abstract_segments.h"

abstract_segments::abstract_segments()
{
	segments_count = 0;
	segments_list = (char**)malloc(POWERLINE_MAX_SEGMENT);
}

// abstract_segments::~abstract_segments()
// {
// }

int
abstract_segments::powerline_register_segment(char* name)
{
	char** segments_list_store;

	if (name == NULL)
	{
		JEG("name is null, will not add to list!");
		return -1;
	}
	else if (strlen(name) > POWERLINE_SEGMENT_NAME_MAX_LEN) {
		JEG("name too long! will not add to list!");
		return -2;
	}

	segments_list[segments_count] = (char*)malloc(POWERLINE_SEGMENT_NAME_MAX_LEN);
	memset(segments_list[segments_count], 0x0, sizeof(POWERLINE_SEGMENT_NAME_MAX_LEN));
	sprintf(segments_list[segments_count], "%s", name);
	segments_count++;
	return 0;
}

int
abstract_segments::powerline_get_segment_list()
{
	powerline_get_segment_by_name(NULL);
}

int
abstract_segments::powerline_get_segment_by_name(char* name)
{
	int i0 = 0;
	while( i0 < segments_count)
	{
		JCG("--segment[%d]-->%s<--",i0, segments_list[i0]);
		i0++;
	}
	return 0;
}

int
abstract_segments::powerline_get_segment_by_order(unsigned int index)
{
}

int
abstract_segments::powerline_segment_set_foreground(true_color value)
{
	fg_color = value;
	return 0;
}

int
abstract_segments::powerline_segment_set_background(true_color value)
{
	bg_color = value;
	return 0;
}

int
abstract_segments::powerline_free_all()
{
	int i0 = 0;
	while (i0 < segments_count)
	{
		free(segments_list[i0]);
		i0++;
	}
	free(segments_list);
}

