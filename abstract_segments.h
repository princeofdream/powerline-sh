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

class abstract_segments
{
public:
	abstract_segments ();
	// virtual ~abstract_segments () = 0;
	~abstract_segments ();

public:
	// virtual int test_vt() = 0;
	virtual int segment_set_value(char* value, true_color fg, true_color bg) = 0;
	int register_segment(char* name);
	int get_segment_list();
	int get_segment_by_name(char* name);
	int get_segment_by_order(unsigned int index);
	int segment_set_foreground(true_color value);
	int segment_set_background(true_color value);

private:
	/* data */
};

#endif /* ifndef __ABSTRACT_SEGMENTS_HEADER__ */



