#!/bin/bash

# docker run --gpus all -u $(id -u):$(id -g) -it demo-image /bin/bash
docker run --gpus all -it demo-image /bin/bash
