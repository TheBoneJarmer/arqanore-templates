#!/bin/bash

g++ -o ./app ./src/main.cpp -larqanore -Wl,-rpath='$ORIGIN:$ORIGIN/lib'
