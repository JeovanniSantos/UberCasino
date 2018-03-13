OSPL_LIBS = -lpthread -lddskernel -ldcpssacpp
LIBS=-L${OSPL_HOME}/lib ${OSPL_LIBS}
CFLAGS = -Wall -O0 -g -I. -I./include -I${OSPL_HOME}/include/dcps/C++/SACPP -I${OSPL_HOME}/include/sys
CXXFLAGS = 

all: PitBoss Dealer Player


IDL_GENERATED_H= \
		 ccpp_UberCasino.h \
                 UberCasinoDcps.h \
                 UberCasinoDcps_impl.h \
                 UberCasino.h \
                 UberCasinoSplDcps.h 

IDL_GENERATED_CPP=\
                 UberCasino.cpp \
                 UberCasinoDcps.cpp \
                 UberCasinoDcps_impl.cpp \
                 UberCasinoSplDcps.cpp

IDL_GENERATED=${IDL_GENERATED_H} ${IDL_GENERATED_CPP}

${IDL_GENERATED}: ./idl/UberCasino.idl
	${OSPL_HOME}/bin/idlpp -l cpp ./idl/UberCasino.idl

COMMON_CPP=./src/CheckStatus.cpp ./src/DDSEntityManager.cpp \
	   ./src/pubsub.cpp

COMMON_H=./include/pubsub.h

PitBoss: ${IDL_GENERATED_H} ${IDL_GENERATED_CPP} ./src/PitBoss.cpp
	g++ -o $@ ${CFLAGS} ${CXXFLAGS} $^ ${LIBS}

Dealer: ${IDL_GENERATED_H} ${IDL_GENERATED_CPP} ./src/Dealer.cpp ${COMMON_H} ${COMMON_CPP}
	g++ -o $@ ${CFLAGS} ${CXXFLAGS} $^ ${LIBS}

Player: ${IDL_GENERATED_H} ${IDL_GENERATED_CPP} ./src/Player.cpp ${COMMON_H} ${COMMON_CPP}
	g++ -o $@ ${CFLAGS} ${CXXFLAGS} $^ ${LIBS}

clean:
	-rm -f PitBoss Player Dealer
	-rm -f ${IDL_GENERATED_H} ${IDL_GENERATED_CPP}
	-rm -f ospl-error.log ospl-info.log