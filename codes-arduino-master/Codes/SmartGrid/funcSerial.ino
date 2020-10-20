char conteudo[] = "";

//---------------------------------------------------------------
//FUNÇÕES
//---------------------------------------------------------------

//Procedimento usado para iniciar serial
void iniciaSerial(int Velocidade)
{
  //Iniciando comunicação serial
  Serial.begin(Velocidade);

    //Mensagem
    Serial.println("Iniciando comunicação serial...");  

  //-------------------------------------------------------------

  //Reservando espaço de memória para string a ser recebida
  //conteudo.reserve(NUM_CHARS_RX);
}

//---------------------------------------------------------------

//Procedimento usado para indicar evento na porta serial
void serialEvent() 
{
  //Caso a porta serial esteja disponível
  if(Serial.available() > 0)
  {                   
    //Variaveis locais  
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
  }
}

//---------------------------------------------------------------

//Procedimento usado para tratar dado recebido da serial
void trataDadosRecebidosSerial()
{
  //Variáveis locais
  String valRemota = "";

  //-------------------------------------------------------------
  
  //Verifica flag de string completa
    //Processando dado recebido - Leitura de dados
    if (conteudo == "pedidoLeitura") 
    {
      //Criando JSON
      criarJSON(); 
    }

    //-----------------------------------------------------------

    //Processando dado recebido - Gravar número remota    
    if (conteudo.substring(0, 12) == "gravaRemota(") 
    {
      //Criando JSON
      valRemota = conteudo.substring(conteudo.indexOf('(')+1, conteudo.indexOf(')'));

      //Grava EEPROM
      escreveInt(END1_REMOTA, END2_REMOTA, valRemota.toInt()); 
    }

    //-----------------------------------------------------------

    //Processando dado recebido - Leitura número remota    
    if (conteudo == "leNumRemota") 
    {
      //Escrevendo na serial
      Serial.print(lerInt(END1_REMOTA, END2_REMOTA));
    }

    //-----------------------------------------------------------

    //Processando dado recebido - Gravar nome remota    
    if (conteudo.substring(0, 10) == "gravaNome(") 
    {
      //Criando JSON
      valRemota = conteudo.substring(conteudo.indexOf('(')+1, conteudo.indexOf(')'));

      //Criando JSON
      escreveString(END_NOME_REM, valRemota);
    }

    //-----------------------------------------------------------

    //Processando dado recebido - Leitura nome remota    
    if (conteudo == "leNomeRemota") 
    {
      //Escrevendo na serial
      Serial.print(leString(END_NOME_REM));
    }

    //-----------------------------------------------------------

    //Processando dado recebido - Resetar remota    
    if (conteudo == "resetRemota") 
    {
      //Resetando
      software_Reset();
    }
    
    //-----------------------------------------------------------

    //Limpando variáveis para próximo evento de serial
    Serial.println(conteudo); 
}
