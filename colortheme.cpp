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


colortheme::colortheme(void)
{
}

colortheme::~colortheme(void)
{
}


int
colortheme::display_truecolor(int colortype, int colorstyle, true_color fg, true_color bg, char* content, char** dest)
{
	// printf("\e[38;5;%dm\e[48;5;240m test[%d] \e[48;5;166m\e[38;5;%dm\n",i0,i0,i0);
	char color_string[COLOR_STRING_LEN];

	memset(color_string,0x0,sizeof(color_string));
	if (colortype == DISP_FRONTGROUND)
	{
		sprintf( color_string, "\e[38;%d;%d;%d;%dm%s\e[0m",colorstyle, fg.red, fg.green, fg.blue, content);
	}
	else if (colortype == DISP_BACKGROUND)
	{
		sprintf( color_string, "\e[48;%d;%d;%d;%dm%s\e[0m",colorstyle, bg.red, bg.green, bg.blue, content);
	}
	else if (colortype == DISP_BOTH)
	{
		sprintf( color_string, "\e[38;2;%d;%d;%dm\e[48;2;%d;%d;%dm%s\e[0m", \
				  fg.red, fg.green, fg.blue, \
				  bg.red, bg.green, bg.blue, content);
	}
	else
		return -1;

	printf("%s\e[0m\e[0m",color_string);
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
		// display_truecolor(DISP_FRONTGROUND, style, fg, bg, content, &color_string_value);
		// display_truecolor(DISP_BOTH, style, fg, bg, content, &color_string_value);
		if (i0%32 == 31) {
			printf("\n");
		}
		i0++;
	}
	printf("\n\e[48;2;0;0;0mbyJames\n");
	i0=0;
	while (i0 < 256) {
		memset(content, 0x0,sizeof(content));
		sprintf(content,"%03d ",i0);
		bg.red = i0;
		fg.blue = 255 - i0;
		// display_truecolor(DISP_BACKGROUND, style, fg, bg, content, &color_string_value);
		display_truecolor(DISP_FRONTGROUND, style, fg, bg, content, &color_string_value);
		// display_truecolor(DISP_BOTH, style, fg, bg, content, &color_string_value);
		if (i0%32 == 31) {
			printf("\n");
		}
		i0++;
	}
	printf("\n\e[48;2;0;0;0mbyJames\n");
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
		// display_truecolor(DISP_FRONTGROUND, style, fg, bg, content, &color_string_value);
		display_truecolor(DISP_BOTH, style, fg, bg, content, &color_string_value);
		if (i0%32 == 31) {
			printf("\n");
		}
		i0++;
	}
	printf("\n\e[48;2;0;0;0m\e[0mbyJames\n");
	printf("\n");

	return 0;
}

int
colortheme::show_color_map()
{
	show_truecolor_map();
}

int
colortheme::get_color_theme()
{
	return 0;
}

int
colortheme::get_color()
{
	return 0;
}

