/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "cena.hpp"

Cena *cena;
GLsizei largura, altura;

// Função callback de redesenho da janela de visualização
void Desenha(void)
{
  // Limpa a janela de visualização com a cor branca
  glClearColor(1,1,1,0);
  glClear(GL_COLOR_BUFFER_BIT);

  float w,h;
  if (largura <= altura){
    h = altura/largura;
    w = 1;
  }else{
    w = largura/altura;
    h = 1;
  }
  
  cena->RayTracing(60*w,40*h,25,largura,altura );
  
  //Executa os comandos OpenGL 
  glFlush();
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
  if (key == 27)
    exit(0);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
  largura = w;
  altura = h;
  
  // Especifica as dimensões da Viewport
  glViewport(0, 0, largura, altura);

  // Inicializa o sistema de coordenadas
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Estabelece a janela de seleção
  gluOrtho2D(0,largura,0,altura);
}


int main(int argc, char** argv){
  Camera *camera;
  Luz *luz;
  Esfera *esfera;
  Material *mat;
  Malha *malha;
  Cone *cone;
  Retangulo *ret;
  
  camera = new Camera(Vetor3(0,0,0),Vetor3(-0.5,0.0,1),Vetor3(0,1,0));
  camera->setLocalizacao(Vetor3(50,5,-30)  );
  
  luz    = new Luz( Vetor3(100,100,100) , Vetor3(0.4,0.4,0.4 ), Vetor3(0.6,0.6,0.6), Vetor3(0.5,0.5,0.5) );
  cena = new Cena(*luz,*camera,Vetor3(0,0,0));
  
  
  mat    = new Material( Vetor3(0.0215,0.1745,0.0215 ), Vetor3(0.07568,0.61424,0.07568), Vetor3(0.633,0.727811,0.633), Vetor3(0.0,0.0,0.0),
                         0.6*128.0, 1  );
  esfera = new Esfera(Vetor3(5,0,40), 10, *mat );
  cena->addObjeto(esfera);
  
  mat = new Material( Vetor3( 0.05, 0.05, 0.05 ), Vetor3(0.5,0.5,0.5), Vetor3(0.60,0.60,0.60), Vetor3(0.5,0.5,0.5),
                         0.078125*128.0, 1 );
  esfera = new Esfera(Vetor3(50,0,45), 10, *mat );
  cena->addObjeto(esfera);
  
  mat = new Material( Vetor3(0.1,0.1,0.6 ), Vetor3(0.2,0.2,0.7), Vetor3(1,1,1), Vetor3(0.0,0.0,0.0),
                         10, 1  );
  esfera = new Esfera(Vetor3(10,10,85), 20, *mat );
  cena->addObjeto(esfera);
  
  mat = new Material( Vetor3(0.4,0.1,0.1 ), Vetor3(0.7,0.2,0.2), Vetor3(0.54,0.2,0.2), Vetor3(0.0,0.0,0.0),
                         10, 1  );
  esfera = new Esfera(Vetor3(10,0,-25), 20, *mat );
  cena->addObjeto(esfera);
  
  malha = new Malha();
  mat = new Material( Vetor3(0.34,0.34,0.019 ), Vetor3(0.75,0.60,0.22), Vetor3(0.1,0.4,0.3), Vetor3(0.0,0.0,0.0),
                         0.4*128.0, 1  );
  malha->addFace(Vetor3(-20,-10,20),Vetor3(60,-10,20),Vetor3(60,-10,100),Vetor3(-20,-10,100) ,*mat);
  
  mat = new Material( Vetor3(0.0,0.3,0.3 ), Vetor3(0.2,0.6,0.7), Vetor3(0.3,0.3,0.3), Vetor3(0.0,0.0,0.0),
                         0.4*128.0, 1  );
  malha->addFace(Vetor3(-20,-10,100),Vetor3(60,-10,100),Vetor3(60,40,100) ,Vetor3(-20,40,100),*mat);
  
  mat = new Material( Vetor3(0.19,0.19,0.19 ), Vetor3(0.5,0.5,0.5), Vetor3(0.05,0.05,0.05), Vetor3(0.0,0.0,0.0),
                         0.4*128.0, 1  );
  
  malha->addFace(Vetor3(-20,-10,20) ,Vetor3(-20,-10,100),Vetor3(-20,40,100),Vetor3(-20,40,20), *mat);
  malha->addFace(Vetor3(60,-10,20) ,Vetor3(60,-10,100),Vetor3(60,40,100),Vetor3(60,40,20), *mat);
  
  mat = new Material( Vetor3(0.34,0.34,0.019 ), Vetor3(0.75,0.60,0.22), Vetor3(0.1,0.4,0.3), Vetor3(0.0,0.0,0.0),
                         0.4*128.0, 1  );
  malha->addFace(Vetor3(-20,40,20),Vetor3(60,40,20),Vetor3(60,40,100),Vetor3(-20,40,100) ,*mat);
  mat = new Material( Vetor3(0.0,0.2,0.2 ), Vetor3(0.1,0.5,0.6), Vetor3(0.2,0.2,0.2), Vetor3(0.7,0.7,0.7),
                         0.4*128.0, 1  );
  malha->addFace(Vetor3(-20,-10,20),Vetor3(60,-10,20),Vetor3(60,40,20) ,Vetor3(-20,40,20),*mat);
  cena->addObjeto(malha);

  mat = new Material( Vetor3(0.5,0.2,0.2 ), Vetor3(0.6,0.5,0.5), Vetor3(0.2,0.43,0.12), Vetor3(0.4,0.2,0.3),
                         0.6*128.0, 1.0  );
  cone = new Cone(Vetor3(40,-10,30),Vetor3(40,0,30),10,*mat );
  cena->addObjeto(cone);
  cone = new Cone(Vetor3(40,10,30),Vetor3(40,0,30),10,*mat );
  cena->addObjeto(cone);
  
  mat    = new Material( Vetor3(0.01,0.1,0.2 ), Vetor3(0.03,0.4,0.07), Vetor3(0.2,0.2,0.4), Vetor3(0.2,0.2,0.2), 50, 1  );
  malha = new Malha();
  malha->addFace(Vetor3(-90,20,0),Vetor3(-30,20,0),Vetor3(-30,20,60),Vetor3(-90,20,60),*mat);
  malha->addFace(Vetor3(-30,20,60),Vetor3(-90,20,60),Vetor3(-90,80,60),Vetor3(-30,80,60),*mat);
  malha->addFace(Vetor3(-90,80,0),Vetor3(-30,80,0),Vetor3(-30,80,60),Vetor3(-90,80,60),*mat);
  malha->addFace(Vetor3(-30,20,0),Vetor3(-30,20,60),Vetor3(-30,80,60),Vetor3(-30,80,0),*mat);
  malha->addFace(Vetor3(-90,20,60),Vetor3(-90,20,0),Vetor3(-90,80,0),Vetor3(-90,80,60),*mat);
  malha->addFace(Vetor3(-30,20,0),Vetor3(-30,20,0),Vetor3(-30,80,0),Vetor3(-90,80,0),*mat);
  cena->addObjeto(malha);
  
  mat    = new Material( Vetor3(0.1,0.4,0.1 ), Vetor3(0.3,0.7,0.3), Vetor3(0.3,0.4,0.2), Vetor3(0.0,0.0,0.0), 50, 1  );
  malha = new Malha();
  malha->addFace(Vetor3(40,-5,-10),Vetor3(50,-5,-10),Vetor3(45,-5,-20),*mat);
  malha->addFace(Vetor3(40,-5,-10),Vetor3(50,-5,-10),Vetor3(45,2,-15),*mat);
  malha->addFace(Vetor3(40,-5,-10),Vetor3(45,-5,-20),Vetor3(45,2,-15),*mat);
  malha->addFace(Vetor3(50,-5,-10),Vetor3(45,-5,-20),Vetor3(45,2,-15),*mat);
  cena->addObjeto(malha);
  
  mat    = new Material( Vetor3(0.4,0.1,0.4 ), Vetor3(0.7,0.3,0.6), Vetor3(0.4,0.1,0.5), Vetor3(0.0,0.0,0.0), 50, 1  );
  malha = new Malha();
  malha->addFace(Vetor3(50,8,-10),Vetor3(55,8,-10),Vetor3(55,8,-20),Vetor3(50,8,-20),*mat);
  mat    = new Material( Vetor3(0.4,0.1,0.4 ), Vetor3(0.7,0.3,0.6), Vetor3(0.4,0.1,0.5), Vetor3(0.7,0.5,0.7), 50, 1  );
  malha->addFace(Vetor3(50,8,-10),Vetor3(55,8,-10),Vetor3(52,0,-15),*mat);
  malha->addFace(Vetor3(50,8,-20),Vetor3(50,8,-10),Vetor3(52,0,-15),*mat);
  malha->addFace(Vetor3(55,8,-20),Vetor3(50,8,-20),Vetor3(52,0,-15),*mat);
  malha->addFace(Vetor3(55,8,-10),Vetor3(55,8,-20),Vetor3(52,0,-15),*mat);
  cena->addObjeto(malha);
  
  largura = 600;
  altura = 400;
  
  glutInit(&argc, argv);
  
  // Define do modo de operação da GLUT
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  
  // Especifica o tamanho inicial em pixels da janela GLUT
  glutInitWindowSize(largura,altura); 
 
  // Cria a janela passando como argumento o título da mesma
  glutCreateWindow("Ray Tracing");
   
  // Registra a função callback de redesenho da janela de visualização
  glutDisplayFunc(Desenha);
  
  // Registra a função callback de redimensionamento da janela de visualização
  glutReshapeFunc(AlteraTamanhoJanela);

  // Registra a função callback para tratamento das teclas ASCII
  glutKeyboardFunc (Teclado);
 
   //glPixelStorei(GL_UNPACK_ALIGNMENT,2);
 
  // Inicia o processamento e aguarda interações do usuário
  glutMainLoop();
  
}

