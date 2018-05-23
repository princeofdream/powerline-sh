/*
 * =====================================================================================
 *
 *       Filename:  theme_basic.h
 *
 *    Description:  theme basic
 *
 *        Version:  1.0
 *        Created:  05/23/2018 01:33:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#ifndef __THEME_BASIC_HEADER__
#define __THEME_BASIC_HEADER__ value

class theme_basic
{
public:
	theme_basic ();
	virtual ~theme_basic ();

private:
	/* data */
	unsigned short USERNAME_FG          = 250;
	unsigned short USERNAME_BG          = 240;
	unsigned short USERNAME_ROOT_BG     = 124;
	unsigned short HOSTNAME_FG          = 250;
	unsigned short HOSTNAME_BG          = 238;
	unsigned short HOME_SPECIAL_DISPLAY = 1;
	unsigned short HOME_BG              = 31;  // blueish
	unsigned short HOME_FG              = 15;  // white
	unsigned short PATH_BG              = 237;  // dark grey
	unsigned short PATH_FG              = 250;  // light grey
	unsigned short CWD_FG               = 254;  // nearly-white grey
	unsigned short SEPARATOR_FG         = 244;
	unsigned short READONLY_BG          = 124;
	unsigned short READONLY_FG          = 254;
	unsigned short SSH_BG               = 166;  // medium orange
	unsigned short SSH_FG               = 254;
	unsigned short REPO_CLEAN_BG        = 148;  // a light green color
	unsigned short REPO_CLEAN_FG        = 0;  // black
	unsigned short REPO_DIRTY_BG        = 161;  // pink/red
	unsigned short REPO_DIRTY_FG        = 15;  // white
	unsigned short JOBS_FG              = 39;
	unsigned short JOBS_BG              = 238;
	unsigned short CMD_PASSED_BG        = 236;
	unsigned short CMD_PASSED_FG        = 15;
	unsigned short CMD_FAILED_BG        = 161;
	unsigned short CMD_FAILED_FG        = 15;
	unsigned short SVN_CHANGES_BG       = 148;
	unsigned short SVN_CHANGES_FG       = 22;  // dark green
	unsigned short GIT_AHEAD_BG         = 240;
	unsigned short GIT_AHEAD_FG         = 250;
	unsigned short GIT_BEHIND_BG        = 240;
	unsigned short GIT_BEHIND_FG        = 250;
	unsigned short GIT_STAGED_BG        = 22;
	unsigned short GIT_STAGED_FG        = 15;
	unsigned short GIT_NOTSTAGED_BG     = 130;
	unsigned short GIT_NOTSTAGED_FG     = 15;
	unsigned short GIT_UNTRACKED_BG     = 52;
	unsigned short GIT_UNTRACKED_FG     = 15;
	unsigned short GIT_CONFLICTED_BG    = 9;
	unsigned short GIT_CONFLICTED_FG    = 15;
	unsigned short GIT_STASH_BG         = 221;
	unsigned short GIT_STASH_FG         = 0;
	unsigned short VIRTUAL_ENV_BG       = 35;  // a mid-tone green
	unsigned short VIRTUAL_ENV_FG       = 00;
	unsigned short BATTERY_NORMAL_BG    = 22;
	unsigned short BATTERY_NORMAL_FG    = 7;
	unsigned short BATTERY_LOW_BG       = 196;
	unsigned short BATTERY_LOW_FG       = 7;
	unsigned short AWS_PROFILE_FG       = 39;
	unsigned short AWS_PROFILE_BG       = 238;
	unsigned short TIME_FG              = 250;
	unsigned short TIME_BG              = 238;
};

#endif /* ifndef __THEME_BASIC_HEADER__ */
