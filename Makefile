all: geglx gesolar

geglx: geglx.c
	gcc -g -o $@ $^ -lGL -lGLU -lX11

gesolar: gesolar.c
	gcc -g -o $@ $^ -lGL -lGLU -lglut -lm

clean:
	rm geglx gesolar

