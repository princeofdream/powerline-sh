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

#include "basic.h"

class abstract_segments
{
public:
	abstract_segments ();
	// virtual ~abstract_segments () = 0;

public:
	// virtual int test_vt() = 0;
	virtual int powerline_segment_set_value(char* value, true_color fg, true_color bg) = 0;
	int powerline_register_segment(char* name);
	int powerline_get_segment_list();
	int powerline_get_segment_by_name(char* name);
	int powerline_get_segment_by_order(unsigned int index);
	int powerline_segment_set_foreground(true_color value);
	int powerline_segment_set_background(true_color value);
	int powerline_free_all();

protected:
	true_color fg_color;
	true_color bg_color;
private:
	char** segments_list = NULL;
	unsigned int segments_count = 0;
	/* data */
};

#endif /* ifndef __ABSTRACT_SEGMENTS_HEADER__ */



