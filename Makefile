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


INCS=abstract_segments.h

OUTPUT=powerline-sh

CFLAGS = -I$(HOME)/Environment/env_rootfs/include
CFLAGS += -I./
LDFLAGS=-L/home/james/Environment/env_rootfs/lib64 -Wl,-rpath=/home/james/Environment/env_rootfs/lib64
LDFLAGS+=-L/home/james/Environment/env_rootfs/lib -Wl,-rpath=/home/james/Environment/env_rootfs/lib

all: $(OBJS) $(INS)
	$(CXX) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(OUTPUT)

%.o: %.cpp %.h
	$(CXX) $(CFLAGS) -c $< -o $@


clean:
	rm -rf *.o $(OUTPUT)

