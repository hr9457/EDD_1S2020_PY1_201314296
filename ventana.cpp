#include "ventana.h"

//contructor de la ventana
ventana::ventana()
{
    menu();//arranca el menu principal 
}



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


//-----------------para lectura y asignaciones respectivas del archivo json
void ventana::lecturaDeJson(json JSON)
{
    //GUARDO LA DIMESION PARA LA MATRIZ QUE TRAE EL ARCHIVO JSON
    dimensionMaxima = JSON.at("dimension");

    //creacion de la biblioteca  para la validacion de las palabras
    //for me ayuda saber la cantidad de labras que hay y buscarlas una por una
    
    for (int palabra = 0; palabra<JSON.at("diccionario").size() ; palabra++)
    {
        string palabraEncontrada = JSON.at("diccionario")[palabra].at("palabra");
        bibliotecaDePalabras.insertar(palabraEncontrada);
    }
}


//------------para la apertura de los reportes segun la opcion del usuario
void ventana::opReportes(int op)
{
    if(op == 49)
    {
        bibliotecaDePalabras.generarDot();
        bibliotecaDePalabras.generarPNG();
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
        inKeyborad=getch();//entrada por teclado para saber la entrada en codigo ascii
        opReportes(inKeyborad);//mando la entrada por teclado para la apertura de reporte
    } while (inKeyborad!=50);
    menu();
}





//-----------opciones del menu------------
void ventana::opMenu(int op)
{
    //-----------opcion 1 para la lectura del archiv json
    if(op==49)
    {
        gotoxy(centroMenu,lineaMenu);
        cout<<"ingrese la ruta del archivo json: ";
        lineaMenu = lineaMenu +1;
        gotoxy(centroMenu,lineaMenu);
        cout<<">>";
        cin>>rutaArchivo;

        ifstream archivojson(rutaArchivo);
        if(archivojson.fail())
        {
            lineaMenu = lineaMenu +1;
            gotoxy(centroMenu,lineaMenu);
            cout<<"no se encuentra el archivo";
            this->rutaArchivo = "";//vaciado de la variable
        }
        else
        {   
            //json JSON;
            archivojson>>JSON;
            lecturaDeJson(JSON);
        }
    }

    //1. jugar
    else if(op==50)
    {        
    }

    //3. jugadores
    else if(op==51)
    {
    }

    //4. reportes
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
        cout<<"1. Leer Archivo";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"2. Jugar";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"3. Jugadores";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"4. Reportes";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"5. Salir";
        lineaMenu=lineaMenu+3;
        inKeyborad=getch();//obtengo la entrada del  teclado 

        cout<<"valor entrada es: "<<inKeyborad;
        opMenu(inKeyborad);//envio de la entrada por teclado

    } while (inKeyborad!=53);//para cerrar la ventana      
 }




//desctructor de la ventana
ventana::~ventana(){}