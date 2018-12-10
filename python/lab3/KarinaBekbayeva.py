from matrix import *
from vector import *
from rational import *

def tests():
	m1 = Matrix(Rational(1, 2), Rational(1, 3), Rational(-2, 7), Rational(2, 8))
	m2 = Matrix(Rational(-1, 3), Rational(2, 7), Rational(2, 5), Rational(-1, 7))
	m3 = Matrix(1, 2, 3, 4)
	v = Vector(1, 2)
	print("m1xm2:")
	print(m1@m2)
	print("inverse of m1:")
	print(m1.inverse())
	print("(m 1 × m 2 ) × m 3 - m 1 × (m 2 × m 3 )")
	print((m1@m2)@m3 - (m1@(m2@m3)))
	print("m 1 ×(m 2 +m 3 ) - m 1 ×m 2 +m 1 ×m 3:")
	print(m1@(m2+m3) - (m1 @ m2 + m1@m3))
	print("m 1 (m 2 (v)) - (m 1 × m 2 )(v)")
	print(m1(m2(v)) - (m1@m2)(v))
	print("det(m 1 ).det(m 2 ) - det(m 1 × m 2 )")
	print(m1.determinant()*m2.determinant() - (m1@m2).determinant())
	print("m1 × inv(m1) - I:")
	print(m1@m1.inverse() - Matrix(1, 0, 0, 1))
