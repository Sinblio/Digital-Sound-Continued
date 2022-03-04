all: partb

partb: testmain

testmain: wave.o SoundSamples.o soundio.o TestMain.o
	g++ -o TestMain TestMain.o -lm

TestMain.o: TestMain.cpp
	g++ -c TestMain.cpp

wave.o: wave.cpp
	g++ -c wave.cpp

SoundSamples.o: SoundSamples.cpp
	g++ -c SoundSamples.cpp

soundio.o: soundio.cpp
	g++ -c soundio.cpp

clean:
	rm wave.o SoundSamples.o soundio.o TestMain.o TestMain
