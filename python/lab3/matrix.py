
from numbers import Number
from vector import *


class Matrix( object ) : 

   def __init__( self, a11 = 0, a12 = 0, a21 = 0, a22 = 0 ) : 
      self. a11 = a11
      self. a12 = a12
      self. a21 = a21
      self. a22 = a22 

   def __repr__( self ):
      return '/ {:4} {:4} \\\n\\ {:4} {:4} /\n '. format( 
                            str( self.a11 ), str( self.a12 ), 
                            str( self.a21 ), str( self.a22 ))

   def __neg__( self ) :
      return Matrix( -self. a11, -self.a12, -self.a21, -self.a22 )

   def __add__( self, other ) :
      return Matrix( self. a11 + other. a11,  self. a12 + other. a12,
                     self. a21 + other. a21,  self. a22 + other. a22 ) 

   def __sub__( self, other ) :
      return Matrix( self. a11 - other. a11,  self. a12 - other. a12,
                     self. a21 - other. a21,  self. a22 - other. a22 )   

   def __mul__( self, other ) :
      return Matrix( self. a11 * other, self. a12 * other,
                     self. a21 * other, self. a22 * other )

   def __truediv__( self, other ) :
      return Matrix( self. a11 / other, self. a12 / other,
                     self. a21 / other, self. a22 / other )

   def __rmul__( self, other ) :
      return Matrix( other * self. a11, other * self. a12,
                     other * self. a21, other * self. a22 )

   def __imul__( self, other ) :
      self. a11 *= other
      self. a12 *= other
      self. a21 *= other
      self. a22 *= other
      return self

   def __itruediv__( self, other ) :
      self. a11 /= other
      self. a12 /= other
      self. a21 /= other
      self. a22 /= other
      return self

   def determinant( self ) :
      return self. a11 * self. a22 - self. a21 * self. a12

   def __matmul__( self, other ) :
      return Matrix( self. a11 * other. a11 + self. a12 * other. a21,
                     self. a11 * other. a12 + self. a12 * other. a22,
                     self. a21 * other. a11 + self. a22 * other. a21, 
                     self. a21 * other. a12 + self. a22 * other. a22 ) 

   def adjugate( self ) :
      return Matrix( self. a22, -self. a12, -self. a21, self. a11 )

   def inverse( self ) :
      d = self. determinant( )
      if d == 0 :
         raise ZeroDivisionError

      return self. adjugate( ) / d

   def __call__( self, v ) :
      return Vector( self. a11 * v.x + self. a12 * v.y, 
                     self. a21 * v.x + self. a22 * v.y )


   ## This is operator //

   def __floordiv__( self, other ) :
      raise NotImplementedError      



