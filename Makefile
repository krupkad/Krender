EXE = main
CC = clang
CXX = clang++
CFLAGS = -Wall  -I. -O3 -march=native -fopenmp -g
CXXFLAGS = $(CFLAGS) -Wno-reorder
LDFLAGS =  -Llib -lglfw  -lsoil2  -lGLEW -lGL -liomp5 -L/usr/lib -lprofiler
SOIL_DIR = SOIL2
SOIL_OBJS = stb_image.o etc1_utils.o image_DXT.o stb_image_write.o image_helper.o SOIL2.o
OBJS = camera.o conf.o main.o	node.o scene.o shader.o texture.o util.o kdtree.o
OBJS += mesh/cube.o mesh/cylinder.o mesh/mesh.o mesh/object.o mesh/sphere.o
OBJS += EasyBMP/EasyBMP.cpp

all: $(EXE) Makefile

$(EXE): lib/libsoil2.so.1  $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

lib/libsoil2.so.1: $(addprefix $(SOIL_DIR)/,$(SOIL_OBJS))
	$(CXX) -Wl,-soname,$@ -shared $^ -o $@
	ln -s libsoil2.so.1 lib/libsoil2.so

.cpp.o: %.cpp %.hpp %.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.c.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o
	rm -rf mesh/.o
	rm -rf lib/libsoil2.so*

