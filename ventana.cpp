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




//------------para la apertura de los reportes segun la opcion del usuario
void ventana::opReportes(int op)
{
    //--------- generar el reporte de la lista circulas
    //--------- visualizar la biblioteca
    if(op == 49)
    {
        bibliotecaDePalabras.generarDot();
        bibliotecaDePalabras.generarPNG();
        bibliotecaDePalabras.aperturaImagen();
    }
    //visualizar la matriz
    if(op == 50)
    {
        matrizScrabble.crearDOT();
        matrizScrabble.crearPNG();
        matrizScrabble.abrirPNG();
    }
}




//-------------vetana para la visualizacion de los reportes de cada EDD
void ventana::ventanaReportes()
{
    do
    {
        system("cls");//limpieza de pantalla
        system("color 2");   
        lineaMenu=5;//para posicionar el cursos arriba
        gotoxy(centroMenu,lineaMenu);
        cout<<"Reportes de las EDD";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"1. Lista Circular";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"2. Matriz juego";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"3. Salir";
        inKeyborad=getch();//entrada por teclado para saber la entrada en codigo ascii
        opReportes(inKeyborad);//mando la entrada por teclado para la apertura de reporte
    } while (inKeyborad!=51);
    menu();
}




//------------------------------------------------
//-------------------opciones del menu------------
void ventana::opMenu(int op)
{
    //----------------------- opcion 1 para la lectura del archiv json
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

    //--------------------------------  1. jugar
    else if(op==50)
    {        
    }

    //3. jugadores
    else if(op==51)
    {
    }

    //------------------------------ 4. reportes
    else if(op==53)
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
        cout<<"1. Leer Archivo";//leer un archivo json
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"2. Jugar";//entrar al juego
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"3. Jugadores";//ver y ingreso de juadores
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"4. Score Board";//record de los jugadores
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"5. Reportes";//ventana de reportes
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"6. Salir";//salir de la aplicacion
        lineaMenu=lineaMenu+3;
        inKeyborad=getch();//obtengo la entrada del  teclado 

        //cout<<"valor entrada es: "<<inKeyborad;
        opMenu(inKeyborad);//envio de la entrada por teclado

    } while (inKeyborad!=54);//para cerrar la ventana      
 }




//desctructor de la ventana
ventana::~ventana(){}