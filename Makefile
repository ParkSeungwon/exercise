CFLAG = -g -fmax-errors=1 -lm
CC = gcc
SRC = $(wildcard *.c)
EXE = $(patsubst %.c, %.x, $(SRC))
TEX = $(patsubst %.tex, %.pdf, $(wildcard *.tex))
PNG = $(patsubst %.c, %.png, $(SRC))

all : $(EXE)
png : $(PNG)
tex : $(TEX)

%.x : %.c
	$(CC) $< -o $@ $(CFLAG)

%.png : %.x
	@echo "---------- 문제 $<\b\b번 실행을 시작합니다. --------------------------"
	./$<
	@echo "---------- 문제 $<\b\b번 실행을 종료합니다. -----------------------------"
	@gnome-screenshot -wBf $@

%.pdf : %.tex $(PNG) $(EXE) $(SRC)
	pdflatex $<
	evince $@

clean:
	rm $(EXE)
