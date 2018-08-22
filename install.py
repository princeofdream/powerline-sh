#! /usr/bin/env python3
import os
import subprocess

#  os.popen("./install.sh")
make_proc = subprocess.Popen("./install.sh")
make_proc.wait()

