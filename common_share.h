/*
 * =====================================================================================
 *
 *       Filename:  common_share.h
 *
 *    Description:  common share header
 *
 *        Version:  1.0
 *        Created:  05/23/2018 11:52:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#include <segments.h>

class common_share
{
public:
	common_share ();
	virtual ~common_share ();

	int get_config_file(int* fd, char* name, char* extern_path);
	int init_segment_color(segment_color* s_color);

private:
	/* data */
};


