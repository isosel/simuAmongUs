#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main()
{
    int valRand1 = 0;
    int valRand2 = 0;


    string joueur[10] =
    {
        "P0",
        "P1",
        "P2",
        "P3",
        "P4",
        "P5",
        "P6",
        "P7",
        "P8",
        "P9"
    };

    int nOcurrenceJoueur[10] =
    {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
    };

    float MinMaxChance[10][2] =
    {
        {100,0},
        {100,0},
        {100,0},
        {100,0},
        {100,0},
        {100,0},
        {100,0},
        {100,0},
        {100,0},
        {100,0}
    };

    srand (time(NULL));

    for(int j=0;j<1000;j++)
    {
        for(int i=0;i<10;i++)
            nOcurrenceJoueur[i] = 0;
        /*for(int i=0;i<10;i++)
        {
            MinMaxChance[i][0] = 100;
            MinMaxChance[i][1] = 0;
        }*/

        for(int i=0;i<40;i++)
        {
            valRand1 = rand() % 10;
            valRand2 = rand() % 10;

                while(valRand1 == valRand2)
                    valRand2 = rand() % 10;

            nOcurrenceJoueur[valRand1]++;
            nOcurrenceJoueur[valRand2]++;
        }

        for(int i=0;i<10;i++)
        {
            if((float(nOcurrenceJoueur[i])/40)*100 < MinMaxChance[i][0])
                MinMaxChance[i][0] = (float(nOcurrenceJoueur[i])/40)*100;
            if((float(nOcurrenceJoueur[i])/40)*100 > MinMaxChance[i][1])
                MinMaxChance[i][1] = (float(nOcurrenceJoueur[i])/40)*100;
        }

    }

    for(int i = 0;i<10;i++)
        cout << joueur[i] << ": min = " << MinMaxChance[i][0] << ", max = " << MinMaxChance[i][1] << endl;

    return 0;
}
