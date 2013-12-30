//nombre: EDGAR CELESTINO LARIOS AMEZCUA
// practica process
#include <cstdlib>
#include <iostream>
#include<cstdio>
#define strg 100

using namespace std;

char cad[strg]="";
int estado=0;
int i=0; 
 

int delta (int estado, char evento){
     
  
 if((evento=='0') || (evento=='1')){
                                  
    if((estado==0) && (evento=='0')){
                   estado=1;              
    }
    else
     if((estado==0) && (evento=='1')){
                   estado=2;                  
    }
    else
     if((estado==1) && (evento=='0')){
                   estado=1;                   
    }
    else
     if((estado==1) && (evento=='1')){
                   estado=3;                 
    }
    else
     if((estado==2) && (evento=='0')){
                   estado=1;                
    }
    else
     if((estado==2) && (evento=='1')){
                   estado=4;                  
    }
    else
     if((estado==3) && (evento=='0')){
                   estado=1;                
    } 
    else  
     if((estado==3) && (evento=='1')){
                   estado=4;               
    } 
    else
     if((estado==4) && (evento=='0')){
                   estado=5;
    }
    else
      if((estado==4) && (evento=='1')){
                   estado=4;                   
    }
    else
     if((estado==5) && (evento=='0')){
                   estado=5;
    }
    else
     if((estado==5) && (evento=='1')){
                   estado=6;
    }
    else
     if((estado==6) && (evento=='0')){
                   estado=5;
    }
    else
     if((estado==6) && (evento=='1')){
                   estado=4;
    }
  }
  else{
     if(evento != '\0'){
     estado= -1;
     }                   
  }   
return estado;      
}
   
   
   
int process (int estado, char *evento) {
     
   int i=0;
   while(evento[i] != '\0'){
   
   cout<<"["<<estado<<","<<evento[i]<<"]";             
                    
      if(estado==6){
           cout<<" ACEPTADO"<<endl;
           estado= delta(estado, evento[i]);
           i++;
      }         
      else{
           cout<<" RECHAZO"<<endl;
           estado= delta(estado, evento[i]);
           i++;    
      }              
      if(estado==-1){
           cout<<"evento "<< evento[i-1]<<" es un estado indefinido"<<endl;   
           break; 
      }            
   }   
   return estado;
}


int processIN (int estado, char *evento) {
     
 
      cout<<"["<<estado<<","<<evento[i]<<"]"; 
                                
      if(estado==6){
           cout<<" ACEPTADO"<<endl;
           estado= delta(estado, evento[i]);
           i++;
      }         
      else{
           cout<<" RECHAZO"<<endl;
           estado= delta(estado, evento[i]);
           i++;    
      } 
      if(estado==-1){
           cout<<"evento "<< evento[i-1]<<" es un estado indefinido"<<endl;     
           i++;          
      }   
      if((evento[i] != '\0') &&( estado != -1)){
        estado=processIN(estado,evento);         
      }                   
   return estado;
}


bool test(char* str){
         
    bool verdad= false;
    int estado = process(estado,str); 
          
    cout<<"["<<estado<<",-] ";
      
    if(estado==-1){
           cout<<"RECHAZO"<<endl;                 
    }
    else   
      if(estado==6){
           cout<<"ACEPTADO"<<endl;
           verdad=true;
       }
       else{
           cout<<"RECHAZO"<<endl;
           verdad=false;
          }     
     return verdad;    
}
     
     
bool test2(char* str){
     
        
    
    int estado= processIN(estado,str); 
          
    cout<<"["<<estado<<",-] ";
      
    if(estado==-1){
           cout<<"RECHAZO"<<endl;                 
    }
    else {  
      if(estado==6){
           cout<<"ACEPTADO"<<endl;
           return true;
       }
       else{
           cout<<"RECHAZO"<<endl;
           return false;
          }     
}
 }
     
     


int main()
   {
        
   int opc=0,num=0;
   bool verdad;          
    cout<<"ingrese cadena de caracteres";
    cin>>cad;
    
   while(opc != 3){
                   
       cout<<"1-proceso inductivo"<<endl;
       cout<<"2-proceso iterativo"<<endl;
       cout<<"3- salir"<<endl;
       cout<<endl; 
       cin>>opc;    
   
        switch(opc){
    
           case 1:
              num=0;
              i=0;
               verdad= test(cad);
              cout<<endl;
              cout<<"FIN DEL PROCESAMIENTO"<<endl;
              if(verdad == true){
                  cout<<"LA CADENA ES ACEPTADA"<<endl;
              }
              else{
                  cout<<"LA CADENA NO ES ACEPTADA"<<endl;
             }  
              cout<<" presiona 3 para regresar al menu ";
              cin>>num;
              if(num==3)
                     system("cls");            
              break;
        
           case 2:
               num=0;
               i=0;
               verdad = test2(cad);
               cout<<endl;
               cout<<"FIN DEL PROCESAMIENTO"<<endl;
              if(verdad == true){
                  cout<<"LA CADENA ES ACEPTADA"<<endl;
              }
              else{
                  cout<<"LA CADENA NO ES ACEPTADA"<<endl;
             }  
               cout<<" presiona 3 para regresar al menu ";
               cin>>num;
               if(num==3)
                     system("cls"); 
               break;       
       }     
    }                                        
system("PAUSE>nul");
return EXIT_SUCCESS;   
}
          
