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

#ifndef __COMMON_SHARE_HEADER__
#define __COMMON_SHARE_HEADER__

#include <basic.h>

class common_share
{
public:
	common_share ();
	virtual ~common_share ();

	int get_config_file(int* fd, char* name, char* extern_path);
	int init_segment_color(segment_color* s_color);
	int run_cmd(char* cmd, char** result);
	int command_stream(char* cmd, char** result);

	int GetLocalTime(char** value);
	int Conv_Time_Set_to_String(struct tm *m_tm, char** value);

private:
	/* data */
};

#endif /* ifndef __COMMON_SHARE_HEADER__ */

