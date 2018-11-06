#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{

    ///WCZYTYWANIE PLIKU

    vector<string> element;
    string line;
    ifstream ip("la.csv");/// otwieranie pliku
    if(!ip.is_open()) cout << "ERROR: File Open" << '\n';
    while(ip.good())
        {
            getline(ip, line);/// pobieranie lini i wrzucanie do zmiennej
            cout << line << endl;
            element.push_back(line);///zmienna wrzucana na wektor
        }

    ip.close();

    ///PRZEKONWERTOWANIE I WRZUCANIE DO TABLIC 2 WYMIAROWYCH

    string tymczas;
    cout << tymczas;
    vector<int>table;
    vector<vector<int> > vector_dwuwymiarowy;
    int x=0;
    int y=0;
    int zmiananaint;
    for(int j=0; j<element.size()-1; j++) ///wczytywanie kolejnych elementow wektora
    {
        tymczas=element[j].at(0);         ///pierwszy znak od lini wrzucany do tymczasowej zmiennej
        for(int z=1; z<element[j].length();z++) /// przechodzenie po kolejnych znakach w danej lini (elementów wektora)
            {
                if(element[j].at(z)==';') /// znak ; oznaczeniem końca kolumny w danej lini
                {
                    stringstream sso;
                    sso<<tymczas;    ///zmiana stringa na int inne rozwiazanie mi nie wychodzilo
                    sso>>zmiananaint;
                    //cout << "wartosc cosss "<< zmiananaint<< endl;
                    table.push_back(zmiananaint); /// wrzucanie liczby do wektora
                    tymczas=""; ///czyszczenie zmiennej
                    x=x+1;
                }
                else
                    {
                        tymczas=tymczas+element[j].at(z);/// dodawanie kolejnych znaków do zmiennej
                        if(z==element[j].length()-1)///gdy zblizamy sie do końca lini (elementu wektora)
                        {
                                stringstream sso;
                                sso<<tymczas;    ///zmiana stringa na int inne rozwiazanie mi nie wychodzilo
                                sso>>zmiananaint;
                                //cout << "wartosc cosss "<< zmiananaint<< endl;
                                table.push_back(zmiananaint);/// wrzucanie liczby do wektora
                                tymczas="";///czyszczenie zmiennej
                                x=x+1;
                        }
                    }
            }
        vector_dwuwymiarowy.push_back(table);/// zrzucanie calej do tad tablicy do wektora 2 elementowego
        table.clear();/// czyszczenie pierwszej tablicy


    }
    y=element.size();
    x=x/y; /// wynik daje nam x-1 kolumn w danym pliku

    //cout << endl <<"vector 2 wymiarowy size = " << vector_dwuwymiarowy.size()<< endl;
    //cout << endl <<"watosc x  "<< x << " i y " << y << endl<<endl;

    ///MAKSYMALNY ELEMENT

    int maxymalny_element=0;
    /// wyszukanie max
    for( int i=0; i<=vector_dwuwymiarowy.size()-1;i++)
    {
        for( int j=0; j<=x;j++)
        {
            //cout << vector_dwuwymiarowy[i][j] << " ";
            if (maxymalny_element<vector_dwuwymiarowy[i][j])
            {
                maxymalny_element=vector_dwuwymiarowy[i][j];
            }
        }
        //cout << endl;
    }

    cout << " maxymalna wartosc =" << maxymalny_element << endl<<endl;

    ///PRZEDZIALY

    int ilosc_przedzialow=maxymalny_element/10*(x+1)+x+1;///automatyczne obliczanie domyslnej wartosci
    string taknie;
    do
        {
            cout << "Czy chcesz podawac ilosc przedzialow tak/nie(domyslnie co 10): ";
            cin >> taknie;
            if(taknie!="tak"&&taknie!="nie"&&taknie!="TAK"&&taknie!="NIE"&&taknie!="Nie"&&taknie!="Tak"){cout <<" \n Nie rozumiem" <<endl;};
        }while(taknie!="tak"&&taknie!="nie"&&taknie!="TAK"&&taknie!="NIE"&&taknie!="Nie"&&taknie!="Tak");
    int segment=10;
    if(taknie=="tak"||taknie=="TAK"||taknie=="Tak")
    {
        cout << "Podaj ilosc przedzialow w jednej kolumnie: ";
        cin >> ilosc_przedzialow;

        segment=maxymalny_element/ilosc_przedzialow+1; ///obliczenie segmentu dla wszystkich przedzialow
        if(segment*(ilosc_przedzialow-1)>=maxymalny_element) /// zabezpieczenie w przypadku gdy liczba podana przedzialow jest nie korzystna
        {                                                    /// np gdy ostatni segment rozpoczyna sie powyzej maksymalnej wartosci
           ilosc_przedzialow=ilosc_przedzialow-1;
           cout<< "Dzialam na intach ostatni, ostatni przedzial zawsze bylby pusty, wiec go kasuje " << endl;
        }
        ilosc_przedzialow=ilosc_przedzialow*(x+1); ///przedzialy dla kazdej kolumny z osobna
        cout << "Podzial co: " << segment << endl;
    }
    vector<int> przedzialy(ilosc_przedzialow,0); ///poczatkowa wartosc wszystkich przedzialow to 0
    int wartosc_do_przedzialow=0;
    cout << endl <<"ilosc przedzialow razem: "<< ilosc_przedzialow << endl;

    ///PRZYDZIELANIE LICZB DO PRZEDZIALOW

    for( int i=0; i<=vector_dwuwymiarowy.size()-1;i++)
    {

        for( int j=0; j<=x;j++)
        {
            //cout << table[ i ] << endl;

            wartosc_do_przedzialow=j*ilosc_przedzialow/(x+1);

            for(int z=0; z<=maxymalny_element; z+=segment)
            {
                    //cout<<"w srodku";
                if(vector_dwuwymiarowy[i][j]<z+segment-1&&vector_dwuwymiarowy[ i ][j]>=z)
                {
                        cout << "wektor dwuwymiarowy "<< vector_dwuwymiarowy[i][j]<< "w kolumnie "<< j+1<< " dodaje do przedzialu "<<wartosc_do_przedzialow<< endl;
                        przedzialy[wartosc_do_przedzialow]++;
                }
                wartosc_do_przedzialow++;
            }

        }

    }

    ///ZAPIS DANYCH DO PLIKU

    int biezacy_wiersz;
    int ifowa=0,ifowanew=0;
    ofstream pliknowy("nowy.csv");

    for(unsigned int i= 0; i<=przedzialy.size()-1;i++)
    {
        biezacy_wiersz=(i+(ilosc_przedzialow/(x+1)))/(ilosc_przedzialow/(x+1));///OBLICZANIE BIEZACEGO WIERSZU

        cout<< "Ilosc liczb w przedziale od "<< (i*segment)-((maxymalny_element/segment*segment+segment)*(biezacy_wiersz-1)) << " do "
        << i*segment+segment-1-((maxymalny_element/segment*segment+segment)*(biezacy_wiersz-1))<< " w kolumnie "<< biezacy_wiersz <<  " = "
        << przedzialy[i]<<endl;

        biezacy_wiersz=(i+(ilosc_przedzialow/(x+1)))/(ilosc_przedzialow/(x+1));
        ifowanew=ilosc_przedzialow/biezacy_wiersz;
            if(ifowanew!=ifowa)
            {
                if (i==0)
                {
                    pliknowy << przedzialy[i];
                }
                else{pliknowy<< endl  << przedzialy[i];}

            }
        else {pliknowy <<";"<<przedzialy[i];}
        ifowa=ifowanew;




    }
    pliknowy.close();
    cout << endl << 7%3 << endl;

    return 0;
}

///INNE ROZWIAZANIA DZIALAJACE LECZ KONCEPTOWO ZLE
        ///pliknowy << "Ilosc liczb w przedziale od "<< (i*segment)-((maxymalny_element/segment*segment+segment)*(biezacy_wiersz-1))
        ///<< " do " << i*10+9-((maxymalny_element/segment*segment+segment)*(biezacy_wiersz-1))<< " w wierszu "<< biezacy_wiersz <<  " = "
        ///<< przedzialy[i]<<endl;///x+1 to liczba kolumn
/*
    vector <int> table;
    vector<vector<int> > vector_dwuwymiarowy;
    string tempo;
    bool spra=false;
    int cossssss;
    string pierwsz;
    for(int j=0; j<=t-1; j++)
    {
        tempo="";
        //cout << ma[j] << endl;
        for(int z=1; z<=ma[j].length()-1;z++)
        {
            if(ma[j].at(z)=='\n')
            {
                //cout << "wchodze" << endl;
                for (int i=z; i<=ma[j].length()-1;i++)
                {
                    tempo=tempo+ma[j].at(i);
                }
                for(int k=0; k<z; k++)
                {
                    pierwsz=pierwsz+ma[j].at(k);
                }
                spra=true;
                y++;
            }
        }
        if(tempo==""){tempo=ma[j];}
        if (spra==true)
        {


            stringstream sso;
            sso<<pierwsz;    ///zmiana stringa na int inne rozwiazanie mi nie wychodzilo
            sso>>cossssss;
            //cout << "wartosc cosss "<< cossssss<< endl;
            table.push_back(cossssss);
            spra=false;
            pierwsz="";
            x=-1;
            vector_dwuwymiarowy.push_back(table);
            table.clear();

        }
        stringstream sso;
        sso<<tempo;    ///zmiana stringa na int inne rozwiazanie mi nie wychodzilo
        sso>>cossssss;
        //cout << "wartosc cosss "<< cossssss<< endl;
        table.push_back(cossssss);
        x++;


    }
    */
/*
    string czykolumny;
    string czywiersze;
    cout << "Czy w pliku s¹ kolumny opisane ";
    cin >> czykolumny;
    if(czykolumny=="nie"||czykolumny=="NIE"||czykolumny=="Nie")
    {
        cout << "Czy chcesz opisac kolumny ";
        cin >> czykolumny;
        if(czykolumny=="tak"||czykolumny=="TAK"||czykolumny=="Tak")
        {
            string czykolumny[x+1];
            for(int i=0; i==x+1; i++)
            {
                cout << "Opisz "<< i+1 << " kolumne ";
                cin >> czykolumny[i];
            }
        }
    }
    cout << "Czy w pliku sa wiersze opisane ";
    cin >> czywiersze;
    if(czywiersze=="nie"||czywiersze=="NIE"||czywiersze=="Nie")
    {
        cout << "Czy chcesz opisac wiersze ";
        cin >> czywiersze;
        if(czywiersze=="tak"||czywiersze=="TAK"||czywiersze=="Tak")
        {
            string czywiersze[y];
            for(int i=0; i==y; i++)
            {
                cout << "Opisz "<< i+1 << " wiersz ";
                cin >> czywiersze[i];
            }
        }
    }

    vector <int> table;
    vector<vector<int> > vector_dwuwymiarowy;
    int cossssss;
    for(int j=0; j<y; j++)
    {
        for(int i=0;i<=x+1;i++)
        {
            cout << "wartosc mapa "<< mapa[j][i]<< endl;
            stringstream sso;
            sso<<mapa[j][i];    ///zmiana stringa na int inne rozwiazanie mi nie wychodzilo
            sso>>cossssss;
            cout << "wartosc cosss "<< cossssss<< endl;
            table.push_back(cossssss);
        }
        vector_dwuwymiarowy.push_back(table);
        table.clear();
    }
    */
