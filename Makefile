GCC=g++

# test from Alex

LIB_EVTGEN=/home/anton/programs/EvtGen-01.07.00/EvtGen/R01-07-00/lib/archive/libEvtGen.a
LIB_MC=/home/anton/programs/EvtGen-01.07.00/EvtGen/EvtGen/external/HepMC/lib/libHepMC.a
ROOT_LIBS = `root-config --libs`
LIBS = ${ROOT_LIBS} ${LIB_EVTGEN} ${LIB_MC}

ROOT_INCDIR = `root-config --incdir`
EVTGEN_INC = /home/anton/programs/EvtGen-01.07.00/EvtGen/R01-07-00/
INC=-I ./ -I ${ROOT_INCDIR}  -I ${EVTGEN_INC}

FLAGS = `root-config --cflags`


#all: baryons3pi.exe rrF.exe
all: baryons.exe rrF.exe


%.exe: %.cpp EvtOmegaOmega.cpp ${LIB_EVTGEN}
#	${GCC} -o $@ EvtOmegaOmega3pi.cpp EvtWHad.cpp $< ${FLAGS}  ${INC} ${LIBS} 
	${GCC} -o $@ EvtOmegaOmega.cpp EvtWHad.cpp $< ${FLAGS}  ${INC} ${LIBS} 

%.exe: %.cc EvtOmegaOmega.cpp ${LIB_EVTGEN}
#	${GCC} -o $@ EvtOmegaOmega3pi.cpp EvtWHad.cpp $< ${FLAGS}  ${INC} ${LIBS} 
	${GCC} -o $@ EvtOmegaOmega.cpp EvtWHad.cpp $< ${FLAGS}  ${INC} ${LIBS} 

clean:
	rm *.exe *~
