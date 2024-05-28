# Basic overview over the dll structure & examples

If you are not following my guide “Compiling the first dll” there might
be slight differences in the basic files you use, since i already added
some code, which is needed anyway.

## The OH-DLL.cpp

```
#define WHUSER_EXPORTS 
#include "OH-DLL.h" #include <windows.h>
/////////////////////////////////////  
//card macros  
#define RANK(c)       ((c>>4)&0x0f)  
#define SUIT(c)          ((c>>0)&0x0f)  
#define ISCARDBACK(c)   (c==0xff)  
#define ISUNKNOWN(c)     (c==0) 
///////////////////////////////////// 
////////////////////////////////////  
//consecutive states  
holdem_state    m_holdem_state[256];  
unsigned char   m_ndx;  
////////////////////////////////////
////////////////////////////////////  
//versus list & prwin 
phl1k_t m_phl1k; 
pp13 prw1326; 
////////////////////////////////////
////////////////////////////////////  
//WH symbols pfgws_t m_pget_winholdem_symbol; 
////////////////////////////////////
double gws(int chair, const char* name, bool& iserr) {
  return (*m_pget_winholdem_symbol)(chair,name,iserr);  
} 

double gws(const char* name) {
  bool iserr;  
  int mychair = (int)gws(0,"userchair",iserr);  
  return gws(mychair,name,iserr);  
}

bool hlset( int rank0, int rank1, int listnum, bool onoff ) {
  return ((*m_phl1k)[listnum][rank0-2][rank1-2] = onoff); 
}

bool hlget( int rank0, int rank1, int listnum ) {
    return ((*m_phl1k)[listnum][rank0-2][rank1-2]); 
}

double process_query(const char* pquery){
  if(pquery==NULL)      
    return 0;   //example   
  if(strcmp(pquery,"dll$test")==0)      
    return 101;
  return 0;
}
double process_state(holdem_state* pstate){
  if(pstate!=NULL)       
    m_holdem_state[ (++m_ndx)&0xff ] = *pstate;
  return 0;
} 

/////////////////////////////////////////////////////  
//WINHOLDEM RUNTIME ENTRY POINT  
/////////////////////////////////////////////////////  
WHUSER_API double process_message(const char* pmessage, const void* param) {
  if(pmessage==NULL){       
    return 0;   }   
  if(param==NULL) 
    return 0;
  if(strcmp(pmessage,"state")==0)
    return process_state( (holdem_state*)param );   
  if(strcmp(pmessage,"phl1k")==0) {         
    m_phl1k = (phl1k_t)param;       
    return 0;   
  }     
  if(strcmp(pmessage,"prw1326")==0) {
    prw1326 = (pp13)param;      
    return 0;   
  }     
  if(strcmp(pmessage,"query")==0) 
    return process_query((const char*)param);   
  if(strcmp(pmessage,"pfgws")==0) {          
    m_pget_winholdem_symbol = (pfgws_t)param;       
    return 0;   
  }
  return 0;
} 

/////////////////////////////////  
//DLLMAIN  
/////////////////////////////////  
BOOL APIENTRY DllMain( HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
  switch(ul_reason_for_call) {      
    case DLL_PROCESS_ATTACH: break;         
    case DLL_THREAD_ATTACH:  break;         
    case DLL_THREAD_DETACH:  break;         
    case DLL_PROCESS_DETACH: break;     
  }
  return TRUE;
}
```

## gws function

```
double gws(const char* name) {      
  bool iserr;   
  int mychair = (int)gws(0,"userchair",iserr);      
  return gws(mychair,name,iserr);  
}
```

This function you see here, is very important, because you can access
all symbols, which are available for Openholdem with it. E.g:
gws(userchair) returns the value of the userchair symbol.

## hlset & hlget

```
bool hlset( int rank0, int rank1, int listnum, bool onoff ) {
  return ((*m_phl1k)[listnum][rank0-2][rank1-2] = onoff); 
}

bool hlget( int rank0, int rank1, int listnum ) {
  return ((*m_phl1k)[listnum][rank0-2][rank1-2]); 
}
```

These functions can be used to access and dynamically modify versus
lists during play e.g:

    hlset( 14, 13, 5, 1);

this sets AKs on list 5 to true. More details can be found here:
<http://www.maxinmontreal.com/wiki/index.php5?title=Phl1k>.!!!

## process_query function

```
double process_query(const char* pquery){
  if(pquery==NULL)      
    return 0;   //example   
  if(strcmp(pquery,"dll$test")==0)      return 101;
    return 0;
}
```

Inside this scope you can define symbols which you can access with the
OH formula editor.

E.g: If you add = dll\$test in the OH formula editor in the debug tab,
you’ll get the value . You can experiment with it if you want and try
some values from the gws function, but remember to recompile each time
you change something in the code.

## process_state function

    double process_state(holdem_state* pstate){
      if(pstate!=NULL) m_holdem_state[ (++m_ndx)&0xff ] = *pstate;
      return 0;
    }

## The OH-DLL.h Header

    #ifndef _whuser_h_ #define _whuser_h_
    #ifdef WHUSER_EXPORTS #define WHUSER_API __declspec(dllexport) 
    #else 
    #define WHUSER_API __declspec(dllimport) #
    endif

    struct holdem_player{
      char            m_name[16];   //player name if known     
      double          m_balance;    //player balance      
      double          m_currentbet; //player current bet     
      unsigned char   m_cards[2]          ; //player cards
      unsigned char   m_name_known    : 1 ; //0=no 1=yes     
      unsigned char   m_balance_known : 1 ; //0=no 1=yes     
      unsigned char   m_fillerbits    : 6 ; //filler bits     
      unsigned char   m_fillerbyte        ; //filler bytes
    };

    struct holdem_state{
      char            m_title[64]         ; //table title     
      double          m_pot[10]           ; //total in each pot
      unsigned char   m_cards[5]          ; //common cards
      unsigned char   m_is_playing    : 1 ; //0=sitting-out, 1=sitting-in     
      unsigned char   m_is_posting    : 1 ; //0=autopost-off, 1=autopost-on     
      unsigned char   m_fillerbits    : 6 ; //filler bits
      unsigned char   m_fillerbyte        ; //filler byte     
      unsigned char   m_dealer_chair      ; //0-9
      holdem_player   m_player[10]        ; //player records
    };

    struct sprw1326_chair{
      int   level;         //indicates weighting level for 'always consider'    
      int   limit;         //max index into weight array - used for computational efficiency
      int   ignored;       //if non-zero no weighting will be applied to this chair
      int   rankhi[1326];  //higher ranked card number in pocket cards
      int   ranklo[1326];  //lower ranked card number in pocket cards
      int   weight[1326];  //the significance value for this hand
      double scratch;      //for future reference 
    };

    struct sprw1326{
      int   useme;        //unless set to 1326 the normal OH prwin will be used
      int   preflop;      //unless set to 1326 the normal OH prwin will be used pre-flop
      int   usecallback;  //unless set to 1326 the callback function will not be invoked
      double (*prw_callback)(void); //if enabled will be invoked before the prwin calculation
      pass  
      double scratch;    //for future reference     int bblimp;     
      //if non-zero no weighting will be applied if a chair has put nothing in the pot
      //will be precalculated by OH at startup - convenience values
      sprw1326_chair vanilla_chair;     
      sprw1326_chair chair[10];  //structures for each chair
    };

    typedef double (*process_message_t)(const char* message, const void* param ); 
    WHUSER_API double process_message( const char* message, const void* param );
    typedef double (*pfgws_t)( int c, const char* psym, bool& iserr );
    typedef bool hl1k_t[1000][13][13];  // list number, rank0, rank1 
    // rank0>=rank1 == suited, rank0<rank1 == unsuited 
    typedef hl1k_t* phl1k_t; 
    typedef sprw1326* pp13;
    #endif

Here you have some definitions of datatypes. The important definitions
are the two structs, you can basically compare a struct-datatype to an
object with some attributes, these attributes are accessed by using the
. operator, look in the examples section below.

## The struct holdem_state

    struct holdem_state{
      char  m_title[64]         ;   //table title     
      double          m_pot[10]           ; //total in each pot
      unsigned char   m_cards[5]          ; //common cards
      unsigned char   m_is_playing    : 1 ; //0=sitting-out, 1=sitting-in     
      unsigned char   m_is_posting    : 1 ; //0=autopost-off, 1=autopost-on     
      unsigned char   m_fillerbits    : 6 ; //filler bits
      unsigned char   m_fillerbyte        ; //filler byte     
      unsigned char   m_dealer_chair      ; //0-9
      holdem_player   m_player[10]        ; //player records
    };

- What you basically have here is the information of a OH state which
  was scraped.

- You can access information like the tabletitle/potsize/dealerchair
  etc. Ofcourse that is nothing new, as you have symbols formost of that
  at the formula level.

- It also holds information about the players which is saved in the
  struct holdem_player.

## The struct holdem_player

    struct holdem_player{
      char            m_name[16]          ; //player name if known     
      double          m_balance           ; //player balance      
      double          m_currentbet        ; //player current bet     
      unsigned char   m_cards[2]          ; //player cards
      unsigned char   m_name_known    : 1 ; //0=no 1=yes     
      unsigned char   m_balance_known : 1 ; //0=no 1=yes     
      unsigned char   m_fillerbits    : 6 ; //filler bits     
      unsigned char   m_fillerbyte        ; //filler bytes
    };

Pretty obvious that this contains information about the players at the
table. You can access balances / currentbets /cards (if yours or at
showdown) / names.

## prw1326 Datastructures

You can find all information and examples on it in these articles:
<http://www.maxinmontreal.com/wiki/index.php5?title=Prw1326>,
<http://www.maxinmontreal.com/wiki/index.php5?title=Enhanced_Prwin>.!!!

## Examples

### Acessing information from the struct holdem_state

    double process_query(const char* pquery){
      if(pquery==NULL) 
        return 0;   //example   
      if(strcmp(pquery,"dll$test")==0) 
        return 101;
      if(strcmp(pquery,"dll$dealerchair")==0) 
        return m_holdem_state[(m_ndx)&0xff].m_dealer_chair; 
      if(strcmp(pquery,"dll$currentbet3")==0) 
        return m_holdem_state[(m_ndx)&0xff].m_player[3].m_currentbet;
      return 0;
    }

You can see in the code example above, how you have to use the point
operator on a struct to access the information stored in the struct of
the scraped state.

### A function returning the flush rank of the player

For convinience we restructure the code, by adding another header file:

- Click on project -\> Add New Item -\> select Header File (.h) -\> name
  it OH-general, you can also do it in the solution explorer by clicking
  on the Header Files folder.

      /////////////////////////////////////  
      //card macros  
      #define RANK(c)       ((c>>4)&0x0f)  
      #define SUIT(c)          ((c>>0)&0x0f)  
      #define ISCARDBACK(c)   (c==0xff)  
      #define ISUNKNOWN(c)     (c==0)  
      ///////////////////////////////////// 
      ////////////////////////////////////  
      //consecutive states  
      holdem_state    m_holdem_state[256];  
      unsigned char   m_ndx;  
      ////////////////////////////////////
      ////////////////////////////////////  
      //versus list & prwin 
      phl1k_t m_phl1k; 
      pp13 prw1326; 
      ////////////////////////////////////
      ////////////////////////////////////  
      //WH symbols 
      pfgws_t m_pget_winholdem_symbol; 
      ////////////////////////////////////
      double gws(int chair, const char* name, bool& iserr) {      
        return (*m_pget_winholdem_symbol)(chair,name,iserr);  
      } 

      double gws(const char* name) {      
        bool iserr;   
        int mychair = (int)gws(0,"userchair",iserr);      
        return gws(mychair,name,iserr);  
      }

      bool hlset( int rank0, int rank1, int listnum, bool onoff ) {
        return ((*m_phl1k)[listnum][rank0-2][rank1-2] = onoff); 
      }

      bool hlget( int rank0, int rank1, int listnum ) {    
        return ((*m_phl1k)[listnum][rank0-2][rank1-2]); 
      }

- Cut / paste the code above from the OH-DLL.cpp file to the
  OH-general.h header file.

- We will also need another include now, its a standart library of c++,
  wich contains a datatype called bitset.

- The bitset datatype converts integer values to their binary
  representation, we will need this because we are going to work with
  srankbits.

- You can read more about how rankbit values are obtained in the chapter
  about OpenHoldem symbols; look at the very bottom of the page.

- You can find documentation on the C++ library here:
  <http://www.cppreference.com/wiki/stl/bitset/start>.

After you’re done with cut-pasting add the bitset include and also using
namespace std; this is neccessary line, don’t think much about it, but
the include would not work without it. Your OH-DLL.cpp “\#includes”
section should look like this now:

    #define WHUSER_EXPORTS 
    #include "OH-DLL.h" 
    #include <windows.h> 
    #include <bitset>
    using namespace std;
    #include "OH-general.h"

Now we can begin with the actual coding, in the next step open
OH-general.h and add the following code:

    int srankhiplayer; 
    int srankbits; 
    int flushrank;

    int set_flush_rank(){
    bitset<16> srb( srankbits ); 
    srb = (~srb ) >>= srankhiplayer; 
    return (int)srb.count();  }

This function will determine the flush rank via some bitset operations,
1 = nutflush, 2 = 2nd nutflush, etc.

    void int_oh_symbols(){
      srankbits = (int)gws("srankbits");    
      srankhiplayer = (int)gws("srankhiplayer");    
      flushrank = set_flush_rank();
    }

This function will update the values each time a new state is scraped.

You also need to modify the OH-DLL.cpp to include this new symbol:

    double process_query(const char* pquery) {
      if(pquery==NULL)      
        return 0;   //example   
      if(strcmp(pquery,"dll$test")==0)      
        return 101;     
      if(strcmp(pquery,"dll$dealerchair")==0)
        return m_holdem_state[(m_ndx)&0xff].m_dealer_chair;
      if(strcmp(pquery,"dll$currentbet3")==0)       
        return m_holdem_state[(m_ndx)&0xff].m_player[3].m_currentbet;
      if(strcmp(pquery,"dll$flushrank")==0)         
        return flushrank;
      return 0;
    }

    double process_state(holdem_state* pstate){
        if(pstate!=NULL){m_holdem_state[ (++m_ndx)&0xff ] = *pstate;}
        int_oh_symbols();
        return 0;
    }

If all went well you can access the flush rank with dll\$flushrank on
formula level now.

## Files

The files for this tutorial can be found here:
<http://www.maxinmontreal.com/wiki/index.php5?title=Image:OH-DLL-B.rar>.
