MPICXX     := mpicxx
SMPICXX := smpicxx

TARGETS := latency.smpi

all: $(TARGETS)

%.mpi: %.cc
	$(MPICXX) $< -o $@

%.smpi: %.cc
	$(SMPICXX) $< -o $@

clean:
	rm -rf $(TARGETS)
