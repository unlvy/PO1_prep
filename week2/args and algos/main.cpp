#include <iostream>
#include "Suma.h"
#include "Pierwiastek.h"
#include "Argumenty.h"

int main() {

  Argumenty a( 4 );
  a( 0, 2.5 )( 1, 4 )( 3, 8 )( 2, 9 );
  a.print( "Wartosci wejsciowe:" );

  Algo *s = new Suma();
  s->wykonaj( a ).print( "Po zsumowaniu:" );

  Pierwiastek *p = new Pierwiastek();
  p->wykonaj( a ).print( "Pierwiastki:" );
  s->wykonaj( p->wykonaj( a ) ).print( "Suma pierwiastkow:" );
  p->wykonaj( s->wykonaj( a ) ).print( "Pierwiastek sumy:" );
  
  Algo* z = s->sklonuj( );
  const Pierwiastek* b = p->sklonuj( ); 

  z->wykonaj( z->wykonaj( const_cast<const Argumenty&>( a ) ) ).print( "Powtorka: " );
  b->wykonaj( s->wykonaj( a ) ).print( "Powtorka: ", std::cout );
  
  delete s;
  delete p;
  delete z;
  delete b;
}
/* wynik
Wartosci wejsciowe: 2.5 4 9 8 
Po zsumowaniu: 23.5 
Pierwiastki: 1.58114 2 3 2.82843 
Suma pierwiastkow: 9.40957 
Pierwiastek sumy: 4.84768 
Powtorka:  23.5 
Powtorka:  4.84768 
 */
