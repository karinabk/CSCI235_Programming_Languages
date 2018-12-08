
#include <iostream>
#include <cmath>
#include <stdio.h> 
#include <functional>


// Runge-Kutta methods have two template parameters H and X.
// X must be of vector type.
// H must be a type with which elements of X can be multiplied.
// Normally H = double, H = float or but H = math::complex 
// should also work.
// I didn't test with complex numbers, because I don't know
// a good example. 

// runge_kutta1 is Euler's method:

template< typename X, typename F, typename H = double >
X runge_kutta1( const X& x, const F& f, H h )
{
   X k1 = f( x );
   return x + h * k1;
}

// We have two methods of order two. The first method is Heun's method.
// runge_kutta22 is approximately two times better than 
// runge_kutta21. 

template< typename X, typename F, typename H = double > 
X runge_kutta21( const X& x, const F& f, H h )
{
   X k1 = f( x );
   X k2 = f( x + h * k1 );

   return x + h * ( 0.5 * k1 + 0.5 * k2 );
}

template< typename X, typename F, typename H = double > 
X runge_kutta22( const X& x, const F& f, H h )
{
   X k1 = f( x );
   X k2 = f( x + 0.5 * h * k1 );

   return x + h * k2; 
}


// A third order method:

template< typename X, typename F, typename H = double > 
X runge_kutta31( const X& x, const F& f, H h )
{
   X k1 = f( x );
   X k2 = f( x + h * (2.0/3.0) * k1 );
   X k3 = f( x + h * ( (1.0/3.0) * k1 + (1.0/3.0) * k2 ) );

   return x + h * ( (1.0/4.0) * k1 + (3.0/4.0) * k3 );
}


// The standard Runge Kutta method:

template< typename X, typename F, typename H = double > 
X runge_kutta41( const X& x, const F& f, H h )
{
   X k1 = f( x );
   X k2 = f( x + 0.5 * h * k1 );
   X k3 = f( x + 0.5 * h * k2 );
   X k4 = f( x + h * k3 );

   return x + ( 1.0 / 6.0 ) * h * ( k1 + 2.0 * k2 + 2.0 * k3 + k4 );
}


// A fourth order method by J.Kuntzmann. Accuracy is 
// approximately two times better than standard Runge Kutta. 

template< typename X, typename F, typename H = double > 
X runge_kutta4_kuntzmann( const X& x, const F& f, H h )
{
   X k1 = f( x );
   X k2 = f( x + h * (2.0/5.0) * k1 );
   X k3 = f( x + h * ( (-3.0/20.0) * k1 + (3.0/4.0) * k2 ) );
   X k4 = f( x + h * ( (19.0/44.0) * k1 + (-15.0/44.0) * k2 + 
                       (40.0/44.0) * k3 ) );

   return x + h * ( (55.0/360.0) * k1 + (125.0/360.0) * k2 +
                    (125.0/360.0) * k3 + (55.0/360.0) * k4 );
}


// A fifth-order Runge Kutta method with six stages:
// (Page 92 in J.C.Butcher, Numerical Methods for Ordinary Differential
// Equations.) 

template< typename X, typename F, typename H = double >
X runge_kutta5( X& x, const F& f, H h )
{
   X k1 = f( x );
   X k2 = f( x + h * (1.0/4.0) * k1 );
   X k3 = f( x + h * ( (1.0/8.0) * k1 + (1.0/8.0) * k2 ) );
   X k4 = f( x + h * (1.0/2.0) * k3 );
   X k5 = f( x + h * ( (3.0/16.0) * k1 + (-3.0/8.0) * k2 +
                       (3.0/8.0) * k3 + (9.0/16.0) * k4 ) );
   X k6 = f( x + h * ( (-3.0/7.0) * k1 + (8.0/7.0) * k2 +
                       (6.0/7.0) * k3 + (-12.0/7.0) * k4 + 
                       (8.0/7.0) * k5 ) );
      
   return x + h * 
      (   ( 7.0 / 90.0 ) * k1 + ( 32.0 / 90.0 ) * k3 + 
          ( 12.0 / 90.0 ) * k4 + ( 32.0 / 90.0 ) * k5 +
          ( 7.0 / 90.0 ) * k6 );
}


struct pair 
{
   double v;
   double w;

   pair( double v, double w )
      : v{v}, w{w}
   { }
};

inline pair operator * ( double h, pair p )
{
   return { h * p.v, h * p.w };
}

inline pair operator + ( pair p1, pair p2 )
{
   return { p1.v + p2.v, p1.w + p2.w };
}

pair euler( pair p, const std::function< pair(pair) > & F, double h )
{
   return p + h * F(p);
}

pair heun( pair p, const std::function< pair(pair) > & F, double h )
{
   pair k1 = p + h * F( p ); 
   return p + h * 0.5 * ( F(p) + F( k1 )); 
}

inline std::ostream& operator << ( std::ostream& stream, const pair& p )
{
   stream << "[ " << p.v << ", " << p.w << " ]";
   return stream;
}


void test(){

   double h = 2.0E-3;

   double x0 = 0.0;
   double x1 = 1.0;

   double lambda = 2;

   pair s0{ 1.0 / lambda, 0.0 }; 
 
   pair p = s0;
   double x = x0;

   std::function< pair(pair) > cat = 
      [ &lambda ] ( const pair& p ) 
         { return pair{ p.w, lambda * sqrt( 1.0 + p.w * p.w ) }; };
 
   while( x + h < x1 )
   {
      p = runge_kutta21( p, cat, h ); 
      x = x + h;
   }

   p = runge_kutta1( p, cat, x1 - x );
   x = x1;

   std::cout << "h = " << h << "\n";
   std::cout << "final value " << p << "\n";
   
   pair expected = { cosh( lambda * x1 ) / lambda, sinh( lambda * x1 ) }; 
   pair error = p + -1.0 * expected;
   printf( "error = %.18le, %.18le\n", error.v, error.w ); 
}

int main( int argc, char * argv [ ] )
{
   for(int i = 0; i < 1000; i++){
	test();
   }
   return 0;
}


