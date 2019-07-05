CFLAGS = -O3
LDFLAGS =
appname = eagle
HEADERS = main.h

all: $(appname)
.PHONY: all clean

clean:
	rm -f $(appname) *.o

sdl_cflags := $(shell pkg-config --cflags sdl2 SDL2_mixer)
sdl_libs := $(shell pkg-config --libs sdl2 SDL2_mixer)
override CFLAGS += $(sdl_cflags)
override LIBS += $(sdl_libs)

$(appname): zozo.o
	$(CC) $(HEADERS) $(LDFLAGS) -o $@ $^ $(LIBS) -lSDL2_image 
