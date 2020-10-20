//-----------------------------------------------------------------------------------------------------

//FITA DE LEDS + DIP

//-----------------------------------------------------------------------------------------------------

//Configuração DIP Switch
void posicoesDIP(bool tipo)
{
  //TIPO
    //Endereçada
    if (tipo) fita_Tipo = true;
    //RGB
    else      fita_Tipo = false;

  //Config
  switch(config + 1) 
  {
    case 1:
    {
      //Endereçada
      if (fita_Tipo)
      {
        currentPalette  = RainbowStripeColors_p;   
        currentBlending = NOBLEND;  

        Serial.println("1 - Enderecada!");
      }
      //RGB
      else
      {
        Serial.println("1 - RGB!"); 
      }
      
      break;
    }  

    case 2:
    {
      //Endereçada
      if (fita_Tipo)
      {
        currentPalette  = CloudColors_p;           
        currentBlending = LINEARBLEND;

        Serial.println("2 - Enderecada!");
      }
      //RGB
      else
      {
        Serial.println("2 - RGB!");  
      }
      
      break;
    }
    case 3:
    {
      //Endereçada
      if (fita_Tipo)
      {
        currentPalette  = RainbowColors_p;         
        currentBlending = LINEARBLEND; 

        Serial.println("3 - Enderecada!");
      }
      //RGB
      else
      {
        Serial.println("3 - RGB!");  
      }
      
      break;
    }
    default:
    {
      //Endereçada
      if (fita_Tipo)
      {
        currentPalette  = RainbowColors_p;         
        currentBlending = LINEARBLEND;
        //sinelon(255);

        Serial.println("4 - Enderecada!");
      }
      //RGB
      else
      {
        Serial.println("4 - RGB!"); 
      }
      
      break;
    }
  }  
}

//-----------------------------------------------------------------------------------------------------

//Procedimento usado para pegar posição da cancela 
void PosicaoCancela()
{
  if ((fc_alto > VARIACAO) and (fc_baixo > VARIACAO))
  {
    //if (fc_baixo > rdAux)
    //{
      //Serial.println("Meio - Subindo");  

      sinelon(32, 32, 0, 60);

      exit;
    //}
    
    if (fc_alto < rdAux)
    {
      //sinelon(100);
      //Serial.println("Meio - Baixando");    
    }
  }
  else
  {
    if (fc_alto <= VARIACAO)
    {
      //Leitura atual
      rdAux = 1023;
      
      //sinelon(200);
      //Serial.println("Alto");
    }
  
    if (fc_baixo <= VARIACAO)
    {
      //Leitura atual
      rdAux = 0; 
   
      //sinelon(50);
      //Serial.println("Baixo");
    }  
  }
}

//-----------------------------------------------------------------------------------------------------

//Função FillLEDsFromPaletteColors - Auxiliar FastLED
void FillLEDsFromPaletteColors(uint8_t colorIndex)
{
  //Iniciando variáveis
  uint8_t brightness = 255;

  //Ativando LEDs
  for(int i = 0; i < NUM_LEDS; i++) 
  {
    leds[i] = ColorFromPalette(currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 3;
  }
}

//-----------------------------------------------------------------------------------------------------

//Procedimento sinelon - Auxiliar FastLED
void sinelon(uint8_t colorR, uint8_t colorG, uint8_t colorB, uint8_t velocidade)
{
  //Ponto colorido indo e voltando
  fadeToBlackBy(leds, NUM_LEDS, 20);
  
  //Posições
  int pos = beatsin16(velocidade, 0, NUM_LEDS-1);

  //Cores - GREEN, RED, BLUE
  leds[pos] = CRGB(colorG, colorR, colorB);
}

//-----------------------------------------------------------------------------------------------------

//Constante myRedWhiteBluePalette_p - Auxiliar FastLED
const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM =
{
    CRGB::Red,
    CRGB::Gray, 
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
