CC = cc
AR = ar
RANLIB = ranlib

SRCDIR = ./src
INCDIR = ./inc
BINDIR = ./bin

CFLAGS_OPTIMIZATION = -g
#CFLAGS_OPTIMIZATION = -O3
CFLAGS_VERSION = -std=c11
CFLAGS_WARNINGS = -Wall -Wextra -Wno-unused-parameter -Wno-unused-but-set-parameter -Wno-unused-result
CFLAGS_DEFINES = -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -D_POSIX_SOURCE=1 -D_DEFAULT_SOURCE=1 -D_GNU_SOURCE=1
CFLAGS = $(CFLAGS_OPTIMIZATION) $(CFLAGS_VERSION) $(CFLAGS_WARNINGS) $(CFLAGS_DEFINES)

RM = rm -rf

OBJL  = $(BINDIR)/liba2gs_ToolBox_Wizard_by_list.o
OBJJT = $(BINDIR)/liba2gs_ToolBox_Wizard_by_jumptable.o
OBJR  = $(BINDIR)/liba2gs_ToolBox_Wizard_by_return.o

LIBL  = $(BINDIR)/liba2gs_ToolBox_Wizard_by_list.a
LIBJT = $(BINDIR)/liba2gs_ToolBox_Wizard_by_jumptable.a
LIBR  = $(BINDIR)/liba2gs_ToolBox_Wizard_by_return.a

SOURCESL  = $(SRCDIR)/wizard_by_list.c
SOURCESJT = $(SRCDIR)/wizard_by_jumptable.c
SOURCESR  = $(SRCDIR)/wizard_by_return.c

SAMPLEDIR = ./samples

all: clean list jumptable return
	-$(RM) $(BINDIR)/*.o

list:
	@echo
	@echo === Wizard lib LIST ==============================================
	$(CC) -c -o$(OBJL) $(SOURCESL) -I$(INCDIR) $(CFLAGS)
	$(AR) rc $(LIBL) $(OBJL)
	$(RANLIB) $(LIBL)

jumptable:
	@echo
	@echo === Wizard lib JUMPTABLE =========================================
	$(CC) -c -o$(OBJJT) $(SOURCESJT) -I$(INCDIR) $(CFLAGS)
	$(AR) rc $(LIBJT) $(OBJJT)
	$(RANLIB) $(LIBJT)

return:
	@echo
	@echo === Wizard lib RETURN ============================================
	$(CC) -c -o$(OBJR) $(SOURCESR) -I$(INCDIR) $(CFLAGS) -Wno-int-conversion
	$(AR) rc $(LIBR) $(OBJR)
	$(RANLIB) $(LIBR)

samples: clean list jumptable return
	@echo
	@echo === Building SAMPLES =============================================
	$(CC) -o $(BINDIR)/sample_List $(SAMPLEDIR)/sample_List.c -I$(INCDIR) -l a2gs_ToolBox_Wizard_by_list -L$(BINDIR) $(CFLAGS)
	$(CC) -o $(BINDIR)/sample_JumpTable $(SAMPLEDIR)/sample_JumpTable.c -l a2gs_ToolBox_Wizard_by_jumptable -L$(BINDIR) -I$(INCDIR) $(CFLAGS)
	$(CC) -o $(BINDIR)/sample_Return $(SAMPLEDIR)/sample_Return.c -l a2gs_ToolBox_Wizard_by_return -L$(BINDIR) -I$(INCDIR) $(CFLAGS) -Wno-incompatible-pointer-types

clean:
	-$(RM) $(BINDIR)/*
