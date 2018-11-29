/*
 * =====================================================================================
 *
 *       Filename:  abstract_segments.h
 *
 *    Description:  abstract_segments
 *
 *        Version:  1.0
 *        Created:  05/09/2018 11:31:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */


#ifndef __ABSTRACT_SEGMENTS_HEADER__
#define __ABSTRACT_SEGMENTS_HEADER__

#include <basic.h>
#include <segments.h>
#include <colortheme.h>

class abstract_segments
{
public:
	abstract_segments ();
	// virtual ~abstract_segments () = 0;
	~abstract_segments ();

public:
	// virtual int test_vt() = 0;
	int segment_set_value_with_color(char* value, true_color fg, true_color bg);
	int segment_set_value(char* value);
	int register_segment(char* name, segment_color *s_color, void* param);
	int get_segment_list(char** value_list);
	int get_segment_value_list(char** value_list);
	int get_segment_pvalue_list(char** value_list);
	int get_segment_color_list(char** value_list, segmentaction action);
	int get_segment_output_list(char** value_list, segmentaction action);
	int get_segment_by_name(char* name, segment_unit** unit);
	int get_segment_by_order(unsigned int index, segment_unit** unit);

	int on_segment_change(int action);

	virtual int segment_get_foreground(char* name, segment_color** value) = 0;
	virtual int segment_get_background(char* name, segment_color** value) = 0;
	virtual int segment_get_value(char* name, char** value, void* param) = 0;
	virtual int segment_get_color(char* fg_color_name, char* bg_color_name, segment_color* value) = 0;

private:
	/* data */
	char segment_name[SEGMENT_NAME_MAX_LEN];
	char segment_value[MAXLEN];
	char segment_color_value[MAXLEN];
	segment_unit* unit;
};

#endif /* ifndef __ABSTRACT_SEGMENTS_HEADER__ */



