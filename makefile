CC = cc
AR = ar
RANLIB = ranlib

SRCDIR = ./src
INCDIR = ./inc
BINDIR = ./bin

CFLAGS = -g -Wall -std=c11 -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -D_POSIX_SOURCE=1 -D_DEFAULT_SOURCE=1 -D_GNU_SOURCE=1
#CFLAGS = -O2 -Wall -std=c11 -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -D_POSIX_SOURCE=1 -D_DEFAULT_SOURCE=1 -D_GNU_SOURCE=1

RM = /bin/rm -f

OBJL  = $(BINDIR)/liba2gs_ToolBox_Wizard_by_list.o
OBJJT = $(BINDIR)/liba2gs_ToolBox_Wizard_by_jumptable.o

LIBL  = $(BINDIR)/liba2gs_ToolBox_Wizard_by_list.a
LIBJT = $(BINDIR)/liba2gs_ToolBox_Wizard_by_jumptable.a

SOURCESL = $(SRCDIR)/wizard_by_list.c
SOURCESJT = $(SRCDIR)/wizard_by_jumptable.c

all: $(SOURCES)
	$(CC) -c -o$(OBJL)  -I$(INCDIR) $(SOURCESL)  $(CFLAGS)
	$(CC) -c -o$(OBJJT) -I$(INCDIR) $(SOURCESJT) $(CFLAGS)

	$(AR) rc $(LIBJT) $(OBJJT)
	$(AR) rc $(LIBL) $(OBJL)

	$(RANLIB) $(LIBJT)
	$(RANLIB) $(LIBL)

	-$(RM) $(BINDIR)/*.o

clean:
	-$(RM) $(BINDIR)/*
