/*
 * =====================================================================================
 *
 *       Filename:  common_segment_manager.h
 *
 *    Description:  common_segment_manager.h
 *
 *        Version:  1.0
 *        Created:  05/09/2018 11:26:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */


#ifndef __COMMON_SEGMENT_MANAGER_HEADER__
#define __COMMON_SEGMENT_MANAGER_HEADER__

#include <basic.h>
#include <abstract_segments.h>


// class common_segment_manager
class common_segment_manager :public abstract_segments
{
public:
	common_segment_manager ();
	virtual ~common_segment_manager ();

public:
	// int segment_set_value(char* value, true_color fg, true_color bg);
	int get_segment_value(char** value);
private:
	/* data */
};


#endif /* ifndef __COMMON_SEGMENT_MANAGER_HEADER__ */



