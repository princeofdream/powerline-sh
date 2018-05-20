/*
 * =====================================================================================
 *
 *       Filename:  segments.cpp
 *
 *    Description:  segments
 *
 *        Version:  1.0
 *        Created:  05/07/2018 04:09:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#include <segments.h>

class segments m_segments;

segments::segments()
{
	JCG("%s",__FUNCTION__);
	segments_count = 0;
	segments_list = (char**)malloc(MAX_SEGMENTS);
#if 1
	m_unit = (segment_unit**)malloc(MAX_SEGMENTS);
#endif
	JCG("segment unit size:%d",sizeof(segment_unit));
}

segments::~segments()
{
	int i0 = 0;
	JCG("%s",__FUNCTION__);
	free(segments_list);
#if 1
	while(i0 < segments_count)
	{
		if (m_unit != NULL)
			free(m_unit[i0]);
		i0++;
	}
#endif
}


int
segments::register_segment(char* item)
{
	if (item == NULL)
	{
		JEG("item is null, will not add to list!");
		return -1;
	}
	else if (strlen(item) > SEGMENT_NAME_MAX_LEN) {
		JEG("item name too long! will not add to list!");
		return -2;
	}

#if 1
	m_unit[segments_count] = (segment_unit*)malloc(sizeof(segment_unit));
	m_unit[segments_count]->name = (char*)malloc(strlen(item)+1);
	m_unit[segments_count]->index = segments_count;
	sprintf(m_unit[segments_count]->name, "%s", item);
#else
	segments_list[segments_count] = (char*)malloc(SEGMENT_NAME_MAX_LEN);
	memset(segments_list[segments_count], 0x0, sizeof(SEGMENT_NAME_MAX_LEN));
	sprintf(segments_list[segments_count], "%s", item);

#if 0
	m_unit[segments_count].name = (char*)malloc(strlen(item)+1);
	m_unit[segments_count].index = 0;
	memset(m_unit[segments_count].name,0x0,strlen(item)+1);
	sprintf(m_unit[segments_count].name,"%s",item);
#endif
#endif
	segments_count++;
	return 0;
}

int
segments::get_segment_list()
{
	get_segment_by_name(NULL, NULL);
}

int
segments::get_segment_by_name(char* name, segment_unit** unit)
{
	int i0 = 0;
	if (name == NULL)
	{
		while( i0 < segments_count )
		{
#if 1
			JCG("segments[%d] name:%s",i0,m_unit[i0]->name);
#else
			JCG("segments[%d] name:%s",i0,segments_list[i0]);
#endif
			i0++;
		}
	}
	else
	{
		while( i0 < segments_count )
		{
			// JCG("segments[%d] name:%s",i0,m_unit[i0]->name);
			/* *unit = (segment_unit*)malloc(sizeof(segment_unit)); */
			// memcpy(*unit,m_unit[i0],sizeof(segment_unit));
			if (strcmp(m_unit[i0]->name, name) == 0)
			{
				*unit = m_unit[i0];
			}
			i0++;
		}
	}
	return 0;
}

int
segments::get_segment_by_order(unsigned int index)
{
	return 0;
}

int
segments::segment_set_foreground(true_color fg_color)
{
	return 0;
}

int
segments::segment_set_background(true_color bg_color)
{
	return 0;
}

int
segments::segment_set_color(true_color fg_color,true_color bg_color)
{
	return 0;
}


