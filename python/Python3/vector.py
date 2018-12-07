
from numbers import * 

class Vector( object ) : 
   def __init__( self, x, y ) : 
      self. x = x
      self. y = y 

   def __str__( self ) :
      return '( {}, {} )'. format( self.x, self.y )

   def __repr__( self ):
      return '( {}, {} )'. format( self.x, self.y )

   def __neg__( self ) :
      return Vector( -self. x, -self. y )

   def __add__( self, other ) :
      return Vector( self. x + other. x, self. y + other. y ) 

   def __sub__( self, other ) :
      return Vector( self. x - other. x, self. y - other. y ) 

   def __mul__( self, other ) :
      return Vector( self. x * other, self. y * other )

   def __truediv__( self, other ) :
      return Vector( self. x / other, self. y / other )
  
   ## This is operator //

   def __floordiv__( self, other ) :
      raise NotImplementedError      

   def __rmul__( self, other ) :
      return Vector( other * self. x, other * self.y ) 

   def norm( self ) :
      return self.x * self.x + self.y * self.y 

   
   # In place operators:

   def __iadd__( self, other ) : 
      self. x += other. x
      self. y += other. y
      return self
 
   def __isub__( self, other ) : 
      self. x -= other. x
      self. y -= other. y
      return self

   def __imul__( self, other ) :
      self. x *= other 
      self. y *= other
      return self

   def __itruediv__( self, other ) :
      self. x /= other
      self. y /= other
      return self

 
