val input = TextIO.openIn "names.txt";
val names = String.tokens (fn c => c = #"," orelse c = #"\"" orelse c = #"\n")
			  (case TextIO.inputLine input of
			       SOME s => s
			     | NONE => "" );

fun merge f L1 L2 =
    case (L1, L2) of ([], L2) => L2
		   | (L1, []) => L1
		   | (x1::xs1, x2::xs2) =>
		     if (f (x1, x2))
		     then x1::(merge f xs1 L2)
		     else x2::(merge f L1 xs2);

fun split L =
    let
	val middle = (length L) div 2
    in
	(List.take (L, middle), List.drop(L, middle))
    end;

fun mergesort f L =
    case L of [] => []
	    | [_] => L
	    | _ =>
	      let
		  val (LL, RL) = split L
	      in
		  merge f (mergesort f LL) (mergesort f RL)
	      end;
fun compute str =
    foldl (fn (x, acc) => acc + 1 + (ord(x) - ord(#"A"))) 0 (explode str);

fun score L =
    #1 (foldl (fn (x, (sum, pos)) => (sum + x * pos, pos +1))
	      (0, 1) ((map compute L)));

val answer = score (mergesort (fn (x,y) => x<=y ) names);
