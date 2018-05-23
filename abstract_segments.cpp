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

#include <abstract_segments.h>

abstract_segments::abstract_segments()
{
	// m_segments = new segments();
	JCG("%s",__FUNCTION__);
	memset(segment_name,0x0,sizeof(segment_name));
	memset(segment_value,0x0,sizeof(segment_value));
	memset(segment_color_value,0x0,sizeof(segment_color_value));
}

abstract_segments::~abstract_segments()
{
	JCG("%s",__FUNCTION__);
}

int
abstract_segments::segment_set_value_with_color(char* value, true_color fg, true_color bg)
{
	return 0;
}

int
abstract_segments::segment_set_value(char* value)
{
	segment_unit *unit;

	memset(segment_value,0x0,sizeof(segment_value));
	sprintf(segment_value,"%s",value);
	get_segment_by_name(segment_name, &unit);

	if (value != NULL)
	{
		memset(unit->value,0x0,MAXLEN);
		sprintf(unit->value,"%s",value);
		// memcpy(unit->value,value,strlen(value)+1);
		JCG("\nget segment info\nname:\t%s\nvalue:\t%s\npvalue:\t%s\nindex:\t%d",unit->name, unit->value,unit->pvalue,unit->index);
		// JCG("segment [%s] address: 0x%x, name address: 0x%x, value: 0x%x",unit->name, unit, unit->name, unit->value);
	}
	else
	{
		JEG("value is NULL!");
		return -1;
	}

	return 0;
}

int
abstract_segments::register_segment(char* name)
{
	char* value = NULL;
	segment_color* m_color = NULL;

	memset(segment_value,0x0,sizeof(segment_value));
	memset(segment_name,0x0,sizeof(segment_name));

	sprintf(segment_name,"%s",name);
	m_segments.register_segment(name);
	segment_get_value(name, &value);
	JCG("%s get value---->%s",name, value);
	if (value != NULL)
	{
		JCG("value:%s",value);
		segment_set_value(value);
		free(value);
		value = NULL;
	}
	segment_get_foreground(&m_color);
	if (m_color != NULL)
	{
		// JCG("color: %d",m_color->red);
		// JCG("m_color:%s",m_color);
		free(m_color);
		m_color = NULL;
	}
	return 0;
}

int
abstract_segments::get_segment_list(char** value_list)
{
	m_segments.get_segment_list(value_list);
	return 0;
}

int
abstract_segments::get_segment_value_list(char** value_list)
{
	m_segments.get_segment_value_list(value_list);
	return 0;
}

int
abstract_segments::get_segment_pvalue_list(char** value_list)
{
	m_segments.get_segment_pvalue_list(value_list);
	return 0;
}

int
abstract_segments::get_segment_by_name(char* name, segment_unit** unit)
{
	m_segments.get_segment_by_name(name,unit);
	return 0;
}

int
abstract_segments::get_segment_by_order(unsigned int index, segment_unit** unit)
{
	m_segments.get_segment_by_order(index);
	return 0;
}

#if 0
int
abstract_segments::segment_get_foreground(true_color value)
{
	return 0;
}

int
abstract_segments::segment_get_background(true_color value)
{
	return 0;
}
#endif

