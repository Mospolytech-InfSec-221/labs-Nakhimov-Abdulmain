#include <iostream>
#include <cstring>
using namespace std;

void finch(char *mas)
{
  char d;

  for (int i=0; i<256; i++)
  { 
    cin>>d;
    if (d == '.')
    {
      mas[i]='\0';

      break;
    }
    mas[i]=d;
  }  
}

void foutch(char *mas)
{
   for (int i=0; i<256; i++)
   {
    cout<<mas[i];
   }
}

bool Palindrom(char* mas) //proverka na palindrom
{   int i = 0;

    int j = strlen(mas) - 1;

      while (i < j) 
      {
        if (mas[i] == ' ') i++;

        if (mas[j] == ' ') j++;

          mas[i] = tolower(mas[i]);

          mas[j] = tolower(mas[j]);

             if (mas[i] != mas[j])
             {
                return false;
 
                break;
             }
        i++;
        
        j--;
      }
    return true;
}

int main()
{ 
  int c; cin>>c;  

  char mas[256] {};     

  swith (c)
  {
    case 1:
    {
      foutch(mas);

      finch(mas);

        break;
    }
    case 2:
    {
      finch(mas);

      cout<<(Palindrom(mas))<<endl;

        break;
    }
    case 3:
    {
      break;
    }
  }
}
