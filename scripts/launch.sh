#!/bin/bash

# docker run --gpus all -u $(id -u):$(id -g) -it demo-image /bin/bash
docker run --gpus all \
           -v `pwd`/baselines:/workspace/DRL-TaskMapping \
           -v `pwd`/data:/data \
           -it demo-image /bin/bash
