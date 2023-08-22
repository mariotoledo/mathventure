EXECUTABLE_NAME := bin/game

ALLEGRO_LIBS := allegro-5 \
	allegro_main-5 \
	allegro_image-5 \
	allegro_font-5 \
	allegro_audio-5 \
	allegro_acodec-5 \
	allegro_primitives-5

CC := gcc
PKG_CONFIG := pkg-config
CFLAGS := -g -Wall -MMD -Iinclude `$(PKG_CONFIG) --cflags $(ALLEGRO_LIBS)`
LIBS := `$(PKG_CONFIG) --libs $(ALLEGRO_LIBS)`

SOURCE_FILES := $(wildcard src/*.c)
OBJECT_FILES := $(patsubst src/%, obj/%, $(SOURCE_FILES:.c=.o))

DEPENDENCY_FILES := $(OBJECT_FILES:.o=.d)

$(EXECUTABLE_NAME): $(OBJECT_FILES)
	$(CC) $^ -o $(EXECUTABLE_NAME) $(LIBS)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(EXECUTABLE_NAME)

clean:
	$(RM) -r obj $(EXECUTABLE_NAME)

run: $(EXECUTABLE_NAME)
	./$(EXECUTABLE_NAME)

-include $(DEPENDENCY_FILES)

#gcc src/*.c -o main $(pkg-config allegro-5 allegro_main-5 allegro_font-5 --libs --cflags)
#gcc obj/main.o -o game `/opt/local/bin/pkg-config --libs allegro-5 allegro_main-5 allegro_image-5 allegro_font-5 allegro_audio-5 allegro_acodec-5 allegro_primitives-5`