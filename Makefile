clean:
	rm -rf bin && mkdir bin

build:
	g++ -I lib/gtest-1.6.0/include src/** test/** -o bin/test

runtest:
	bin/test

all: clean build runtest