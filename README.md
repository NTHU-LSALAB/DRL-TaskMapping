# DRL-TaskMapping

# Requirement

* nvidia-docker

# Download the DRL-TaskMapping Source Code

```
$ git clone https://github.com/NTHU-LSALAB/DRL-TaskMapping.git
$ cd DRL-TaskMapping
$ git submodule update --init --recursive --progress
```

# Setting up the demo environment

```
$ bash scripts/build.sh
```

```
$ tar -xf data/testcases/sample-test.tar.xz -C data/testcases
$ tar -xf data/testcases/sample-train.tar.xz -C data/testcases
```

```
$ bash scripts/launch.sh
```

```
$ make -C /data/src
```

```
$ cd workspace/DRL-TaskMapping
$ bash scripts/train.sh
```
