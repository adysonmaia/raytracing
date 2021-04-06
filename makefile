LIBS = -lm -lglut -lGLU -lGL
all: RayTracing

RayTracing: main.o cena.o objeto.o cone.o esfera.o retangulo.o malha.o triangulo.o plano.o camera.o raio.o matriz3.o matriz4.o vetor3.o vetor4.o
	g++ -o $@ $^ $(LIBS)
main.o: main.cpp cena.hpp
	g++ -c $<
cena.o: cena.cpp cena.hpp esfera.hpp camera.hpp prerequisitos.hpp
	g++ -c $<
esfera.o: esfera.cpp esfera.hpp objeto.hpp
	g++ -c $<
retangulo.o: retangulo.cpp retangulo.hpp triangulo.hpp
	g++ -c $<
malha.o: malha.cpp malha.hpp triangulo.hpp
	g++ -c $<
triangulo.o: triangulo.cpp triangulo.hpp plano.hpp
	g++ -c $<
plano.o: plano.cpp plano.hpp objeto.hpp
	g++ -c $<
cone.o: cone.cpp cone.hpp objeto.hpp
	g++ -c $<
objeto.o: objeto.cpp objeto.hpp matriz4.hpp raio.hpp
	g++ -c $<
camera.o: camera.cpp camera.hpp matriz4.hpp
	g++ -c $<
raio.o: raio.cpp raio.hpp vetor3.hpp
	g++ -c $<
matriz4.o: matriz4.cpp matriz4.hpp matriz3.hpp vetor4.hpp vetor3.hpp
	g++ -c $<
matriz3.o: matriz3.cpp matriz3.hpp vetor3.hpp
	g++ -c $<
vetor4.o: vetor4.cpp vetor4.hpp prerequisitos.hpp
	g++ -c $<
vetor3.o: vetor3.cpp vetor3.hpp prerequisitos.hpp
	g++ -c $<
clean:
	-rm -f *.o
