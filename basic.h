/*
 * =====================================================================================
 *
 *       Filename:  basic.h
 *
 *    Description:  basic header
 *
 *        Version:  1.0
 *        Created:  05/07/2018 03:57:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#ifndef __BASIC_HEADER__
#define __BASIC_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/times.h>
#include <sys/time.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <sched.h>


#ifdef DEBUG
#undef DEBUG
#endif
// #define DEBUG

#ifdef DEBUG
#define JCG(frm,args...) printf("---<%s:%d>---" frm "\n",__FILE__,__LINE__,##args)
#define JEG(frm,args...) printf("---<%s:%d>---" frm "\n",__FILE__,__LINE__,##args)
#define JDG(frm,args...) printf(frm,##args)
#define JJG(frm,args...) printf("---<%s:%d>---" frm "\n",__FILE__,__LINE__,##args)
#else
#define JCG(frm,args...) while(0){;}
#define JEG(frm,args...) while(0){;}
#define JDG(frm,args...) while(0){;}
#define JJG(frm,args...) while(0){;}
#endif


#define COLOR_STRING_LEN 1024
#define SEGMENT_NAME_MAX_LEN 64
#define MAX_SEGMENTS 256
#define MAX_THEME_SIZE (MAX_SEGMENTS * 8)
#ifdef MAXLEN
#undef MAXLEN
#endif
#define MAXLEN 1024
#define SEPERATE_SYMBOL ""

#define SEGMENT_ACTION_COUNT 8

#define DEFAULT_THEME_CONFIG_FILE_NAME ".powershell_sh_rc"
#define DEFAULT_THEME_CONFIG_THEME_NAME ".powershell_sh_theme"

#if 1
#define SHELL_FOREGROUND "\\[\\e[38;"
#define SHELL_BACKGROUND "\\[\\e[48;"
#define SHELL_FG_BG_END        "\\[\\e[0m"
#define SHELL_COLOR_END  "\\]"
#else
#define SHELL_FOREGROUND "\\[(38;"
#define SHELL_BACKGROUND "\\[(48;"
#define SHELL_FG_BG_END        "\\[(0m\\]"
#endif

/*! \enum displaytype
 *
 *  Detailed description
 */
enum displaytype {
	DISP_FOREGROUND = 0,
	DISP_BACKGROUND,
	DISP_BOTH,
	DISP_FOREGROUND_PART,
	DISP_BACKGROUND_PART,
	DISP_END,
};

/*! \enum colorformat
 *
 *  Detailed description
 */
enum colorformat {
	COLOR_FORMAT_BOLD      = 1,
	COLOR_FORMAT_DIM       = 2,
	COLOR_FORMAT_UNDERLINE = 4,
	COLOR_FORMAT_BLINK     = 5,
	COLOR_FORMAT_REVERT    = 7,
	COLOR_FORMAT_HIDDEN    = 8,
};

/*! \enum colorreset
 *
 *  Detailed description
 */
enum colorreset {
	COLOR_RESET_ALL       = 0,
	COLOR_RESET_BOLD      = 21,
	COLOR_RESET_DIM       = 22,
	COLOR_RESET_UNDERLINE = 24,
	COLOR_RESET_BLINK     = 25,
	COLOR_RESET_REVERT    = 27,
	COLOR_RESET_HIDDEN    = 28,
};

/*! \enum colortype
 *
 *  Detailed description
 */
enum colortype {
	COLOR_TYPE_TRUE_COLOR = 0,
	COLOR_TYPE_256_COLOR,
	COLOR_TYPE_16_COLOR,
};

/*! \enum segmentaction
 *
 *  Detailed description
 */
enum segmentaction {
	SEGMENT_ACTION_NORMAL = 0,
	SEGMENT_ACTION_ACTIVE,
	SEGMENT_ACTION_DEACTIVE,
	SEGMENT_ACTION_WARNING,
	SEGMENT_ACTION_ERROR,
};

typedef	struct true_color_t {
	unsigned short red;
	unsigned short green;
	unsigned short blue;
	colortype type;
} true_color;

typedef	struct segment_color_t {
	/* data */
	true_color fg_color[SEGMENT_ACTION_COUNT];
	true_color bg_color[SEGMENT_ACTION_COUNT];
} segment_color;

typedef	struct segments_unit_t {
	/* data */
	unsigned short index;
	char* name;
	char* value;
	char* pvalue;
	segment_color color;
	// struct segment_unit_t *next_unit;
} segment_unit;

#if 0
typedef struct 16bit_color_t {
	char* name;
	unsigned short value;
}16bit_color;

struct 16bit_color_t 16bit_color_fg[] = {
	/* 8/16 bit color foreground */
	{ "default"       , 39 } ,
	{ "black"         , 30 } ,
	{ "red"           , 31 } ,
	{ "green"         , 32 } ,
	{ "yellow"        , 33 } ,
	{ "blue"          , 34 } ,
	{ "magenta"       , 35 } ,
	{ "cyan"          , 36 } ,
	{ "light_gray"    , 37 } ,
	{ "dark_gray"     , 90 } ,
	{ "light_red"     , 91 } ,
	{ "light_green"   , 92 } ,
	{ "light_yellow"  , 93 } ,
	{ "light_blue"    , 94 } ,
	{ "light_magenta" , 95 } ,
	{ "light_cyan"    , 96 } ,
	{ "white"         , 97 }
};
struct 16bit_color_t 16bit_color_bg[] = {
	/* 8/16 bit color background */
	{ "default"       , 49 } ,
	{ "black"         , 40 } ,
	{ "red"           , 41 } ,
	{ "green"         , 42 } ,
	{ "yellow"        , 43 } ,
	{ "blue"          , 44 } ,
	{ "magenta"       , 45 } ,
	{ "cyan"          , 46 } ,
	{ "light_gray"    , 47 } ,
	{ "dark_gray"     , 100} ,
	{ "light_red"     , 101} ,
	{ "light_green"   , 102} ,
	{ "light_yellow"  , 103} ,
	{ "light_blue"    , 104} ,
	{ "light_magenta" , 105} ,
	{ "light_cyan"    , 106} ,
	{ "white"         , 107}
};
#endif

#endif


