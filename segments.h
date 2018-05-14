/*
 * =====================================================================================
 *
 *       Filename:  segments.h
 *
 *    Description:  segments header
 *
 *        Version:  1.0
 *        Created:  05/07/2018 04:14:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#ifndef __SEGMENTS_HEADER__
#define __SEGMENTS_HEADER__

#include <basic.h>



class segments
{
public:
	segments ();
	virtual ~segments ();

public:
	// int delete_segment_from_list(char* item);
int register_segment(char* item);
int get_segment_list();
int get_segment_by_name(char* name);
int get_segment_by_order(unsigned int index);
int segment_set_foreground(true_color fg_color);
int segment_set_background(true_color bg_color);
int segment_set_color(true_color fg_color,true_color bg_color);

private:
	char** segments_list = NULL;
	unsigned int segments_count = 0;
};


extern class segments m_segments;


#endif


