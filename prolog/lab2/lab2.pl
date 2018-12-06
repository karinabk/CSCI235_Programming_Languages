%Lab_work #2 Karina Bekbayeva
%task #1
cartesian([],X,[]).
cartesian([F|R], X, C3 ) :- cartesian(R,X,C1),
			    product(F,X,C2),
			    append( C1,C2,C3).
product(X,[], []).
product(X,[F|R] , [pair(X,F)|L]):- product( X,R,L).

%task #2

deepmember(X, [F | _]) :- deepmember(X, F); X = F.
deepmember(X, [_ | R]) :- deepmember(X, R).


%task #3
notcontains(X,[]).
notcontains( X, [H | T ]) :- X \= H, notcontains( X, T).

%second_version%
notcontains1(X , L) :- \+deepmember(X, L).

%task #4 a)
addunique(X,[],[X]).
addunique(X,L1,L1):- deepmember(X,L1).
addunique(X, L1, [X|L1]) :-notcontains(X,L1).

%task #4 b)  
setinsertion(X,S1,S1):- deepmember(X,S1),!.
setinsertion(X,S1,[X|S1]):-
			notcontains(X, S1).

%task #5 a)
allvertices([[X,Y]], [X,Y]).

allvertices([[X,Y]|R],L) :- 
		allvertices(R, L1),
		setinsertion(X,L1,L2),
		setinsertion(Y,L2,L).



%task #5 b)

connected(V0, V1, [[V0, V1]|R]).
connected(V0, V1, [[_, _]|R]) :- 
			connected(V0, V1, R).

%task #5 c)	

path( G,      Vbegin, 1,         Forbidden,            [Vbegin], Vbegin).

path( G, Vbegin, N, Forbidden, [Vbegin| Path], Vend) :-
			connected(Vbegin, X, G), Vbegin \= X,
			notcontains(X, Forbidden),
			J is N - 1,
			path(G, X, J, [X|Forbidden], Path,  Vend).	


%task #5 d)
hamiltoniancircuit( G, C ) :-
	allvertices( G, Vert ),
	Vert = [ V0 | _ ],
	length( Vert, N ),
	path( G, V0, N, [ V0 ], C, LastV ),
	connected( LastV, V0, G ).
