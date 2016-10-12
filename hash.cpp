#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;
#define HASHMAP 10000

string hm[HASHMAP] ;

struct key{
  string str ;
  int kin ;
} ;

struct key  karr[10000] ;

int si = 0 ;
// global variable for counting the elements present in the structure

int hash(string s)                 //     ------------  Hash Function
{
  int size = s.size() ;
  unsigned long long int hash = 7 ;
  for (int i = 0; i < size; i++) {
      hash = hash*31 + s[i];
  }
  int ret = hash%HASHMAP ;
  return  ret;
}

bool compare(key &a , key &b)    // -- modified compare for using in
{                                           // -- in sort function
  if(a.str < b.str)
    return true ;
  else
    return false ;
}

void SortStructure()
{
  int n = si + 1 ;
  sort(karr , karr + n , compare) ;
}


/* -------------------- put Function  ----------------------------- */

void put(string v , string k)    //  ----------------- put function
{
  int index = hash(k) ;
  hm[index] = v ;
  karr[si].str = k ;              // storing this would help me to find the
  karr[si].kin = index ;          // greater and lesser
  si++ ;
}

/* -----------------------------------------------------------------  */

bool has(string k)    // ------------    has function
{
  int index = hash(k) ;
  if(hm[index] == "")
  return false ;
  else
  return true ;
}


/* -------------------- get Function  ----------------------------- */

string get(string k)    // --------------------  get  function
{
  if(has(k))
  {
    int index = hash(k) ;
    return hm[index] ;
  }
  else
  {
    cout << "Given key is not present " ;
    return "null" ;
  }
}
/* ---------------------------------------------------------------------  */


int findIndex(string k)    // ----------------  Utility function
{
  for(int i = 0 ; i < si+1 ; i++)
  {
    if(karr[i].str == k)
      return i ;
  }
  return -1 ;
}

/* -------------------- getGreaterThan Function  ----------------------------- */

string * getGreaterThan(string k)   // getGreaterThan  function
{
  std::vector<string> v;
  SortStructure() ;
  // sort the structure ;
  if(has(k))
  {
    int ind = findIndex(k) ;
    for(int i = ind+1 ; i <= si ; i++)
      {
        v.push_back(hm[karr[i].kin]) ;
      }
    int size = v.size() ;
    string * retarr ;
    retarr = new string[size] ;
    for(int i = 0 ; i < size ; i++)
      {
        retarr[i] = v[i] ;
      }
    return retarr ;
  }
  else
  {
    cout << "key is not present : "<< endl ;
    return NULL ;
  }
}

/* -----------------------------------------------------------------------  */

/* -------------------- getLessThan Function  ----------------------------- */

string * getLessThan(string k)  // ---------------- getLessThan function
{
  std::vector<string> v;
  SortStructure() ;
  // sort the structure ;
  if(has(k))
  {
    int ind = findIndex(k) ;
    for(int i = 1 ; i < ind ; i++)
      {
        v.push_back(hm[karr[i].kin]) ;
      }
    int size = v.size() ;
    string * retarr ;
    retarr = new string[size] ;
    for(int i = 0 ; i < size ; i++)
      {
        retarr[i] = v[i] ;
      }
    return retarr ;
  }
  else
  {
    cout << "key is not present : "<< endl ;
    return NULL ;
  }
}

/* ------------------------------------------------------------------ */

/* -------------------- getNotEquals Function  ----------------------------- */

string * getNotEquals(string k) // getNotEquals   function
{
  // SortStructure() ;
  std::vector<string> v;
  for(int i = 1 ; i <= si ; i++)
  {
    if(karr[i].str == k || karr[i].kin == 0)
      continue ;
    else
    {
      v.push_back(hm[karr[i].kin]) ;
    }
  }
  int size = v.size() ;
  string * retarr ;
  retarr = new string[size] ;
  for(int i = 0 ; i < size ; i++)
  {
    retarr[i] = v[i] ;
  }
  return retarr ;
}

void printStructure()   // ----------------  Utilty function
{
  for(int j = 0 ; j <= si ; j++)
  {
    cout << "  " << karr[j].kin << endl ;
  }
}

/* -------------------------------------------------------------------  */

int main()
{

  // This is for testing the hash function
  string arr[] = {"puneet" , "aggarwal" , "yo" , "first" , "cmsodc" , "even" ,  "number" ,  "of" ,  "elements," ,  "the median" , "is" ,  "actually" ,"the" ,"average" ,"of" ,"the", "middle",
"two" ,"elements." ,"The" ,"middle" , "two" , "elements" , "can’t" , "both" , "be" , "at" , "the" , "top"} ;
  for (size_t i = 0; i < 25; i++) {
    int h = hash(arr[i]) ;
    cout << h << endl ;
  }

  // going to define all the function

  // CHECK FOR function

  put("punnu" , "q") ;
  put("punnu2" , "a") ;
  put("punt" , "z") ;
  put("puneet" , "x") ;
  put("puneet" , "c") ;
  put("ara" , "s") ;
  put("parmar" , "w") ;

  string s = get("z") ;
  cout << "value of get " << s << endl ;

  string s3 = get("15") ;
  cout << "value of get " << s3 << endl ;


  printStructure() ;
  SortStructure() ;
  printStructure() ;

  string *st = getLessThan("s") ;
  cout << "LESS" << endl ;
  for(int i = 0 ; i < 3 ; i++)
  {
    cout << st[i] << endl ;
  }

  cout << "NOT EQUAL" << endl ;
  string *stt = getNotEquals("s") ;
  for(int i = 0 ; i < 6 ; i++)
  {
    cout << stt[i] << endl ;
  }

  cout << "Greater" << endl ;
  string *st2 = getGreaterThan("s") ;
  for(int i = 0 ; i < 3 ; i++)
  {
    cout << st2[i] << endl ;
  }

}
