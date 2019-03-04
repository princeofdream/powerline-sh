#
# =====================================================================================
#
#       Filename:  Makefile
#
#    Description:  Makefile
#
#        Version:  1.0
#        Created:  05/07/2018 03:56:38 PM
#       Revision:  none
#       Compiler:  gcc
#
#         Author:  James Lee (JamesL), princeofdream@outlook.com
#   Organization:  BookCL
#
# =====================================================================================
#

# CROSS_COMPILE=
CC=${CROSS_COMPILE}gcc
CXX=${CROSS_COMPILE}g++

OBJS=main.o colortheme.o segments.o
OBJS+=abstract_segments.o
OBJS+=cwd_segment.o
OBJS+=host_segment.o
OBJS+=common_segment_manager.o
OBJS+=common_share.o
OBJS+=debug_utils.o


INCS=abstract_segments.h basic.h

OUTPUT=powerline-sh

CFLAGS = -I$(HOME)/Environment/env_rootfs/include
CFLAGS += -I./
CFLAGS += -fpermissive -Wno-format-extra-args
#LDFLAGS=-L$(HOME)/Environment/env_rootfs/lib64 -Wl,-rpath=$(HOME)/Environment/env_rootfs/lib64
#LDFLAGS+=-L$(HOME)/Environment/env_rootfs/lib -Wl,-rpath=$(HOME)/Environment/env_rootfs/lib

all: $(OBJS) $(INCS)
	$(CXX) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(OUTPUT)

%.o: %.cpp %.h $(INCS)
	$(CXX) $(CFLAGS) -c $< -o $@

install:
	mkdir -p $(HOME)/Environment/env_rootfs/bin/
	install powerline-sh $(HOME)/Environment/env_rootfs/bin/

uninstall:
	rm $(HOME)/Environment/env_rootfs/bin/powerline-sh

clean:
	rm -rf *.o $(OUTPUT)

