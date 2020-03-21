#include "matrizDispersa.h"

//constructor
matrizDispersa::matrizDispersa()
{
    nodoMatriz *nodoTemporal = new nodoMatriz(0,0,-1,-1);
    this->root = nodoTemporal;
    this->inicioColumnas = root;
    this->finalColumnas = NULL;
    this->inicioFilas = root;
    this->finalFilas = NULL;
}



//estado de la matriz
bool matrizDispersa::estadoMatriz()
{
    if(root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }    
}






//----------------------------------------------------------------
//para insertar en la lista - en el lado que maneja las columnas
//apuntadores de siguiente y anterior en el root
nodoMatriz * matrizDispersa::insertarEnColumna(int posX)
{
    if(root->getSiguiente() == NULL)//si no hay ningun elemento en la matriz
    {
        nodoMatriz *nuevaColumna = new nodoMatriz(0,0,posX,0);
        root->setSiguiente(nuevaColumna);
        nuevaColumna->setAnterior(root);
        return nuevaColumna;
    }
    else
    {
        nodoMatriz *rootTemporal = root;
        //obtiene el nodo anterior para agregar el nuevo en el siguiente
        //para que la agregacion sea en orden
        while (rootTemporal->getSiguiente() != NULL && rootTemporal->getSiguiente()->getPosx()<posX)
        {
            rootTemporal = rootTemporal->getSiguiente();
        }

        //agregando despues de aver encontrado el nodo 
        if(rootTemporal->getSiguiente() == NULL)
        {
            nodoMatriz *nuevaColumna = new nodoMatriz(0,0,posX,0);
            rootTemporal->setSiguiente(nuevaColumna);
            nuevaColumna->setAnterior(rootTemporal);
            return nuevaColumna;
        }
        else if(rootTemporal->getSiguiente() != NULL && rootTemporal->getSiguiente()->getPosx() != posX)
        {
            nodoMatriz *nuevaColumna = new nodoMatriz(0,0,posX,0);
            nodoMatriz *nodoDerecha = rootTemporal->getSiguiente();
            rootTemporal->setSiguiente(nuevaColumna);
            nuevaColumna->setAnterior(rootTemporal);
            nuevaColumna->setSiguiente(nodoDerecha);
            nodoDerecha->setAnterior(nuevaColumna);
            return nuevaColumna;
        }
        else
        {
            nodoMatriz *columnaDeRetorno = rootTemporal->getSiguiente();
            return columnaDeRetorno;
        }
                        
    }
    return NULL;
}






//----------------------------------------------------------------
//para insertar en la matriz del lado que maneja las filas
//apuntadores de abajo y arriba
nodoMatriz *  matrizDispersa::insertarEnFila(int posY)
{
    if(root->getAbajo() == NULL)
    {
        nodoMatriz *nuevaFila = new nodoMatriz(0,0,0,posY);
        root->setAbajo(nuevaFila);
        nuevaFila->setArriba(root);
        return nuevaFila;
    }
    else
    {
        //recorrido hacia abajo en la filas
        //buscar nodo y posicionarme en el nodo anterior para insertar
        nodoMatriz *rootTemporal = root;
        while (rootTemporal->getAbajo()!=NULL && rootTemporal->getAbajo()->getPosy()<posY)
        {
            rootTemporal = rootTemporal->getAbajo();
        }

        //primer caso
        if(rootTemporal->getAbajo() == NULL)
        {
            nodoMatriz *nuevaFila = new nodoMatriz(0,0,0,posY);
            rootTemporal->setAbajo(nuevaFila);
            nuevaFila->setArriba(rootTemporal);
            return nuevaFila;
        }
        else if(rootTemporal->getAbajo()!=NULL && rootTemporal->getAbajo()->getPosy()!=posY)
        {
            nodoMatriz *nuevaFila = new nodoMatriz(0,0,0,posY);
            nodoMatriz *nodoAbajoTemporal = rootTemporal->getAbajo();
            rootTemporal->setAbajo(nuevaFila);
            nuevaFila->setArriba(rootTemporal);
            nuevaFila->setAbajo(nodoAbajoTemporal);
            nodoAbajoTemporal->setArriba(nuevaFila); 
            return nuevaFila;
        }
        else
        {
            nodoMatriz *filaDeRetorno = rootTemporal->getAbajo();
            return filaDeRetorno;
        }
                
    }  
    return NULL;  
}



//--------------------------------------------------------------------------------
//metodo que anida la informacion por columnas
void matrizDispersa::anidarInformacionColumna(nodoMatriz *columna,nodoMatriz *nodoTemporal)
{
    if(columna->getAbajo()==NULL)
    {
        columna->setAbajo(nodoTemporal);
        nodoTemporal->setArriba(columna);
    }
    else
    {
        //para buscar la posicion en la fila para insertar
        nodoMatriz *columnaTemporal = columna;
        while (columnaTemporal->getAbajo() != NULL && 
            columnaTemporal->getAbajo()->getPosy() < nodoTemporal->getPosy())
        {
            columnaTemporal = columnaTemporal->getAbajo();
        }

        //situaciones que pueden existir
        if(columnaTemporal->getAbajo() == NULL)
        {
            columnaTemporal->setAbajo(nodoTemporal);
            nodoTemporal->setArriba(columnaTemporal);
        }
        else if(columnaTemporal->getAbajo() != NULL && columnaTemporal->getAbajo()->getPosy() != nodoTemporal->getPosy())
        {
            nodoMatriz *nodoAbajo = columnaTemporal->getAbajo();
            columnaTemporal->setAbajo(nodoTemporal);
            nodoTemporal->setArriba(nodoTemporal);
            nodoTemporal->setAbajo(nodoAbajo);
            nodoAbajo->setArriba(nodoTemporal);
        }
        else if(columnaTemporal->getAbajo()!=NULL && columnaTemporal->getAbajo()->getPosy() == nodoTemporal->getPosy())
        {
            columnaTemporal->getAbajo()->setPalabra(nodoTemporal->getPalabra());               
        }        
    }
}



//------------------------------------------------------------------------------------
//--------------anidar la informacion en la filas corespondientes----------------------
void matrizDispersa::anidarInforamcionFila(nodoMatriz *fila,nodoMatriz *nodoTemporal)
{
    if(fila->getSiguiente()==NULL)
    {
        fila->setSiguiente(nodoTemporal);
        nodoTemporal->setAnterior(fila);    
    }
    else
    {
        //para buscar la posicion en la fila para insertar
        nodoMatriz *filaTemporal = fila;
        while (filaTemporal->getSiguiente() != NULL && 
            filaTemporal->getSiguiente()->getPosx() < nodoTemporal->getPosx())
        {
            filaTemporal = filaTemporal->getSiguiente();
        }

        //situaciones que pueden existir
        if(filaTemporal->getSiguiente() == NULL)
        {
            filaTemporal->setSiguiente(nodoTemporal);
            nodoTemporal->setAnterior(filaTemporal);
        }
        else if(filaTemporal->getSiguiente() != NULL && filaTemporal->getSiguiente()->getPosx() != nodoTemporal->getPosx())
        {
            nodoMatriz *nodoDerecha = filaTemporal->getSiguiente();
            filaTemporal->setSiguiente(nodoTemporal);
            nodoTemporal->setAnterior(nodoDerecha);
            nodoTemporal->setSiguiente(nodoDerecha);
            nodoDerecha->setAnterior(nodoTemporal);
        }
        else if(filaTemporal->getSiguiente()!=NULL && filaTemporal->getSiguiente()->getPosx() == nodoTemporal->getPosx())
        {
            filaTemporal->getSiguiente()->setPalabra(nodoTemporal->getPalabra());               
        }
        
    }
    
}





//------------------------------------------------------------------------------
//-------------------------insertar un nuevo nodo en la matriz
//-------------------------metodo que recibe los parametros iniciales para crear el nodo 
//-------------------------despues mandar a sus respetivos metodos para crea y buscar filas , columas
//-------------------------despues anido la info en su columnas y su fila
void matrizDispersa::insertarNodo(int tipoCasilla,char caracter,int posX,int posY)
{
    if(estadoMatriz() == true)
    {
    }
    else
    {
        //nodo que se va agregar dentro de la matriz
        nodoMatriz *nodoTemporal = new nodoMatriz(tipoCasilla,caracter,posX,posY);
        //buscamos o creamos su columna
        nodoMatriz *posicionColumna = insertarEnColumna(posX);
        //buscamos o creamos su fila
        nodoMatriz *posicionFila =  insertarEnFila(posY);

        cout<<"insercion se realizara en: ["<<posicionColumna->getPosx()
        <<","<<posicionFila->getPosy()<<"]"<<endl;

        //agregando informacion
        anidarInformacionColumna(posicionColumna,nodoTemporal);
        anidarInforamcionFila(posicionFila,nodoTemporal);
    }    
}




//--------------------codigo para pruebas---------------------------
//para la impresion y saber que columnas hay creadas
void matrizDispersa::imprimirColumnas()
{
    if(estadoMatriz() == true)
    {
        cout<<"no hay columnas en la matriz";
    }
    else
    {
        nodoMatriz *rootTemporal = root;
        while (rootTemporal != NULL)
        {
            cout<<rootTemporal->getPosx()<<"<->";
            rootTemporal = rootTemporal->getSiguiente();       
        }         
    }    
}



//para la impresion y saber que filas hay creadas
void matrizDispersa::imprimirFilas()
{
    if(estadoMatriz()==true)
    {
        cout<<"no hay filas en la matriz";
    }
    else
    {
        nodoMatriz *rootTemporal = root;
        while (rootTemporal != NULL)
        {
            cout<<rootTemporal->getPosy()<<"|"<<endl;
            rootTemporal = rootTemporal->getAbajo();
        }        
    }    
}


void matrizDispersa::impresionPorFilas(nodoMatriz *filaInicio)
{
    do
    {
        cout<<filaInicio->getPalabra()<<"<->";
        filaInicio = filaInicio->getSiguiente();    
    }while (filaInicio!=NULL);
}

void matrizDispersa::impresionPorColumnas(nodoMatriz *columnaIncio)
{
    do
    {
        cout<<columnaIncio->getPalabra()<<"|"<<endl;
        columnaIncio = columnaIncio->getAbajo();
    }while (columnaIncio != NULL);   
}


//para imprimir la lista fila por fila
void matrizDispersa::imprimirMatriz()
{
    if(estadoMatriz()==true)
    {
        cout<<"no hay elementos en la matriz";
    }
    else
    {      
        nodoMatriz *rootTemporal = root;
        
        do
        {
            impresionPorFilas(rootTemporal);
            cout<<endl;
            rootTemporal = rootTemporal->getAbajo();
        }while(rootTemporal!=NULL);     
        
        cout<<endl;
        //----------------------------------
        
        rootTemporal = root;
        do
        {
            impresionPorColumnas(rootTemporal);
            cout<<endl;
            rootTemporal = rootTemporal->getSiguiente();
        } while (rootTemporal!=NULL);
        
    }
}





//---------------------CODIGO PARA CREAR EL ARCHIVO DOT - IMAGEN VISUAL PARA EL JUGADOR--------------
//--------------------------------------------------------------------
//---------------------CREAR Y ENLAZAR COLUMNAS-----------------------
void matrizDispersa::columnasDOT(nodoMatriz *columnas,nodoMatriz *enlazeColumnas)
{
    //crear las columnas con su nombre
    while (columnas != NULL)
    {        
        archivo<<"C"<<columnas->getPosx()<<""<<columnas->getPosy()<<
        "[group ="<<contadorGroup<<",label=\""<<"C"<<columnas->getPosx()<<"\"];"<<endl;
        contadorGroup ++;
        columnas = columnas->getSiguiente();        
    }   

    while (enlazeColumnas != NULL)
    {
        archivo<<"C"<<enlazeColumnas->getPosx()<<""<<enlazeColumnas->getPosy();
        if(enlazeColumnas->getSiguiente() != NULL)
        {
            archivo<<"->";
        }
        enlazeColumnas = enlazeColumnas->getSiguiente();
    }

    archivo<<"[dir=both];"<<endl;

    archivo<<"{rank = same; matriz;";
    enlazeColumnas = root->getSiguiente();
    //ranke para la columna
    while (enlazeColumnas != NULL)
    {
        archivo<<"C"<<enlazeColumnas->getPosx()<<""<<enlazeColumnas->getPosy();
        if(enlazeColumnas->getSiguiente() != NULL)
        {
            archivo<<";";
        }
        enlazeColumnas = enlazeColumnas->getSiguiente();
    }    
    archivo<<"}"<<endl; 
}



//----------------------------------------------------------------------
//---------------------------CREAR Y ENLAZAR LAS FILAS
void matrizDispersa::filasDOT(nodoMatriz *filas,nodoMatriz *enlazeFilas)
{
    //creando filas con su nombre
    while (filas != NULL)
    {        
        archivo<<"F"<<filas->getPosx()<<""<<filas->getPosy()<<"[group = columna];"<<endl;
        filas = filas->getAbajo();        
    }

    while (enlazeFilas != NULL)
    {
        archivo<<"F"<<enlazeFilas->getPosx()<<""<<enlazeFilas->getPosy();
        if(enlazeFilas->getAbajo() != NULL)
        {
            archivo<<"->";
        }
        enlazeFilas = enlazeFilas->getAbajo();
    }
    archivo<<"[dir=both];";
}



//--------------------------------------------------------------------------
//--------------CREAR INFO Y ENLAZAR CON LAS FILAS--------------------------
void matrizDispersa::nodosFILASDOT(nodoMatriz *nodoInformacion)
{
    nodoMatriz *rankInformacion = nodoInformacion;//para poner a la misma altura

    //busco o creo la fila para poder anidar los nodos que puedan venir a la izquierda
    archivo<<"F"<<nodoInformacion->getPosx()<<""<<nodoInformacion->getPosy()<<
    "->";
    //paso al dato de la derecha
    nodoInformacion = nodoInformacion->getSiguiente();    
    while (nodoInformacion != NULL)
    {
        archivo<<"nodo"<<nodoInformacion->getPosx()<<""<<
        nodoInformacion->getPosy()<<"";
        //---------condicion por si el nodo tiene no exite la palabra
        if(nodoInformacion->getPalabra() != 0)
        {
            archivo<<nodoInformacion->getPalabra();
        }
        else
        {
            archivo<<"0";
        }
        //-----------------------------------------------------------
        if(nodoInformacion->getSiguiente() != NULL)
        {
            archivo<<"->";
        }
        nodoInformacion = nodoInformacion->getSiguiente();   
    } 
    archivo<<"[dir=both];"<<endl;

    archivo<<"{rank = same; ";
    archivo<<"F"<<rankInformacion->getPosx()<<""<<rankInformacion->getPosy()<<";";
    rankInformacion = rankInformacion->getSiguiente(); 

    while (rankInformacion != NULL)
    {
        archivo<<"nodo"<<rankInformacion->getPosx()<<""<<
        rankInformacion->getPosy(); 
        //-------------condicion saber si no viene la letra
        if(rankInformacion->getPalabra() != 0)
        {
            archivo<<rankInformacion->getPalabra()<<";";
        }
        else
        {
            archivo<<0<<";";
        }
        rankInformacion = rankInformacion->getSiguiente(); 
    }  
    archivo<<"}"<<endl; 
}



//--------------------------------------------------------------------------
//--------------CREAR INFO Y ENLAZAR CON LAS COLUMNAS--------------------------
void matrizDispersa::nodoCOLUMNASDOT(nodoMatriz *nodoInformacion)
{
    //crear los nodos que poseen informacion por columna
    nodoMatriz *crearNodo = nodoInformacion->getAbajo();
    while (crearNodo != NULL)
    {
        archivo<<"nodo"<<crearNodo->getPosx()<<""<<
        crearNodo->getPosy();
        //-------------condicion para saber si el nodo no contiene ninguna letra
        if(crearNodo->getPalabra() != 0)
        {
            archivo<<crearNodo->getPalabra();
        }
        else
        {
            archivo<<0;
        }


        archivo<<"[group ="<<contadorGroup<<",";
        //-------------condicion para saber si el nodo no contiene ninguna letra
        if(crearNodo->getPalabra() != 0)
        {
            archivo<<"label=\""<<crearNodo->getPalabra()<<"\"";
        }
        else
        {
            archivo<<"label=\"\"";
        }
        
        
        //----------- condicion para saber que color se colocara en el nodo -----------
        if(crearNodo->getTipoCasilla() == 0)
        {
            archivo<<"];"<<endl;
        }
        else if(crearNodo->getTipoCasilla() == 1)
        {
            archivo<<",style=filled,fillcolor=\"Indianred\"];"<<endl;
        }
        else
        {
            archivo<<",style=filled,fillcolor=\"cyan4\"];"<<endl;
        }
        
        crearNodo = crearNodo->getAbajo();   
    }

    //busco o creo la fila para poder anidar los nodos que puedan venir a la izquierda
    archivo<<"C"<<nodoInformacion->getPosx()<<""<<nodoInformacion->getPosy()<<
    "->";

    //paso al dato de la derecha
    //---metodo donde anido la informacion con sus columnas respectivas
    nodoInformacion = nodoInformacion->getAbajo();    
    while (nodoInformacion != NULL)
    {
        archivo<<"nodo"<<nodoInformacion->getPosx()<<""<<
        nodoInformacion->getPosy()<<"";
        //---------condicion por si el nodo tiene no exite la palabra
        if(nodoInformacion->getPalabra() != 0)
        {
            archivo<<nodoInformacion->getPalabra();
        }
        else
        {
            archivo<<"0";
        }
        
        //--------------------------------------
        if(nodoInformacion->getAbajo() != NULL)
        {
            archivo<<"->";
        }
        nodoInformacion = nodoInformacion->getAbajo();   
    } 
    archivo<<"[dir=both];"<<endl;   
}






//metodo para crear el dot del archivo
void matrizDispersa::crearDOT()
{
    archivo.open("ArchivosDot\\Matriz.dot",ios::out);
    if(archivo.fail()){
        cout<<"no se puedo abrir el archivo"<<endl;
    }else{

        archivo<<"digraph Matriz {"<<endl; 
        archivo<<"graph [ranksep=\"0.5\", nodesep=\"0.5\"];"<<endl;       
        archivo<<"node [shape=record];"<<endl;
        archivo<<"matriz[group = columna];"<<endl;
        
        //crea y anidar las columnas
        nodoMatriz *columnas = root->getSiguiente();
        nodoMatriz *enlazeColumnas = root->getSiguiente();

        //crear y anidad la filas
        nodoMatriz *filas = root->getAbajo();
        nodoMatriz *enlazeFilas = root->getAbajo();


        //para crear y anidar la informacion con las filas
        nodoMatriz *nodoInformacionFilas = root->getAbajo();//para empezar abajo de la raiz
        nodoMatriz *nodoInformacionColumnas = root->getSiguiente();//empezar a la izq de la raiz                    

        //crear y anidar columnas
        columnasDOT(columnas,enlazeColumnas);
        archivo<<"matriz->"<<"C"<<root->getSiguiente()->getPosx()<<""
        <<root->getSiguiente()->getPosy()<<"[dir=both];"<<endl;
        archivo<<endl;

        //crear y anidar filas
        filasDOT(filas,enlazeFilas);
        archivo<<endl;
        archivo<<"matriz->"<<"F"<<root->getAbajo()->getPosx()<<""
        <<root->getAbajo()->getPosy()<<"[dir=both];";
        archivo<<endl;
        archivo<<endl;


        
        //crear y anidar informacion por filas
        while (nodoInformacionFilas != NULL)
        {
            nodosFILASDOT(nodoInformacionFilas);
            nodoInformacionFilas = nodoInformacionFilas->getAbajo();
        }        
        archivo<<endl;
        

        //para alinear por group
        contadorGroup = 0;
        //crear y anidar informacion por columnas
        while (nodoInformacionColumnas != NULL)
        {
            nodoCOLUMNASDOT(nodoInformacionColumnas);
            nodoInformacionColumnas = nodoInformacionColumnas->getSiguiente();
            contadorGroup++;
        }
        archivo<<endl;
        

        archivo<<"}"<<endl; 
        archivo.close(); 
    }    
}





//-------------------CONVERTIR EL ARCHIVO DOT A PNG
void matrizDispersa::crearPNG()
{
    system("dot.exe -Tpng ArchivosDot\\Matriz.dot -o Reportes\\Matriz.png");
}


//---------------------  APERTURA DEL ARCHIVO PNG QUE SER GENERO ---------------------
void matrizDispersa::abrirPNG()
{
    system("Reportes\\Matriz.png");
}





//----------------------   destructor   ---------------------
matrizDispersa::~matrizDispersa(){}