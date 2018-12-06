findElem(X,[X]).
%findElem(X, [X]).
findElem(X,[F|R]):-findElem(X,F).
findElem(X,[_|R]):-findElem(X,R).

makeSet([X],[X]).
makeSet([F|R],[F|L]):-  \+member(F,R),
		    makeSet(R,L).
makeSet([F|R],L):- 
		member(F,R),
		makeSet(R,L).

lastE([X],X).
lastE([F|R],X):-lastE(R,X).


kth(F,[F|R],0).
kth(X,[F|R],Num):-
	Num1 is Num-1,
	kth(X,R,Num1).

num([],0).
num([F|R],X):- 	num(R,X1),
		X is X1+1.



rev1( X1,X2):- rev(X1,X2,[]).


rev([],X1,X1):- !.
rev([F|R],X,Y):-rev(R,X, [F|Y]).

dupl([X],[X,X]).
dupl([F|R],[F,F|X]):-dupl(R,X).

			
