#include "ventana.h"

//contructor de la ventana
ventana::ventana()
{
    menu();//arranca el menu principal 
}




//----------metodo que grafica todo en la ventana
//----------metodo gotoxy----para dibujar en la consola
void ventana::gotoxy(int posx, int posy)
{
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = posx;  
    dwPos.Y= posy;  
    SetConsoleCursorPosition(hcon,dwPos);  
}



//---------------------- JSON
//--------------------- para lectura y asignaciones respectivas del archivo json
//--------------------- metodo para la opcion 1 de lectura de archivo json
/*
void ventana::lecturaDeJson(json JSON)
{
    //GUARDO LA DIMESION PARA LA MATRIZ QUE TRAE EL ARCHIVO JSON
    //limitar la entrada de posiciones  x,y con esta variable no ingreesa datos sobrepasen la matriz
    dimensionMaxima = JSON.at("dimension");

    //creacion de la biblioteca  para la validacion de las palabras
    //for me ayuda saber la cantidad de labras que hay y buscarlas una por una    
    for (int palabra = 0; palabra<JSON.at("diccionario").size() ; palabra++)
    {
        string palabraEncontrada = JSON.at("diccionario")[palabra].at("palabra");
        bibliotecaDePalabras.insertar(palabraEncontrada);
    }

    //creacion de la matriz principal donde se jugara
    //for me ayuda ver las casillas que tendran doble y triple puntuacion
    //for para casillas con doble puntuacion
    // valor 1 para casillas dobles
    
    for(int casilla = 0; casilla<JSON.at("casillas").at("dobles").size(); casilla++)
    {
        int posicionX = JSON.at("casillas").at("dobles")[casilla].at("x");
        int posicionY = JSON.at("casillas").at("dobles")[casilla].at("y");
        matrizScrabble.insertarNodo(1,0,posicionX,posicionY);//ingreso a la matriz un nodo con datos
        //cout<<"poscion x: "<<JSON.at("casillas").at("dobles")[casilla].at("x");
        //getch();
    }
    
    //for para casillas con triple puntuacion
    // valro 2 para casillas triples
    for(int casilla = 0; casilla<JSON.at("casillas").at("triples").size(); casilla++)
    {
        int posicionX = JSON.at("casillas").at("triples")[casilla].at("x");
        int posicionY = JSON.at("casillas").at("triples")[casilla].at("y");
        matrizScrabble.insertarNodo(2,0,posicionX,posicionY);//ingreso a la matriz
    }
    
}
*/



//---------------------- metodo para la opcion 2 JUGAR
void ventana::generarFichas()
{
    //insertando todas la letras con la que se van a jugar
    //------------ LISTADO OFICIAL EN LA PAGINA DEL PROYECTO
    //------------ 1PUNTO
    listaFichas.insertar(1,"A",12);
    listaFichas.insertar(1,"E",12);
    listaFichas.insertar(1,"O",9);
    listaFichas.insertar(1,"I",6);
    listaFichas.insertar(1,"S",6);
    listaFichas.insertar(1,"N",5);
    listaFichas.insertar(1,"L",4);
    listaFichas.insertar(1,"R",5);
    listaFichas.insertar(1,"U",5);
    listaFichas.insertar(1,"T",4);
    //------------ 2PUNTOS
    listaFichas.insertar(2,"D",5);
    listaFichas.insertar(2,"G",2);
    //------------ 3PUNTOS
    listaFichas.insertar(3,"C",4);
    listaFichas.insertar(3,"B",2);
    listaFichas.insertar(3,"M",2);
    listaFichas.insertar(3,"P",2);
    //------------ 4PUNTOS
    listaFichas.insertar(4,"H",2);
    listaFichas.insertar(4,"F",1);
    listaFichas.insertar(4,"V",1);
    listaFichas.insertar(4,"Y",1);
    //------------- 5PUNTOS
    listaFichas.insertar(5,"Q",1);
    //------------- 8PUNTOS
    listaFichas.insertar(8,"J",1);
    //listaFichas.insertar(8,"Ñ",1);
    listaFichas.insertar(8,"X",1);
    //-------------- 10PUNTOS
    listaFichas.insertar(10,"Z",1);

    //--------------CREAR LA COLA RANDOM
    int size = listaFichas.getSize();
    int puntajeReturn;
    string letraReturn;
    srand((unsigned)time(0)); 
    int numeroRandom;
    do
    {     
        numeroRandom = (rand()%size);//genero mi numero random

        listaFichas.eliminar(numeroRandom,puntajeReturn,letraReturn);//saco de mi lista ficha de esa posicion 
        colaFichas.insertarLetra(puntajeReturn,letraReturn);//lo ingreso en mi cola
        size = listaFichas.getSize();
    }while(size>0);
}





//------------------------- metodo para la ventana de la opcion  3
void ventana::opJugadores(int op)
{
    if(op == 49)
    {
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"ingrese el nombre del nuevo jugador ";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<">>>";
        cin>>nuevoJugador;
        arbol.insertarJugador(nuevoJugador);
    }
    
}

//------------------------- anadir jugadores
void ventana::ventanaJugadores()
{    
    do
    {
        arbol.generarDot();
        arbol.generarPNG();
        arbol.abrirPNG();
        //nodoArbol *auxRoot = arbol.getRoot();//para mostrar cuantos usuarios hay 
        system("cls");//limpieza de pantalla
        system("color 2");   
        lineaMenu=5;//para posicionar el cursos arriba
        gotoxy(centroMenu,lineaMenu);
        cout<<"-Ventana para agregar jugadores-";    
        lineaMenu = lineaMenu +1;        
        gotoxy(centroMenu,lineaMenu);
        cout<<"1. Agregar nuevo jugador: ";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"2. Salir";
        inKeyborad=getch();//entrada por teclado para saber la entrada en codigo ascii
        opJugadores(inKeyborad);
    }while (inKeyborad !=50);
    menu();//regreso al menu principal
}



//-----------------    para la apertura de los reportes segun la opcion del usuario
void ventana::opReportes(int op)
{
    //--------- generar el reporte de la lista circulas
    //--------- visualizar la biblioteca
    if(op == 49)
    {
        //bibliotecaDePalabras.generarDot();
        //bibliotecaDePalabras.generarPNG();
        //bibliotecaDePalabras.aperturaImagen();
        system("Reportes\\ListaCircular.png");
    }

    //cola fichas disponibles
    else if(op == 50)
    {        
        colaFichas.generarDot();
        colaFichas.generarPNG();
        colaFichas.abrirPNG();
    }

    //arbol binario
    else if(op == 51)
    {
        arbol.generarDot();
        arbol.generarPNG();
        arbol.abrirPNG();
    }

    //arbol binario preorden
    else if(op == 52)
    {
        arbol.generarDotPreorden();
        arbol.generarPNGPreorden();
        arbol.abrirPNGPreorden();
    }

    //arbol binario inorden
    else if(op == 53)
    {
        arbol.generarDotInorden();
        arbol.generarPNGInorden();
        arbol.abrirPNGInorden();
    }

    //para mostrar los record general de la aplicacion
    else if(op==55)
    {
        listaTOP.ordenamientoBurbuja();
        listaTOP.generarDOTGeneral();
    }

    //arbol binario postorden
    else if(op == 54)
    {
        arbol.generarDotPostorden();
        arbol.generarPNGPostorden();
        arbol.abrirPNGPostorden();
    }

    //matriz
    else if(op ==56)
    {
        //matrizScrabble.crearDOT();
        //matrizScrabble.crearPNG();
        //matrizScrabble.abrirPNG();
        system("Reportes\\Matriz.png");
    }

    //ultima lista de jugador
    else if(op==57)
    {
       system("Reportes\\ListaJugador.png"); 
    }

    //historila por jugador
    else if(op==70)
    {
        string nombre;
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"INGRESE EL NOMBRE DEL JUGADOR: ";
        cin>>nombre;
        arbol.puntajeOrdenado(nombre);
    }
}




//------------------   vetana para la visualizacion de los reportes de cada EDD
void ventana::ventanaReportes()
{
    do
    {
        system("cls");//limpieza de pantalla
        system("color 2");   
        lineaMenu=5;//para posicionar el cursos arriba
        gotoxy(centroMenu,lineaMenu);
        cout<<"-Reportes de las EDD-";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"1. Lista Circular";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"2. Cola Fichas disponibles";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"3. Arbol Binario";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"4. Recorrido preorden arbol binario";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"5. Recorrdio inorden arbol binario";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"6. Recorrdio postorden arbol binario";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"7. Scoreboard General jugadores";//55
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"8. matriz dispersa";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"9. lista contiene ficahs por de los jugadores";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"F. LISTADO INDIVIDUAL POR JUGADOR";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"Esc(Salir)";
        inKeyborad=getch();//entrada por teclado para saber la entrada en codigo ascii
        opReportes(inKeyborad);//mando la entrada por teclado para la apertura de reporte
    } while (inKeyborad!=27);
    menu();
}















//------------------------ METODO PARA INICIAR LA VENTANA DE INTERRACION CON EL JUEGO
void ventana::ventanaJugar()
{
    matrizDispersa matrizScrabble;//creo una matriz
    listaCircular bibliotecaDePalabras;//creo la lista para la biblioteca
    //----------------------- realizo la lectura del archivo json primero
    gotoxy(centroMenu,lineaMenu);
    cout<<"ingrese la ruta del archivo json: ";
    lineaMenu = lineaMenu +1;
    gotoxy(centroMenu,lineaMenu);
    cout<<">>";
    cin>>rutaArchivo;

    ifstream archivojson(rutaArchivo);
    if(archivojson.fail())//por si el archivo de entrada no se encuentra
    {
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"no se encuentra el archivo";
        getch();//espera de una entrada en teclado
        this->rutaArchivo = "";//vaciado de la variable
    }
    else//el archivo se encuentra en el ordenador
    {   
        //json JSON;
        archivojson>>JSON;
        //lecturaDeJson(JSON);//metodo realiza toda la lectura del archivo json
        //GUARDO LA DIMESION PARA LA MATRIZ QUE TRAE EL ARCHIVO JSON
        //limitar la entrada de posiciones  x,y con esta variable no ingreesa datos sobrepasen la matriz
        dimensionMaxima = JSON.at("dimension");

        //creacion de la biblioteca  para la validacion de las palabras
        //for me ayuda saber la cantidad de labras que hay y buscarlas una por una    
        for (int palabra = 0; palabra<JSON.at("diccionario").size() ; palabra++)
        {
            string palabraEncontrada = JSON.at("diccionario")[palabra].at("palabra");
            for (int i = 0; i < palabraEncontrada.length(); i++)
            {
                palabraEncontrada[i] = toupper(palabraEncontrada[i]);
            }            
            bibliotecaDePalabras.insertar(palabraEncontrada);
        }

        //creacion de la matriz principal donde se jugara
        //for me ayuda ver las casillas que tendran doble y triple puntuacion
        //for para casillas con doble puntuacion
        // valor 1 para casillas dobles
        
        for(int casilla = 0; casilla<JSON.at("casillas").at("dobles").size(); casilla++)
        {
            int posicionX = JSON.at("casillas").at("dobles")[casilla].at("x");
            int posicionY = JSON.at("casillas").at("dobles")[casilla].at("y");
            matrizScrabble.insertarNodo(1,"",0,posicionX,posicionY);//ingreso a la matriz un nodo con datos
            //cout<<"poscion x: "<<JSON.at("casillas").at("dobles")[casilla].at("x");
            //getch();
        }
        
        //for para casillas con triple puntuacion
        // valro 2 para casillas triples
        for(int casilla = 0; casilla<JSON.at("casillas").at("triples").size(); casilla++)
        {
            int posicionX = JSON.at("casillas").at("triples")[casilla].at("x");
            int posicionY = JSON.at("casillas").at("triples")[casilla].at("y");
            matrizScrabble.insertarNodo(2,"",0,posicionX,posicionY);//ingreso a la matriz
        }
    }//fin de la lectura json y asignacion 



    //-----------------------ABRO LA MATRIZ
    //-----------------------PARA QUE LOS JUGADORES PUEDAN VER EL TABLERO    
    //matrizScrabble.crearDOT();
    //matrizScrabble.crearPNG();
    //matrizScrabble.abrirPNG();
    bibliotecaDePalabras.generarDot();
    bibliotecaDePalabras.generarPNG();


    //----------------creo la pila aleatoriamente con las fichas 
    generarFichas();



    //--------------creo las dos lista de cada jugador    
    listaDoble listaJugador1;
    listaDoble listaJugador2;

    
    //asignos fichas a cada lista del jugador
    int puntajeLista;
    string letraLista;
    //insetando las 7 fichas en cada lista del jugador
    for (int i = 0; i < 7; i++)
    {
        //-------------- insertar en la lista del jugador1
        colaFichas.eliminarLetra(puntajeLista,letraLista);
        listaJugador1.insertaFicha(letraLista,puntajeLista,0,0);
        //-------------- insertar en la lista del jugador2
        colaFichas.eliminarLetra(puntajeLista,letraLista);
        listaJugador2.insertaFicha(letraLista,puntajeLista,0,0);
    }
    
    
    //---------------------------------- JUGABILIDAD
    int entradaTeclado;
    int numeroJugador=1;
    int opMenuJugador;
    int puntajeJugador1=0,puntajeJugador2=0;//puntajes por jugador
    int tamanioColaFichas;


    string palabraJugador1="";//PARA BUSCAR LA PALABRA EN LA BIBLIOTECA
    string palabraJugador2="";//PARA BUSCAR LA PALABRA EN LA BIBLIOTECA
    listaDoble ultimaJugada;//PARA GUARDAR LAS FICHAS QUE VA JUGANDO 
    int tamanioListaJugador1;
    int tamanioListaJugador2;

    //---------------------------------REPITE HASTA QUE TERMINEN EL JUEGO
    do
    { 
        //------------- PANTALLA PARA JUGADOR 1
        if(numeroJugador==1)
        {
            //------------------------PARA MOSTRAR AL JUGADOR CUANTAS FICHAS TIENE
            //------------------------  QUE FICHAS TIENE ACTUALMENTE
            listaJugador1.generarDOT(jugador1);
            listaJugador1.generarPNG();
            listaJugador1.abrirPNG();
            //--------------------------------------------------------------------
            //-----------------------ABRO LA MATRIZ
            //-----------------------PARA QUE LOS JUGADORES PUEDAN VER EL TABLERO    
            matrizScrabble.crearDOT();
            matrizScrabble.crearPNG();
            matrizScrabble.abrirPNG();
            

            system("cls");//limpieza de pantalla
            system("color 2");//color de letras pantalla
            lineaMenu=5;//para posicionar el cursos arriba
            gotoxy(centroMenu,lineaMenu);
            cout<<"JUEGO INICIADO   -   ESC PARA SALIR";
            
            //----------MUESTRO EN SU PANTALLA LAS OPCIONES
            lineaMenu=lineaMenu+1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"JUGANDO JUGADOR 1: "<<jugador1;//muetro en patalla que jugador esta jugando
            lineaMenu=lineaMenu+1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"1. INGRESAR FICHA";//49
            lineaMenu=lineaMenu+1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"2. USAR FICHA DEL TABLERO";//50
            lineaMenu=lineaMenu+1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"3. INTERCAMBIAR MIS FICHAS";//51
            lineaMenu=lineaMenu+1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"4. VALIDAR JUGADA";//52
            lineaMenu=lineaMenu+1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"5. SALTAR TURNO";//53


            entradaTeclado = getch();
            //----------REVISANDO OP QUE ESCOGIO EL JUGADOR

            if(entradaTeclado==49)//OP PARA INSERTAR UNA FICHA EN EL JUEGO
            {
                //--------------------------------------------------------------------
                string letra;
                int posx,posy;
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"INGRESE LA LETRA DE LA FICHA: ";
                cin>>letra;
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"INGRESE LA POSICION EN X: ";
                cin>>posx;
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"INGRESE LA POSICION EN Y: ";
                cin>>posy;

                //condicional para que no se salgo mas alla del tablero
                if(posx<=dimensionMaxima && posy<=dimensionMaxima)
                {
                    //------------SACO DE LA LISTA DEL JUGADOR
                    int puntajeReturnLista;

                    try
                    {
                        listaJugador1.eliminarFicha(letra,puntajeReturnLista);
                    }
                    catch(...)
                    {}

                    //sumo al puntaje del jugador
                    puntajeJugador1=puntajeJugador1+puntajeReturnLista;

                    //------------LA INGRESO A LA MATRIZ Y ACTUALIZO
                    matrizScrabble.insertarNodo(0,letra,0,posx,posy);//tipo,letra,puntaje,posx,posy
                    //matrizScrabble.crearDOT();
                    //matrizScrabble.crearPNG();
                    //matrizScrabble.abrirPNG();

                    //-----------CONCATENO LA PALABRA
                    palabraJugador1 = palabraJugador1 + letra;

                    //------------INGRESO A LA LISTA DE LA ULTIMA JUGADA
                    ultimaJugada.insertaFicha(letra,puntajeReturnLista,posx,posy);
                }
                else
                {
                    lineaMenu=lineaMenu+1;
                    gotoxy(centroMenu,lineaMenu);
                    cout<<"POSICIONES X Y Y SE SALEN DEL TABLERO DEL JUEGO";
                }

            }//FIN DE LA OPCION 1 DE INSERTAR UNA FICHA



            //-------------------EL USUARIO DESEEA USAR UNA FICHA DEL TABLERO
            else if(entradaTeclado==50)
            {
                string letraEscogida;
                int posxLetraEscogida, posyLetraEscogida;
                int puntajeEscogida;
                bool resultadoLetraBusqueda;

                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"INGRESE LA LETRA DE LA FICHA: ";
                cin>>letraEscogida;
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"INGRESE LA POSICION QUE ESTA EN X: ";
                cin>>posxLetraEscogida;
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"INGRESE LA POSICION QUE ESTA EN Y: ";
                cin>>posyLetraEscogida;

                //---------------BUSCO LA LETRA EN LA MATRIZ
                int puntajeDevuelta;
                resultadoLetraBusqueda=matrizScrabble.buscarNodo(posxLetraEscogida,posyLetraEscogida,puntajeDevuelta);//posx,posy,puntaje referencia

                //VERIFICACION DE LA PALABRA BUSCADA
                if(resultadoLetraBusqueda==true)
                {
                    //-----------CONCATENO LA PALABRA
                    palabraJugador1 = palabraJugador1 + letraEscogida;
                    //agrego al puntaje del jugador
                    puntajeJugador1=puntajeJugador1+puntajeDevuelta;
                }
                else
                {
                    lineaMenu=lineaMenu+1;
                    gotoxy(centroMenu,lineaMenu);
                    cout<<"LETRA NO SE ENCUNTRA EN EL TABLERO ";
                }
            }//FIN DE ESCOGE UNA FICHA DEL TABLERO



            //-------------------------ACAD DONDE EL USUARIO ESCOGIO 
            //-------------------------CAMBIAR TODOAS SUS FICHAS
            else if(entradaTeclado==51)
            {
                //MIRO CUANTAS FICHAS TIENE EL JUGADOR
                int cantidadFichasJugador = listaJugador1.getSize();
                for (int i = 0; i < cantidadFichasJugador; i++)
                {
                    string letra;
                    int puntajeReturn;
                    int posxReturnEliminacion;
                    int posyReturnEliminacion;
                    listaJugador1.eliminarUltimo(letra,puntajeReturn,posxReturnEliminacion,posyReturnEliminacion);
                    colaFichas.insertarLetra(puntajeReturn,letra);
                }
                //----ELIMINO LAS 7 FICHAS DEL JUGADOR DE SU LISTA
                //----Y LAS COLOCO NUEVAMENTE EN LA COLA DE FICHAS

                //----BUSCO FICHAS EN LA COLA
                //----LAS INSERTO EN LA LISTA DEL JUGADOR
                //cantidadFichasJugador = listaJugador1.getSize();
                for (int i=0; i < 7; i++)
                {
                    int puntaje;
                    string letra;
                    colaFichas.eliminarLetra(puntaje,letra);
                    listaJugador1.insertaFicha(letra,puntaje,0,0);
                }

                if(numeroJugador=1)
                {
                    numeroJugador=2;
                }
                
            }//FIN DEL INTERCAMBIO DE FICHAS



            //-------------------------ACA DONDE VALIDO LA JUGADA DEL JUEGO
            //------------------------Y ELIMINO DE LA MATRIZ SI LA PALABRAS ES INCORECTA
            else if(entradaTeclado==52)
            {
                bool validacionDeJugada;
                //CONDICION PARA QUE NO BUSQUE UNA PALABRA EN BLANCO
                if(palabraJugador1!="")
                {
                    bibliotecaDePalabras.buscar(palabraJugador1,validacionDeJugada);
                }

                if(validacionDeJugada==true && palabraJugador1!="")//si es valida la jugada
                {
                    //ver cuantas fichas tiene el jugador
                    tamanioListaJugador1 = listaJugador1.getSize();
                    for (tamanioListaJugador1; tamanioListaJugador1 < 6; tamanioListaJugador1++)
                    {
                        int puntaje;
                        string letra;
                        colaFichas.eliminarLetra(puntaje,letra);
                        listaJugador1.insertaFicha(letra,puntaje,0,0);
                    }
                    
                    //QUITO LAS FICHAS QUE EN LA ULTIMA JUGADA
                    ultimaJugada.setPrimero(NULL);
                    ultimaJugada.setUltimo(NULL);
                    //agrego a su puntuacion general
                    puntajeGeneralJugador1=puntajeGeneralJugador1+puntajeJugador1;
                    puntajeJugador1=0;
                    
                }
                else if(validacionDeJugada==false && palabraJugador1!="")
                {
                    //ELIMINO DE LA MATRIZ, Y LAS DEVUELVO A JUGADOR
                    do{
                        string letra;
                        int puntajeReturn;
                        int posxReturnEliminacion;
                        int posyReturnEliminacion;
                        ultimaJugada.eliminarUltimo(letra,puntajeReturn,posxReturnEliminacion,posyReturnEliminacion);
                        matrizScrabble.eliminarNodo(posxReturnEliminacion,posyReturnEliminacion);
                        listaJugador1.insertaFicha(letra,puntajeReturn,0,0);
                    }while(ultimaJugada.estdoLista()!=true);
                    //quito del puntaje que llevaba el jugador
                    puntajeJugador1=0;
                    //QUITO LAS FICHAS QUE EN LA ULTIMA JUGADA
                    ultimaJugada.setPrimero(NULL);
                    ultimaJugada.setUltimo(NULL);
                }
                else{}
                
                //borroo lo actual con la que se evaluo
                palabraJugador1 = "";
                //cambiar de jugador
                if(numeroJugador=1)
                {
                    numeroJugador=2;
                }

            }//FIN VALIDACION DE LA PALABRA

            //EL JUGADOR DECIDE SALTA SU TURNO
            else if(entradaTeclado==53)
            {
                if(numeroJugador=1)
                {
                    numeroJugador=2;
                }
            }

            //para salir del la jugabilidad
            else if(entradaTeclado==27)
            {
                puntajeGeneralJugador1=puntajeGeneralJugador1+puntajeJugador1;
                puntajeJugador1=0;
                break;
            }

        }//FIN DE LA PANTALLA PARA EL JUGADOR 1




        //------------- PANTALLA PARA JUGADOR 2
        else if(numeroJugador==2)
        {
            //------------------------PARA MOSTRAR AL JUGADOR CUANTAS FICHAS TIENE
            //------------------------  QUE FICHAS TIENE ACTUALMENTE
            listaJugador2.generarDOT(jugador2);
            listaJugador2.generarPNG();
            listaJugador2.abrirPNG();
            //--------------------------------------------------------------------
            //-----------------------ABRO LA MATRIZ
            //-----------------------PARA QUE LOS JUGADORES PUEDAN VER EL TABLERO    
            matrizScrabble.crearDOT();
            matrizScrabble.crearPNG();
            matrizScrabble.abrirPNG();
            

            system("cls");//limpieza de pantalla
            system("color 2");//color de letras pantalla
            lineaMenu=5;//para posicionar el cursos arriba
            gotoxy(centroMenu,lineaMenu);
            cout<<"JUEGO INICIADO   -   ESC PARA SALIR";
            
            //----------MUESTRO EN SU PANTALLA LAS OPCIONES
            lineaMenu=lineaMenu+1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"JUGANDO JUGADOR 2: "<<jugador2;//muetro en patalla que jugador esta jugando
            lineaMenu=lineaMenu+1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"1. INGRESAR FICHA";//49
            lineaMenu=lineaMenu+1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"2. USAR FICHA DEL TABLERO";//50
            lineaMenu=lineaMenu+1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"3. INTERCAMBIAR MIS FICHAS";//51
            lineaMenu=lineaMenu+1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"4. VALIDAR JUGADA";//52
            lineaMenu=lineaMenu+1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"5. SALTAR TURNO";//53


            entradaTeclado = getch();
            //----------REVISANDO OP QUE ESCOGIO EL JUGADOR

            if(entradaTeclado==49)//OP PARA INSERTAR UNA FICHA EN EL JUEGO
            {
                //--------------------------------------------------------------------
                string letra;
                int posx,posy;
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"INGRESE LA LETRA DE LA FICHA: ";
                cin>>letra;
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"INGRESE LA POSICION EN X: ";
                cin>>posx;
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"INGRESE LA POSICION EN Y: ";
                cin>>posy;
                //CONDICIONAL PARA QUE NO SALGA MAS ALLA DEL TABLERO DEL JUEGO
                if(posx<=dimensionMaxima && posy<=dimensionMaxima)
                {
                    //------------SACO DE LA LISTA DEL JUGADOR
                    int puntajeReturnLista;

                    try//por si surge un erro a la hora eliminar de la lista del jugador
                    {
                        listaJugador2.eliminarFicha(letra,puntajeReturnLista);
                    }
                    catch(...)
                    {}

                    //agergo al puntaje del jugador
                    puntajeJugador2=puntajeJugador2+puntajeReturnLista;

                    //------------LA INGRESO A LA MATRIZ Y ACTUALIZO
                    matrizScrabble.insertarNodo(0,letra,0,posx,posy);//tipo,letra,puntaje,posx,posy
                    //matrizScrabble.crearDOT();
                    //matrizScrabble.crearPNG();
                    //matrizScrabble.abrirPNG();

                    //-----------CONCATENO LA PALABRA
                    palabraJugador2 = palabraJugador2 + letra;

                    //------------INGRESO A LA LISTA DE LA ULTIMA JUGADA
                    ultimaJugada.insertaFicha(letra,puntajeReturnLista,posx,posy);
                }
                else
                {
                    lineaMenu=lineaMenu+1;
                    gotoxy(centroMenu,lineaMenu);
                    cout<<"POSICIONES X Y Y SE SALEN DEL TABLERO DEL JUEGO";
                }

            }//FIN DE LA OPCION 1 DE INSERTAR UNA FICHA



            //-------------------EL USUARIO DESEEA USAR UNA FICHA DEL TABLERO
            else if(entradaTeclado==50)
            {
                string letraEscogida;
                int posxLetraEscogida, posyLetraEscogida;
                int puntajeEscogida;
                bool resultadoLetraBusqueda;

                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"INGRESE LA LETRA DE LA FICHA: ";
                cin>>letraEscogida;
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"INGRESE LA POSICION QUE ESTA EN X: ";
                cin>>posxLetraEscogida;
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"INGRESE LA POSICION QUE ESTA EN Y: ";
                cin>>posyLetraEscogida;

                //---------------BUSCO LA LETRA EN LA MATRIZ
                int puntajeDevuelta;
                resultadoLetraBusqueda=matrizScrabble.buscarNodo(posxLetraEscogida,posyLetraEscogida,puntajeDevuelta);//posx,posy,puntaje referencia

                //VERIFICACION DE LA PALABRA BUSCADA
                if(resultadoLetraBusqueda==true)
                {
                    //-----------CONCATENO LA PALABRA
                    palabraJugador2 = palabraJugador2 + letraEscogida;
                    //agergo al puntaje del jugador
                    puntajeJugador2=puntajeJugador2+puntajeDevuelta;
                }
                else
                {
                    lineaMenu=lineaMenu+1;
                    gotoxy(centroMenu,lineaMenu);
                    cout<<"LETRA NO SE ENCUNTRA EN EL TABLERO ";
                }
            }//FIN DE ESCOGE UNA FICHA DEL TABLERO



            //-------------------------ACAD DONDE EL USUARIO ESCOGIO 
            //-------------------------CAMBIAR TODOAS SUS FICHAS
            else if(entradaTeclado==51)
            {
                //MIRO CUANTAS FICHAS TIENE EL JUGADOR
                int cantidadFichasJugador = listaJugador2.getSize();
                for (int i = 0; i < cantidadFichasJugador; i++)
                {
                    string letra;
                    int puntajeReturn;
                    int posxReturnEliminacion;
                    int posyReturnEliminacion;
                    listaJugador2.eliminarUltimo(letra,puntajeReturn,posxReturnEliminacion,posyReturnEliminacion);
                    colaFichas.insertarLetra(puntajeReturn,letra);
                }
                //----ELIMINO LAS 7 FICHAS DEL JUGADOR DE SU LISTA
                //----Y LAS COLOCO NUEVAMENTE EN LA COLA DE FICHAS

                //----BUSCO FICHAS EN LA COLA
                //----LAS INSERTO EN LA LISTA DEL JUGADOR
                //cantidadFichasJugador = listaJugador1.getSize();
                for (int i=0; i < 7; i++)
                {
                    int puntaje;
                    string letra;
                    colaFichas.eliminarLetra(puntaje,letra);
                    listaJugador2.insertaFicha(letra,puntaje,0,0);
                }
                //cambiar de jugador
                if(numeroJugador=2)
                {
                    numeroJugador=1;
                }
                
            }//FIN DEL INTERCAMBIO DE FICHAS



            //-------------------------ACA DONDE VALIDO LA JUGADA DEL JUEGO
            //------------------------Y ELIMINO DE LA MATRIZ SI LA PALABRAS ES INCORECTA
            else if(entradaTeclado==52)
            {
                bool validacionDeJugada;
                //mira que la palaabra no venga vacia
                if(palabraJugador2!="")
                {
                    bibliotecaDePalabras.buscar(palabraJugador2,validacionDeJugada);
                }

                if(validacionDeJugada==true && palabraJugador2!="")//si la jugada es valida
                {
                    //ver cuantas fichas tiene el jugador
                    tamanioListaJugador2 = listaJugador2.getSize();
                    for (tamanioListaJugador2; tamanioListaJugador2 < 6; tamanioListaJugador2++)
                    {
                        int puntaje;
                        string letra;
                        colaFichas.eliminarLetra(puntaje,letra);
                        listaJugador2.insertaFicha(letra,puntaje,0,0);
                    }
                    
                    //QUITO LAS FICHAS QUE EN LA ULTIMA JUGADA
                    ultimaJugada.setPrimero(NULL);
                    ultimaJugada.setUltimo(NULL);

                    //agrego a su puntuacion general
                    puntajeGeneralJugador2=puntajeGeneralJugador2+puntajeJugador2;
                    puntajeJugador2=0;
                }//fin de validez
                else if(validacionDeJugada==false && palabraJugador2!="")
                {
                    //ELIMINO DE LA MATRIZ, Y LAS DEVUELVO A JUGADOR
                    do{
                        string letra;
                        int puntajeReturn;
                        int posxReturnEliminacion;
                        int posyReturnEliminacion;
                        ultimaJugada.eliminarUltimo(letra,puntajeReturn,posxReturnEliminacion,posyReturnEliminacion);
                        matrizScrabble.eliminarNodo(posxReturnEliminacion,posyReturnEliminacion);
                        listaJugador2.insertaFicha(letra,puntajeReturn,0,0);
                    }while(ultimaJugada.estdoLista()!=true);
                    //le quito los puntos al jugadore
                    puntajeJugador2=0;
                    //QUITO LAS FICHAS QUE EN LA ULTIMA JUGADA
                    ultimaJugada.setPrimero(NULL);
                    ultimaJugada.setUltimo(NULL);
                }
                else{}
                //borroo lo actual con la que se evaluo
                palabraJugador2 = "";
                //cambiar de jugador
                if(numeroJugador=2)
                {
                    numeroJugador=1;
                }
            }

            //EL JUGADOR DECIDE SALTA SU TURNO
            else if(entradaTeclado==53)
            {
                if(numeroJugador=2)
                {
                    numeroJugador=1;
                }
            }

            //para salir del la jugabilidad
            else if(entradaTeclado==27)
            {
                puntajeGeneralJugador2=puntajeGeneralJugador2+puntajeJugador2;
                puntajeJugador2=0;
                break;
            }

        }//FIN DE LA PANTALLA JUGADOR 2


        //entradaTeclado = getch();
        //guardo la cantidad actual de la cola de fichas
        tamanioColaFichas = colaFichas.getSize();
    } while (entradaTeclado!=27 || tamanioColaFichas != 0);


    
    
}//----------------------------FIN DE LA JUGABILIDAD








///---------------------------- METODO PARA SELECIONAR EL JUGADOR
void ventana::selecionJugador(int op)
{
    if(op==49)
    {
        arbol.generarDot();
        arbol.generarPNG();
        arbol.abrirPNG(); 
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"Ingrese el nombre del primer jugador";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<">>";
        cin>>jugador1;
    	resultadoBusquedaJugador1 = arbol.buscarEnArbol(jugador1);

        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"Ingrese el nombre del segundo jugador";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<">>";
        cin>>jugador2; 
        resultadoBusquedaJugador2 = arbol.buscarEnArbol(jugador2);    
    }
    else if(op==50)
    {
        if(resultadoBusquedaJugador1==false && resultadoBusquedaJugador2==false)
        {
            lineaMenu=lineaMenu+1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"jugadores no exiten vuelva a selecionarlos";
            getch();
        }
        else
        {
            ventanaJugar();
            listaTOP.insertar(jugador1,puntajeGeneralJugador1);
            listaTOP.insertar(jugador2,puntajeGeneralJugador2);
            arbol.insertaPuntaje(jugador1,puntajeGeneralJugador1);
            arbol.insertaPuntaje(jugador2,puntajeGeneralJugador2); 
            rutaArchivo="";
            jugador1="";
            jugador2="";
            puntajeGeneralJugador1=0;            
            puntajeGeneralJugador2=0;
        }        
    }
}


//------------------------------ VENTANA PARA LA SELECCION DE LOS JUGADORES
void ventana::ventanaSelecionJugador()
{
    do
    {
        system("cls");//limpieza de pantalla
        system("color 2");   
        lineaMenu=5;//para posicionar el cursos arriba
        gotoxy(centroMenu,lineaMenu);
        cout<<"-Selecionar dos jugadores para iniciar la partida-";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"1. Selecionar jugadores";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"2. JUGAR";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"(Esc) para salir ";  
        inKeyborad=getch();//entrada por teclado para saber la entrada en codigo ascii
        selecionJugador(inKeyborad);
    } while (inKeyborad!=27);
    menu();
}













//------------------------------------------------
//-------------------opciones del menu------------
void ventana::opMenu(int op)
{
    //----------------------- opcion 1 para la lectura del archiv json
    /*
    if(op==49)
    {
        gotoxy(centroMenu,lineaMenu);
        cout<<"ingrese la ruta del archivo json: ";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<">>";
        cin>>rutaArchivo;

        ifstream archivojson(rutaArchivo);
        if(archivojson.fail())//por si el archivo de entrada no se encuentra
        {
            lineaMenu = lineaMenu +1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"no se encuentra el archivo";
            getch();//espera de una entrada en teclado
            this->rutaArchivo = "";//vaciado de la variable
        }
        else//el archivo se encuentra en el ordenador
        {   
            //json JSON;
            archivojson>>JSON;
            lecturaDeJson(JSON);//metodo realiza toda la lectura del archivo json
        }
    }
    */

    //--------------------------------  opcion 1 - jugar
    if(op==49)
    {   
        //generarFichas();//metodo realiza lo de las fichas
        ventanaSelecionJugador();
    }


    //--------------------------------  opcion 2 agregar jugadores
    else if(op==50)
    {
        ventanaJugadores();
        
    }

    //--------------------------------- opcion 4 ventana de  reportes
    else if(op==52)
    {
        ventanaReportes();
    }
}



//----------------menu principal- menu de arranque
void ventana::menu(){
    do
    {
        system("cls");//limpieza de pantalla
        system("color 2");
        //gotoxy(110,2);
        //gotoxy(1,1);
        //cout<<"ancho: "<<ancho<<" alto: "<<alto;
        lineaMenu=5;
        gotoxy(centroMenu,lineaMenu);
        cout<<"UNIVERSIDAD DE SAN CARLOS DE GUATEMALA";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"FACULTAD DE INGENIERIA";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"PROYECTO 1";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"HECTOR JOSUE OROZCO SALAZAR";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"201314296";
        lineaMenu=lineaMenu+5;

        gotoxy(centroMenu,lineaMenu);
        cout<<"MENU";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"1. Jugar";//entrar al juego
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"2. Agregar Jugadores";//agregar jugadores
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"3. Score Board";//top jugadores
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"4. Reportes";//reportes
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"(Esc) Salir";//salir de la aplicacion
        lineaMenu=lineaMenu+3;
        inKeyborad=getch();//obtengo la entrada del  teclado 

        //cout<<"valor entrada es: "<<inKeyborad;
        opMenu(inKeyborad);//envio de la entrada por teclado

    } while (inKeyborad!=27);//para cerrar la ventana      
 }




//desctructor de la ventana
ventana::~ventana(){}