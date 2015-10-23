#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int slumpaSiffra(int slumpMin, int slumpMax)
{
    int slumpadSiffra;
    
    srand(time(0));
    slumpadSiffra = rand() % slumpMax + slumpMin;
    
    return slumpadSiffra;
}

int gissaSiffra()
{
    int gissadSiffra;
    
    while(1)
    {
        cout << "Vilken siffra vill du gissa på?" << endl;
        cout << "1-50: "; cin >> gissadSiffra;
        cin.clear();
        cin.ignore(5000, '\n');
        
        if(gissadSiffra >= 1 && gissadSiffra <= 50)
        {
            break;
        }
        else
        {
            cout << "Ogiltigt val" << endl;
        }
    }
    
    return gissadSiffra;
}

bool spelaNy(string fraga)
{
    string svar;
    
    while(1)
    {
        cout << "Vill du spela " << fraga << "?" << endl;
        cout << "ja/nej: "; cin >> svar;
        
        if(svar == "ja" || svar == "nej")
        {
            break;
        }
        else
        {
            cout << "Ogiltigt val" << endl;
        }
    }
    
    if(svar == "ja")
    {
        return true;
    }
    else
    {
        return false;
    }
}

int gePoang(int antal)
{
    if(antal == 1)
    {
        return 10;
    }
    else if(antal < 2)
    {
        return 5;
    }
    else if(antal < 9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int slumpadeSiffror[50];
    int gissadeSiffror[50];
    int runda;
    int antalGissningar;
    int rundaGissningar;
    bool nyRunda;
    bool nyttSpel;
    int poang;
    int poangRunda;
    bool kvittDubbelt;
    int kvittSiffror[5];
    int slumpadKvitt;
    int svarKvitt;
    
    while(1)
    {
        cout << "Nytt spel" << endl;
        
        poang = 0;
        
        runda = -1;
        
        while(1)
        {
        	runda = runda + 1;

            cout << "Ny runda" << endl;
            cout << "Du har " << poang << " poäng" << endl;
            
            slumpadeSiffror[runda] = slumpaSiffra(1, 50);

            cout << "#Fusk: " << slumpadeSiffror[runda] << endl;
            
            antalGissningar = -1;
            
            for (int i = 0;i < 50 ; i++)
          	{
          		gissadeSiffror[i] = slumpaSiffra(1, 50);
          	}
            
            while(1)
            {
                antalGissningar = antalGissningar + 1;
                rundaGissningar = rundaGissningar + 1;
                
                gissadeSiffror[antalGissningar] = gissaSiffra();
                
                if(slumpadeSiffror[runda] == gissadeSiffror[antalGissningar])
                {
                    cout << "Du gissade rätt!"<< endl;
                    break;
                }
                else if(slumpadeSiffror[runda] < gissadeSiffror[antalGissningar])
                {
                    cout << "Det rätta svaret är mindre" << endl;
                }
                else if(slumpadeSiffror[runda] > gissadeSiffror[antalGissningar])
                {
                    cout << "Det rätta svaret är större" << endl;
                }
            }
            
            poangRunda = gePoang(antalGissningar);
            poang = poang + poangRunda;
            cout << "Du har vunnit " << poangRunda << " poäng och du har totalt " << poang << " poäng" << endl;
            
            kvittDubbelt = spelaNy("kvitt eller dubbelt");
                
            if( kvittDubbelt == true)
            {
                    if(poang > 0)
                    {
                        for(int i =0; i < 5; i++)
                        {   
                        	kvittSiffror[i] = slumpadeSiffror[slumpaSiffra(0, 50)];
                        }

                        slumpadKvitt = kvittSiffror[rand() % 5];
                        
                        cout << "#Fusk: " << slumpadKvitt << endl;
                        
                        cout << "Välj siffra" << endl;
                        for ( int i = 0; i < 5; i++ )
                        {
                          cout << kvittSiffror[i] << ' ';
                        }
                        cin >> svarKvitt;
                        cin.clear();
                        cin.ignore(5000, '\n');
                        
                        if(slumpadKvitt == svarKvitt)
                        {
                            poang = poang * 2;
                            cout << "Du gisade på rätt siffra och du har nu " << poang << " poäng" << endl;
                        }
                        else
                        {
                            poang = 0;
                            cout << "Du gissade på fel siffra och du har nu förlorat alla dina poäng" << endl;
                        }
                         
                    }
                    else
                    {
                        cout << "Du har inte nått kriterierna för att få spela kvitt eller dubbelt än" << endl;
                    }
            }

            
            nyRunda = spelaNy("en ny runda");
            
            if(nyRunda == false)
            {
                break;
            }
        }
        
        nyttSpel = spelaNy("ett nytt spel");
        
        if(nyttSpel == false)
        {
            break;
        }
    }
}
