#!/bin/bash

docker run --gpus all \
           -u $(id -u):$(id -g) \
           -v `pwd`/baselines:/workspace/DRL-TaskMapping \
           -v `pwd`/data:/data \
           -it demo-image /bin/bash
