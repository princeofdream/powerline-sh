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
	// JCG("segment [%s] address: 0x%x, name address: 0x%x, value: 0x%x",m_unit[segments_count]->name, m_unit[segments_count], m_unit[segments_count]->name, m_unit[segments_count]->value);
	m_unit[segments_count] = (segment_unit*)malloc(sizeof(segment_unit));
	m_unit[segments_count]->name = (char*)malloc(strlen(item)+1);
	m_unit[segments_count]->value = (char*)malloc(MAXLEN);
	m_unit[segments_count]->pvalue = (char*)malloc(MAXLEN);
	m_unit[segments_count]->index = segments_count;
	sprintf(m_unit[segments_count]->name, "%s", item);
	JCG("segment [%s] address: 0x%x, name address: 0x%x, value: 0x%x",m_unit[segments_count]->name, m_unit[segments_count], m_unit[segments_count]->name, m_unit[segments_count]->value);
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
segments::get_segment_list_common(char** value_list, char* type)
{
	int i0 = 0;
	char item_value[MAXLEN];

	*value_list = (char*)malloc(MAXLEN*2);
	memset(*value_list, 0x0, MAXLEN*2);

	JCG();
	if (type == NULL)
	{
		JEG("get list type can not be NULL");
		return -1;
	}

	while( i0 < segments_count )
	{
		memset(item_value, 0x0, sizeof(item_value));
		if (strcmp(type, "name") == 0 && m_unit[i0]->name != NULL)
		{
			sprintf(item_value,"%s",m_unit[i0]->name);
		}
		else if (strcmp(type, "value") == 0 && m_unit[i0]->value != NULL)
		{
			sprintf(item_value,"%s",m_unit[i0]->value);
		}
		else if (strcmp(type, "pvalue") == 0 && m_unit[i0]->pvalue != NULL)
		{
			sprintf(item_value,"%s",m_unit[i0]->pvalue);
		}
		else
		{
			i0++;
			continue;
		}

		if (strlen(*value_list) <= 0)
			sprintf(*value_list,"%s",item_value);
		else if (strlen(item_value) > 0)
			sprintf(*value_list,"%s%s%s",*value_list,SEPERATE_SYMBOL,item_value);
		i0++;
	}
	return 0;
}

int
segments::get_segment_list(char** value_list)
{
	get_segment_list_common(value_list,"name");
	return 0;
}

int
segments::get_segment_value_list(char** value_list)
{
	get_segment_list_common(value_list,"value");
	return 0;
}

int
segments::get_segment_pvalue_list(char** value_list)
{
	get_segment_list_common(value_list,"pvalue");
}

int
segments::get_segment_by_name(char* name, segment_unit** unit)
{
	int i0 = 0;
	while( i0 < segments_count )
	{
		// JCG("segments[%d] name:%s",i0,m_unit[i0]->name);
		/* *unit = (segment_unit*)malloc(sizeof(segment_unit)); */
		// memcpy(*unit,m_unit[i0],sizeof(segment_unit));
		JCG("segment [%s] address: 0x%x, name address: 0x%x, value: 0x%x",m_unit[i0]->name, m_unit[i0], m_unit[i0]->name, m_unit[i0]->value);
		if(name == NULL)
		{
			JCG("segments[%d] name:%s",i0,m_unit[i0]->name);
		}
		else if (strcmp(m_unit[i0]->name, name) == 0)
		{
			*unit = m_unit[i0];
			break;
		}
		i0++;
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


