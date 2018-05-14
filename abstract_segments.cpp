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
}

abstract_segments::~abstract_segments()
{
	JCG("%s",__FUNCTION__);
}

int
abstract_segments::register_segment(char* name)
{
	m_segments.register_segment(name);
	return 0;
}

int
abstract_segments::get_segment_list()
{
	m_segments.get_segment_list();
	return 0;
}

int
abstract_segments::get_segment_by_name(char* name)
{
	m_segments.get_segment_by_name(name);
	return 0;
}

int
abstract_segments::get_segment_by_order(unsigned int index)
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


