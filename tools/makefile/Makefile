OBJECTS = main.o
TARGET = hello

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^
	@echo you see lyp

main.o: main.c version.h

version.h: new_header

new_header:
	@sed -e "s/<version>/$$(git describe)/g" <version.h.in> version.h  
	@if diff -q version.h.tmp version.h >/dev/null 2>&1; \
	then \
		rm resion.h.tmp \
	else \
		echo "version.j in => version.h ;" \
		mv version.h.tmp version.h;\
	fi

clean:
	rm -f $(TARGET) $(OBJECT) version.h

lyp:
	@echo hello lyp
.PHONY: all clean
