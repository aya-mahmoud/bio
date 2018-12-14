#include "RNA.h"
#include "PROTEIN.h"
class Protein ;
class CodonsTable ;
RNA::RNA() {}

RNA::RNA(char * seq, RNA_Type atype,int l)
{
    seq = new char  ;
    this->seq = seq ;
    type = atype;
    length=l;
    for(int i=0; i<length; i++)
    {
        try
        {
            if(seq[i]!='U')
            {
                throw "its not a RNA ";
            }
        }
        catch(const char *x)
        {
            cout<<x;
        }
    }
}
RNA::RNA(RNA& rhs)
{
    seq = rhs.seq;
    length = rhs.length;
    type = rhs.type;
}
void RNA::Print()
{
    cout << "RNA:" << seq << "  " << "TYPE : " << type <<" " << length<<endl;
}
DNA RNA::ConvertToDNA()
{
    for (int i=0 ; i< strlen(seq) ; i++)
    {
        if (seq[i]=='U')
        {
            seq[i] = 'T';
        }
        cout << seq[i] ;
    }
    DNA dna(seq, promoter);

    return dna;
}

Protein& RNA::ConvertToProtein(CodonsTable &table)
{       char x;
        char*  value = new char [3];
        char*P=new char[length/3];
        int counter = 0 ;
        for(int i=0 ;i<(length/3);i++){
         for(int k=0;k<3;k++){
          value[k]= seq[k+counter];

           // cout<<"VALUE "<<k<<" "<<value[k]<<" ";
        }
          counter += 3 ;

          P[i]=table.getAminoAcid(value) ;

           //cout<<x;
            //counter++ ;
        }
       Protein p(P,Hormon,length/3);
      cout << p << endl ;
        cout<<endl;
//        return p;
}

RNA::~RNA()
{
    delete [] seq ;
}
bool RNA::operator==(RNA& s1)
{

    if (seq == s1.seq)
    {
        // cout << "TWO SEQUENCES ARE EQUAL:" << endl ;
        return true ;
    }
    else
    {
        //  cout << "TWO SEQUENCES ARE NOT EQUAL" << endl ;
        return false ;
    }
}
bool RNA::operator!=(RNA& s1)
{
    // s1 = new char ;
    if (seq != s1.seq)
    {
        // cout << "TWO SEQUENCES ARE NOT EQUAL:" << endl ;
        return true ;
    }
    else
    {
        // cout << "TWO SEQUENCES ARE EQUAL" << endl ;
        return false ;
    }
}
ostream& operator << (ostream& out, RNA&rna)
{
    //out<<   rna.seq;
    // << " " <<rna.length<< endl ;
    return out ;
}
istream& operator>>(istream& in, RNA&s1)
{
    int type ;
    cout << "HEY!!" << endl ;
    /*  cout <<"How Many Sequences" << "one or two" << endl ;
        cout <<"1-one for functions" << endl ;
        cout <<"2-two for operators" << endl ;
        int h ;
        cout << "Enter 1 or 2" << endl ;
        cin >> h ; */
    cout << "ENTER THE LENGTH OF THE SEQUENCE:" << endl ;
    in >> s1.length ;
    cout << "ENTER YOUR SEQUENCE PLEASE" << endl;
    in >> s1.seq ;
    if (s1.length != strlen(s1.seq))
    {
        cout <<"^^^^^^"<<"ERROR!!"<<"^^^^^^" << endl ;
        cout <<"PLEASE ENTER SEQUENCE RIGHT:"<< endl ;
        cin >> s1.seq ;
    }
 /*   for (int i = 0 ; i < s1.length ; i++)
    {
        if (s1.seq[i]!='U')
            cout << "please enter sequence contain letter U" << endl ;
            cin >> s1.seq ; }
            cout << s1.seq ;
    */
    cout << "enter your type from the types of DNA " << endl ;
    cout <<"{mRNA, pre_mRNA, mRNA_exon, mRNA_intron}" << endl ;
    cout << "PLEASE choice between numbers {0 , 1 , 2 , 3}" << endl ;
    in >> type ;
    s1.type=RNA_Type(type);
    if (type == 0)
    {
        cout <<"so your type is" <<" :: "<< "mRNA" << endl ;
    }
    else if (type==1)
    {
        cout <<"so your type is" <<" :: "<< "pre_mRNA" << endl ;
    }
    else if (type==2)
    {
        cout <<"so your type is" <<" :: "<< "mRNA_exon" << endl ;
    }
    else if (type==3)
    {
        cout <<"so your type is" <<" :: "<< "mRNA_intron" << endl ;
    }
    else
    {
        cout <<"so your type is" <<" :: "<< "ERROR" << endl ;
    }
    cout << endl ;
    cout << "NEXT" << endl ;

    return in ;
}
char* RNA::operator + (RNA &s1)
{
    char* s3 = new char[strlen(seq)+strlen(s1.seq) + 1] ;
    strcpy(s3, seq) ;
    strcat(s3,s1.seq) ;
    return s3 ;
}
