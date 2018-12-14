#include "DNA.h"
class RNA;
DNA::DNA()
{
    startIndex = 0;
    endIndex = 0;
}
DNA::DNA(char* seq , DNA_Type atype)
{
    this->seq = new char ;
    this->seq =seq ;
    type = atype ;
}
/*
DNA::DNA(char * seq, DNA_Type atype)
{

    seq = new char;
    this->seq = seq ;
    type = atype;
   // length = l ;
    for(int i=0;i<length;i++){
     try{
     if(seq[i]!='A' &&  seq[i]!='C' && seq[i]!='G' && seq[i]!='T'){
        throw "its not a dna ";
     }}
    catch(const char *x){
     cout<<x;
        } }
} */
DNA::DNA(int startIndex , int endIndex )
{
    this->startIndex = startIndex ;
    this->endIndex = endIndex ;
}
DNA::DNA(DNA& rhs)
{
    seq = new char ;
    this->seq = rhs.seq;
    length = rhs.length;
    type = rhs.type;

}
void DNA::getType()
{
    cout << type << endl ;
}
void DNA::setStartIndex(int startIndex)
{
    this->startIndex = startIndex;
}
void DNA::setEndIndex(int endIndex)
{
    this->endIndex = endIndex;
}
int DNA::getStartIndex()const
{
    return startIndex;
}
int DNA::getEndIndex()const
{
    return endIndex;
}
void DNA::setSequence (char* seq)
{
    seq = new char;
    this->seq = seq;
}
char DNA :: getSequence()const
{
    return *seq;


}
void DNA::Print()
{
    cout << "DNA:" << seq << "TYPE:" << type << endl ;
}

void DNA::BuildComplementaryStrand()
{
    cout << "Complementary Strand is:" << endl ;
  // complementary_strand->seq = seq ;
    complementary_strand = new DNA() ;
    complementary_strand->seq = new char (endIndex-startIndex+1) ;
    complementary_strand->seq[endIndex-startIndex] = '\0' ;
    for (int i = startIndex ; i <=endIndex; i++)
    {
        if (seq[i]== 'A')
        {
            complementary_strand->seq[i] = 'T' ;
        }
        else if (seq[i] == 'T')
        {
            complementary_strand->seq[i] = 'A' ;
        }
        else if (seq[i] == 'C')
        {
            complementary_strand->seq[i] = 'G' ;
        }
        else if (seq[i] == 'G')
        {
            complementary_strand->seq[i] = 'C' ;
        }

        cout <<complementary_strand->seq[i] ;
    }
    cout << endl ;
    cout << "the Inverse strand " << "::" << " " ;
    for(int j=endIndex ; j >= startIndex ; j--)
    {
        cout <<complementary_strand->seq[j];
    }
}
RNA DNA::ConvertToRNA()
{
    cout << endl ;
    cout << "Convert to RNA" << endl ;
    char* rna = complementary_strand->seq ;

    for (int i = startIndex ; i <= endIndex ; i++)
    {
        if (complementary_strand->seq[i] == 'T')
        {
            rna[i]='U';
        }
           cout <<rna[i];
    }
//    RNA rna (seq ,mRNA_exon,length) ;
//    return rna ;
   /* cout<<"start index";
cin>>startIndex;
cout<<"End index:";
cin>>endIndex;

    DNA*RNA_Strand=new DNA;
    RNA_Strand->seq=new char[endIndex-startIndex];
    //complementary_strand =new DNA;
    //char* rna = new char[startIndex-endIndex];

    for (int i=startIndex ; i<=endIndex ; i++)
    {
        if (seq[i] == 'T')
        {
            RNA_Strand->seq[i]='U';
        }
           cout <<RNA_Strand->seq[i];
    }
    return RNA_Strand ;
*/
}
DNA::~DNA()
{
    delete seq ;
}
ostream& operator << (ostream& out,DNA&s1)
{
    out<<s1.seq <<"  "<< s1.length << endl ;
    return out ;
}
istream& operator>> (istream& in,DNA&s1)
{
    int type ;
    cout << "HEY!!" << endl ;
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
    cout << "enter your type from the types of DNA " << endl ;
    cout <<"promoter , motif , tail ,noncoding" << endl ;
    cout << "PLEASE choice between numbers {0 , 1 , 2 , 3}" << endl ;
    in >> type ;
    s1.type=DNA_Type(type);
    if (type == 0)
    {
        cout <<"so your type is" <<" :: "<< "PROMOTER" << endl ;
    }
    else if (type==1)
    {
        cout <<"so your type is" <<" :: " <<"MOTIF" << endl ;
    }
    else if (type==2)
    {
        cout <<"so your type is" <<" :: "<< "TAIL" << endl ;
    }
    else if (type==3)
    {
        cout <<"so your type is" <<" :: "<< "NONCODING" << endl ;
    }
    else
    {
        cout <<"so your type is" <<" :: "<< "ERROR" << endl ;
    }
    cout << endl ;
    cout << "NEXT" << endl ;
    cout << "Enter the startIndex" << endl ;
    in >> s1.startIndex ;
    cout << "Enter the endIndex" << endl ;
    in >> s1.endIndex ;
    return in ;
}

bool DNA::operator==(DNA &s1)
{

    if (this->seq == s1.seq)
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
bool DNA::operator!=(DNA& s1)
{
   // s1 = new char ;
    if (this->seq != s1.seq)
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
/*
    void DNA::LoadSequenceFromFile(char* filename)
    {
       ifstream file;
       file.open(filename);
       if(!file.fail())
       {
           cout<<"Error opening file."<<endl;
       }

       while(!file.eof())
       {
           string str="";
           file >> str;
       }

    }
*/
char* DNA::operator+(DNA &s1)
{
    char* s3 = new char[strlen(seq)+strlen(s1.seq) + 1] ;
    strcpy(s3 , seq) ;
    strcat(s3 ,s1.seq) ;
    return s3 ;
}
