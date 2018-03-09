#include <stdio.h>
#include <math.h>
/*Falta implementar fatorial*/
double CharToDouble(char n)
{
  double i;
  switch(n)
  {
     case '0': i = 0;
     break;
     case '1': i = 1;
     break;
     case '2': i = 2;
     break;
     case '3': i = 3;
     break;
     case '4': i = 4;
     break;
     case '5': i = 5;
     break;
     case '6': i = 6;
     break;
     case '7': i = 7;
     break;
     case '8': i = 8;
     break;
     case '9': i = 9;
     break;
     default: return 0;
  }   
  return i;
}

double PontoFlutuante(char a)
{
}

int CondicaoDeSoma(char b)
{
  switch(b)
  {
     case '0': return 1;
     break;
     case '1': return 1;
     break;
     case '2': return 1;
     break;
     case '3': return 1;
     break;
     case '4': return 1;
     break;
     case '5': return 1;
     break;
     case '6': return 1;
     break;
     case '7': return 1;
     break;
     case '8': return 1;
     break;
     case '9': return 1;
     break;
     case ' ': return 1;
     break;
     case '.': return 1;
     break;
     case '!': return 1;
     break;
     default: return 0;
  } 
}

double fatorial(char d)
{
  switch(d)
  {
     case '0': return 1;
     break;
     case '1': return 1;
     break;
     case '2': return 2;
     break;
     case '3': return 6;
     break;
     case '4': return 24;
     break;
     case '5': return 120;
     break;
     case '6': return 720;
     break;
     case '7': return 5040;
     break;
     case '8': return 40320;
     break;
     case '9': return 362880;
     break;
     default: return 0;
  } 
}

int main(void)
{
  char c;
  int condicao = 0, i = 0, j = 0, n, m = 0, dezenas;
  int dizima = 0;
  double potencia = 0;
  double somaDinamica = 0;
  double somaDinamicaFlutuante = 0;
  double somaFatorial = 0;
  double somaFinal = 0;
  char cadeia[1028];
  char decada[1028];
  // printf("Dê entrada de caracteres:");
  /*Permite entrada de caracteres enquanto a entrada não é quebra de linha*/
  for(; c!= '\n';)
  {
    scanf("%c", &c);
    cadeia[i] = c;
    
    if(cadeia[i] == '!' && condicao == 0) {somaFatorial = somaFatorial + fatorial(cadeia[i-1])-CharToDouble(cadeia[i-1]);}
    i++;
    
    if(c == '.')
    { 
      dizima = 1;
    }
    
    if(dizima)
    {
      somaDinamicaFlutuante = somaDinamicaFlutuante + (CharToDouble(c)/pow(10,potencia));
      potencia += 1;
    }
    /* else
     {
     decada[j] = c; 
     j+=1;
     }*/
     
     else somaDinamica = somaDinamica + CharToDouble(c);
     
    if(c == ' ' || c == '\n')
    {
           
      if(condicao)
      {
       somaDinamica = 0;
       somaDinamicaFlutuante = 0;
       somaFatorial = 0;
       condicao = 0;
      }
      
      /*for(n = j-1; n >= 0; n--)
      {
	somaDinamica = somaDinamica + CharToDouble(decada[n])*pow(10, m);
	m++;
      }*/
      
      somaFinal = somaFinal + somaDinamica + somaDinamicaFlutuante + somaFatorial;
      i = 0;
      j = 0;
      m = 0; 
      potencia = 0;
      dizima = 0;
      somaDinamica = 0;
      somaDinamicaFlutuante = 0;
      somaFatorial = 0;
    }
     else if(!CondicaoDeSoma(c)) 
     {
      condicao = 1;   
     }
     
     /*somaFinal = somaFinal + somaDinamica + somaDinamicaFlutuante + somaFatorial;*/
     
  }   
  printf("%.2f\n", somaFinal);
  return 0;
}

