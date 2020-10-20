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

//-----------------------------------------------------------------------------------------------------

//FITA DE LEDS + DIP

//-----------------------------------------------------------------------------------------------------

void escolheEfeito(int num)
{
  switch(num) 
  {
    case 1:
    {
      currentPalette  = RainbowStripeColors_p;   
      currentBlending = NOBLEND;
      break;
    }
    case 2:
    {
      currentPalette  = CloudColors_p;           
      currentBlending = LINEARBLEND;
      break;
    }
    case 3:
    {
      currentPalette  = RainbowColors_p;         
      currentBlending = LINEARBLEND;
      break;
    }
    case 4:
    {
      currentPalette = CloudColors_p;           
      currentBlending = LINEARBLEND;
      break;
    }
    case 5:
    {
      currentPalette  = PartyColors_p;           
      currentBlending = LINEARBLEND;
      break;
    }
    case 6:
    {
      currentPalette  = myRedWhiteBluePalette_p; 
      currentBlending = NOBLEND;
      break;
    }
    case 7:
    {
      currentPalette  = myRedWhiteBluePalette_p; 
      currentBlending = LINEARBLEND;
      break;
    }      
    default:
    {
      //currentPalette  = RainbowColors_p;         
      //currentBlending = LINEARBLEND;
      //sinelon();
      break;
    }
  }  
}

void FillLEDsFromPaletteColors(uint8_t colorIndex)
{
  Serial.println(colorIndex);
  
  uint8_t brightness = 255;
    
  for( int i = 0; i < NUM_LEDS; i++) 
  {
    leds[i] = ColorFromPalette(currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 3;
  }
}

const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM =
{
    CRGB::Red,
    CRGB::Gray, // 'white' is too bright compared to red and blue
    CRGB::Blue,
    CRGB::Black,
    
    CRGB::Red,
    CRGB::Gray,
    CRGB::Blue,
    CRGB::Black,
    
    CRGB::Red,
    CRGB::Red,
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Blue,
    CRGB::Blue,
    CRGB::Black,
    CRGB::Black
};

void sinelon(int value)
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16(13, 0, NUM_LEDS-1 );
  leds[pos] += CHSV(value, 255, 192);
}


