#*************************************************************
# Name: Juan D. Cardozo
# Cruz I.D: jcardozo
# Student I.D: 1362585
# Assigment: pa02
# File: Makefile
# Purpose: Compile dfs02.c
#*************************************************************

CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE

dfs02:dfs02.o intList.o edgeList.o loadGraph.o dfsTrace.o
	${CC}  -o  dfs02  dfs02.o intList.o edgeList.o loadGraph.o dfsTrace.o

dfs02.o:dfs02.c  intList.h edgeList.h loadGraph.h dfsTrace.h
	${CC}  -c  ${CFLAGS}  dfs02.c

dfsTrace.o: dfsTrace.c dfsTrace.h 
	${CC}  -c  ${CFLAGS}  dfsTrace.c

loadGraph.o:loadGraph.c loadGraph.h
	${CC}  -c  ${CFLAGS}  loadGraph.c

edgeList.o:edgeList.c edgeList.h
	${CC}  -c  ${CFLAGS}  edgeList.c

intList.o:intList.c  intList.h
	${CC}  -c  ${CFLAGS}  intList.c




clean:
	rm dfs02.o intList.o edgeList.o loadGraph.o dfsTrace.o 
submit:
	submit cmps101-avg.f15 edge02 intList.c intList.h edgeList.h edgeList.c dfs02.c dfsTrace.c dfsTrace.h loadGraph.c loadGraph.h README Makefile test1 test2