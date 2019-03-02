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
#include <colortheme.h>

#include "common_share.h"

class segments
{
public:
	segments ();
	virtual ~segments ();

public:
	// int delete_segment_from_list(char* item);
	int register_segment(char* item);
	int get_segment_left_list_common(char** value_list, char* type, segmentaction action);
	int get_segment_right_list_common(char** value_list, char* type, segmentaction action);
	int get_segment_list(char** value_list);
	int get_segment_value_list(char** value_list);
	int get_segment_pvalue_list(char** value_list);
	int get_segment_color_list(char** value_list, segmentaction action);
	int get_segment_output_list(char** value_list, segmentaction action);
	int get_segment_by_name(char* name, segment_unit** unit);
	int get_segment_by_order(unsigned int index);

	int segment_get_foreground(char* name, segment_color** fg_color);
	int segment_get_background(char* name, segment_color** bg_color);
	int segment_set_color(segment_color* s_color);
	int segment_set_side(bool leftside);
	int combile_to_one_line(char** value_list, char* val_left, char* val_right);

private:
	segment_unit **m_unit = NULL;
	segment_unit *current_unit = NULL;
	char** segments_list = NULL;
	unsigned int segments_count = 0;
};


extern class segments m_segments;


#endif


