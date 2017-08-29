# ==================================================================
# Name: Juan D. Cardozo
# Cruz I.D: jcardozo
# Student I.D: 1362585
# ===================================================================

CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE

intList.o:	intList.c  intList.h
	${CC}  -c  ${CFLAGS}  intList.c

graph01.o:	graph01.c  intList.h
	${CC}  -c  ${CFLAGS}  graph01.c

graph01:	graph01.o  intList.o
	${CC}  -o  graph01  graph01.o intList.o
