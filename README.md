# DRL-TaskMapping

A deep reinforcement learning method for solving task mapping problems.

## Requirements

Ensure you meet the following system requirements:

* [CUDA](https://developer.nvidia.com/cuda-toolkit) >= 10.2
* [Docker](https://docs.docker.com/install/) >= 19.03
* [NVIDIA Docker](https://github.com/NVIDIA/nvidia-docker) >= 2.0 or `nvidia-container-toolkit`

## Installation

### Download the DRL-TaskMapping Source Code

```
$ git clone https://github.com/NTHU-LSALAB/DRL-TaskMapping.git
$ cd DRL-TaskMapping
$ git submodule update --init --recursive --progress
```

### Setting up the demo environment

Build the docker image
```
$ bash scripts/build.sh
```

Extract demo train/test cases
```
$ tar -xf data/testcases/sample-test.tar.xz -C data/testcases
$ tar -xf data/testcases/sample-train.tar.xz -C data/testcases
```

Launch the container
```
$ bash scripts/launch.sh
```

In the demo, we use a MPI program to explore the communication pattern. Compile it.
```
$ make -C /data/src
```

## Training

Enter the DRL-TaskMapping and run the training script. The demo trains the model with only 1024 steps. 
Modify the `num_timesteps` parameter to train longer.
```
$ cd workspace/DRL-TaskMapping
$ bash scripts/train.sh
```

## Inference
Run the `play.sh` to do the inference, the output will be logged at `logs/<num_env>/<num_eval>/<checkpoint>/runtime-*`
```
bash scripts/play.sh
```

