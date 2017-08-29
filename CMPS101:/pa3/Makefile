#*************************************************************
# Name: Juan D. Cardozo
# Cruz I.D: jcardozo
# Student I.D: 1362585
# Assigment: pa03
# File: Makefile
# Purpose: Compile scc03.c
#*************************************************************

CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE

scc03:scc03.o intList.o edgeList.o loadGraph.o dfsTrace1.o dfsPhase2.o
	${CC}  -o  scc03  scc03.o intList.o edgeList.o loadGraph.o dfsTrace1.o

scc03.o:scc03.c  intList.h edgeList.h loadGraph.h dfsTrace1.h
	${CC}  -c  ${CFLAGS}  scc03.c

dfsTrace1.o: dfsTrace1.c dfsTrace1.h 
	${CC}  -c  ${CFLAGS}  dfsTrace1.c

dfsPhase2.o: dfsPhase2.c dfsPhase2.h 
	${CC}  -c  ${CFLAGS}  dfsPhase2.c

loadGraph.o:loadGraph.c loadGraph.h
	${CC}  -c  ${CFLAGS}  loadGraph.c

edgeList.o:edgeList.c edgeList.h
	${CC}  -c  ${CFLAGS}  edgeList.c

intList.o:intList.c  intList.h
	${CC}  -c  ${CFLAGS}  intList.c

clean:
	rm scc03.o intList.o edgeList.o loadGraph.o dfsTrace1.o dfsPhase2.o

submit:
	submit cmps101-avg.f15 pa03 intList.c intList.h edgeList.h edgeList.c scc03.c dfsTrace1.c dfsTrace1.h loadGraph.c loadGraph.h dfsPhase2.c dfsPhase2.h README Makefile test1 test2