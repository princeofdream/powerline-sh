/*
 * =====================================================================================
 *
 *       Filename:  colortheme.h
 *
 *    Description:  color theme
 *
 *        Version:  1.0
 *        Created:  05/07/2018 04:33:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#ifndef __COLORTHEME_HEADER__
#define __COLORTHEME_HEADER__

#include <basic.h>


class colortheme
{
public:
	colortheme ();
	virtual ~colortheme ();

public:
	int display_truecolor(int colortype, int colorstyle, true_color fg, true_color bg, char* content, char** dest);
	int display_256color(int colortype, int colorstyle, true_color fg, true_color bg, char* content, char** dest);
	// int display_16color(int colortype, int colorstyle, true_color fg, true_color bg, char* content, char** dest);
	int show_truecolor_map();
	int show_256color_map();
	// int show_16color_map();
	int show_color_map();
	int get_color_theme(char* extern_path);
	int get_color();

private:
	/* data */
};

#endif /* __COLORTHEME_HEADER__ */
