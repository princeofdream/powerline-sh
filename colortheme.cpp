/*
 * =====================================================================================
 *
 *       Filename:  colortheme.cpp
 *
 *    Description:  color theme
 *
 *        Version:  1.0
 *        Created:  05/07/2018 04:28:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */
#include <colortheme.h>
#include <common_share.h>

#define THEME_DEFAULT
#define THEME_DARK

#ifdef THEME_DARK
	#undef THEME_LIGHT
#else
	#define THEME_LIGHT
#endif


theme_color_map combile_color_map[MAX_THEME_SIZE];
theme_color_map default_theme[] =
{
	{ "HOME_SPECIAL_DISPLAY" , 1   } ,
	{ "HOME_BG"              , 31  } ,  // blueish
	{ "HOME_FG"              , 15  } ,  // white
	{ "SVN_CHANGES_BG"       , 148 } ,
	{ "SVN_CHANGES_FG"       , 22  } ,  // dark green
	{ "GIT_AHEAD_BG"         , 240 } ,
	{ "GIT_AHEAD_FG"         , 250 } ,
	{ "GIT_BEHIND_BG"        , 240 } ,
	{ "GIT_BEHIND_FG"        , 250 } ,
	{ "GIT_STAGED_BG"        , 22  } ,
	{ "GIT_STAGED_FG"        , 15  } ,
	{ "GIT_NOTSTAGED_BG"     , 130 } ,
	{ "GIT_NOTSTAGED_FG"     , 15  } ,
	{ "GIT_UNTRACKED_BG"     , 52  } ,
	{ "GIT_UNTRACKED_FG"     , 15  } ,
	{ "GIT_CONFLICTED_BG"    , 9   } ,
	{ "GIT_CONFLICTED_FG"    , 15  } ,
	{ "GIT_STASH_BG"         , 221 } ,
	{ "GIT_STASH_FG"         , 0   } ,
	{ "BATTERY_NORMAL_BG"    , 22  } ,
	{ "BATTERY_NORMAL_FG"    , 7   } ,
	{ "BATTERY_LOW_BG"       , 196 } ,
	{ "BATTERY_LOW_FG"       , 7   } ,
	{ "AWS_PROFILE_FG"       , 39  } ,
	{ "AWS_PROFILE_BG"       , 238 } ,
	{ "PROMPT_FG"            , 234 } ,
	{ "PROMPT_BG"            , 117 } ,
	{ "PROMPT_NG_FG"         , 236 } ,
	{ "PROMPT_NG_BG"         , 198 } ,
	{ "ANDROID_ENV_FG"       , 235 } ,
	{ "ANDROID_ENV_BG"       , 147 } ,

#if defined(THEME_DEFAULT)
	#if defined(THEME_DARK)
	// { "USERNAME_FG"          , 254 } ,
	// { "USERNAME_BG"          , 31  } ,
	{ "USERNAME_FG"          , 254 } ,
	{ "USERNAME_BG"          , 31  } ,
	{ "USERNAME_ROOT_BG"     , 124 } ,
	{ "HOSTNAME_FG"          , 250 } ,
	{ "HOSTNAME_BG"          , 238 } ,
	{ "PATH_BG"              , 237 } ,  // dark grey
	{ "PATH_FG"              , 254 } ,  // light grey
	{ "CWD_FG"               , 254 } ,  // nearly-white grey
	{ "SEPARATOR_FG"         , 244 } ,
	{ "READONLY_BG"          , 124 } ,
	{ "READONLY_FG"          , 254 } ,
	{ "SSH_BG"               , 166 } ,  // medium orange
	{ "SSH_FG"               , 254 } ,
	{ "REPO_CLEAN_BG"        , 148 } ,  // a light green color
	{ "REPO_CLEAN_FG"        , 0   } ,  // black
	{ "REPO_DIRTY_BG"        , 161 } ,  // pink/red
	{ "REPO_DIRTY_FG"        , 15  } ,  // white
	{ "JOBS_FG"              , 39  } ,
	{ "JOBS_BG"              , 238 } ,
	{ "CMD_PASSED_BG"        , 245 } ,
	{ "CMD_PASSED_FG"        , 232 } ,
	{ "CMD_FAILED_BG"        , 161 } ,
	{ "CMD_FAILED_FG"        , 15  } ,
	{ "VIRTUAL_ENV_BG"       , 35  } ,  // a mid-tone green
	{ "VIRTUAL_ENV_FG"       , 0   } ,
	// { "TIME_FG"              , 250 } ,
	// { "TIME_BG"              , 238 } ,
	{ "TIME_FG"              , 236 } ,
	{ "TIME_BG"              , 98  } ,
	#elif defined(THEME_LIGHT)
	// { "USERNAME_FG"          , 254 } ,
	// { "USERNAME_BG"          , 31  } ,
	{ "USERNAME_FG"          , 255 } ,
	{ "USERNAME_BG"          , 75  } ,
	{ "USERNAME_ROOT_BG"     , 124 } ,
	{ "HOSTNAME_FG"          , 250 } ,
	{ "HOSTNAME_BG"          , 238 } ,
	{ "PATH_FG"              , 238 } ,  // dark grey
	{ "PATH_BG"              , 254 } ,  // light grey
	{ "CWD_FG"               , 254 } ,  // nearly-white grey
	{ "SEPARATOR_FG"         , 244 } ,
	{ "READONLY_BG"          , 124 } ,
	{ "READONLY_FG"          , 254 } ,
	{ "SSH_BG"               , 166 } ,  // medium orange
	{ "SSH_FG"               , 254 } ,
	{ "REPO_CLEAN_BG"        , 154 } ,  // a light green color
	{ "REPO_CLEAN_FG"        , 27  } ,  // black
	{ "REPO_DIRTY_FG"        , 161 } ,  // pink/red
	{ "REPO_DIRTY_BG"        , 15  } ,  // white
	{ "JOBS_BG"              , 39  } ,
	{ "JOBS_FG"              , 238 } ,
	{ "CMD_PASSED_BG"        , 249 } ,
	{ "CMD_PASSED_FG"        , 238 } ,
	{ "CMD_FAILED_BG"        , 207 } ,
	{ "CMD_FAILED_FG"        , 15  } ,
	{ "VIRTUAL_ENV_FG"       , 35  } ,  // a mid-tone green
	{ "VIRTUAL_ENV_BG"       , 0   } ,
	{ "TIME_FG"              , 25  } ,
	{ "TIME_BG"              , 229 } ,
	#endif
#else
	#if defined(THEME_DARK)
	{ "USERNAME_FG"      , 15  } ,
	{ "USERNAME_BG"      , 4   } ,
	{ "USERNAME_ROOT_BG" , 1   } ,
	{ "HOSTNAME_FG"      , 15  } ,
	{ "HOSTNAME_BG"      , 10  } ,
	{ "PATH_FG"          , 7   } ,
	{ "PATH_BG"          , 10  } ,
	{ "CWD_FG"           , 15  } ,
	{ "SEPARATOR_FG"     , 14  } ,
	{ "READONLY_BG"      , 1   } ,
	{ "READONLY_FG"      , 7   } ,
	{ "REPO_CLEAN_FG"    , 14  } ,
	{ "REPO_CLEAN_BG"    , 0   } ,
	{ "REPO_DIRTY_FG"    , 3   } ,
	{ "REPO_DIRTY_BG"    , 0   } ,
	{ "JOBS_FG"          , 4   } ,
	{ "JOBS_BG"          , 8   } ,
	{ "CMD_PASSED_FG"    , 15  } ,
	{ "CMD_PASSED_BG"    , 2   } ,
	{ "CMD_FAILED_FG"    , 15  } ,
	{ "CMD_FAILED_BG"    , 1   } ,
	{ "VIRTUAL_ENV_BG"   , 15  } ,
	{ "VIRTUAL_ENV_FG"   , 2   } ,
	{ "AWS_PROFILE_FG"   , 7   } ,
	{ "AWS_PROFILE_BG"   , 2   } ,
	{ "TIME_FG"          , 15  } ,
	{ "TIME_BG"          , 10  } ,
	#elif defined(THEME_LIGHT)
	{ "USERNAME_FG"      , 15 } ,
	{ "USERNAME_BG"      , 4  } ,
	{ "USERNAME_ROOT_BG" , 1  } ,
	{ "HOSTNAME_FG"      , 15 } ,
	{ "HOSTNAME_BG"      , 10 } ,
	{ "PATH_FG"          , 10 } ,
	{ "PATH_BG"          , 7  } ,
	{ "CWD_FG"           , 0  } ,
	{ "SEPARATOR_FG"     , 14 } ,
	{ "READONLY_BG"      , 1  } ,
	{ "READONLY_FG"      , 7  } ,
	{ "REPO_CLEAN_FG"    , 0  } ,
	{ "REPO_CLEAN_BG"    , 15 } ,
	{ "REPO_DIRTY_FG"    , 1  } ,
	{ "REPO_DIRTY_BG"    , 15 } ,
	{ "JOBS_FG"          , 4  } ,
	{ "JOBS_BG"          , 7  } ,
	{ "CMD_PASSED_FG"    , 15 } ,
	{ "CMD_PASSED_BG"    , 2  } ,
	{ "CMD_FAILED_FG"    , 15 } ,
	{ "CMD_FAILED_BG"    , 1  } ,
	{ "VIRTUAL_ENV_BG"   , 15 } ,
	{ "VIRTUAL_ENV_FG"   , 2  } ,
	{ "TIME_FG"          , 15 } ,
	{ "TIME_BG"          , 10 } ,
	#endif
#endif
};

colortheme::colortheme(void)
{
	memset(combile_color_map,0x0,sizeof(combile_color_map));
	memcpy(combile_color_map, default_theme,sizeof(default_theme));
}

colortheme::~colortheme(void)
{
}


int
colortheme::display_truecolor(int colortype, int colorstyle, true_color fg, true_color bg, char* content, char** dest)
{
	// JDG("\e[38;5;%dm\e[48;5;240m test[%d] \e[48;5;166m\e[38;5;%dm\n",i0,i0,i0);
	char color_string[COLOR_STRING_LEN];

	memset(color_string,0x0,sizeof(color_string));
	if (colortype == DISP_FOREGROUND)
	{
		sprintf( color_string, "\e[38;%d;%d;%d;%dm%s\e[0m\e[0m",colorstyle, fg.red, fg.green, fg.blue, content);
	}
	else if (colortype == DISP_BACKGROUND)
	{
		sprintf( color_string, "\e[48;%d;%d;%d;%dm%s\e[0m\e[0m",colorstyle, bg.red, bg.green, bg.blue, content);
	}
	else if (colortype == DISP_BOTH)
	{
		sprintf( color_string, "\e[38;%d;%d;%d;%dm\e[48;%d;%d;%d;%dm%s\e[0m\e[0m", \
				  colorstyle, fg.red, fg.green, fg.blue, \
				  colorstyle, bg.red, bg.green, bg.blue, content);
	}
	else
		return -1;

	*dest = (char*)malloc(strlen(color_string) + 1);
	memset(*dest,0x0,strlen(color_string)+1);
	memcpy(*dest, color_string, strlen(color_string)+1);

	return 0;
}

int
colortheme::display_256color(int colortype, int colorstyle, true_color fg, true_color bg, char* content, char** dest)
{
	// JDG("\e[38;5;%dm\e[48;5;240m test[%d] \e[48;5;166m\e[38;5;%dm\n",i0,i0,i0);
	char color_string[COLOR_STRING_LEN];

	memset(color_string,0x0,sizeof(color_string));
	if (colortype == DISP_FOREGROUND)
	{
		sprintf( color_string, BASH_FOREGROUND"%d;%dm%s"BASH_END""BASH_END,colorstyle, fg.red, content);
	}
	else if (colortype == DISP_BACKGROUND)
	{
		sprintf( color_string, BASH_BACKGROUND"%d;%dm%s"BASH_END""BASH_END,colorstyle, bg.red, content);
	}
	else if (colortype == DISP_BOTH)
	{
		sprintf( color_string, BASH_FOREGROUND"%d;%dm"BASH_BACKGROUND"%d;%dm%s"BASH_END""BASH_END, \
				 colorstyle, fg.red, \
				 colorstyle, bg.red, content);
	}
	else if (colortype == DISP_FOREGROUND_PART)
	{
		sprintf( color_string, BASH_FOREGROUND"%d;%dm", colorstyle, fg.red);
	}
	else if (colortype == DISP_BACKGROUND_PART)
	{
		sprintf( color_string, BASH_BACKGROUND"%d;%dm", colorstyle, fg.red);
	}
	else if (colortype == DISP_END)
	{
		sprintf( color_string, BASH_END);
	}
	else
		return -1;

	*dest = (char*)malloc(strlen(color_string) + 1);
	memset(*dest,0x0,strlen(color_string)+1);
	memcpy(*dest, color_string, strlen(color_string)+1);
	return 0;
}

int
colortheme::show_truecolor_map()
{
	int i0 = 0,i1 = 0,i2 = 0;
	true_color fg, bg;
	int style = 2;
	char content[1024];
	char* color_string_value;

	fg.red   = 0;
	fg.green = 0;
	fg.blue  = 0;
	bg.red   = 0;
	bg.green = 0;
	bg.blue  = 0;

	while (i0 < 256) {
		memset(content, 0x0,sizeof(content));
		sprintf(content,"%03d ",i0);
		bg.red = i0;
		fg.blue = 255 - i0;
		display_truecolor(DISP_BACKGROUND, style, fg, bg, content, &color_string_value);
		// display_truecolor(DISP_FOREGROUND, style, fg, bg, content, &color_string_value);
		// display_truecolor(DISP_BOTH, style, fg, bg, content, &color_string_value);
		if (color_string_value != NULL) {
			JDG("\e[0m\e[0m%s\e[0m\e[0m",color_string_value);
			free(color_string_value);
		} else {
			JEG("get color error!");
		}
		if (i0%32 == 31) {
			JDG("\n");
		}
		i0++;
	}
	JDG("\n\e[48;2;0;0;0mbyJames\n");
	i0=0;
	while (i0 < 256) {
		memset(content, 0x0,sizeof(content));
		sprintf(content,"%03d ",i0);
		bg.red = i0;
		fg.blue = 255 - i0;
		// display_truecolor(DISP_BACKGROUND, style, fg, bg, content, &color_string_value);
		display_truecolor(DISP_FOREGROUND, style, fg, bg, content, &color_string_value);
		// display_truecolor(DISP_BOTH, style, fg, bg, content, &color_string_value);
		if (color_string_value != NULL) {
			JDG("\e[0m\e[0m%s\e[0m\e[0m",color_string_value);
			free(color_string_value);
		} else {
			JEG("get color error!");
		}
		if (i0%32 == 31) {
			JDG("\n");
		}
		i0++;
	}
	JDG("\n\e[48;2;0;0;0mbyJames\n");
	i0=0;
	while (i0 < 256) {
		memset(content, 0x0,sizeof(content));
		sprintf(content,"%03d ",i0);
		bg.red = i0;
		bg.green = i0;
		bg.blue = 0;
		fg.blue = 255 - i0;
		fg.green = 255 - i0;
		// display_truecolor(DISP_BACKGROUND, style, fg, bg, content, &color_string_value);
		// display_truecolor(DISP_FOREGROUND, style, fg, bg, content, &color_string_value);
		display_truecolor(DISP_BOTH, style, fg, bg, content, &color_string_value);
		if (color_string_value != NULL) {
			JDG("\e[0m\e[0m%s\e[0m\e[0m",color_string_value);
			free(color_string_value);
		} else {
			JEG("get color error!");
		}
		if (i0%32 == 31) {
			JDG("\n");
		}
		i0++;
	}
	JDG("\n\e[48;2;0;0;0m\e[0mbyJames\n");
	JDG("\n");

	return 0;
}

int
colortheme::show_256color_map()
{
	int i0 = 0,i1 = 0,i2 = 0;
	true_color fg, bg;
	int style = 5;
	char content[1024];
	char* color_string_value;

	fg.red   = 0;
	fg.green = 0;
	fg.blue  = 0;
	bg.red   = 0;
	bg.green = 0;
	bg.blue  = 0;

	while (i0 < 256) {
		memset(content, 0x0,sizeof(content));
		sprintf(content,"%03d   ",i0);
		bg.red = i0;
		fg.red = 0;
		// display_256color(DISP_BACKGROUND, style, fg, bg, content, &color_string_value);
		// display_256color(DISP_FOREGROUND, style, fg, bg, content, &color_string_value);

		if (i0 == 0 || i0 == 8 || (i0 >= 16 && i0<=21)|| (i0>=232 && i0< 232 + 6 + 6)) {
			fg.red = 255;
		}

		display_256color(DISP_BOTH, style, fg, bg, content, &color_string_value);
		if (color_string_value != NULL) {
			JDG("\e[0m%s",color_string_value);
			free(color_string_value);
		} else {
			JEG("get color error!");
		}
		if (i0 < 16 && i0%8 == 7) {
			JDG("\n");
		} else if (i0 >= 16 && i0%6 == 3) {
			JDG("\n");
		}
		i0++;
	}
	// JDG("\n\e[48;2;0;0;0mbyJames\n");
	// JDG("\n\e[48;5;0;0;0m\e[0mbyJames\n");
	JDG("\n");

	return 0;
}

int
colortheme::show_color_map()
{
	show_truecolor_map();
	show_256color_map();
}



int
colortheme::get_color_theme(char* extern_path)
{
	int ret;

	ret = get_color_theme_from_file(extern_path);
	if (ret > 0)
	{
		memset(combile_color_map,0x0,sizeof(combile_color_map));
		JCG("use theme in file!");
	}
	return 0;
}

int
colortheme::get_color_theme_from_file(char* extern_path)
{
	int fd0;

	common_share m_share;

	m_share.get_config_file(&fd0, NULL, extern_path);
	if (fd0 < 0)
	{
		JEG("get config file error! use default theme");
		return fd0;
	}
	JCG("get fd: %d",fd0);


	close(fd0);
	return 0;
}

int
colortheme::get_color_by_name(char* name, unsigned short* value)
{
	int i0;

	i0 = 0;
	while (i0 < MAX_THEME_SIZE )
	{
		if(strcasecmp(combile_color_map[i0].name, name) == 0)
		{
			*value = combile_color_map[i0].color;
			return 0;
		}
		i0++;
	}
	return -1;
}

