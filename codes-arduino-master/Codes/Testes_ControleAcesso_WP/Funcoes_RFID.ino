//-----------------------------------------------------------------------------------------------------

//FUNÇÕES RFID

//-----------------------------------------------------------------------------------------------------

//Função usada para verificar a existência de uma credencial na EEPROM
void loop_RFID()
{
  //Variáveis
  String conteudoRFID = "";
  char conteudo[]     = "";
  
  //---------------------------------------------------------------------------------------------------

  //Olha por novos cartões
  if ( ! mfrc522.PICC_IsNewCardPresent()) return;
  
  //Seleciona um dos cartões
  if ( ! mfrc522.PICC_ReadCardSerial()) return;
  
  //Adquirindo cartão
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     conteudoRFID.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudoRFID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  //Colocando em letras maiúsculas
  conteudoRFID.toUpperCase();

  //Caso o dado ligo tenha tamanho maior que 0
  if (conteudoRFID.length()>0) 
  {
    //Adquirindo dados
    for (byte i=0, j=0; conteudoRFID[i] != '\0'; i++)
    {
      //Ignorando os espaços
      if (conteudoRFID[i] != ' ')
      {
        conteudo[j] = conteudoRFID[i];
        j++;      
      }
    }

    //Colocando caracter fim de string
    conteudo[8] = '\0'; 
    
    //-------------------------------------------------------------------------------------------------

    //Protocolo - RFID
      //Acrescentar
      if ((boolAcrescenta) and (!charIgual(CARTAO_ADD, conteudo)))
      {       
        //Adicionando
        if (verificaCredencial(conteudo) == -1)
        {
          //Adicionando credencial da EEPROM
          adicionaCredencialEEPROM(conteudo);  
        }
        else
        {
          //Buzzer
          AcionaBuzzer(1, 2000, 50); 
        }

        //Reiniciando código
        software_Reset();
      }
      
      //-----------------------------------------------------------------------------------------------
      
      //Deletar
      if ((boolDeleta) and (!charIgual(CARTAO_DEL, conteudo)))
      {
        //Deletando credencial da EEPROM
        deletaCredencialEEPROM(conteudo);

        //Reiniciando código
        software_Reset();
      }

      //-----------------------------------------------------------------------------------------------
      
      //Credencial usada para adicionar
      if (charIgual(CARTAO_ADD, conteudo)) 
      {
        //Flag para adição
        boolAcrescenta = true; 

        //Buzzer
        AcionaBuzzer(1, 1000, 50); 
        AcionaBuzzer(1,   50, 50); 
      }

      //-----------------------------------------------------------------------------------------------
      
      //Credencial usada para deletar
      if (charIgual(CARTAO_DEL, conteudo)) 
      {
        //Flag para deleção
        boolDeleta = true;

        //Buzzer
        AcionaBuzzer(1, 1000, 50); 
        AcionaBuzzer(3,   50, 50); 
      } 

      //-----------------------------------------------------------------------------------------------
      
      //Verifica credencial para entrada, ignora credenciais usadas para adicionar e deletar
      if ((!charIgual(CARTAO_ADD, conteudo)) and (!charIgual(CARTAO_DEL, conteudo)))
      {
        //Verifica existência da credencial
        if (verificaCredencial(conteudo) != -1) 
        {
          //Buzzer aprovação
          AcionaBuzzer(1, 50, 50);

          //Acionar porta
          acionamento_Rele();
        }
        else
        { 
          //Buzzer reprovação                                   
          AcionaBuzzer(3, 50, 50);
        }  
      }
     
    //-------------------------------------------------------------------------------------------------

    //Atraso para proxima leitura
    delay(TIME_REFRESH_LEITURA);
  }
}
