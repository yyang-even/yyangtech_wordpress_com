#!/usr/bin/python

import subprocess


DBFARM_PATH = "/tmp/dbfarm"
subprocess.call(
    ["monetdbd", "start", DBFARM_PATH],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
)
