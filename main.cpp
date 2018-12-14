#include <iostream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include <bits/stdc++.h>
#include "PROTEIN.h"
#include "CodonsTable.h"
using namespace std;
int main ()
{
    int x = 0 ;
    int choice ;
    while (x < 5) {
    cout << " " << endl ;
    cout << "******************WELCOME TO THE PROGRAM BIOLOGICAL DATA : ^.^******************" << endl ;
    cout << "ENTER YOUR CHOICE HERE : " << endl ;
    cout <<"1.DNA" << endl ;
    cout <<"2.RNA" << endl ;
    cout <<"3.PROTEIN" << endl ;
    cout <<"4.CODON CLASS" << endl ;
    cout <<"5.ALIGNMENT LCS " << "IF YOU WANT TO KNOW THIS : " <<" ^.^ " << endl ;

   /* cout <<"5.BOOLEAN TWO SEQUENCES ARE EQUAL"<< endl ;
    cout <<"6.BOOLEAN TWO SEQUENCES ARE NOT EQUAL"<< endl ;
    cout <<"7.ADDITION TWO SEQUENCES" << endl ;
    cout <<"8.GLOBAL ALIGNMENT AND LOCAL ALIGNMENT" << endl ; */
    cin >> choice ;
    if (choice > 5)
    {
        cout << "ERROR !!"<< endl ;
        cout << "please enter the choice right" << endl ;
        cin  >> choice ;
    }
    if (choice == 1 )
    {
        int x ;
        cout << "what do you want in DNA" << endl ;
        cout << "1.build complementary starnd !" << endl ;
        cout << "2.convert to RNA " << endl ;
        cout << "3.boolean two sequences from DNA " <<"equal or not" << endl ;
        cout << "4.Addition two sequences from DNA" << endl ;
      //  cout << "5.Alignment LCS" << "if you wanna know that enter 5" << endl ;
        cout << "5.GLOBAL ALIGNMENT OR LOCAL ALIGNMENT" << endl ;
        cout << "6.FUNCTION PRINT () " << endl ;
        cout << "**********ENTER YOUR CHOICE FROM THE LIST NOW.***********:";
        cin  >> x ;
        if (x>7)
        {
            cout << "ERROR . we have 7 choices ONLY !!" << endl ;
            cout << "ENTER AGIAN" << endl ;
            cin >> x ;
        }
        else if (x==1)
        {
            DNA dna ;
            cin >> dna ;
            dna.BuildComplementaryStrand() ;
           // dna.ConvertToRNA() ;
        }
        else if (x==2)
        {
            DNA S ;
            cin >> S ;
            S.BuildComplementaryStrand() ;
            S.ConvertToRNA() ;
        }
        else if (x==3)
        {
            int m ;
            cout << "which operator you want:" << endl ;
            cout << "1.== operator" << endl ;
            cout << "2.!= operator" << endl ;
            cin >> m ;
            if(m==1)
            {
                DNA d ;
                cout << "*****THE FIRST ONE******" << endl ;
                cin >> d ;
                DNA s ;
                cout <<"******the second*******" << endl ;
                cin >> s ;
                if (d == s)
                {
                    cout << "TWO SEQUENCES ARE not EQUAL" << endl  ;
                }
                else
                {
                    cout <<"TWO SEQUENCES ARE EQUAL" << endl ;
                }
            }
            else if (m==2)
            {
                DNA a ;
                cout << "******the first one*******" << endl ;
                cin >> a ;
                DNA c ;
                cout << "*******the second*******" << endl ;
                cin >> c ;
                if (a!=c)
                {
                    cout << "TWO SEQUENCES ARE EQUAL" <<endl ;
                }
                else
                {
                    cout <<"TWO SEQUENCES ARE NOT EQUAL"<< endl  ;
                }

            }
            else
            {
                cout << "ERROR!!!!!!!!!!!!" << endl ;
                cout << "ENTER AGAIN" << endl ;
                cin >> m ;
            }


        }
        else if(x==4)
        {
            cout << "******first******" << endl ;
            DNA d ;
            cin >> d ;
            cout << "******second*****" << endl ;
            DNA f ;
            cin >> f ;
            cout << (d+f) << endl ;
        }
        else if(x==7)
        {
            DNA d ;
            cin >> d ;
            d.Print() ;
        }

        else
        {
            cout << "ERROR!!!!" << endl ;
            cout << "ENTER AGAIN:" << endl ;
            cin >> x ;
        }
    }
    if (choice == 2)
    {
        int y ;
        cout << "what do you want in DNA" << endl ;
        cout << "1.Convert to DNA!" << endl ;
        cout << "2.Convert to PROTEIN!" << endl ;
        cout << "3.boolean two sequences from RNA " <<"equal or not" << endl ;
        cout << "4.Addition two sequences from RNA" << endl ;
        cout << "5.GLOBAL ALIGNMENT OR LOCAL ALIGNMENT" << endl ;
        cout << "6.FUNCTION PRINT () " << endl ;
        cout << "**********ENTER YOUR CHOICE FROM THE LIST NOW.***********:";
        cin  >> y ;
        if( y > 6 )
        {
            cout << "ERROR . we have 7 choices ONLY !!" << endl ;
            cout << "ENTER AGIAN" << endl ;
            cin >> y ;
        }
        else if (y==1)
        {
            RNA rna ;
            cin >>  rna ;
            rna.ConvertToDNA() ;
        }
        else if (y==2)
        {
            RNA rna ;
            cin >> rna ;
            CodonsTable table ;
            table.LoadCodonsFromFile("aminoacids.txt");
        //    rna.ConvertToDNA() ;
            cout << endl ;
            cout << "CONVERT TO PROTEIN " << endl ;
            cout << rna.ConvertToProtein(table) <<endl ;
          //  cout << rna ;
        }
        else if (y==3)
        {
            int m ;
            cout << "which operator you want:" << endl ;
            cout << "1.== operator" << endl ;
            cout << "2.!= operator" << endl ;
            cin >> m ;
            if(m==1)
            {
                RNA d ;
                cout << "*****THE FIRST ONE******" << endl ;
                cin >> d ;
                RNA s ;
                cout <<"******the second*******" << endl ;
                cin >> s ;
                if (d == s)
                {
                    cout << "TWO SEQUENCES ARE not EQUAL" << endl  ;
                }
                else
                {
                    cout <<"TWO SEQUENCES ARE EQUAL" << endl ;
                }
            }
            else if(m!=2)
            {
                RNA d ;
                cout << "*****THE FIRST ONE******" << endl ;
                cin >> d ;
                RNA s ;
                cout <<"******the second*******" << endl ;
                cin >> s ;
                if (d != s)
                {
                    cout << "TWO SEQUENCES ARE not EQUAL" << endl  ;
                }
                else
                {
                    cout <<"TWO SEQUENCES ARE EQUAL" << endl ;
                }
            } }
            else if (y==4)
             {
            cout << "******first******" << endl ;
            RNA d ;
            cin >> d ;
            cout << "******second*****" << endl ;
            RNA f ;
            cin >> f ;
            cout << (d+f) << endl ;
        }
            else if (y==6)
            {
                RNA d ;
                cin >> d ;
                d.Print() ;
            }
    }
     if (choice==3)
    {
        int k ;
        cout << "what do you want in PROTEIN" << endl ;
        cout << "1.DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA)" << endl ;
        cout << "2.boolean two sequences from RNA " <<"equal or not" << endl ;
        cout << "3.Addition two sequences from RNA" << endl ;
        cout << "4.FUNCTION PRINT () " << endl ;
        cout << "**********ENTER YOUR CHOICE FROM THE LIST NOW.***********:";
        cin  >> k ;
        if( k > 5 )
        {
            cout << "ERROR . we have 6 choices ONLY !!" << endl ;
            cout << "ENTER AGIAN" << endl ;
            cin >> k ;
        }
        else if (k==1)
        {
            Protein P("AKC",Hormon,3);
             DNA D("GCUAAAUGC",promoter);
           P.GetDNAStrandsEncodingMe(D);


        }
        else if (k==2)
        {
           int m ;
            cout << "which operator you want:" << endl ;
            cout << "1.== operator" << endl ;
            cout << "2.!= operator" << endl ;
            cin >> m ;
            if(m==1)
            {
                Protein p ;
                cout << "*****THE FIRST ONE******" << endl ;
                cin >> p ;
                Protein s ;
                cout <<"******the second*******" << endl ;
                cin >> s ;
                if (p == s)
                {
                    cout << "TWO SEQUENCES ARE not EQUAL" << endl  ;
                }
                else
                {
                    cout <<"TWO SEQUENCES ARE EQUAL" << endl ;
                }
            }
            else if (m!=2)
            {
                Protein a ;
                cout << "*****THE FIRST ONE******" << endl ;
                cin >> a ;
                Protein b ;
                cout <<"******the second*******" << endl ;
                cin >> b ;
                if (a == b)
                {
                    cout << "TWO SEQUENCES ARE not EQUAL" << endl  ;
                }
                else
                {
                    cout <<"TWO SEQUENCES ARE EQUAL" << endl ;
                }

            }
        }
        else if(k==2)
            {
                cout << "*****THE FIRST*******" << endl ;
                 Protein f ;
                cin >> f;
                cout <<"******THE SECOND******" << endl ;
                 Protein c ;
                cin >> c ;
                cout << (f+c) << endl ;
            }
            else if (k==4)
            {
                Protein d ;
                cin >> d ;
                d.Print() ;
            }



        }


    if (choice==4)
    {
        cout << "WELCOME TO THE CODON CLASS" << endl ;
        CodonsTable table;
        table.LoadCodonsFromFile("aminoacids.txt")  ;
        string x;
        cout<<"enter your sequence:";
        cin>>x;
        const int f=x.size();
        char* newarr=new char[f];
        for(int i=0;i<x.size();i++){


        newarr[i]=x[i] ;
       cout << table.getAminoAcid(newarr) ;
        }
    }
    if (choice==5)
    {
        Sequence *s1 , *s2  ;
        DNA d1("AATTGGBB" , tail) ;
        DNA d2("AAFFDDWW", tail) ;
        s1=&d1;
        s2=&d2;
       cout<< Align(s1,s2) << endl ;
    }
    }
}

