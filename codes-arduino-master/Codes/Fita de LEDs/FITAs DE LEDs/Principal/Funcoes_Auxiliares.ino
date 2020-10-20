//-----------------------------------------------------------------------------------------------------

//FUNÇÕES PARA USO DE ARRAY DE CHAR

//-----------------------------------------------------------------------------------------------------

//Função usada para contar tamanho do array da char
byte charTam(char str[])
{
  //Variáveis
  byte tam;

  //Contando tamanho
  for (tam=0; str[tam]!='\0'; tam++);   

  //Retorno
  return tam;
}

//-----------------------------------------------------------------------------------------------------

//Função usada para verificar se dois arrays de char são iguais
bool charIgual(char str1[], char str2[])
{  
  //Comparando tamanho de dados
  if (charTam(str1) != charTam(str2))  return false;

  //Procurando diferenças
  for (int i=0; str1[i]!='\0'; i++)
  {
    //Comparando caracteres
    if (str1[i]!=str2[i]) return false;
  }

  //Palavras iguais
  return true;
}

//-----------------------------------------------------------------------------------------------------

//RESETAR

//-----------------------------------------------------------------------------------------------------

//Função usada para reiniciar o código
void software_Reset() 
{
  asm volatile ("  jmp 0");  
}


//-----------------------------------------------------------------------------------------------------

//MATH

//-----------------------------------------------------------------------------------------------------

//Função usada para calcular potência
int powint(int base, int exponent)
{
  //Variáveis
  int result = 1;

  //Cálculo
  for(;exponent > 0; exponent--)
    result *= base;
  
  //Retorno
  return result;
}

//-----------------------------------------------------------------------------------------------------

//DIP

//-----------------------------------------------------------------------------------------------------

//Função usada para verificar dados do DIP Switch
int bin2int(int numvalues, ...)
{
  //Variáveis
  int total = 0;
  va_list values;
  
  //Iniciando lista
  va_start(values, numvalues);

  //Cálculo
  for(;numvalues > 0; numvalues--)
    if (!(digitalRead(va_arg(values, int))) )
      total += powint(2, numvalues-1);

  //Finalizando lista
  va_end(values);

  //Retorno
  return total;
}
