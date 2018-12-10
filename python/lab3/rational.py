



def gcd(n1, n2 ):
	
	if n1== 0 and n2 == 0 :
		raise ArithmeticError("gcd(0,0) does not exist")
	if n1 ==0:
		return n2
	elif n2 ==0:
		return n1 
	return gcd(n2,n1%n2)

from numbers import *
class Rational( Number ) :
	def normalize(self):
		val = gcd(self.num,self.denum)
		self.num = self.num//val
		self.denum = self.denum//val
		if self.denum <0:
			self.denum *= -1
			self.num *= -1	


	def __init__( self, num, denum = 1 ) :
		self. num = num
		self. denum = denum
		self. normalize( )
		
	def __repr__(self):
		answer = ""
		if self.denum == 1:
			answer+= str(self.num)
		else:
			answer+= str(self.num) +" / "+ str(self.denum)
		return answer

	def __neg__(self):
		return Rational(-self.num,self.denum)
	
	def __add__(self, other):
		if isinstance(other,Rational):
			return Rational(self.num*other.denum+self.denum*other.num,self.denum*other.denum)
		else:
			return Rational(self.denum*other + self.num , self.denum)

	def __sub__(self, other):
		if isinstance(other, Rational):
			return Rational(self.num*other.denum-self.denum*other.num,self.denum*other.denum)
		else:
			return Rational( self.num - self.denum*other  , self.denum)

	def __radd__(self, other):
		return self + other

	def __rsub__(self, other):
		return (self - other)*(-1)

	def __mul__(self,other):
		if isinstance(other,Rational):
			return Rational(self.num * other.num , self.denum*other.denum)
		else:
			return Rational(self.num*other , self.denum)

	def __truediv__(self,other):
		if isinstance(other,Rational):
			return Rational(self.num*other.denum , self.denum*other.num)
		else:
			return Rational(self.num , self.denum*other)
	
	def __rmul__(self, other):
		return self*other

	def __rtruediv__(self,other):
		if isinstance(other,Rational):
			return Rational(self.denum*other.num , self.num*other.denum)
		else:
			return Rational(other*self.denum , self.num)



		
	



