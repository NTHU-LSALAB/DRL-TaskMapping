FROM tensorflow/tensorflow:1.14.0-gpu-py3

RUN mkdir /workspace && chown 1000 /workspace
RUN apt-get update && apt-get install -y git libsm6 libxrender1 aria2 cmake libboost-dev openmpi-bin
RUN cd /workspace && git clone 'https://github.com/zlsh80826/baselines.git' && cd baselines && pip install -e .
RUN cd /workspace && \
    aria2c -x 4 'https://github.com/simgrid/simgrid/archive/v3.23.tar.gz' && \
    tar -xf simgrid-3.23.tar.gz && \
    rm simgrid-3.23.tar.gz && \
    mkdir -p simgrid-3.23/build && \
    cd simgrid-3.23/build && \
    cmake .. && \
    make -j8

ENV PATH /workspace/simgrid-3.23/build/bin:$PATH
ENV LD_LIBRARY_PATH /workspace/simgrid-3.23/build/bin:$LD_LIBRARY_PATH
