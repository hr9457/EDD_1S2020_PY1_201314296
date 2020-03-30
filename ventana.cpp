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
    }

    //cola fichas disponibles
    if(op == 50)
    {        
        colaFichas.generarDot();
        colaFichas.generarPNG();
        colaFichas.abrirPNG();
    }

    //arbol binario
    if(op == 51)
    {
        arbol.generarDot();
        arbol.generarPNG();
        arbol.abrirPNG();
    }

    //arbol binario preorden
    if(op == 52)
    {
        arbol.generarDotPreorden();
        arbol.generarPNGPreorden();
        arbol.abrirPNGPreorden();
    }

    //arbol binario inorden
    if(op == 53)
    {
        arbol.generarDotInorden();
        arbol.generarPNGInorden();
        arbol.abrirPNGInorden();
    }

    //arbol binario postorden
    if(op == 54)
    {
        arbol.generarDotPostorden();
        arbol.generarPNGPostorden();
        arbol.abrirPNGPostorden();
    }

    //matriz
    if(op ==56)
    {
        //matrizScrabble.crearDOT();
        //matrizScrabble.crearPNG();
        //matrizScrabble.abrirPNG();
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
        cout<<"7. historial puntaje por jugador";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"8. matriz dispersa";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"9. lista contiene ficahs por de los jugadores";
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
    matrizScrabble.crearDOT();
    matrizScrabble.crearPNG();
    matrizScrabble.abrirPNG();


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
        listaJugador1.insertaFicha(letraLista,puntajeLista);
        //-------------- insertar en la lista del jugador2
        colaFichas.eliminarLetra(puntajeLista,letraLista);
        listaJugador2.insertaFicha(letraLista,puntajeLista);
    }
    
    
    //---------------------------------- JUGABILIDAD
    int entradaTeclado;
    int numeroJugador=1;
    int opMenuJugador;
    int puntajeJugador1,puntajeJugador2;
    //---------------------------------REPITE HASTA QUE TERMINEN EL JUEGO
    do
    {       

        //------------- PANTALLA PARA JUGADOR 1
        if(numeroJugador==1)
        {
            string validacionPalabra="";//PARA BUSCAR LA PALABRA EN LA BIBLIOTECA
            listaDoble listaUltimaJugada;//PARA GUARDAR LAS FICHAS QUE VA JUGANDO 

            //--------------REPTIR EL MENU HASTA
            do
            { 
                system("cls");//limpieza de pantalla
                system("color 2");//color de letras pantalla
                lineaMenu=5;//para posicionar el cursos arriba
                gotoxy(centroMenu,lineaMenu);
                cout<<"JUEGO INICIADO   -   ESC PARA SALIR";
                //---------ABRO SU LISTA CON SUS FICHAS DISPONIBLES
                listaJugador1.generarDOT(jugador1);
                listaJugador1.generarPNG();
                listaJugador1.abrirPNG();
                //----------MUESTRO EN SU PANTALLA LAS OPCIONES
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"JUGANDO JUGADOR 1: "<<jugador1;//muetro en patalla que jugador esta jugando
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"1. INGRESAR FICHA";
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"2. USAR FICHA DEL TABLERO";
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"3. INTERCAMBIAR MIS FICHAS";
                lineaMenu=lineaMenu+1;
                gotoxy(centroMenu,lineaMenu);
                cout<<"4. VALIDAR JUGADA";
                opMenuJugador=getch();
                //----------REVISANDO OP QUE ESCOGIO EL JUGADOR

                if(opMenuJugador==49)//OP PARA INSERTAR UNA FICHA EN EL JUEGO
                {
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
                    //------------SACO DE LA LISTA DEL JUGADOR
                    int puntajeReturnLista;
                    listaJugador1.eliminarFicha(letra,puntajeReturnLista);

                    //-----------CONCATENO LA PALABRA
                    validacionPalabra = validacionPalabra + letra;

                    //------------INGRESO A LA LISTA DE LA ULTIMA JUGADA
                    listaUltimaJugada.insertaFicha(letra,puntajeReturnLista);

                    //------------LA INGRESO A LA MATRIZ
                    matrizScrabble.insertarNodo(0,letra,puntajeReturnLista,posx,posy);//tipo,letra,puntaje,posx,posy
                
                }//FIN DE LA OPCION 1 DE INSERTAR UNA FICHA

                else if(opMenuJugador==50)//OP PARA USAR UNA FICHA EN EL TABLERO
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
                        validacionPalabra = validacionPalabra + letraEscogida;
                    }
                    else
                    {
                        lineaMenu=lineaMenu+1;
                        gotoxy(centroMenu,lineaMenu);
                        cout<<"LETRA NO SE ENCUNTRA EN EL TABLERO ";
                    }
                    
                }//FIN DE LA OPCION 2 DE ESCOGER UNA LETRA DEL TABLERO


                else if(opMenuJugador==51)//OPCION PARA QUE EL JUGADOR INTERCAMBIE TODOS SUS FICHAS
                {}//FIN DEL METODO PAR INTERCAMBIAR LAS FICHAS

                else if(opMenuJugador==52)//OPCION DONDE EL JUGADOR VALIDA SU JUGADA
                {
                    bool validacionDeJugada;
                    bibliotecaDePalabras.buscar(validacionPalabra,validacionDeJugada);//busco en la biblioteca
                    //reviso si exite o no en la biblioteca
                    if(validacionDeJugada==true)
                    {}
                    else
                    {                        
                    }
                    
                }//FIN DEL METODO PARA VALIDAR LA JUGADA
            

            }while(opMenuJugador!=54 || opMenuJugador!=27);//FIN DEL REPETIR HASTA QUE

            numeroJugador=2;
        }//FIN DE LA PANTALLA PARA EL JUGADOR 1


        //-----PANTALLA PARA JUGADOR 2
        else if(numeroJugador==2)
        {
            numeroJugador=1;
        }//FIN DE LA PANTALLA PARA EL JUGADOR 2

        entradaTeclado = getch();
    } while (entradaTeclado!=27);
    
    
    //abro las fichas disponibles para el jugador 1
    //para que inicie a jugar el jugador 1
    /*
    listaJugador1.generarDOT(jugador1);
    listaJugador1.generarPNG();
    listaJugador1.abrirPNG();
    */

}









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