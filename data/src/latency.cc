#include <iostream>
#include <vector>
#include <cstdlib>
#include "mpi.h"
#include <unistd.h>
#include <fstream>
#include <cassert>

int main(int argc, char** argv) {
    
    MPI_Init(&argc, &argv);
    
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::vector<int> sends;
    std::vector<int> recvs;
    
    size_t messages_cnt = 1024;
    int repeat_times = 1;

    assert(argc > 1);

    std::ifstream infs;
    int src, dst, weight;
    infs.open(argv[1]);

    infs >> src;

    while (infs >> src) {
        infs >> dst >> weight;
        if (src == rank) {
            for (ssize_t i = 0; i < weight; ++ i) {
                sends.push_back(dst);
            }
        } 
        if (dst == rank) {
            for (ssize_t i = 0; i < weight; ++ i) {
                recvs.push_back(src);
            }
        }
    }

    MPI_Request* requests;
    MPI_Status* status;
    requests = (MPI_Request*) std::malloc(recvs.size() * sizeof(MPI_Request));
    status = (MPI_Status*) std::malloc(recvs.size() * sizeof(MPI_Status));

    double** recvbufs = (double**) std::malloc(recvs.size() * sizeof(double*));
    double** sendbufs = (double**) std::malloc(sends.size() * sizeof(double*));
    
    for (int i = 0; i < recvs.size(); ++ i) {
        recvbufs[i] = (double*) std::malloc(messages_cnt * sizeof(double));
    }

    for (int i = 0; i < sends.size(); ++ i) {
        sendbufs[i] = (double*) std::malloc(messages_cnt * sizeof(double));
    }

    for (int t = 0; t < repeat_times; ++ t) {
        for (int i = 0; i < recvs.size(); ++ i) {
            MPI_Irecv(recvbufs[i], messages_cnt, MPI_DOUBLE, recvs[i], recvs[i], MPI_COMM_WORLD, &requests[i]);
        }

        for (int i = 0; i < sends.size(); ++ i) {
            MPI_Ssend(sendbufs[i], messages_cnt, MPI_DOUBLE, sends[i], rank, MPI_COMM_WORLD);
        }
        MPI_Waitall(recvs.size(), requests, status);
    }

    MPI_Finalize();
}
