/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  main
 *
 *        Version:  1.0
 *        Created:  05/07/2018 03:56:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#include <main.h>

int main(int argc, char *argv[])
{
	int i0 = 0, i1 = 0;
	char string_content[1024];
	int style;
	true_color fg;
	true_color bg;
	segment_unit *cwd_unit;

	memset(string_content,0x0,sizeof(string_content));
	style = 38;
	// sprintf(string_content,"\e[%d;%d;%dm=======\n",i0,5,48);
	// printf("\e[38;5;%dm\e[48;5;240m test[%d] \e[48;5;166m\e[38;5;%dm\n",i0,i0,i0);

	// m_colortheme.show_truecolor_map();
	m_colortheme = new colortheme();
	m_colortheme->show_256color_map();

	m_cwd = new cwd_segment();
	// m_cwd->segment_set_value(NULL);
	m_cwd->register_segment("cwd");
	m_cwd->get_segment_list();


	JCG("-----------------------------------");
	m_host = new host_segment();
	m_host->register_segment("host");
	m_host->get_segment_list();

	JCG("-----------------------------------");
	m_sgmgr = new common_segment_manager();
	m_sgmgr->register_segment("ssh");
	// delete(m_colortheme);
	// delete(m_cwd);
	// delete(m_host);
	// delete(m_sgmgr);
	// m_colortheme = NULL;
	// m_cwd = NULL;
	// m_host = NULL;
	// m_sgmgr = NULL;
	return 0;
}


