#*************************************************************
# Name: Juan D. Cardozo
# Cruz I.D: jcardozo
# Student I.D: 1362585
# Assigment: pa04
# File: Makefile
# Purpose: Compile greedy04.c and testGreedy04.c
#*************************************************************

CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE

all: testGreedy04 greedy04

greedy04:greedy04.o  edgeList.o loadWgtGraph.o minPQ.o
	${CC}  -o  greedy04  greedy04.o  edgeList.o loadWgtGraph.o minPQ.o

testGreedy04: testGreedy04.o edgeList.o loadWgtGraph.o minPQ.o
	${CC}  -o  testGreedy04  testGreedy04.o  edgeList.o loadWgtGraph.o minPQ.o

greedy04.o: greedy04.c edgeList.h loadWgtGraph.h minPQ.h
	${CC}  -c  ${CFLAGS}  greedy04.c

testGreedy04.o: testGreedy04.c edgeList.h loadWgtGraph.h minPQ.h
	${CC}  -c  ${CFLAGS}  testGreedy04.c

minPQ.o: minPQ.c minPQ.h
	${CC}  -c  ${CFLAGS} minPQ.c

loadWgtGraph.o:loadWgtGraph.c loadWgtGraph.h
	${CC}  -c  ${CFLAGS}  loadWgtGraph.c

edgeList.o:edgeList.c edgeList.h
	${CC}  -c  ${CFLAGS}  edgeList.c

clean:
	rm greedy04.o testGreedy04.o edgeList.o loadWgtGraph.o minPQ.o

submit:
	submit cmps101-avg.f15 pa04A edgeList.h edgeList.c minPQ.h minPQ.c greedy04.c testGreedy04.c loadWgtGraph.c loadWgtGraph.h  README Makefile test1 