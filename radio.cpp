#include <iostream>
#include <fstream>

using namespace std;

string d[12][21];


int szame(string szo)
{
    int valasz = 1;
    for (int i = 0;i<szo.length();i++)
    {
        if ((szo[i] < '0') || (szo[i]>'9'))
            valasz = 0;
    }
    return valasz;
}


int main()
{
    string seged;
    int eid =0;
    int uid=0;
    ifstream fajl ("veetel.txt");
    while (!fajl.eof())
    {
        int nap = 0;
        int rid = 0;
        getline (fajl,seged);
        sscanf(seged.c_str(),"%d %d",&nap,&rid);
        if (nap>0)
        {
            if (eid == 0)
                eid = rid;
            uid = rid;
            getline (fajl,seged);
            d[nap][rid]=seged;
        }
    }

    cout<<"3. feladat"<<endl;

    cout<<"Utolso: "<<uid<<" Elso: "<<eid<<endl;

    for (int i = 1;i<12;i++)
    {

        for (int j =1;j<21;j++)
        {
            if (d[i][j].find("farkas") != string::npos)
            {
                cout<<i<<" "<<j<<endl;
            }
        }
    }

    cout<<"4. feladat"<<endl;

    for (int i =1;i<12;i++)
    {
        int sz = 0;
        for (int j = 1;j<22;j++)
        {
            if (d[i][j].length() >0)
                sz++;
        }
        cout<<i<<". nap :"<<sz<<endl;
    }

    cout<<"5. feladat"<<endl;

    for (int i = 1;i<12;i++)
    {
        string b = "##########################################################################################";
        for (int j = 1;j<21;j++)
        {
            if (d[i][j].length() > 0)
            {
                for (int k = 0;k<90;k++)
                {
                    if (d[i][j][k] != '#')
                        b[k] = d[i][j][k];
                }
            }
        }
        cout<<b<<endl;
    }


    cout<<"7. feladat"<<endl;

    int benap;
    int ber;
    cout<<"Nap sorszama: ";
    cin>>benap;
    cout<<"Radio amator sorszama: ";
    cin>>ber;
    //out<<benap<<" "<<ber<<endl;

    string x = d[benap][ber];

    if (x.length()==0)
        cout<<"Nincs ilyen feljegyzes"<<endl;
    else
    {
        int perhely = x.find('/');
        if (perhely == string::npos)
            cout<<"Nincs informacio"<<endl;
        else
        {
            string eleje = x.substr(0,perhely);
            string vege = x.substr(perhely+1,x.length()-perhely-1);
            int vegepos = vege.find(' ');
            if (vegepos == string::npos)
                cout<<"Nincs informacio"<<endl;
            else
            {
                vege = vege.substr(0,vegepos);
                if ((szame(eleje)) && (szame(vege)))
                {
                    cout<<"A megfigyelt egyedek szama: "<<stoi(eleje)+ stoi(vege)<<endl;
                }
                else
                    cout<<"Nincs informacio"<<endl;
            }
        }
    }


    return 0;
}
