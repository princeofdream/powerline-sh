/*
 * =====================================================================================
 *
 *       Filename:  host_segment.h
 *
 *    Description:  host segment header
 *
 *        Version:  1.0
 *        Created:  05/11/2018 02:40:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */


#ifndef __HOST_SEGMENT_HEADER__
#define __HOST_SEGMENT_HEADER__

#include <basic.h>
#include <abstract_segments.h>

class host_segment :public abstract_segments
{
public:
	host_segment ();
	virtual ~host_segment ();

public:
	// int segment_set_value(char* value, true_color fg, true_color bg);
	int get_segment_value(char** value);
private:
	/* data */
};

#endif /* ifndef __HOST_SEGMENT_HEADER__ */



