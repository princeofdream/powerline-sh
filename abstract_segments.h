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
	// abstract_segments ();
	// virtual ~abstract_segments () = 0;

public:
	// virtual int test_vt() = 0;
	virtual int powerline_set_segment_value(char* value, true_color fg, true_color bg) = 0;

private:
	/* data */
};

#endif /* ifndef __ABSTRACT_SEGMENTS_HEADER__ */



