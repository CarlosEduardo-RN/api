//-----------------------------------------------------------------------------------------------------

//FUNÇÕES SERIAL

//-----------------------------------------------------------------------------------------------------

//Função usada para realizar a leitura da porta serial
void thread_leSerial()
{
  //Caso a porta serial esteja disponível
  if(Serial.available() > 0)
  {                   
    //Variaveis locais  
    char conteudo[] = "";
    char caractere;
    byte charcont = 0;

    //-------------------------------------------------------------------------------------------------

    // Enquanto receber algo pela serial  
    while(Serial.available() > 0) 
    { 
      //Lê byte da serial 
      caractere = Serial.read();              
                    
      //Ignora caractere de quebra de linha  
      if(caractere != '\n') conteudo[charcont] = caractere;             

      //Contador
      charcont++;
      
      //Aguarda buffer serial ler próximo caractere  
      delay(1);                              
    }

    //Colocando caracter fim de string
    conteudo[charcont] = '\0';

    //-------------------------------------------------------------------------------------------------

    //Protocolo - SERIAL
      //Limpar EEPROM
      if (charIgual("limpar", conteudo)) limpaEEPROM();

      //Mostrar EEPROM
      if (charIgual("mostrar", conteudo)) mostraEEPROM();

      //Contagem EEPROM
      if (charIgual("contagem", conteudo)) Serial.println(contagemEEPROM());             
  } 
}
