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
	if (segment_name != NULL)
	{
		free(segment_name);
	}
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
	sprintf(segment_value,"%s",value);
	get_segment_by_name(segment_name, &unit);
	JCG("set value to: %s",value);
	if (unit->value == NULL)
		unit->value = (char*)malloc(MAXLEN);
	memset(unit->value,0x0,MAXLEN);
	sprintf(unit->value,"%s",value);
	JCG("\nget segment info\nname:\t%s\nvalue:\t%s\npvalue:\t%s\nindex:\t%d",unit->name, unit->value,unit->pvalue,unit->index);

	return 0;
}

int
abstract_segments::register_segment(char* name)
{
	memset(segment_name,0x0,sizeof(segment_name));
	sprintf(segment_name,"%s",name);
	m_segments.register_segment(name);
	get_segment_value(&name);
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

int
abstract_segments::segment_set_foreground(true_color value)
{
	return 0;
}

int
abstract_segments::segment_set_background(true_color value)
{
	return 0;
}


