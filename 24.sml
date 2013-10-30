fun fact 0 = 1
  | fact n = n * fact(n-1);

fun get_nth_per n L =
    case n of 0 => L
	    | n => 
	      let
		  val first = n div fact(length L - 1)
		  val elem = List.nth(L, first)
	      in
		  elem::(get_nth_per (n mod fact(length L - 1))
				     (List.take(L, first)@List.drop(L, first+1)))
	      end;

val ans = implode(get_nth_per (1000000 - 1) (explode "0123456789"));
