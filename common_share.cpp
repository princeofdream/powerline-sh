/*
 * =====================================================================================
 *
 *       Filename:  common_share.cpp
 *
 *    Description:  common share
 *
 *        Version:  1.0
 *        Created:  05/23/2018 11:51:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#include <basic.h>
#include <common_share.h>

char* config_path[] = {
	".",
	"$HOME",
};

common_share::common_share()
{
}

common_share::~common_share()
{
}

int
common_share::get_config_file(int* fd, char* name, char* extern_path)
{
	int i0;
	char config_file[MAXLEN];
	char config_name[MAXLEN];
	char* m_path;
	int fd0 = -1;

	memset(config_name,0x0,sizeof(config_name));
	if (name == NULL)
		sprintf(config_name, "%s", DEFAULT_THEME_CONFIG_FILE_NAME);
	else
		sprintf(config_name, "%s", name);

	if (extern_path != NULL)
	{
		memset(config_file,0x0,sizeof(config_file));
		sprintf(config_file, "%s/%s",extern_path, config_name);
		fd0 = open(config_file,O_RDWR);
		if (fd0 < 0)
		{
			memset(config_file,0x0,sizeof(config_file));
			sprintf(config_file, "%s",extern_path);
			fd0 = open(config_file,O_RDWR);
		}
	}

	if (fd0 < 0)
	{
		i0 = 0;
		m_path = getenv("HOME");
		while(i0 < sizeof(config_path)/sizeof(config_path[0]))
		{
			memset(config_file,0x0,sizeof(config_file));

			if (strcmp("$HOME",config_path[i0]) == 0)
				sprintf(config_file, "%s/%s",m_path,config_name);
			else
				sprintf(config_file, "%s/%s",config_path[i0],config_name);
			fd0 = open(config_file,O_RDWR);
			JCG("load config from: %s",config_file);
			if (fd0 > 0)
			{
				JCG("get config: %s", config_file);
				break;
			}
			i0++;
		}
	}

	*fd = fd0;

	// if (fd0 > 0)
		// close(fd0);

	return 0;
}


