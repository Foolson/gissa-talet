#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int slumpaSiffra()
{
    int slumpadSiffra;
    
    srand(time(NULL));
    slumpadSiffra = rand() % 50 + 1;
    
    return slumpadSiffra;
}

int gissaSiffra()
{
    int gissadSiffra;
    
    while(1)
    {
        cout << "Vilket tal vill du gissa på?" << endl;
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
    else if(antal < 3)
    {
        return 5;
    }
    else if(antal < 10)
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
        antalGissningar = -1;
        
        while(1)
        {
        	runda = runda + 1;

            cout << "Ny runda" << endl;
            cout << "Du har " << poang << " poäng" << endl;
            
            slumpadeSiffror[runda] = slumpaSiffra();

            cout << "#Fusk: " << slumpadeSiffror[runda] << endl;
            
            rundaGissningar = 0;
            
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
            
            poangRunda = gePoang(rundaGissningar);
            cout << "Du har vunnit " << poangRunda << " poäng och du har totalt " << poang << " poäng" << endl;
            
            poang = poang + poangRunda;
            

            kvittDubbelt = spelaNy("kvitt eller dubbelt");
                
            if( kvittDubbelt == true)
            {
                    if(antalGissningar > 3 && poang > 0)
                    {
                        kvittSiffror[0] = gissadeSiffror[0];
                        kvittSiffror[1] = gissadeSiffror[1];
                        kvittSiffror[2] = gissadeSiffror[2];
                        kvittSiffror[3] = gissadeSiffror[3];
                        kvittSiffror[4] = gissadeSiffror[4];
                        
                        slumpadKvitt = kvittSiffror[rand() % 5];
                        
                        cout << "#Fusk: " << slumpadKvitt << endl;
                        
                        cout << "Välj siffra" << endl;
                        cout << kvittSiffror[0] << ", " << kvittSiffror[1] << ", " << kvittSiffror[2] << ", " << kvittSiffror[3] << ", " << kvittSiffror[4] << ": ";
                        cin >> svarKvitt;
                        cin.clear();
                        cin.ignore(5000, '\n');
                        
                        if(slumpadKvitt == svarKvitt)
                        {
                            poang = poang * 2;
                            cout << poang << endl;
                        }
                        else
                        {
                            poang = 0;
                            cout << poang << endl;
                        }
                         
                    }
                    else
                    {
                        cout << "Du har inte nått kriterierna för att spela kvitt eller dubbelt" << endl;
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